#include "root.h"
#include "ogre_initialiser.h"
#include "camera_manager.h"
#include "state_manager.h"

namespace ZSys
{
    Root::Root( const Ogre::String &base_path,
                bool create_,
                const Ogre::String &plugins,
                const Ogre::String &config,
                const Ogre::String &log_)
    {
        mCreated=false;
        mContinue=true;
        if (create_)
            create(base_path, plugins, config, log_);
    }

    Root::~Root()
    {
        if (isCreated())
            destroy();
    }
    bool                    Root::handleWindowEvents()
    {
        Ogre::WindowEventUtilities::messagePump();
        if (!mInputMgr)
            return false;
        mInputMgr->capture();

#ifdef Z_DEV_BUILD
        if (mInputMgr->isActionWanted(ACTION_QUIT))
            mStateMgr->popState();
#endif
        return true;
    }

    bool                        Root::renderOneFrame()
    {
        if (!mInit->getRoot())
            return false;
        return mInit->getRoot()->renderOneFrame();
    }

    void Root::stopMainLoop(bool state)
    {
        mContinue = state;
    }
    void Root::mainLoop()
    {
        DEV_INFO("Creating app's main loop ...");
        while (mContinue)
        {
            if (!handleWindowEvents())
            {
                mContinue = false;
                return ;
            }

            if(!renderOneFrame())
            {
                mContinue = false;
                return ;
            }
        }
    }
    bool Root::isCreated() const{ return mCreated; }
    InputSystem       *Root::createInputSystem()
    {
        if (mInputMgr)
            return mInputMgr.get();
        mInputMgr = std::unique_ptr<InputSystem>(new InputSystem);
        mInputMgr->create(mParams->getMainWindow());
        return mInputMgr.get();
    }
    void                    Root::destroyInputSystem()
    {
        if (!mInputMgr)
            return ;
        mInputMgr->destroy();
        mInputMgr.release();
    }

    void Root::create(  const Ogre::String &base_path,
                        const Ogre::String &plugins,
                        const Ogre::String &config,
                        const Ogre::String &log_)
    {
        if (isCreated())
            return ;
        DEV_INFO("Creating root:\n---------------\n");
        DEV_INFO("Creating OgreParams");
        mParams = std::shared_ptr<OgreParams>(new OgreParams);
        DEV_INFO("Creating OgreInitializer");
        mInit = std::unique_ptr<OgreInitializer>(new OgreInitializer(base_path, true, plugins, config, log_));
        DEV_INFO("Allocating CameraManager");
        mCamMgr = std::unique_ptr<CameraManager>(new CameraManager);
        DEV_INFO("Allocating CameraManager");
        mStateMgr = std::unique_ptr<StateManager>(new StateManager);

        DEV_INFO("Creating RenderWindow");
        mParams->setMainWindow(mInit->createWindow(true));
        mParams->setRoot(mInit->getRoot());

        DEV_INFO("Adding resources");
        mInit->parseResourcesConfig(OGRE_RESOURCES_FILE);

        mInit->initResourceGroups();
        DEV_INFO("Setting SceneManager");
        mParams->setSceneMgr(mInit->createSceneManager());

        DEV_INFO("Creating InputSystem");
        createInputSystem();

        DEV_INFO("Creating UI");
        mInit->createUi();

        DEV_INFO("Creating CameraManager");
        mCamMgr->create(mParams, mInputMgr.get());

        DEV_INFO("Creating StateManager");
        mStateMgr->create(this);

        DEV_MSG("Root successfully created !", DMT_SUCCESS);
        mCreated = true;
    }
    void Root::destroy()
    {
        if (!isCreated())
            return ;
        DEV_INFO("Destroying root");
        mStateMgr->destroy();
        mCamMgr->destroy();
        destroyInputSystem();
        mInit->destroy();
        mInit.release();
        mParams.reset();
        mCamMgr.release();
        mStateMgr.release();
        mCreated = false;
    }
    InputSystem                 *Root::getInputSystem(){ return mInputMgr.get(); }
    const InputSystem           *Root::getInputSystem() const{ return mInputMgr.get(); }
};
