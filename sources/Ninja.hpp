#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character 
    {
    private:
        int _speed;

    public:
        Ninja(const std::string&, const Point&, int, int);
        void move(Character*);
        void slash(Character*);
        int getSpeed() const;
        std::string print() const override;
    };

}