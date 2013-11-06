#ifndef Z_ROOT_H
#define Z_ROOT_H

#include <OgreRoot.h>
#include <memory>
#include "platform.h"
#include "ogre_initialiser.h"
#include "camera_manager.h"

namespace zsys
{
    class Root
    {
        public:
            Z_API Root(   const Ogre::String &base_path = Ogre::StringUtil::BLANK,
                    bool create_ = true,
                    const Ogre::String &plugins = OGRE_PLUGINS_FILE,
                    const Ogre::String &config = OGRE_CONFIG_FILE,
                    const Ogre::String &log_ = OGRE_LOG_FILE);
            virtual ~Root();

            void stopMainLoop(bool state = true);
            void mainLoop();

            bool isCreated() const;
            void create(const Ogre::String &base_path = Ogre::StringUtil::BLANK,
                    const Ogre::String &plugins = OGRE_PLUGINS_FILE,
                    const Ogre::String &config = OGRE_CONFIG_FILE,
                    const Ogre::String &log_ = OGRE_LOG_FILE);
            void destroy();

            void setParameters(const OgreParamsPtr& p){ mParams = p; }
            const OgreParamsPtr& getParameters() const{ return mParams; }
            OgreParamsPtr& getParameters(){ return mParams; }

            const std::unique_ptr<CameraManager>& getCameraMgr() const{ return mCamMgr; }
            std::unique_ptr<CameraManager>      & getCameraMgr(){ return mCamMgr; }

        protected:
            bool                                mContinue;
            bool                                mCreated;
            OgreParamsPtr                       mParams;
            std::unique_ptr<OgreInitializer>    mInit;
            std::unique_ptr<CameraManager>      mCamMgr;
        private:
    };
};

#endif // Z_ROOT_H
