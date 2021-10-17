#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(const Vector3D& v)
{
	(*this).x = v.x;
	(*this).y = v.y;
	(*this).z = v.z;
}

Vector3D& Vector3D::operator=(const Vector3D& v)
{
	(*this).x = v.x;
	(*this).y = v.y;
	(*this).z = v.z;
	return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D& t)
{
	(*this).x = (*this).x + t.x;
	(*this).y = (*this).y + t.y;
	(*this).z = (*this).z + t.z;
	return *this;
}
Vector3D& Vector3D::operator-=(const Vector3D& t)
{
	(*this).x = (*this).x - t.x;
	(*this).y = (*this).y - t.y;
	(*this).z = (*this).z - t.z;
	return *this;
}
Vector3D& Vector3D::operator*=(const float& t)
{
	(*this).x = (*this).x * t;
	(*this).y = (*this).y * t;
	(*this).z = (*this).z * t;
	return *this;
}
Vector3D& Vector3D::operator/=(const float& t)
{
	float temp = static_cast<float>(1.0f / t);
	*this = *this * t;
	return *this;
}

float Vector3D::getLength() const
{
	return sqrt((*this).x * (*this).x + (*this).y * (*this).y + (*this).z * (*this).z);
}

float Vector3D::squareLength() const
{
	return (*this).x * (*this).x + (*this).y * (*this).y + (*this).z * (*this).z;
}

Vector3D Vector3D::normalizeVec()
{
	float temp = getLength();
	return (*this) /= temp;
}

void Schmidt(Vector3D& a, Vector3D& b, Vector3D& c)
{
	int alen = a.getLength();
	int blen = b.getLength();
	int clen = c.getLength();
	b = b - a * (dotProduct(a, b)) / (alen);
	c = c - b * (dotProduct(b, c)) / (blen)-a * (dotProduct(a, c)) / (alen);
	a = a / alen;
	b = b / b.getLength();
	c = c / c.getLength();
	//std::cout << a << std::endl;
}

Vector3D crossProduct(const Vector3D& v, const Vector3D& t)
{
	Vector3D temp;
	temp.x = t.y * v.z - v.y * t.z;
	temp.y = t.z * v.x - v.z * t.x;
	temp.z = t.x * v.y - v.x * t.y;
	return temp;
}

Vector3D lerpVector(const Vector3D& v, const Vector3D& t,const float& k)
{
	Vector3D temp;
	temp = v * k;
	temp = v * k + t * (1 - k);
	return temp;
}

std::istream& operator>>(std::istream& is, Vector3D& v)
{
	double temp_x, temp_y;
	is >> temp_x >> temp_y;
	if (is)
	{
		v.x = temp_x;
		v.y = temp_y;
	}
	else
	{
		v = Vector3D();
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
	os << v.x << " " << v.y << " " << v.z;
	return os;
}

Vector3D operator+(const Vector3D& v, const Vector3D& t)
{
	Vector3D temp = v;
	temp += t;
	return temp;
}

Vector3D operator-(const Vector3D& v, const Vector3D& t)
{
	Vector3D temp = v;
	temp -= t;
	return temp;
}

Vector3D operator*(const Vector3D& v,const float& t)
{
	Vector3D temp = v;
	temp *= t;
	return temp;
}

Vector3D operator*(const float& t, const Vector3D& v)
{
	return v * t;
}

Vector3D operator/(const Vector3D& v,const float& t)
{
	Vector3D temp = v;
	temp = temp * (1 / t);
	return temp;
}

float dotProduct(const Vector3D& v, const Vector3D& t)
{
	return v.x * t.x + v.y * t.y + v.z * t.z;
}
