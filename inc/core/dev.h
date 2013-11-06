#ifndef Z_DEV_H
#define Z_DEV_H

#ifdef DEV_BUILD
#include <fstream>
#endif

/**
 * Configures the developper build special options
 */
namespace zsys
{
    enum DevMsgType
    {
        DMT_SUCCESS,
        DMT_FAILURE,
        DMT_CRITICAL,
        DMT_INFO
    };
    class Dev
    {
    public:
#ifdef DEV_BUILD
        static const Ogre::String LOG_NAME;
#endif

        Dev();
        virtual ~Dev();

        static Dev& getSingleton();
        static Dev* getSingletonPtr();

        void treatMessage(const Ogre::String &str, DevMsgType type, bool except_on_critical = true);

    protected:
        static Dev          mInst;

#ifdef DEV_BUILD
        std::fstream        mStream;
#endif
        void open_stream();
    };
};
#ifdef DEV_BUILD
    #define DEV_MSG(msg_str,msg_type) Dev::getSingleton().treatMessage(msg_str, msg_type, true)
#else
    #define DEV_MSG(msg_str,msg_type)
#endif

#endif // Z_DEV_H
