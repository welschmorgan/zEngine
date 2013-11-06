#ifndef Z_ENABLE_CREATE_H
#define Z_ENABLE_CREATE_H

#include "export.h"

namespace zsys
{
    struct Z_API                 IEnableCreate
    {
        IEnableCreate(bool state = false) : m_created(state){}
        IEnableCreate(const IEnableCreate& rk) : m_created(rk.m_created){}
        virtual ~IEnableCreate(){}

        IEnableCreate& operator=(const IEnableCreate& rk){ m_created = rk.m_created; return *this; }

        bool isCreated() const{ return m_created; }
        operator bool() const{ return m_created; }
        bool operator==(bool val) const{ return val == m_created; }
        bool operator!=(bool val) const{ return val != m_created; }
        bool operator==(const IEnableCreate &val) const{ return val.m_created == m_created; }
        bool operator!=(const IEnableCreate &val) const{ return val.m_created != m_created; }
    protected:
        bool                m_created;
    };
    template<typename RetT>
    struct Z_API                  EnableCreate : public IEnableCreate
    {
        typedef RetT        ReturnT;

        RetT                create(){return RetT();}
        void                destroy() {}
    };
    template<>
    struct Z_API                  EnableCreate<void> : public IEnableCreate
    {
        typedef void        ReturnT;

        void                create(){}
        void                destroy() {}
    };
    template<typename RetT, typename Arg0>
    struct Z_API                  EnableCreate1 : public IEnableCreate
    {
        typedef RetT        ReturnT;
        typedef Arg0        Arg0T;

        RetT                create(Arg0 a){return RetT();}
        void                destroy(){}
    };

    template<typename RetT, typename Arg0, typename Arg1>
    struct Z_API                  EnableCreate2 : public IEnableCreate
    {
        typedef RetT        ReturnT;
        typedef Arg0        Arg0T;
        typedef Arg1        Arg1T;

        RetT                create(Arg0 a0, Arg1 a1){return RetT();}
        void                destroy(){}
    };
    template<typename RetT, typename Arg0, typename Arg1, typename Arg2>
    struct Z_API                  EnableCreate3 : public IEnableCreate
    {
        typedef RetT        ReturnT;
        typedef Arg0        Arg0T;
        typedef Arg1        Arg1T;
        typedef Arg2        Arg2T;

        RetT                create(Arg0 a0, Arg1 a1, Arg2 a2){return RetT();}
        void                destroy(){}
    };
};

#endif // Z_ENABLE_CREATE_H
