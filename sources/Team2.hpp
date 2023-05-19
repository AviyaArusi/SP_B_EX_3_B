#pragma once

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team 
    {
    public:
        Team2(Character* leader) : Team(leader) {}
        void add(Character* character) override {}
    };


}