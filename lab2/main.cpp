#include <iostream>
#include "Point.h"

int main() {
    Vector v1 (1,2,3);
    Point p1(1,2,3);
    Point p2(4,5,6);
    Vector v2(p1,p2);
    Vector v4 = v1.reverse(v1);
    std::cout << "Reverse vector " <<  "x = " <<v4.getX() << " y = " << v4.getY() << " z = " << v4.getZ() << std::endl;
    v4 = v1.unit(v1);
    std::cout << "unit vector " <<  "x = " <<v4.getX() << " y = " << v4.getY() << " z = " << v4.getZ() << std::endl;
    std::cout << "length " << v1.length(v1) << std::endl;
    std::cout << "ScalarProduct " << v1.ScalarProduct(v1,v2) << std::endl;
    v4=v4.VectorProduct(v1,v2);
    std::cout << "VectorProduct " << "x = " <<v4.getX() << " y = " << v4.getY() << " z = " << v4.getZ() << std::endl;
    Vector v3(7,8,9);
    std::cout << "MixProduct " << v4.MixProduct(v1,v2,v3) << std::endl;
    v1.Collinear(v1,v3) ? std::cout << "collinear" << std::endl : std::cout << "not collinear" << std::endl;
    v1.Complanarity(v1,v2,v3) ? std::cout << "complanar" << std::endl : std::cout << "not complanar" << std::endl;
    std::cout << "Angle Between Vectors " << v1.AngleBetweenVectors(v1,v2) << std::endl;
    std::cout << "Distance Between Vectors " << v1.DistanceBetweenVectors(v1,v2) << std::endl;
}
