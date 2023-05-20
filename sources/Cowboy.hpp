#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character 
    {
    private:
        int _bullets;

    public:
        Cowboy(const std::string&, const Point&);
        void shoot(Character*);
        bool hasboolets() const;
        void reload(); 
        std::string print() const override;
    };

}