#include "state_manager.h"

namespace zsys
{
    State::State(unsigned char id)
        : mID(id)
    {

    }
    State::~State() noexcept(true)
    {

    }

    const unsigned char State::getID() const
    {
        return mID;
    }

    void State::stateRegistered(){}
    void State::stateUnregistered(){}
    void State::statePushed(const State *old){}
    void State::statePopped(const State *old){}
    bool State::stateMainloop( const Ogre::Real delta )
    {
        return true;
    }

    StateManager::StateManager(){}
    StateManager::StateManager(const StateManager& c):mStates(c.getStates()){}
    StateManager::~StateManager(){}

    const StateList     StateManager::getStates() const{ return mStates; }
    StateList&          StateManager::getStates(){ return mStates; }

    bool                StateManager::hasState( const unsigned char id) const
    {
        for( auto i=mStates.begin(); i!=mStates.end(); i++)
        {
            if (i->getID() == id)
                return true;
        }
        return false;
    }
    void                StateManager::addState( State * s)
    {
        if (hasState(s->getID()))
            throw std::runtime_error((std::string("Cannot add state id ")+std::to_string(s->getID())+", duplicate in StateManager").c_str());
    }
};
