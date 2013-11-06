#include "root.h"
#include "ogre_initialiser.h"

namespace zsys
{
    Root::Root( const Ogre::String &base_path,
                bool create_,
                const Ogre::String &plugins,
                const Ogre::String &config,
                const Ogre::String &log_)
        : mCreated(false)
        , mContinue(true)
    {
        if (create_)
            create(base_path, plugins, config, log_);
    }

    Root::~Root()
    {
        if (isCreated())
            destroy();
    }
    void Root::stopMainLoop(bool state)
    {
        mContinue = state;
    }
    void Root::mainLoop()
    {
        while (mContinue)
        {
            if (!mInit->handleWindowEvents())
            {
                mContinue = false;
                return ;
            }

            if(mInit->renderOneFrame() == false)
            {
                mContinue = false;
                return ;
            }
        }
    }
    bool Root::isCreated() const{ return mCreated; }
    void Root::create(  const Ogre::String &base_path,
                        const Ogre::String &plugins,
                        const Ogre::String &config,
                        const Ogre::String &log_)
    {
        if (isCreated())
            return ;
#ifdef DEV_BUILD
            mkdir(dev)
        std::ofstream ofs("dev.log", )
#else

#endif
        mParams = std::shared_ptr<OgreParams>(new OgreParams);
        mInit = std::unique_ptr<OgreInitializer>(new OgreInitializer(base_path, true, plugins, config, log_));
        mCamMgr = std::unique_ptr<CameraManager>(new CameraManager);
        mParams->setMainWindow(mInit->createWindow(true));
        mParams->setRoot(mInit->getRoot());
        mInit->parseResourcesConfig(OGRE_RESOURCES_FILE);
        mInit->initResourceGroups();
        mParams->setSceneMgr(mInit->createSceneManager());
        mInit->createInputSystem();
        mInit->createUi();
        mCamMgr->create(mParams, mInit->getKeyboard(), mInit->getMouse());
        mCreated = true;
    }
    void Root::destroy()
    {
        if (!isCreated())
            return ;
        mCamMgr->destroy();
        mInit->destroy();
        mInit.release();
    }
};
