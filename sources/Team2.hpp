#pragma once

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team 
    {
    public:
        Team2(Character* leader) : Team(leader) {}
        
        void add(Character* character) override 
        {
            if(character == nullptr) { throw std::invalid_argument("input Character cannot be null! \n"); }
            if(character->isPlay()) { throw std::runtime_error("Character can play only in one game in the same time! \n"); }
            if(getTeam().size() >= MAX_TEAM_SIZE) {throw std::runtime_error("Team size can't be begger then 10! \n"); }

            if(character->isAlive())
            {
                getTeam().push_back(character);
                character->setIsPlay(true);
            }
            else { throw std::invalid_argument("invalide argument! \n"); }
        }

    };


}