#ifndef Z_FORWARD_HH
#define Z_FORWARD_HH

#include "export.h"

namespace ZSys
{
    /**
    * Root class for this engine
    ****************************/
    class Z_API Root;
    /**
    * Manages the user inputs
    ****************************/
    class Z_API InputSystem;
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
    /**
    * Manages different states of the game
    ****************************/
    class Z_API StateManager;
    /**
    * Parameters important to ogre, root, main window
    ****************************/
    class Z_API OgreParams;
}

#endif
