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
    
    vector<Character*> Team::getTeam() const { return _team;};

    void Team::add(Character* character) 
    {
        if (character == nullptr) { throw invalid_argument("input Character cannot be null! \n"); }
        _team.push_back(character);

    }

    void Team::attack(Team* enemy) 
    {

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