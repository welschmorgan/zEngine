#include "dev.h"
#include "config/platform.h"

namespace zsys
{
    Dev Dev::mInst;
    const Ogre::String Dev::LOG_NAME = _T("./dev/diary.log");
    Dev::Dev()
    {
        open_stream();
    }

    Dev::~Dev()
    {
    }
    Dev& Dev::getSingleton(){ return mInst; }
    Dev* Dev::getSingletonPtr(){ return &mInst; }

    void Dev::treatMessage(const Ogre::String &str, DevMsgType type, bool except_on_critical)
    {
        #ifdef DEV_BUILD
            if (type == DMT_SUCCESS)
                mStream << "[+] ";
            else if(type == DMT_FAILURE)
                mStream << "[-] ";
            else if(type == DMT_CRITICAL)
                mStream << "[CRITICAL] ";
            else if(type == DMT_CRITICAL)
                mStream << "[INFO] ";
            mStream << str << std::endl;
            mStream.flush();
            if (except_on_critical && type == DMT_CRITICAL)
                THROW(Ogre::Exception::ERR_RUNTIME_ERROR, _T("Critical error: ")+str);
        #endif
    }
    void Dev::open_stream()
    {
#ifdef DEV_BUILD
        mkdir("./dev", 0);
        unsigned short id = 0;
        string fname(_T("./dev/developper.log"));
        std::ifstream ifs(fname.c_str());
        while (!ifs.is_open())
        {
            fname = _T("./dev/developper-")+std::to_string(id)+_T(".log");
            ifs.open(fname.c_str());
            id ++;
        }
        ifs.close();
        mStream.open(fname);
        mStream << "Developper build started:" << std::endl;
#endif
    }
};
