#pragma once
#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include <memory>

template <typename T>
class Matrix3x3
{
public:
	Matrix3x3() = default;
	Matrix3x3(
		T e0, T e1, T e2,
		T e3, T e4, T e5,
		T e6, T e7, T e8
	         );
	Matrix3x3(const Matrix3x3&);
	Matrix3x3& operator=(const Matrix3x3&);
	~Matrix3x3() = default;

private:
	std::shared_ptr<T[]> e(new T[10]());
};

template <typename T>
Matrix3x3<T>::Matrix3x3(
	T e0, T e1, T e2,
	T e3, T e4, T e5,
	T e6, T e7, T e8)
{
	std::shared_ptr<T[]> temp(new T[9](e0, e1, e2, e3, e4, e5, e6, e7, e8));
	e = temp;
}

template <typename T>
Matrix3x3<T>::Matrix3x3(const Matrix3x3& s)
{
	e = s.e;
}

template <typename T>
Matrix3x3<T>& Matrix3x3<T>::operator=(const Matrix3x3<T>& s)
{
	e = s.e;
}

template <typename T>
Matrix3x3<T> IdentityMat3x3()
{
	return Matrix3x3<T>(
		static_cast<T>(1.0f), 0, 0,
		0, static_cast<T>(1.0f), 0,
		0, 0, static_cast<T>(1.0f)
		);
}
#endif