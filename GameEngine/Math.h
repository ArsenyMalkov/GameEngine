#pragma once

#include <math.h>

struct Vector3 {

    double x;
    double y;
    double z;

    __forceinline Vector3() {
        x = y = z = 0;
    }

    __forceinline Vector3(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    __forceinline Vector3& operator += (double scalar);
    __forceinline Vector3  operator +  (double scalar) const;
    __forceinline Vector3& operator -= (double scalar);
    __forceinline Vector3  operator -  (double scalar) const;
    __forceinline Vector3& operator *= (double scalar);
    __forceinline Vector3  operator *  (double scalar) const;
    __forceinline Vector3& operator /= (double scalar);
    __forceinline Vector3  operator /  (double scalar) const;

    __forceinline Vector3& operator += (const Vector3& vector);
    __forceinline Vector3  operator +  (const Vector3& vector) const;
    __forceinline Vector3& operator -= (const Vector3& vector);
    __forceinline Vector3  operator -  (const Vector3& vector) const;
    __forceinline Vector3& operator *= (const Vector3& vector);
    __forceinline Vector3  operator *  (const Vector3& vector) const;
    __forceinline Vector3& operator /= (const Vector3& vector);
    __forceinline Vector3  operator /  (const Vector3& vector) const;

    __forceinline double magnitude() const;
    __forceinline Vector3 normalize() const;

    __forceinline double dot(const Vector3& vector) const;
    __forceinline Vector3 cross(const Vector3& vector) const;
};

Vector3& Vector3::operator += (double scalar) {
    x += scalar;
    y += scalar;
    z += scalar;
    return *this;
}

Vector3 Vector3::operator + (double scalar) const {
    return Vector3(x + scalar, y + scalar, z + scalar);
}

Vector3& Vector3::operator -= (double scalar) {
    x -= scalar;
    y -= scalar;
    z -= scalar;
    return *this;
}

Vector3 Vector3::operator - (double scalar) const {
    return Vector3(x - scalar, y - scalar, z - scalar);
}

Vector3& Vector3::operator *= (double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3 Vector3::operator * (double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3& Vector3::operator /= (double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

Vector3 Vector3::operator / (double scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator += (const Vector3& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector3 Vector3::operator + (const Vector3& vector) const {
    return Vector3(x + vector.x, y + vector.y, z + vector.z);
}

Vector3& Vector3::operator -= (const Vector3& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

Vector3 Vector3::operator - (const Vector3& vector) const {
    return Vector3(x - vector.x, y - vector.y, z - vector.z);
}

Vector3& Vector3::operator *= (const Vector3& vector) {
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
    return *this;
}

Vector3 Vector3::operator * (const Vector3& vector) const {
    return Vector3(x * vector.x, y * vector.y, z * vector.z);
}

Vector3& Vector3::operator /= (const Vector3& vector) {
    x /= vector.x;
    y /= vector.y;
    z /= vector.z;
    return *this;
}

Vector3 Vector3::operator / (const Vector3& vector) const {
    return Vector3(x / vector.x, y / vector.y, z / vector.z);
}

double Vector3::magnitude() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize() const {
    double magnitude = this->magnitude();
    if (magnitude == 0) {
        return Vector3(0, 0, 0);
    }
    return Vector3(x / magnitude, y / magnitude, z / magnitude);
}

double Vector3::dot(const Vector3& vector) const {
    return x * vector.x + y * vector.y + z * vector.z;
}

Vector3 Vector3::cross(const Vector3& vector) const {
    return Vector3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
}
