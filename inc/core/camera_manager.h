#ifndef Z_CAMERA_MANAGER_H
#define Z_CAMERA_MANAGER_H

#include "platform.h"
#include "exception.h"
#include "ogre_params.h"
#include "enable_create.h"
#include "enable_name.h"
#include <OgreCamera.h>
#include <OgreRoot.h>
#include <OIS/OISInputManager.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISMouse.h>
#include <vector>

namespace ZSys
{
    enum Z_API UserDirection
    {
        /** Go Forward */
        UD_FORWARD,
        /** Go Backward*/
        UD_BACKWARD,
        /** Go Left */
        UD_LEFT,
        /** Go Right */
        UD_RIGHT
    };
    enum Z_API CameraMode
    {
        /**
         * Normal is a normal, gravity affected camera, everything the player can do
         */
        CM_NORMAL,
        CM_PLAYER = CM_NORMAL,
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
        string      UserDirection(ZSys::UserDirection dir, bool capitalise = false);
    };

    class Z_API Camera : public EnableName
    {
        Ogre::Camera                *mCam;
        CameraMode                  mMode;
    public:
        typedef UserDirection       Dir;

        Camera(CameraMode mode = CM_NORMAL, const string &name = Ogre::StringUtil::BLANK, Ogre::Camera * cam = nullptr);
        virtual ~Camera();

        void                setCamera(Ogre::Camera * cam);
        Ogre::Camera        *getCamera();
        const Ogre::Camera  *getCamera() const;

        CameraMode          getMode() const;
        void                setMode( CameraMode mode );

        void                move(UserDirection dir, Ogre::Real delta_time = 1.0f, Ogre::Real speed_mult = 1.0f);

    protected:
        virtual void        move_forward(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f);
        virtual void        move_backward(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f);
        virtual void        move_left(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f);
        virtual void        move_right(Ogre::Real delta_time, Ogre::Real speed_mult = 1.0f);
    };
    class Z_API CameraManager
        : public EnableCreate2<void, const OgreParamsPtr&,InputSystem * >
        , public Ogre::FrameListener
    {
        typedef std::vector<Camera*> List;
        public:
            CameraManager();
            virtual ~CameraManager();

            void                        activate(Camera * cam);
            bool                        hasCamera(const Camera * cam) const;
            Camera                      *addCamera(Camera * cam, bool activate_ = false);
            Camera                      *createCamera(Ogre::Camera * cam, CameraMode mode = CM_NORMAL, bool activate_ = false);
            Camera                      *getActiveCamera(bool except_on_null = true);
            const Camera                *getActiveCamera(bool except_on_null = true)const;
            void                        create(const OgreParamsPtr& ptr, InputSystem * );
            void                        destroy();

            List::const_iterator        findCamera(const Camera * cam) const;
            List::iterator              findCamera(Camera * cam);

            const List&                 getList() const;
            InputSystem                 *getInputSystem(){ return mInputSys; }

            bool                        frameRenderingQueued(const Ogre::FrameEvent& evt);
        protected:
            List                        mList;
            Camera                      *mActive;
            OgreParamsPtr               mParams;
            InputSystem                 *mInputSys;
        private:
    };
};

#endif // Z_CAMERA_MANAGER_H
