#pragma once

#include <iostream>
#include <cmath>

namespace ariel
{

    class Point
    {
        private:
            double _x;
            double _y;

        public:
            Point();
            Point(double, double);
            
            int get_x() const;
            int get_y() const;
            double distance(const Point& other) const;
            std::string print() const;
            static Point moveTowards(const Point&, const Point&, double);

    };

}