#ifndef Z_ROOT_H
#define Z_ROOT_H

#include <OgreRoot.h>
#include <memory>
#include "platform.h"
#include "ogre_initialiser.h"
#include "ogre_params.h"

namespace ZSys
{
    class Z_API Root
    {
        public:
            Root(   const Ogre::String &base_path = Ogre::StringUtil::BLANK,
                    bool create_ = true,
                    const Ogre::String &plugins = OGRE_PLUGINS_FILE,
                    const Ogre::String &config = OGRE_CONFIG_FILE,
                    const Ogre::String &log_ = OGRE_LOG_FILE);
            virtual ~Root();

            void                    stopMainLoop(bool state = true);
            void                    mainLoop();

            bool                    isCreated() const;
            void                    create(const Ogre::String &base_path = Ogre::StringUtil::BLANK,
                                            const Ogre::String &plugins = OGRE_PLUGINS_FILE,
                                            const Ogre::String &config = OGRE_CONFIG_FILE,
                                            const Ogre::String &log_ = OGRE_LOG_FILE);
            void                    destroy();

            bool                    handleWindowEvents();
            bool                    renderOneFrame();

            void                    setParameters(const OgreParamsPtr& p){ mParams = p; }

            const OgreParamsPtr&    getParameters() const{ return mParams; }
            OgreParamsPtr&          getParameters(){ return mParams; }

            const CameraManager     *getCameraMgr() const{ return mCamMgr.get(); }
            CameraManager           *getCameraMgr(){ return mCamMgr.get(); }

            const StateManager      *getStateManager() const{ return mStateMgr.get(); }
            StateManager            *getStateManager(){ return mStateMgr.get(); }

            InputSystem             *createInputSystem();
            void                    destroyInputSystem();

            InputSystem             *getInputSystem();
            const InputSystem       *getInputSystem() const;

        protected:
            bool                                mContinue;
            bool                                mCreated;
            OgreParamsPtr                       mParams;
            std::unique_ptr<OgreInitializer>    mInit;
            std::unique_ptr<InputSystem>        mInputMgr;
            std::unique_ptr<CameraManager>      mCamMgr;
            std::unique_ptr<StateManager>       mStateMgr;
        private:
    };
};

#endif // Z_ROOT_H
