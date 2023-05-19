#include "Character.hpp"

using namespace std;

namespace ariel
{
    // Check validation!!
    Character::Character(const std::string& name, const Point& location, int healthPoints) 
    : _name(name), _location(location), _healthPoints(healthPoints) {}

    // Define copy constructor
    Character::Character(Character& other) 
    : _name(other.getName()), _location(other.getLocation()), _healthPoints(other.getHealth()) {}
    // Define move constructor
    Character::Character(Character&& other) noexcept 
    : _name(other.getName()), _location(other.getLocation()), _healthPoints(other.getHealth()) {}
    // Define copy assignment operator
    Character &Character::operator=(const Character& other) 
    {
        if (this == &other) { return *this;}

        _name = other.getName();
        _location = other.getLocation();
        _healthPoints = other.getHealth();
        return (*this);
    }
    // Define move assignment operator
    Character &Character::operator=(Character&& other) noexcept 
    {
        if (this == &other) { return *this;}

        _name = other.getName();
        _location = other.getLocation();
        _healthPoints = other.getHealth();
        return (*this);
    }


    bool Character::isAlive() const { return _healthPoints > 0; }

    void Character::hit(int damage) { _healthPoints -= damage; }

    string Character::getName() const { return _name; }

    Point Character::getLocation() const { return _location; }

    void Character::setLocation(const Point& other) { _location = other; }

    int Character::getHealth() const { return _healthPoints;};

    double Character::distance(const Character* other) const 
    {
        if(other == nullptr) {throw invalid_argument("Input can't be nullptr!\n");}
        int dis = _location.distance(other->getLocation()); 
        return dis;
    }

    string Character::print() const 
    {
        string output = "";
        if(this->isAlive()) { output += "Name: " + _name + "\nHealth point: " + to_string(_healthPoints) + "\n";}
        else { output += "Name: (" + _name + ")\n";}
        output += "Location: " +_location.print() + "\n";
        return output;
    }

}