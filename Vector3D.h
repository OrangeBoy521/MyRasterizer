#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H

template<typename T>
class Vector3D
{

	friend Vector3D& operator+(const Vector3D&, const Vector3D&);
	friend Vector3D& operator-(const Vector3D&, const Vector3D&);
public:
	Vector3D();
	Vector3D(T newx,T newy,T newz): x(newx),y(newy),z(newz){}
	Vector3D(const Vector3D&);
	Vector3D& operator=(const Vector3D&);
	~Vector3D() = default;

	Vector3D& operator+=(Vector3D&);
	Vector3D& operator-=(Vector3D&);

private:
	T x, y, z;
};

template <typename T>
Vector3D<T>::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template <typename T>
Vector3D<T>::Vector3D(const Vector3D& s)
{
	this->x = s.x;
	this->y = s.y;
	this->z = s.z;
}

template <typename T>
Vector3D<T>& Vector3D<T>::operator =(const Vector3D& s)
{
	this->x = s.x;
	this->y = s.y;
	this->z = s.z;
}

template <typename T>
Vector3D<T>& Vector3D<T>::operator+=(Vector3D<T>& s)
{
	this->x = this->x + s.x;
	this->y = this->y + s.y;
	this->z = this->z + s.z;
	return *this;
}

template <typename T>
Vector3D<T>& Vector3D<T>::operator-=(Vector3D<T>& s)
{
	this->x = this->x - s.x;
	this->y = this->y - s.y;
	this->z = this->z - s.z;
	return *this;
}

template <typename T>
T dotProduct(const Vector3D<T>& A,const Vector3D<T>& B)
{
	return A.x * B.x + A.y * B.y + A.z * B.z;
}

template <typename T>
Vector3D<T> crossProduct(const Vector3D<T>& A,const Vector3D<T>& B)
{
	return Vector3D<T>(
		A.y * B.z - B.y * A.z,
		A.z * B.x - A.x * B.z,
		A.x * B.y - A.y * B.x
		);
}

template <typename T>
Vector3D<T> normalize(const Vector3D<T>& A)
{
	return A / (sqrt(pow(A.x, 2) + pow(A.y, 2) + pow(A.z, 2)));
}

template <typename T>
Vector3D<T> schmidt(Vector3D<T>& a1,Vector3D<T> a2,Vector3D<T>& a3)
{
	Vector3D<T> b1 = a1;
	Vector3D<T> b2 = a2 - dotProduct(a2, b1) / dotProduct(b1, b1) * b1;
	Vector3D<T> b3 = a3 - dotProduct(a3, b1) / dotProduct(b1, b1) * b1 - dotProduct(a3, b2) / dotProduct(b2, b2) * b2;

	a1 = b1;
	a2 = b2;
	a3 = b3;
}

template <typename T>
Vector3D<T>& operator+(const Vector3D<T>& A, const Vector3D<T>& B)
{
	Vector3D<T> temp = A;
	temp += B;
	return temp;
}

template <typename T>
Vector3D<T>& operator-(const Vector3D<T>& A,const Vector3D<T>& B)
{
	Vector3D<T> temp = A;
	temp -= B;
	return temp;
}
#endif