#include "Vector2D.h"
#include <cmath>
#include <iostream>

Vector2D::Vector2D(const Vector2D& v)
{
	x = v.x;
	y = v.y;
}

std::istream& operator>>(std::istream& is, Vector2D& v)
{
	float temp_x, temp_y;
	is >> temp_x >> temp_y;
	if (is)
	{
		v.x = temp_x;
		v.y = temp_y;
	}
	else
	{
		v = Vector2D();
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
	std::cout << v.x << " " << v.y;
	return os;
}

Vector2D& Vector2D::operator+=(const Vector2D& t)
{
	(*this).x = (*this).x + t.x;
	(*this).y = (*this).y + t.y;
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& t)
{
	(*this).x = (*this).x - t.x;
	(*this).y = (*this).y - t.y;
	return *this;
}
Vector2D& Vector2D::operator*=(const float& t)
{
	(*this).x = (*this).x * t;
	(*this).y = (*this).y * t;
	return *this;
}
Vector2D& Vector2D::operator/=(const float& t)
{
	float temp_t;
	temp_t = static_cast<float>(1.0f / t);
	(*this) *= temp_t;
	return *this;
}

Vector2D operator+(const Vector2D& t,const Vector2D& v)
{
	Vector2D temp = t;
	temp += v;
	return temp;
}

Vector2D operator-(const Vector2D& t,const Vector2D& v)
{
	Vector2D temp = t;
	temp -= v;
	return temp;
}

Vector2D operator*(const Vector2D& v,const float& t)
{
	Vector2D temp = v;
	temp *= t;
	return temp;

}

Vector2D operator*(const float& t, const Vector2D& v)
{
	return v * t;
}

Vector2D operator/(const Vector2D& v,const float& t)
{
	Vector2D temp = v;
	float temp_t = static_cast<float>(1.0f / t);
	temp *= temp_t;
	return temp;
}

float dotProduct(const Vector2D& v, const Vector2D& t)
{
	return v.x * t.x + v.y * t.y;
}

Vector2D& Vector2D::operator=(const Vector2D& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

float Vector2D::getLength() const
{
	return sqrt((*this).x * (*this).x + (*this).y * (*this).y);
}

float Vector2D::squareLength() const
{
	return (*this).x * (*this).x + (*this).y * (*this).y;
}

Vector2D Vector2D::normalizeVec()
{
	float temp = getLength();
	return (*this) / temp;
}
