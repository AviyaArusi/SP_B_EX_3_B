#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include "Point.hpp"

namespace ariel
{

    class Character
    {
        private:
            Point _location;
            int _healthPoints;
            std::string _name;
            
        public:
            Character (const std::string&, const Point&, int);
            Character(Character&);
            Character(Character&&) noexcept;
            Character& operator=(const Character&);
            Character& operator=(Character&&) noexcept;
            virtual ~Character() = default;

            std::string getName() const;
            Point getLocation() const;
            void setLocation(const Point&);
            int getHealth() const;
            bool isAlive() const;
            double distance(const Character*) const;
            void hit(int);
            virtual std::string print() const = 0; // Pure virtual function
    };

}