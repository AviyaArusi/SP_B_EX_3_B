#include "Cowboy.hpp"

const int COWBOY_POINTS = 110;
const int COWBOY_BULLETS = 6;

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(const string& name, const Point& location) 
    : Character(name, location, COWBOY_POINTS) , _bullets(COWBOY_BULLETS) {}

    void Cowboy::shoot(Character* enemy) 
    {
        if(enemy == nullptr) { throw invalid_argument("Can't attack null pointer! \n");}
        if(!isAlive() || this == enemy) { throw runtime_error("Dead man can't shoot! \n");}
        if(!enemy->isAlive()) { throw runtime_error("Can't shoot in a dead man! \n");}
        if(_bullets <= 0) { return;}
        enemy->hit(10);
        _bullets--;
    }

    bool Cowboy::hasboolets() const { return _bullets > 0; }

    void Cowboy::reload()  
    {
        if(!isAlive()) { throw runtime_error("Dead Cowboy can't reload! \n"); }
        _bullets = COWBOY_BULLETS; 
    }

    string Cowboy::print() const
    {
        string output = "C- \n" + Character::print();
        return output;
    }

}