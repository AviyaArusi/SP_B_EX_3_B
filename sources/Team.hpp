#pragma once

#include <vector>
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"


namespace ariel
{
    class Team 
    {
    private:
        Character* _leader;
        std::vector<Character*> _team;
    public:
        Team();  // Default constructor
        Team(Character*);
        Team(Team&);
        Team(Team&&) noexcept;
        Team& operator=(const Team&);
        Team& operator=(Team&&) noexcept;
        virtual ~Team();

        Character* getLeader() const;
        std::vector<Character*> getTeam() const;
        virtual void add(Character*);
        virtual void attack(Team*);
        int stillAlive() const;
        std::string print() const;
    };

}