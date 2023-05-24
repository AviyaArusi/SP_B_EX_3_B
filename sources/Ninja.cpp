#include "Ninja.hpp"

using namespace std;

namespace ariel
{    
    Ninja::Ninja(const std::string& name, const Point& location, int healthPoints , int speed) 
    : Character(name, location, healthPoints), _speed(speed) {}
    
    int Ninja::getSpeed() const {return _speed;};

    void Ninja::move(Character* enemy) 
    {
        if(enemy == nullptr) { throw invalid_argument("Null pointer! \n"); }
        if(!isAlive()) { throw runtime_error("Dead Ninja can't move! \n"); }
        if(!enemy->isAlive()) { throw runtime_error("Can't move to dead enemy! \n"); }
        
        setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), _speed) );
    }

    void Ninja::slash(Character* enemy) 
    {
        if(enemy == nullptr) { throw invalid_argument("Null pointer! \n"); }
        if(!isAlive() || this == enemy) { throw runtime_error("Dead Ninja can't slash! \n"); }
        if(!enemy->isAlive()) { throw runtime_error("Can't slash in a dead enemy! \n"); } 
        
        if(distance(enemy) <= 1) { enemy->hit(40); }
    }

    string Ninja::print() const 
    {
        string output = "N- \n" + Character::print();
        return output;
    }

}