#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Vector2D.h"

#include <iostream>

class Vector3D
{
	friend std::istream& operator>>(std::istream&,Vector3D&);
	friend std::ostream& operator<<(std::ostream&, const Vector3D&);
	friend Vector3D operator+(const Vector3D&, const Vector3D&);
	friend Vector3D operator-(const Vector3D&, const Vector3D&);
	friend Vector3D operator*(const Vector3D&,const float&);
	friend Vector3D operator*(const float&, const Vector3D&);
	friend Vector3D operator/(const Vector3D&,const float&);
	friend float dotProduct(const Vector3D& , const Vector3D& );
	friend void Schmidt(Vector3D&, Vector3D&, Vector3D&);
	friend Vector3D crossProduct(const Vector3D&, const Vector3D&);
	friend Vector3D lerpVector(const Vector3D&, const Vector3D&, const float&);
	
public:
	Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3D(float newX, float newY, float newZ) :x(newX), y(newY), z(newZ) {}
	Vector3D(const Vector3D& v);
	Vector3D& operator=(const Vector3D& v);
	~Vector3D() = default;

	Vector3D& operator+=(const Vector3D& t);
	Vector3D& operator-=(const Vector3D& t);
	Vector3D& operator*=(const float& t);
	Vector3D& operator/=(const float& t);

	float getLength() const;
	float squareLength() const;
	Vector3D normalizeVec();

public:
	float x = { 0 }, y = { 0 }, z = { 0 };
};

using Color3D = Vector3D;

std::istream& operator>>(std::istream&, Vector3D&);
std::ostream& operator<<(std::ostream&, const Vector3D&);
Vector3D operator+(const Vector3D&, const Vector3D&);
Vector3D operator-(const Vector3D&, const Vector3D&);
Vector3D operator*(const Vector3D&, const float&);
Vector3D operator/(const Vector3D&, const float&);
float dotProduct(const Vector3D&, const Vector3D&);
void Schmidt(Vector3D&, Vector3D&, Vector3D&);
Vector3D crossProduct(const Vector3D&, const Vector3D&);
Vector3D lerpVector(const Vector3D&, const Vector3D&, const float&);
Vector3D operator*(const float&, const Vector3D&);
#endif