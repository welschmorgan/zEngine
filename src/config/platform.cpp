#include "config/platform.h"

namespace zsys
{
    FORCEINLINE std::wstring mb_to_iso(const std::string & str)
    {
        std::wstring ret(str.length(), _T(' '));
        std::copy(str.begin(), str.end(), ret.begin());
        return ret;
    }
    FORCEINLINE std::string iso_to_mb(const std::wstring & str)
    {
        std::string ret(str.length(), _T(' '));
        std::copy(str.begin(), str.end(), ret.begin());
        return ret;
    }
    FORCEINLINE string getBuildInformations()
    {
        sstream ss;
        ss  << string(AutoVersion::STATUS) << _T(", ") << string(AutoVersion::FULLVERSION_STRING)
            << _T(" built at ")
            << string(AutoVersion::DATE) <<  _T("/") << string(AutoVersion::MONTH) << _T("/") << string(AutoVersion::YEAR);
        return ss.str();
    }
};
