#include "enable_name.h"

namespace zsys
{
    EnableName::EnableName(const string &name) : m_name(name){}
    EnableName::~EnableName(){}

    const string &EnableName::getName() const{ return m_name; }

    bool EnableName::operator==(const string &val) const{ return val == m_name; }
    bool EnableName::operator!=(const string &val) const{ return val != m_name; }
};
