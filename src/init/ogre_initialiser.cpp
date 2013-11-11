#include "ogre_initialiser.h"
#include <OgreLogManager.h>

namespace ZSys
{
    OgreInitializer::OgreInitializer(
                                     const Ogre::String &base_path,
                                     bool create_,
                                     const Ogre::String &plugins,
                                     const Ogre::String &config,
                                     const Ogre::String &log_)
    {
        mRoot = nullptr;
        mWindow = nullptr;
        mCreated = false;
        #if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
            mResourcesPath = Ogre::macBundlePath() + "/Contents/Resources/" + base_path;
        #else
            mResourcesPath = base_path;
        #endif

        if (create_)
            createRoot(plugins, config, log_);
        oldCOUTStreamBuf = std::cout.rdbuf();
        oldCERRStreamBuf = std::cerr.rdbuf();
        mConsole = new OgreConsole(false);
    }
    OgreInitializer::~OgreInitializer()
    {
        if (mConsole)
            delete mConsole, mConsole = nullptr;
        std::cout.rdbuf( oldCOUTStreamBuf );
        std::cerr.rdbuf( oldCERRStreamBuf );
        destroy();
    }
    bool OgreInitializer::isCreated() const{ return mCreated; }
    void OgreInitializer::parseResourcesConfig(const Ogre::String &name)
    {
        mResourcesFile = name;
        Ogre::ConfigFile cf;
        cf.load(mResourcesPath + name);
        // Go through all sections & settings in the file
        Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

        Ogre::String secName, typeName, archName;
        while (seci.hasMoreElements())
        {
            secName = seci.peekNextKey();
            Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                typeName = i->first;
                archName = i->second;

                #if OGRE_PLATFORM == OGRE_PLATFORM_APPLE || OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
                                if (!Ogre::StringUtil::startsWith(archName, "/", false)) // only adjust relative dirs
                                    archName = Ogre::String(Ogre::macBundlePath() + "/" + archName);
                #endif

                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
            }
        }
    }
    OgreConsole             *OgreInitializer::getConsole(){ return mConsole; }
    const OgreConsole       *OgreInitializer::getConsole() const{ return mConsole; }
    void OgreInitializer::addResourceLocation( const Ogre::String &archName, const Ogre::String &typeName, const Ogre::String &secName)
    {
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
    }
    void OgreInitializer::initResourceGroups()
    {
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    }
    void OgreInitializer::destroy()
    {
        destroyRoot();
    }

    Ogre::Root              *OgreInitializer::createRoot(const Ogre::String &plugins, const Ogre::String &config, const Ogre::String &log_)
    {
        std::cout << "Root: "<<(unsigned long)mRoot<<std::endl;
        if (mCreated)
            return mRoot;
        mRoot = new Ogre::Root(mResourcesPath + plugins, mResourcesPath + config, log_);
        if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
        {
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALID_STATE, "Couldn't load or set the ogre configuration", __FUNCTION__);
        }

        mCreated = true;
        return mRoot;
    }
    void                    OgreInitializer::destroyRoot()
    {
        if (mCreated)
            delete mRoot, mRoot = NULL;
        mCreated = false;
    }

    void                    OgreInitializer::createUi()
    {
        if (!mConsole && !mWindow)
            OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Cannot create console, window has not yet been created", __FUNC__);
        //mConsole->create(mWindow);
    }
    Ogre::RenderWindow      *OgreInitializer::createWindow(bool auto_create)
    {
        if (mRoot && !mWindow)
            mWindow = mRoot->initialise(auto_create);
        return mWindow;
    }
    Ogre::SceneManager      *OgreInitializer::createSceneManager(Ogre::SceneType type)
    {
        Ogre::SceneManager * mgr = mRoot->createSceneManager(type);
        mgr->setSkyBox(true,"Examples/CloudyNoonSkyBox");
        mgr->setAmbientLight(Ogre::ColourValue::White);
        mgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
        Ogre::Light * l = mgr->createLight();
        l->setType(Ogre::Light::LT_DIRECTIONAL);
        l->setDirection(0.03, -1.0, 0.01);
        return mgr;
    }

    size_t                      OgreInitializer::getWindowHandle() const
    {
        if (!mWindow)
            return (-1);
        size_t hwnd = 0;
        mWindow->getCustomAttribute("WINDOW", &hwnd);
        return hwnd;
    }

    const Ogre::String          &OgreInitializer::getResourcesPath() const{return mResourcesPath;}

    Ogre::Root                  *OgreInitializer::getRoot(){ return mRoot; }
    const Ogre::Root            *OgreInitializer::getRoot() const{ return mRoot; }

    Ogre::RenderWindow          *OgreInitializer::getWindow(){ return mWindow; }
    const Ogre::RenderWindow    *OgreInitializer::getWindow() const{ return mWindow; }
};
