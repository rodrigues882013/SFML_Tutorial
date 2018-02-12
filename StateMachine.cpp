//
// Created by felipe on 11/02/18.
//

#include "header/StateMachine.hpp"

namespace game
{
    void StateMachine::add_state(StateRef new_state, bool is_replacing)
    {
        this->_is_adding = true;
        this->_is_replacing = is_replacing;
        this->_new_state = std::move(new_state);
    }

    StateRef& StateMachine::get_active_state()
    {
        return this->_states.top();
    }

    void StateMachine::process_state_changes()
    {
        if(this->_is_removing && !this->_states.empty())
        {
            this->_states.pop();

            if(!this->_states.empty())
            {
                this->_states.top()->pause();
            }

            this->_is_removing = false;
        }

        if(this->_is_adding)
        {
            if(!this->_states.empty())
            {
                if(this->_is_replacing)
                {
                    this->_states.pop();
                }
                else
                {
                    this->_states.top()->pause();
                }
            }

            this->_states.push(std::move(this->_new_state));
            this->_states.top()->init();
            this->_is_adding = false;
        }
    }

    void StateMachine::remove_state()
    {
        this->_is_removing = true;
    }

    StateMachine::StateMachine()
    {

    }

    StateMachine::~StateMachine()
    {

    }
}
