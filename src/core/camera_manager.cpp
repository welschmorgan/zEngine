#include "camera_manager.h"
#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>

namespace zsys
{
    namespace   tr
    {
        string      UserDirection(zsys::UserDirection dir, bool capitalise)
        {
            static string ret;
            switch(dir)
            {
            case TD_FORWARD:
                ret = string(1, capitalise?'F':'f') + "orward";
                break;
            case TD_BACKWARD:
                ret = string(1, capitalise?'B':'b') + "ackward";
                break;
            case TD_LEFT:
                ret = string(1, capitalise?'L':'l') + "eft";
                break;
            case TD_RIGHT:
                ret = string(1, capitalise?'R':'r') + "ight";
                break;
            }
            return ret;
        }
    };

    CameraManager::CameraManager()
        : mKbd(nullptr)
        , mMouse(nullptr)
        , mActive(nullptr)
    {
    //ctor
    }

    CameraManager::~CameraManager()
    {
    //dtor
    }
    void CameraManager::activate(Ogre::Camera * cam)
    {
        assert(cam && "Invalid camera");
        assert(!hasCamera(cam) && "Unregistered camera");
        mActive = cam;
    }
    bool CameraManager::hasCamera(const Ogre::Camera * cam) const
    {
        for(List::const_iterator i=mList.cbegin(); i!=mList.cend(); i++)
            if ((*i) == cam)
                return true;
        return false;
    }

    void CameraManager::create(const OgreParamsPtr& ptr,OIS::Keyboard*k, OIS::Mouse *m)
    {
        assert(ptr->getMainWindow() && "Invalid window");
        if (m_created)
            return ;

        Ogre::RenderWindow * w = ptr->getMainWindow();
        assert(w && "Invalid window");
        Ogre::Viewport * vp = nullptr;
        if (w->getNumViewports() == 0)
        {
            mActive = mParams->getSceneMgr()->createCamera("SystemCamera");
            vp = w->addViewport(mActive);
        }
        else
        {
            vp = w->getViewport(0);
            mActive = vp->getCamera();
        }
        if (!mActive)
            vp = w->addViewport(mActive);
        assert(k && m && "Invalid Input System");
        mKbd = k;
        mMouse = m;

        mActive->setPosition(Ogre::Vector3(0,10,500));
        mActive->lookAt(Ogre::Vector3(0,0,0));
        mActive->setFOVy(Ogre::Radian(Ogre::Degree(45.0f)));
        mActive->setNearClipDistance(5);

        if (ptr->getRoot()->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_INFINITE_FAR_PLANE))
            mActive->setFarClipDistance(0);
        addCamera(mActive);

        Ogre::LogManager::getSingleton().logMessage("CameraManager loaded, handling "+std::to_string(mList.size()), Ogre::LML_TRIVIAL);
        m_created = true;
    }
    void CameraManager::destroy()
    {
        if (!m_created)
            return ;
        mList.clear();
        mActive = nullptr;
        m_created = false;
    }

    CameraManager::List::const_iterator CameraManager::findCamera(const Ogre::Camera * cam) const
    {
        for(List::const_iterator i=mList.cbegin(); i!=mList.cend(); i++)
            if ((*i) == cam)
                return i;
        return mList.end();
    }
    CameraManager::List::iterator CameraManager::findCamera(Ogre::Camera * cam)
    {
        for(List::iterator i=mList.begin(); i!=mList.end(); i++)
            if ((*i)== cam)
                return i;
        return mList.end();
    }
    void CameraManager::addCamera(Ogre::Camera * cam, bool activate_)
    {
        if (hasCamera(cam))
            THROW(Ogre::Exception::ERR_DUPLICATE_ITEM, "Camera already registered");
        mList.push_back(cam);
        if (activate_)
            activate(cam);
    }
    const CameraManager::List& CameraManager::getList() const{ return mList; }

};
