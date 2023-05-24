#include "Point.hpp"


using namespace std;
namespace ariel
{
    Point::Point() : _x(0), _y(0) {}
    Point::Point(double x, double y) : _x(x), _y(y) {}

    double Point::get_x() const { return _x;}
    double Point::get_y() const { return _y;}

    double Point::distance(const Point &other) const 
    {
        double ans = sqrt( pow( (other.get_x() -_x) , 2) + pow( (other.get_y()-_y) , 2) );
        return ans;    
    }

    string Point::print() const { return "(" + to_string(_x) + ", " + to_string(_y) + ")"; }
    
    Point Point::moveTowards(const Point& source, const Point& destination, double distance) 
    {
        if(distance < 0) { throw invalid_argument("distance can't be less then zero! \n"); }
        if(distance == 0) { return source; }
        
        double dx = destination._x - source._x;
        double dy = destination._y - source._y;
        double currentDistance = sqrt(dx * dx + dy * dy);

        if (currentDistance <= distance) { return destination; } 
        else 
        {
            double ratio = distance / currentDistance;
            double newX = source.get_x() + dx * ratio;
            double newY = source.get_y() + dy * ratio;
            return Point(newX, newY);
        } 
    
    }


}