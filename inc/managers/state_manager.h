#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "platform.h"

namespace zsys
{
    struct Z_API                      State
    {
    protected:
        unsigned char mID;
    public:
        State(unsigned char id);
        virtual ~State() noexcept(true);

        const unsigned char getID() const;

        void stateRegistered();
        void stateUnregistered();
        void statePushed(const State *old);
        void statePopped(const State *old);
        bool stateMainloop( const Ogre::Real delta );
    };


    typedef std::vector<State>  StateList;


    class Z_API                       StateManager
    {
    public:
        StateManager();
        StateManager(const StateManager& c);
        virtual ~StateManager();

        const StateList     getStates() const;
        StateList&          getStates();

        bool                hasState( const unsigned char id) const;
        void                addState( State * s);

    protected:
        StateList           mStates;
    };
};


#endif // STATEMANAGER_H
