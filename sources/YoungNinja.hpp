#pragma once

#include "Ninja.hpp"

const int YOUNG_NINJA_POINTS = 100;
const int YOUNG_NINJA_SPEED = 14;

namespace ariel
{
    class YoungNinja : public Ninja 
    {
    public:
        YoungNinja(const std::string& name, const Point& location)
        : Ninja(name, location, YOUNG_NINJA_POINTS, YOUNG_NINJA_SPEED) {}
    };

}