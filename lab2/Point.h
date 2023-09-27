#include <iostream>
#include "cmath"
class Point {
private:
    double x,y,z;
public:
    Point(int value_x,int value_y,int value_z) : x(value_x),y(value_y),z(value_z) {}
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double getZ() const {
        return z;
    }
};
class Vector {
private:
    double x,y,z;
public:
    Vector(double value_x = 0, double value_y = 0, double value_z = 0) : x(value_x), y(value_y), z(value_z) {}
    Vector(const Point& start, const Point& end);

    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double getZ() const {
        return z;
    }
    Vector reverse (const Vector &vector); // Обратный вектор
    Vector unit (const Vector &vector); // Единичный вектор
    double length (const Vector &vector); // Длина вектора
    double ScalarProduct (const Vector &vector1, const Vector &vector2); // Скалярное произведение
    Vector VectorProduct (const Vector &vector1, const Vector &vector2); // Векторное произведение
    double MixProduct (const Vector &vector1, const Vector &vector2,const Vector &vector3); // Смешанное произведение
    bool Collinear (const Vector& vector1, const Vector& vector2); // Коллинеарность
    bool Complanarity(const Vector& vector1, const Vector& vector2, const Vector& vector3); // Компланарность
    double AngleBetweenVectors(const Vector& vector1, const Vector& vector2); // Угол между вектрами
    double DistanceBetweenVectors(const Vector& vector1, const Vector& vector2); // Расстояние между векторами

};
Vector operator+(const Vector& vector1, const Vector& vector2);
Vector operator-(const Vector& vector1, const Vector& vector2);

