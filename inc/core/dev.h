#ifndef Z_DEV_H
#define Z_DEV_H

#include "platform.h"
#ifdef Z_DEV_BUILD
#include <fstream>
#endif

/**
 * Configures the developper build special options
 */
namespace ZSys
{
    enum DevMsgType
    {
        DMT_SUCCESS = 0,
        DMT_FAILURE = 1,
        DMT_CRITICAL = 2,
        DMT_INFO = 3
    };
    class Z_API Dev
    {
    public:
#ifdef Z_DEV_BUILD
        static const Ogre::String LOG_NAME;
#endif

        Dev();
        virtual ~Dev();

        static Dev& getSingleton();
        static Dev* getSingletonPtr();

        void treatMessage(const Ogre::String &str,
                          DevMsgType type = DMT_INFO,
                          bool except_on_critical = true,
                          const Ogre::String &file=Ogre::StringUtil::BLANK,
                          const size_t line = size_t(0),
                          const Ogre::String &func=Ogre::StringUtil::BLANK);

    protected:
        static Dev          mInst;

#ifdef Z_DEV_BUILD
        std::ofstream        mStream;
#endif
        void open_stream();
    };
}

#ifdef Z_DEV_BUILD
    #define DEV_MSG(msg_str,msg_type) Dev::getSingleton().treatMessage(msg_str, msg_type, true, __FILE__, __LINE__, __FUNCTION__)
#else
    #define DEV_MSG(msg_str,msg_type)
#endif

#define DEV_INFO(msg) DEV_MSG(msg,ZSys::DMT_INFO)

#endif // Z_DEV_H
