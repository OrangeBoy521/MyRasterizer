#pragma once
#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <cmath>
#include "Vector3D.h"

template <typename T>
class Matrix4x4
{
public:
	Matrix4x4() = default;
	Matrix4x4(
		T e0, T e1, T e2, T e3,
		T e4, T e5, T e6, T e7,
		T e8, T e9, T e10, T e11,
		T e12, T e13, T e14, T e15
	);
	Matrix4x4(const Matrix4x4&);
	Matrix4x4& operator=(const Matrix4x4&);
	~Matrix4x4() = default;
private:
	std::shared_ptr<T[]> e(new T[16]());
};

template <typename T>
Matrix4x4<T>::Matrix4x4()
{
	std::shared_ptr<T[]> temp(new T[16](e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e16));
	e = temp;
}

template <typename T>
Matrix4x4<T>::Matrix4x4(
	T e0, T e1, T e2, T e3,
	T e4, T e5, T e6, T e7,
	T e8, T e9, T e10, T e11,
	T e12, T e13, T e14, T e15
)
{
	std::shared_ptr<T[]> temp(new T[16](e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15));
	e = temp;
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Matrix4x4& s)
{
	e = s.e;
}

template <typename T>
Matrix4x4<T>& Matrix4x4<T>::operator=(const Matrix4x4<T>& s)
{
	e = s.e;
}

template <typename T>
Matrix4x4<T> IdentityMat4x4()
{
	return Matrix4x4<T>(
		static_cast<T>(1.0f), 0, 0, 0,
		0, static_cast<T>(1.0f), 0, 0,
		0, 0, static_cast<T>(1.0f), 0,
		0, 0, 0, static_cast<T>(1.0f)
		);
}

template <typename T>
Matrix4x4<T> ScaleMatrix4x4(T sx,T sy,T sz)
{
	return Matrix4x4<T>(
		sx, 0, 0, 0,
		0, sy, 0, 0,
		0, 0, sz, 0,
		0, 0, 0, 1
		);
}

template <typename T>
Matrix4x4<T> TranslationMatrix4x4(T tx,T ty,T tz)
{
	return Matrix4x4<T>(
		1, 0, 0, tx,
		0, 1, 0, ty,
		0, 0, 1, tz,
		0, 0, 0, 1
		);
}

template <typename T>
Matrix4x4<T> RotateX(T angle)
{
	float tempAngle = angle / 180.0f * M_PI;
	return Matrix4x4<T>(
		1, 0, 0, 0,
		0, cos(tempAngle), -sin(tempAngle), 0,
		0, sin(tempAngle), cos(tempAngle), 0,
		0, 0, 0, 1
		);
}

template<typename T>
Matrix4x4<T> RotateY(T angle)
{
	float tempAngle = angle / 180.0f * M_PI;
	return Matrix4x4<T>(
		cos(tempAngle), 0, sin(tempAngle), 0,
		0, 1, 0, 0,
		-sin(tempAngle), 0, cos(tempAngle), 0,
		0, 0, 0, 1
		);
}

template<typename T>
Matrix4x4<T> RotateZ(T angle)
{
	float tempAngle = angle / 180.0f * M_PI;
	return Matrix4x4<t>(
		cos(tempAngle), -sin(tempAngle), 0, 0,
		sin(tempAngle), cos(tempAngle), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
}

template <typename T>
Matrix4x4<T> OrthoMatrix4x4(T fov,T aspect,T znear)
{
	T half_height = tan(fov / 2) * znear;
	T width = 2 * half_height * aspect;

	return Matrix4x4<T>(
		2.0f / (width), 0, 0, 0
		0, 2.0f / (half_height * 2), 0, 0,
		0, 0, 2.0f / (znear - zfar), 0, 0,
		0, 0, 0, 1
		);
}

template <typename T>
Matrix4x4<T> ProjectionMat4x4(T znear,T zfar)
{
	return Matrix4x4<T>(
		znear, 0, 0, 0,
		0, znear, 0, 0,
		0, 0, znear + zfar, -znear * zfar,
		0, 0, 1, 0
		);
}

template<typename T>
Matrix4x4<T> cameraPosition(Vector3D<T> camPosition)
{
	Vector3D<T> camDir = -(camPosition);
	Vector3D<T> upDir(0, 0, 1.0f);
	Vector3D<T> leftDir = crossProduct(upDir, camDir);

	schmidt(camDir, upDir, leftDir);
	Matrix4x4<T> cameraCoordinate(
		camDir.x, upDir.x, leftDir.x, 0,
		camDir.y, upDir.y, leftDir.y, 0,
		camDir.z, upDir.z, leftDir.z, 0,
		0, 0, 0, 1
	);
	Matrix4x4<T> cameraTrans(
		1, 0, 0, -camPosition, x,
		0, 1, 0, -camPosition.y,
		0, 0, 1, -camPosition.z,
		0, 0, 0, 1
	);
	return cameraTrans * cameraCoordinate;
}

template <typename T>
Matrix4x4<T> ViewportMat4x4(const unsigned int width,const unsigned int height)
{
	return Matrix4x4<T>(
		width / 2, 0, 0, width / 2,
		0, height / 2, 0, height / 2,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
}
#endif