#include "camera_manager.h"
#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include "input_system.h"

namespace ZSys
{
    namespace   tr
    {
        string      UserDirection(ZSys::UserDirection dir, bool capitalise)
        {
            static string ret;
            switch(dir)
            {
            case UD_FORWARD:
                ret = string(1, capitalise?'F':'f') + "orward";
                break;
            case UD_BACKWARD:
                ret = string(1, capitalise?'B':'b') + "ackward";
                break;
            case UD_LEFT:
                ret = string(1, capitalise?'L':'l') + "eft";
                break;
            case UD_RIGHT:
                ret = string(1, capitalise?'R':'r') + "ight";
                break;
            }
            return ret;
        }
    };

    /**
     * Camera
     */
    Camera::Camera(CameraMode mode, const string &name, Ogre::Camera * cam)
        : EnableName(name)
        , mCam(cam)
        , mMode(mode)
    {}
    Camera::~Camera()
    {}

    void                Camera::setCamera(Ogre::Camera * cam){ mCam = cam; }
    Ogre::Camera        *Camera::getCamera(){ return mCam; }
    const Ogre::Camera  *Camera::getCamera() const{ return mCam; }

    CameraMode          Camera::getMode() const{ return mMode; }
    void                Camera::setMode( CameraMode mode ){ mMode = mode; }

    void                Camera::move(UserDirection dir, Ogre::Real delta_time, Ogre::Real speed_mult)
    {
        if (!mCam)
            THROW(Ogre::Exception::ExceptionCodes::ERR_INVALID_STATE, "Cannot move, no camera supplied for UserCamera '" + getName()+"'");
        switch(dir)
        {
        case UD_FORWARD:
            if (mMode == CM_NORMAL)
                move_forward(delta_time, speed_mult);
            break;
        case UD_BACKWARD:
            if (mMode == CM_NORMAL)
                move_backward(delta_time, speed_mult);
            break;
        case UD_LEFT:
            if (mMode == CM_NORMAL)
                move_left(delta_time, speed_mult);
            break;
        case UD_RIGHT:
            if (mMode == CM_NORMAL)
                move_right(delta_time, speed_mult);
            break;
        }
    }

    void            Camera::move_forward(Ogre::Real delta_time, Ogre::Real speed_mult)
    {
        switch (mMode)
        {
        case CM_NORMAL:
            mCam->move(mCam->getDirection() * delta_time * speed_mult);
            break;
        case CM_ORBIT:
            break;
        case CM_TRACK_FREELOOK:
            break;
        case CM_TRACK_FIXED:
            break;
        }
    }
    void            Camera::move_backward(Ogre::Real delta_time, Ogre::Real speed_mult){
        switch (mMode)
        {
        case CM_NORMAL:
            mCam->move(-mCam->getDirection() * delta_time * speed_mult);
            break;
        case CM_ORBIT:
            break;
        case CM_TRACK_FREELOOK:
            break;
        case CM_TRACK_FIXED:
            break;
        }
    }
    void            Camera::move_left(Ogre::Real delta_time, Ogre::Real speed_mult){
        switch (mMode)
        {
        case CM_NORMAL:
            mCam->move(-mCam->getRight() * delta_time * speed_mult);
            break;
        case CM_ORBIT:
            break;
        case CM_TRACK_FREELOOK:
            break;
        case CM_TRACK_FIXED:
            break;
        }}
    void            Camera::move_right(Ogre::Real delta_time, Ogre::Real speed_mult){
        switch (mMode)
        {
        case CM_NORMAL:
            mCam->move(mCam->getRight() * delta_time * speed_mult);
            break;
        case CM_ORBIT:
            break;
        case CM_TRACK_FREELOOK:
            break;
        case CM_TRACK_FIXED:
            break;
        }
    }

    /**
     * Camera Manager
     */
    CameraManager::CameraManager()
        : mActive(nullptr)
        , mInputSys(nullptr)
    {
    //ctor
    }

    CameraManager::~CameraManager()
    {
    //dtor
    }
    void CameraManager::activate(Camera * cam)
    {
        assert(cam && "Invalid camera");
        assert(hasCamera(cam) && "Unregistered camera");
        mActive = cam;
    }
    bool CameraManager::hasCamera(const Camera * cam) const
    {
        for(List::const_iterator i=mList.cbegin(); i!=mList.cend(); i++)
            if ((*i) == cam)
                return true;
        return false;
    }

