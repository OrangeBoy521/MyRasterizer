#include "Vector4D.h"

Vector4D::Vector4D(const Vector4D& v)
{
	(*this).x = v.x;
	(*this).y = v.y;
	(*this).z = v.z;
	(*this).w = v.w;
}

std::istream& operator>>(std::istream& is,Vector4D& v)
{
	double x, y, z, w;
	is >> x >> y >> z >> w;
	if (is)
	{
		v.x = x;
		v.y = y;
		v.z = z;
		v.w = w;
	} 
	else
	{
		v = Vector4D();
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector4D& v)
{
	std::cout << v.x << " " << v.y << " " << v.z << " " << v.w;
	return os;
}

Vector4D operator+(const Vector4D& v, const Vector4D& t)
{
	Vector4D temp = v;
	temp += t;
	return temp;
}
Vector4D operator-(const Vector4D& v, const Vector4D& t)
{
	Vector4D temp = v;
	temp -= t;
	return temp;
}

Vector4D& Vector4D::operator=(const Vector4D& v)
{
	(*this).x = v.x;
	(*this).y = v.y;
	(*this).z = v.z;
	(*this).w = v.w;
	return *this;
}

Vector4D operator*(const Vector4D& v,const float& t)
{
	Vector4D temp = v;
	temp *= t;
	return temp;
}

Vector4D operator/(const Vector4D& v,float& t)
{
	Vector4D temp = v;
	temp *= (1.0f / t);
	return temp;
}


Vector4D& Vector4D::operator+=(const Vector4D& t)
{
	(*this).x = (*this).x + t.x;
	(*this).y = (*this).y + t.y;
	(*this).z = (*this).z + t.z;
	(*this).w = (*this).w + t.w;
	return *this;
}
Vector4D& Vector4D::operator-=(const Vector4D& t)
{
	(*this).x = (*this).x - t.x;
	(*this).y = (*this).y - t.y;
	(*this).z = (*this).z - t.z;
	(*this).w = (*this).w - t.w;
	return *this;
}
Vector4D& Vector4D::operator*=(const float& t)
{
	(*this).x = (*this).x * t;
	(*this).y = (*this).y * t;
	(*this).z = (*this).z * t;
	(*this).w = (*this).w * t;
	return *this;
}

Vector4D operator*(const float& t, const Vector4D& v)
{
	return v * t;
}

Vector4D& Vector4D::operator/=(const float& t)
{
	*this *= (1.0f / t);
	return *this;
}


Vector4D& Vector4D::normalizeVec4()
{
	return (*this) /= (*this).w;
}

float dotProduct(const Vector4D& v, const Vector4D& t)
{
	return v.x * t.x + v.y * t.y + v.z * t.z + v.w * t.w;
}

Vector4D lerpVector(const Vector4D& v, const Vector4D& t,float& k)
{
	Vector4D temp;
	temp = v * k + t * (1.0f - k);
	return temp;
}
