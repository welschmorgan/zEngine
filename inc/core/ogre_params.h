#ifndef Z_OGRE_PARAMS_H
#define Z_OGRE_PARAMS_H


#include <memory>
#include "platform.h"

namespace ZSys
{
    class Z_API OgreParams
    {
        public:
            OgreParams(Ogre::Root *root = NULL, Ogre::RenderWindow *win = NULL, Ogre::SceneManager * mgr = NULL){mSceneMgr=mgr;mWindow = win; mRoot=root;}
            OgreParams(const OgreParams& o){mSceneMgr=o.mSceneMgr;mWindow=o.mWindow;mRoot=o.mRoot;}
            ~OgreParams(){}

            OgreParams& operator=(const OgreParams& o)
            {
                mSceneMgr=o.mSceneMgr;
                mWindow=o.mWindow;
                mRoot=o.mRoot;
                return *this;
            }
            void                setMainWindow(Ogre::RenderWindow *win){ mWindow = win; }
            void                setSceneMgr(Ogre::SceneManager *mgr){ mSceneMgr = mgr; }
            void                setRoot(Ogre::Root *root){ mRoot = root; }

            Ogre::RenderWindow  *getMainWindow(){ assert(mWindow); return mWindow; }
            Ogre::SceneManager  *getSceneMgr(){ assert(mSceneMgr); return mSceneMgr; }
            Ogre::Root          *getRoot(){ assert(mRoot); return mRoot; }

        protected:
            Ogre::RenderWindow  *mWindow;
            Ogre::SceneManager  *mSceneMgr;
            Ogre::Root          *mRoot;
    };

    typedef std::shared_ptr<OgreParams> OgreParamsPtr;
};

#endif // Z_OGRE_PARAMS_H
