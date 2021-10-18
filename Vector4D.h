#pragma once
#ifndef VECTOR4D_H
#define VECTOR4D_H

#include "Vector3D.h"

template <typename T>
class Vector4D
{
public:
    Vector4D() = default;
    Vector4D(T newx,T newy,T newz,T neww) : x(newx),y(newy),z(newz),w(neww){}
    Vector4D(const Vector4D& s)
    {
         this->x = s.x;
         this->y = s.y;
         this->z = s.z;
         this->w = s.w;
    }
    Vector4D& operator=(const Vector4D& s)
    {
        *this = s;
    }
    ~Vector4D() = default;

    Vector4D& operator+=(const Vector4D& s)
    {
        this->x = this->x + s.x;
        this->y = this->y + s.y;
        this->z = this->z + s.z;
        this->w = this->w + s.w;
    }
private:
    T x, y, z, w;
};

template <typename T>
Vector4D<T> operator+(const Vector4D<T>& tempA,const Vector4D<T>& tempB)
{
    Vector4D<T> temp = tempA;
    temp += tempB;
    return temp;
}

template <typename T>
Vector4D<T> toVector4(const Vector3D<T>& temp)
{
    return Vector4D<T>(temp.x, temp.y, temp.z, static_cast<T>(1.0f));
}

template <typename T>
Vector4D<T> normalizeVec4D(Vector4D<T>& temp)
{
    temp = Vector4D<T>(temp.x / temp.w, temp.y / temp.w, temp.z / temp.w, static_cast<T>(1.0f));
    return temp;
}


#endif