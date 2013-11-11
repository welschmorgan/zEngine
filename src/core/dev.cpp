#include "dev.h"
#include "platform.h"
#include <OgreException.h>
#include "exception.h"

namespace ZSys
{
    const Ogre::String Dev::LOG_NAME = "./diary.log";
    Dev Dev::mInst;
    Dev::Dev()
    {
        open_stream();
    }

    Dev::~Dev()
    {
    }

    Dev& Dev::getSingleton(){ return mInst; }
    Dev* Dev::getSingletonPtr(){ return &mInst; }

    void Dev::treatMessage(const Ogre::String &str, DevMsgType type, bool except_on_critical, const Ogre::String &file, const size_t line, const Ogre::String &func)
    {
        #ifdef Z_DEV_BUILD
            if (type == DMT_SUCCESS)
                mStream << "[+] ";
            else if(type == DMT_FAILURE)
                mStream << "[-] ";
            else if(type == DMT_CRITICAL)
                mStream << "[CRITICAL] ";
            else if(type == DMT_INFO)
                mStream << "[INFO] ";
            else
                mStream << "[UNKNOWN] ";
            mStream << str << std::endl;
            mStream.flush();
            if (except_on_critical && type == DMT_CRITICAL)
                THROW(Ogre::Exception::ERR_INTERNAL_ERROR, "Critical error: "+str);
        #endif
    }
    void Dev::open_stream()
    {
#ifdef Z_DEV_BUILD
        unsigned short id = 0;
        string fname(LOG_NAME);
        mStream.open(fname.c_str());
        std::cout << "Trying " << fname << std::endl;
        while (!mStream.is_open() && id < 100)
        {
            fname = LOG_NAME+std::to_string(id)+".log";
            std::cout << "Trying " << fname << std::endl;
            mStream.open(fname.c_str());
            id ++;
        }
        treatMessage("Developper log created");
#endif
    }
};
