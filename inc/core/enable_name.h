#ifndef Z_ENABLE_NAME_H
#define Z_ENABLE_NAME_H

#include "platform.h"

namespace ZSys
{
    struct Z_API    EnableName
    {
        EnableName(const string &name = Ogre::StringUtil::BLANK);
        virtual ~EnableName();

        const string &getName() const;

        bool operator==(const string &val) const;
        bool operator!=(const string &val) const;
    protected:
        string              m_name;
    };
};

#endif // Z_ENABLE_NAME_H
