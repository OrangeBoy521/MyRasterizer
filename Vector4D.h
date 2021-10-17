#pragma once
#ifndef Vector4D_H
#define Vector4D_H

#include <iostream>

class Vector4D
{
	friend std::istream& operator>>(std::istream&, Vector4D&);
	friend std::ostream& operator<<(std::ostream&, const Vector4D&);
	friend Vector4D operator+(const Vector4D&, const Vector4D&);
	friend Vector4D operator-(const Vector4D&, const Vector4D&);
	friend Vector4D operator*(const Vector4D&,const float&);
	friend Vector4D operator*(const float&, const Vector4D&);
	friend Vector4D operator/(const Vector4D&,const float&);
	friend float dotProduct(const Vector4D&, const Vector4D&);
	friend Vector4D lerpVector(const Vector4D&, const Vector4D&,const float&);
	
public:
	Vector4D() : x(0.0f), y(0.0f), z(0.0f),w(0.0f) {}
	Vector4D(float newX, float newY, float newZ,float newW) :x(newX), y(newY), z(newZ),w(newW) {}
	Vector4D(const Vector4D& v);
	Vector4D& operator=(const Vector4D& v);
	~Vector4D() = default;

	Vector4D& operator+=(const Vector4D& t);
	Vector4D& operator-=(const Vector4D& t);
	Vector4D& operator*=(const float& t);
	Vector4D& operator/=(const float& t);

	Vector4D& normalizeVec4();

public:
	float x = { 0 }, y = { 0 }, z = { 0 }, w = { 0 };
};

using Color4D = Vector4D;

std::istream& operator>>(std::istream&, Vector4D&);
std::ostream& operator<<(std::ostream&, const Vector4D&);
Vector4D operator+(const Vector4D&, const Vector4D&);
Vector4D operator-(const Vector4D&, const Vector4D&);
Vector4D operator*(const Vector4D&, const float&);
Vector4D operator/(const Vector4D&, const float&);
float dotProduct(const Vector4D&, const Vector4D&);
Vector4D lerpVector(const Vector4D&, const Vector4D&, const float&);
Vector4D operator*(const float&, const Vector4D&);
#endif