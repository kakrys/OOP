#include "Point.h"
Vector::Vector(const Point& start, const Point& end)
{
    x = end.getX() - start.getX();
    y = end.getY() - start.getY();
    z = end.getZ() - start.getZ();
}

Vector Vector::reverse(const Vector &vector) { // Нахождение обратного вектора
    return Vector(-vector.getX(),-vector.getY(),-vector.getZ());
}

Vector Vector::unit(const Vector &vector) { // Нахождение единичного вектора
    double length = std::sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY() + vector.getZ() * vector.getZ());
    return Vector(vector.getX() / length, vector.getY() / length, vector.getZ() / length);
}

double Vector::length(const Vector &vector) { // Нахождение длины вектора
    return sqrt(vector.getX() * vector.getX() + vector.getY() * vector.getY() + vector.getZ() * vector.getZ());;
}

double Vector::ScalarProduct(const Vector &vector1, const Vector &vector2) { // Скалярное произведение
    return vector1.getX() * vector2.getX() + vector1.getY() * vector2.getY() + vector1.getZ() * vector2.getZ();
}

Vector Vector::VectorProduct(const Vector &vector1, const Vector &vector2) { // Векторное произведение
    return Vector(vector1.getY() * vector2.getZ() - vector1.getZ() * vector2.getZ(),vector1.getZ() * vector2.getX() - vector1.getX() * vector2.getZ(),vector1.getX() * vector2.getY() - vector1.getY() * vector2.getX());
}

double Vector::MixProduct(const Vector &vector1, const Vector &vector2, const Vector &vector3) { // Смешанное произведение
    return vector1.getX() * (vector2.getY() * vector3.getZ() - vector3.getY() * vector2.getZ()) - vector1.getY() * (vector2.getX() * vector3.getZ() - vector3.getX() * vector2.getZ()) + vector1.getZ() * (vector2.getX() * vector3.getY() - vector3.getX() * vector2.getY());
}

bool Vector::Collinear(const Vector &vector1, const Vector &vector2) { // Колинеарность
    return VectorProduct(vector1, vector2).getX() == 0 && VectorProduct(vector1, vector2).getY() == 0 && VectorProduct(vector1, vector2).getZ() == 0;
}

bool Vector::Complanarity(const Vector &vector1, const Vector &vector2, const Vector &vector3) { // Компланарность
    return ScalarProduct(VectorProduct(vector1, vector2), vector3) == 0;
}

double Vector::AngleBetweenVectors(const Vector &vector1, const Vector &vector2) {
    double cos = ScalarProduct(vector1, vector2) / (length(vector1) * length(vector2));
    return std::acos(cos);
}

double Vector::DistanceBetweenVectors(const Vector &vector1, const Vector &vector2) {
    return length(vector1-vector2);
}


Vector operator+(const Vector& vector1, const Vector& vector2) // Сложение векторов
{
    return Vector(vector1.getX() + vector2.getX(), vector1.getY() + vector2.getY(), vector1.getZ() + vector2.getZ());
}
Vector operator-(const Vector& vector1, const Vector& vector2) // Вычитание векторов
{
    return Vector(vector1.getY() - vector2.getX(), vector1.getY() - vector2.getY(), vector1.getZ() - vector2.getZ());
}