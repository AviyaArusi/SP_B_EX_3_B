#pragma once

#include "Ninja.hpp"

const int OLD_NINJA_POINTS = 150;
const int OLD_NINJA_SPEED = 8;

namespace ariel
{
    class OldNinja : public Ninja 
    {
    public:
        OldNinja(const std::string& name, const Point& location)
        : Ninja(name, location, OLD_NINJA_POINTS, OLD_NINJA_SPEED) {}
    };

}