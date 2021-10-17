#pragma once
#ifndef VECTOR2D
#define VECTOR2D

#include <iostream>

class Vector2D
{
	friend Vector2D operator+(const Vector2D&, const Vector2D&);
	friend Vector2D operator-(const Vector2D&, const Vector2D&);
	friend Vector2D operator*(const Vector2D&,const float&);
	friend Vector2D operator*(const float&, const Vector2D&);
	friend Vector2D operator/(const Vector2D&, const float&);
	friend std::istream& operator>>(std::istream&, Vector2D&);
	friend std::ostream& operator<<(std::ostream&, const Vector2D&);
	friend float dotProduct(const Vector2D& v, const Vector2D& t);

public:
	Vector2D() : x(0.0f),y(0.0f){}
	Vector2D(float newX,float newY): x(newX),y(newY){}
	Vector2D(const Vector2D& v);
	Vector2D& operator=(const Vector2D& v);
	~Vector2D() = default;

	Vector2D& operator+=(const Vector2D& t);
	Vector2D& operator-=(const Vector2D& t);
	Vector2D& operator*=(const float& t);
	Vector2D& operator/=(const float& t);

	float getLength() const;
	float squareLength() const;
	Vector2D normalizeVec();

public:
	float x = { 0 }, y = { 0 };
};


Vector2D operator+(const Vector2D&, const Vector2D&);
Vector2D operator-(const Vector2D&, const Vector2D&);
Vector2D operator*(const Vector2D&, const float&);
Vector2D operator/(const Vector2D&, const float&);
std::istream& operator>>(std::istream&, Vector2D&);
std::ostream& operator<<(std::ostream&, const Vector2D&);
float dotProduct(const Vector2D& v, const Vector2D& t);
Vector2D operator*(const float&, const Vector2D&);
#endif