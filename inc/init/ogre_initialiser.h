#ifndef OGREINITIALISER_H
#define OGREINITIALISER_H

 #include <OGRE/Ogre.h>
 #include <OIS/OIS.h>
 #include "platform.h"
 #if OGRE_PLATFORM == OGRE_PLATFORM_APPLE || OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
 #include <macUtils.h>
 #endif

#ifndef NDEBUG
#   define OGRE_RESOURCES_FILE "resources_d.cfg"
#   define OGRE_CONFIG_FILE "ogre_d.cfg"
#   define OGRE_LOG_FILE "ogre_d.log"
#   define OGRE_PLUGINS_FILE "plugins_d.cfg"
#else
#   define OGRE_RESOURCES_FILE "resources.cfg"
#   define OGRE_CONFIG_FILE "ogre.cfg"
#   define OGRE_LOG_FILE "ogre.log"
#   define OGRE_PLUGINS_FILE "plugins.cfg"
#endif

#include "ogre_console.h"

class Z_API OgreInitializer : public Ogre::ConfigFile
{
public:
    OgreInitializer(const Ogre::String &base_path = Ogre::StringUtil::BLANK,
                    bool create_ = true,
                    const Ogre::String &plugins = OGRE_PLUGINS_FILE,
                    const Ogre::String &config = OGRE_CONFIG_FILE,
                    const Ogre::String &log_ = OGRE_LOG_FILE);
    virtual ~OgreInitializer();

    OgreConsole             *getConsole();
    const OgreConsole       *getConsole() const;

    void parseResourcesConfig(const Ogre::String &name = OGRE_RESOURCES_FILE);
    void addResourceLocation(const Ogre::String &archName,
                             const Ogre::String &typeName,
                             const Ogre::String &secName);
    void initResourceGroups();

    void                    destroy();

    void                    createUi();
    Ogre::Root              *createRoot(const Ogre::String &plugins = OGRE_PLUGINS_FILE,
                                        const Ogre::String &config = OGRE_CONFIG_FILE,
                                        const Ogre::String &log_ = OGRE_LOG_FILE);
    void                    destroyRoot();

    Ogre::RenderWindow      *createWindow(bool auto_create=true);
    Ogre::SceneManager      *createSceneManager(Ogre::SceneType type = Ogre::ST_GENERIC);
    OIS::InputManager       *createInputSystem();
    void                    destroyInputSystem();

    bool                    handleWindowEvents();

 	size_t                      getWindowHandle() const;

 	bool                        renderOneFrame();
    const Ogre::String          &getResourcesPath() const;

    OIS::InputManager           *getInputManager();
    const OIS::InputManager     *getInputManager() const;

    OIS::Keyboard               *getKeyboard();
    const OIS::Keyboard         *getKeyboard() const;

    OIS::Mouse                  *getMouse();
    const OIS::Mouse            *getMouse() const;

    Ogre::Root                  *getRoot();
    const Ogre::Root            *getRoot() const;

    Ogre::RenderWindow          *getWindow();
    const Ogre::RenderWindow    *getWindow() const;

    bool                        isCreated() const;
protected:
    bool                    mCreated;
    Ogre::String            mResourcesFile,
                            mResourcesPath;
    Ogre::Root              *mRoot;
    Ogre::RenderWindow      *mWindow;
    OIS::InputManager       *mInputMgr;
    OIS::Keyboard           *mKeyboard;
    OIS::Mouse              *mMouse;

    std::streambuf*         oldCOUTStreamBuf;
    std::streambuf*         oldCERRStreamBuf;

    OgreConsole             *mConsole;
};
#endif // OGREINITIALISER_H
