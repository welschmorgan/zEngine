#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "platform.h"
#include "enable_create.h"
#include "ogre_params.h"
#include "state.h"
#include <OgreFrameListener.h>
#include <stack>

namespace ZSys
{
    class Z_API                       StateManager
        : public EnableCreate1<void, Root*>
        , public Ogre::FrameListener
    {
    public:
        typedef std::unique_ptr<State>      StatePtr;
        typedef std::vector<State*>         List;
        typedef std::stack<State*>          Stack;
        typedef std::map<const State*,bool>       StackRef;

        StateManager();
        StateManager(const StateManager& c);
        virtual ~StateManager();

        void                create(Root*);
        void                destroy();

        bool                frameStarted(const Ogre::FrameEvent& evt);

        const List&         getStates() const;
        List&               getStates();

        State               *getState(const string &id);
        const State         *getState(const string &id)const;

        bool                hasState(const string &id) const;
        bool                isPushed(const string &id) const;
        bool                isPushed(const State * s) const;
        void                registerState(State* s);

        void                unregisterState(State* s);
        void                unregisterState(const string &id);

        State               *pushState(const string &name);
        State               *popState();
        State               *pushState(State* s);
    protected:
        List                mStates;
        Stack               mStack;
        StackRef            mStackRef;
        OgreParamsPtr       mParams;
        Root  *             mRoot;
    };
};


#endif // STATEMANAGER_H
