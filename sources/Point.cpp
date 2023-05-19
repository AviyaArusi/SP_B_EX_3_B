#include "Point.hpp"


using namespace std;
namespace ariel
{
    Point::Point() : _x(0), _y(0) {}
    Point::Point(double x, double y) : _x(x), _y(y) {}

    int Point::get_x() const { return _x;}
    int Point::get_y() const { return _y;}

    double Point::distance(const Point &other) const 
    {
        double ans = sqrt( pow( (other.get_x() -_x) , 2) + pow( (other.get_y()-_y) , 2) );
        return ans;    
    }

    string Point::print() const { cout << "(" << _x << ", " << _y << ")" << endl; }
    
    Point Point::moveTowards(const Point& source, const Point& destination, double distance) 
    {
        double dx = destination.get_x() - source.get_x();
        double dy = destination.get_y() - source.get_y();
        double currentDistance = sqrt(dx * dx + dy * dy);
        if (currentDistance <= distance) 
        {
            return destination;
        } 
        else 
        {
            double ratio = distance / currentDistance;
            double newX = source.get_x() + dx * ratio;
            double newY = source.get_y() + dy * ratio;
            return Point(newX, newY);
        } 
    }


}