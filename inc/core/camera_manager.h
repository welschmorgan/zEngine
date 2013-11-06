#ifndef Z_CAMERA_MANAGER_H
#define Z_CAMERA_MANAGER_H

#include "platform.h"
#include "exception.h"
#include <vector>
#include <OgreCamera.h>
#include <OIS/OISInputManager.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISMouse.h>
#include "ogre_params.h"
#include "enable_create.h"
#include "enable_name.h"

namespace zsys
{
    enum Z_API UserDirection
    {
        /** Go Forward */
        TD_FORWARD,
        /** Go Backward*/
        TD_BACKWARD,
        /** Go Left */
        TD_LEFT,
        /** Go Right */
        TD_RIGHT
    };
    enum Z_API CameraMode
    {
        /**
         * Normal is a normal, gravity affected camera, everything the player can do
         */
        CM_NORMAL,
        /**
         * Orbit is a mode where the camera is orbitting around a target
         */
        CM_ORBIT,
        /**
         * Track mode sets the camera on a predefined path,
         * mouse look is allowed
         */
        CM_TRACK_FREELOOK,
        /**
         * Track mode sets the camera on a predefined path, only
         * allowing it to look arount
         */
        CM_TRACK_FIXED
    };
    namespace   tr
    {
        string      UserDirection(zsys::UserDirection dir, bool capitalise = false);
    };

    class Z_API Camera : public EnableName
    {
        Ogre::Camera                *mCam;
        CameraMode                  mMode;
    public:
        typedef UserDirection       Dir;

        Camera(const string &name = Ogre::StringUtil::BLANK, Ogre::Camera * cam = nullptr)
            : EnableName(name)
            , mCam(cam)
        {}
        virtual ~Camera()
        {}

        void                setCamera(Ogre::Camera * cam){ mCam = cam; }
        Ogre::Camera        *getCamera(){ return mCam; }
        const Ogre::Camera  *getCamera() const{ return mCam; }

        void move(UserDirection dir, Ogre::Real delta_time = 1.0f, Ogre::Real speed_mult = 1.0f)
        {
            if (!mCam)
                THROW(Ogre::Exception::ExceptionCodes::ERR_INVALID_STATE, "Cannot move, no camera supplied for UserCamera '" + getName()+"'");
            switch(dir)
            {
            case TD_FORWARD:
                if (mMode == CM_NORMAL)
                    move_forward(delta_time, speed_mult);
                break;
            case TD_BACKWARD:
                if (mMode == CM_NORMAL)
                    move_backward(delta_time, speed_mult);
                break;
            case TD_LEFT:
                if (mMode == CM_NORMAL)
                    move_left(delta_time, speed_mult);
                break;
            case TD_RIGHT:
                if (mMode == CM_NORMAL)
                    move_right(delta_time, speed_mult);
                break;
            }
        }

    protected:
        virtual void move_forward(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f)
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
        virtual void move_backward(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f){
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
        virtual void move_left(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f){
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
        virtual void move_right(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f){
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
            }}
    };
    class Z_API CameraManager
        : public EnableCreate3<void, const OgreParamsPtr&,OIS::Keyboard*, OIS::Mouse *>
    {
        typedef std::vector<Ogre::Camera*> List;
        public:
            CameraManager();
            virtual ~CameraManager();

            void                        activate(Ogre::Camera * cam);
            bool                        hasCamera(const Ogre::Camera * cam) const;
            void                        addCamera(Ogre::Camera * cam, bool activate_ = false);

            void                        create(const OgreParamsPtr& ptr,OIS::Keyboard*, OIS::Mouse *);
            void                        destroy();

            List::const_iterator        findCamera(const Ogre::Camera * cam) const;
            List::iterator              findCamera(Ogre::Camera * cam);

            const List&                 getList() const;
            OIS::Keyboard               *getKeyboard(){ return mKbd; }
            OIS::Mouse                  *getMouse(){ return mMouse; }
        protected:
            List                        mList;
            Ogre::Camera                *mActive;
            OgreParamsPtr               mParams;
            OIS::Keyboard               *mKbd;
            OIS::Mouse                  *mMouse;
        private:
    };
};

#endif // Z_CAMERA_MANAGER_H
