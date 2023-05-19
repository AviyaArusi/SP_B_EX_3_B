#include "Team.hpp"

using namespace std;
namespace ariel
{
    Team::Team() : _leader(nullptr) {}
    Team::Team(Character* leader) : _leader(leader) 
    {
        if (leader == nullptr) { throw invalid_argument("Input leader cannot be null! \n"); }
        add(_leader);
    }

    // Define copy constructor
    Team::Team(Team& other) : _leader(other.getLeader()), _team(other.getTeam()) {}
    // Define move constructor
    Team::Team(Team&& other) noexcept : _leader(other.getLeader()), _team(other.getTeam()) {}
    // Define copy assignment operator
    Team &Team::operator=(const Team& other) 
    {
        _leader = other.getLeader();
        _team = other.getTeam();
        return (*this);
    }
    // Define move assignment operator
    Team &Team::operator=(Team&& other) noexcept 
    {
        _leader = other.getLeader();
        _team = other.getTeam();
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
    
    void Team::setLeaded(Character* leader)
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
    
    vector<Character*> Team::getTeam() const { return _team;};

    void Team::add(Character* character) 
    {
        if(character == nullptr) { throw invalid_argument("input Character cannot be null! \n"); }
        if(_team.size() >= 10){ return; }
        
        if(dynamic_cast<Cowboy*>(character)) 
        {
            _team.insert(_team.begin(), static_cast<Cowboy*>(character));
        } 
        else if(dynamic_cast<Ninja*>(character)) 
        {
            _team.push_back(static_cast<Ninja*>(character));
        }
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
        if(!stillAlive() || !enemy->stillAlive()) {throw runtime_error("Dead team can't attack! \n"); }
        
        if(!enemy->getLeader()->isAlive()) { enemy->replaceLeader();}
        Character* victim = enemy->chooseVictim(_leader);
        for(auto member : _team)
        {
            if(!victim->isAlive()) { victim = enemy->chooseVictim(_leader); }
            if(member->isAlive()) 
            {
                
            }
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