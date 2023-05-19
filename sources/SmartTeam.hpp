#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character* leader) : Team(leader) {}
        void add(Character* character) override {};
    };


}