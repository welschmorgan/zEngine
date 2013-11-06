#ifndef Z_ROOT_H
#define Z_ROOT_H

#include "export.h"

namespace zsys
{
    /**
    * Root class for this engine
    ****************************/
    class Z_API Root;
    /**
    * Manages ambiances, sounds and weather
    ****************************/
    class Z_API AmbianceManager;
    /**
    * Initialises Ogre, creates render window
    * and SceneManager
    ****************************/
    class Z_API OgreInitializer;
    /**
    * Creates a gui console
    ****************************/
    class Z_API OgreConsole;
    /**
    * A state of the game
    ****************************/
    class Z_API State;
    /**
    * Manages different state of the game
    ****************************/
    class Z_API StateManager;
    /**
    * Manages different cameras of the game
    ****************************/
    class Z_API CameraManager;
};

#endif
