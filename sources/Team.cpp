#include "Team.hpp"

using namespace std;
namespace ariel
{
    Team::Team() : _leader(nullptr) {}
    Team::Team(Character* leader) : _leader(leader) 
    {
        if (leader == nullptr) { throw invalid_argument("Input leader cannot be null! \n"); }
        if(leader->isPlay()) { throw runtime_error("Character can play only in one game is the same time! \n"); }
        add(_leader);
        leader->setIsPlay(true);
    }

    // Define copy constructor
    Team::Team(const Team& other) : _leader(other._leader), _team(other._team) {}
    // Define move constructor
    Team::Team(Team&& other) noexcept : _leader(other._leader), _team(other._team) {}
    // Define copy assignment operator
    Team &Team::operator=(const Team& other) 
    {
        _leader = other._leader;
        _team = other._team;
        return (*this);
    }
    // Define move assignment operator
    Team &Team::operator=(Team&& other) noexcept 
    {
        _leader = other._leader;
        _team = other._team;
        return (*this);
    }

    Team::~Team() 
    {
        for (auto member : _team)
        {
            delete member;
        }
        _team.clear();
    }

    Character* Team::getLeader() const { return _leader;}

    vector<Character*> &Team::getTeam() { return _team;};
    
    void Team::setLeader(Character* leader)
    {
        if(leader == nullptr) { throw invalid_argument("input Character cannot be null! \n"); }
        _leader = leader;
    }

    void Team::replaceLeader()
    {
        if (_leader->isAlive()) { return; }
        Character *newLeader;
        double minDistance = numeric_limits<double>::max();

        for (auto member : _team)
        {
            if (member->isAlive() && member != _leader)
            {
                double currDistance = _leader->getLocation().distance(member->getLocation());
                if (currDistance < minDistance)
                {
                    minDistance = currDistance;
                    newLeader = member;
                }
            }
        }
            _leader = newLeader;
        }
        

        void Team::add(Character* character) 
        {
            if(character == nullptr) { throw invalid_argument("input Character cannot be null! \n"); }
            if(character->isPlay()) { throw runtime_error("Character can play only in one game is the same time! \n"); }
            if(_team.size() >= MAX_TEAM_SIZE) {throw runtime_error("Team size can't be begger then 10! \n"); }
            if(character->isAlive() )
            {
                if(dynamic_cast<Cowboy*>(character)) 
                {
                    _team.insert(_team.begin(), static_cast<Cowboy*>(character));
                } 
                else if(dynamic_cast<Ninja*>(character)) 
                {
                    _team.push_back(static_cast<Ninja*>(character));
                }
                character->setIsPlay(true);
            }

            else { throw invalid_argument("invalide argument! \n"); }
        }

        Character* Team::chooseVictim(Character* enemyLeader)
        {
            if (!stillAlive()) { throw runtime_error("Dead team can't play! \n"); }
            if(enemyLeader == nullptr) { throw invalid_argument("input Character cannot be null! \n"); }
            
            Character* victim = nullptr;
            double minDistance = numeric_limits<double>::max();

            for (auto member : _team)
            {
                if (member->isAlive())
                {
                    double currDistance = enemyLeader->getLocation().distance(member->getLocation());
                    if (currDistance < minDistance)
                    {
                        minDistance = currDistance;
                        victim = member;
                    }
                }
            }
            return victim;
        }


        void Team::attack(Team* enemy) 
        {
            if(enemy == nullptr) { throw invalid_argument("input Enemy cannot be null! \n"); }
            if(!stillAlive() || !enemy->stillAlive()) {throw runtime_error("Dead team can't play! \n"); }
            if(this == enemy) { throw runtime_error("Team can't attack itself! \n"); }

            if(!enemy->getLeader()->isAlive()) { enemy->replaceLeader();}
            Character* victim = enemy->chooseVictim(_leader);
            
            for(auto member : _team)
            {
                if (enemy->stillAlive() == 0) { return; }

                if(!victim->isAlive()) 
                {
                    victim = enemy->chooseVictim(_leader);
                    if(victim == nullptr) { return; } 
                }
                
                if(member == nullptr) { continue; }
                
                if(member->isAlive()) 
                {
                    if(dynamic_cast<Cowboy*>(member)) 
                    {
                        Cowboy* currCowBoy = static_cast<Cowboy*>(member);
                        if(currCowBoy->hasboolets()) { currCowBoy->shoot(victim); }
                        else { currCowBoy->reload(); }
                    } 
                    else if(dynamic_cast<Ninja*>(member)) 
                    {
                        Ninja* currNinja = static_cast<Ninja*>(member);
                        if(currNinja->distance(victim) <= 1) { currNinja->slash(victim); }
                        else { currNinja->move(victim); }
                    }
                    
                }
                // cout << victim->print() << endl;
            }
        }

        int Team::stillAlive() const 
        {
            int counter = 0; 
            for(auto member : _team)
            {
                if(member->isAlive()) {counter++;}
            }
            return counter;
        }

        string Team::print() const 
        {
            string output = "Team members: \n";
            string cowboys = "";
            string ninjas = "";
            for(auto member : _team) 
            {
                if(typeid(member) == typeid(Cowboy)) { cowboys += member->print(); }
                else { ninjas += member->print(); }
            }
        output += cowboys + ninjas;
        return output;
    }

}