    void CameraManager::create(const OgreParamsPtr& ptr, InputSystem * isys)
    {
        assert(ptr->getMainWindow() && "Invalid window");
        if (m_created)
            return ;

        mParams = ptr;
        Ogre::Camera * defaultCam = nullptr;
        Ogre::RenderWindow * w = ptr->getMainWindow();
        assert(w && "Invalid window");
        Ogre::Viewport * vp = nullptr;
        if (w->getNumViewports() == 0)
        {
            defaultCam = mParams->getSceneMgr()->createCamera("SystemCamera");
            vp = w->addViewport(defaultCam);
        }
        else
        {
            vp = w->getViewport(0);
            defaultCam = vp->getCamera();
        }
        if (!defaultCam)
            vp = w->addViewport(defaultCam);
        assert(isys && "Invalid Input System");
        mInputSys = isys;

        defaultCam->setPosition(Ogre::Vector3(0,10,500));
        defaultCam->lookAt(Ogre::Vector3(0,0,0));
        defaultCam->setFOVy(Ogre::Radian(Ogre::Degree(45.0f)));
        defaultCam->setNearClipDistance(5);

        if (ptr->getRoot()->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_INFINITE_FAR_PLANE))
            defaultCam->setFarClipDistance(0);
        createCamera(defaultCam, CM_NORMAL, true);

        Ogre::LogManager::getSingleton().logMessage("CameraManager loaded, handling "+std::to_string(mList.size()), Ogre::LML_TRIVIAL);
        m_created = true;
    }
    void CameraManager::destroy()
    {
        if (!m_created)
            return ;
        for (auto i=mList.begin(); i!=mList.end(); i++)
            delete (*i), (*i) = nullptr;
        mList.clear();
        mActive = nullptr;
        m_created = false;
        mParams.reset();
    }

    CameraManager::List::const_iterator CameraManager::findCamera(const Camera * cam) const
    {
        for(List::const_iterator i=mList.cbegin(); i!=mList.cend(); i++)
            if ((*i) == cam)
                return i;
        return mList.end();
    }
    CameraManager::List::iterator CameraManager::findCamera(Camera * cam)
    {
        for(List::iterator i=mList.begin(); i!=mList.end(); i++)
            if ((*i)== cam)
                return i;
        return mList.end();
    }
    Camera *CameraManager::createCamera(Ogre::Camera * ocam, CameraMode mode, bool activate_)
    {
        Camera * cam = nullptr;
        if (!ocam)
            THROW(Ogre::Exception::ERR_RT_ASSERTION_FAILED, "Invalid Ogre::Camera supplied");
        try
        {
            cam = new Camera(mode, ocam->getName(), ocam);
            addCamera(cam, activate_);
        }
        catch(...)
        {
            delete cam, cam = nullptr;
            throw;
        }
        return cam;
    }
    Camera                      *CameraManager::getActiveCamera(bool except_on_null){
        if (!mActive && except_on_null)
            THROW(Ogre::Exception::ERR_RT_ASSERTION_FAILED, "No active camera found in this manager, activate one first");
        return mActive;
    }
    const Camera                *CameraManager::getActiveCamera(bool except_on_null) const{
        if (!mActive && except_on_null)
            THROW(Ogre::Exception::ERR_RT_ASSERTION_FAILED, "No active camera found in this manager, activate one first");
        return mActive;
    }
    Camera *CameraManager::addCamera(Camera * cam, bool activate_)
    {
        if (hasCamera(cam))
            THROW(Ogre::Exception::ERR_DUPLICATE_ITEM, "Camera already registered");
        mList.push_back(cam);
        if (activate_)
            activate(cam);
        return cam;
    }
    const CameraManager::List& CameraManager::getList() const{ return mList; }

    bool    CameraManager::frameRenderingQueued(const Ogre::FrameEvent& evt)
    {
        if (mInputSys->isActionWanted(ACTION_FORWARD))
            getActiveCamera(true)->move(UD_FORWARD);
        if (mInputSys->isActionWanted(ACTION_BACKWARD))
            getActiveCamera(true)->move(UD_BACKWARD);
        if (mInputSys->isActionWanted(ACTION_STRAFE_LEFT))
            getActiveCamera(true)->move(UD_LEFT);
        if (mInputSys->isActionWanted(ACTION_STRAFE_RIGHT))
            getActiveCamera(true)->move(UD_RIGHT);
        return true;
    }
};
