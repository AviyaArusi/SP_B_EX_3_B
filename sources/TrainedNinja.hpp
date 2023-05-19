#pragma once

#include "Ninja.hpp"

const int TRAINED_NINJA_POINTS = 120;
const int TRAINED_NINJA_SPEED = 12;

namespace ariel
{
    class TrainedNinja : public Ninja 
    {
    public:
        TrainedNinja(const std::string& name, const Point& location)
        : Ninja(name, location, TRAINED_NINJA_POINTS, TRAINED_NINJA_SPEED) {}
    };

}