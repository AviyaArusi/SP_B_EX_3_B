#pragma once

#include <vector>
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

const int  MAX_TEAM_SIZE  = 10;


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
        Team(const Team&);
        Team(Team&&) noexcept;
        Team& operator=(const Team&);
        Team& operator=(Team&&) noexcept;
        virtual ~Team();

        Character* getLeader() const;
        void setLeader (Character*);
        void replaceLeader();
        std::vector<Character*> &getTeam();
        virtual void add(Character*);
        void kill(Character * attacker, Character* victim);
        virtual void attack(Team*);
        Character* chooseVictim(Character*);
        int stillAlive() const;
        std::string print() const;
    };

}