
#include <iostream>

#include "vector.hpp"
#include "plane.hpp"

int main ( int argc, char ** argv ) {
    
    src::Plane2D plane(src::Vector2D(-1,1),src::Vector2D(1,-1));
    std::cout << plane << std::endl;
    
    return 0;
}
