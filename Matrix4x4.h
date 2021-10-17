#pragma once
#ifndef Matrix4x4_H
#define Matrix4x4_H

#include <iostream>
#include "Vector4D.h"
#include "Matrix3x3.h"
#include "Vector3D.h"
class Matrix4x4
{
	friend std::ostream& operator<<(std::ostream&, const Matrix4x4&);
	friend Matrix4x4 operator+(const Matrix4x4&, const Matrix4x4&);
	friend Matrix4x4 operator-(const Matrix4x4&, const Matrix4x4&);
	friend Matrix4x4 operator*(const Matrix4x4&, const Matrix4x4&);
	friend Matrix4x4 operator*(const Matrix4x4&, const float&);
	friend Vector4D Mar4x4Vec(const Matrix4x4&, const Vector4D&);
	friend Matrix4x4 ScaleMar4x4(float, float, float);
	friend Matrix4x4 TranslationMar4x4(float, float, float);
	friend Matrix4x4 RotateXMar4x4(float);
	friend Matrix4x4 RotateYMar4x4(float);
	friend Matrix4x4 RotateZMar4x4(float);
	friend Matrix4x4 OrthoMar4x4(float, float, float, float);
	friend Matrix4x4 ProjectMar4x4(float, float);
	friend Matrix4x4 ViewportMar4x4(float, float);
	friend Matrix4x4 CameraMar4x4(Vector3D&);
	friend Matrix4x4 OPGLViewMar4x4(const int, const int);

public:
	Matrix4x4();
	Matrix4x4(float e1, float e2, float e3, float e4,
		float e5, float e6, float e7, float e8,
		float e9, float e10, float e11, float e12,
		float e13, float e14, float e15, float e16);
	Matrix4x4(const Matrix4x4& v);
	Matrix4x4& operator=(const Matrix4x4& v);
	~Matrix4x4() = default;

	Matrix4x4& operator+=(const Matrix4x4& t);
	Matrix4x4& operator-=(const Matrix4x4& t);
	Matrix4x4& operator*=(const float& t);

	void IdentityMar4x4();
	Matrix4x4& transposeMar4x4();

public:
	float mar[16];
};

std::ostream& operator<<(std::ostream&, const Matrix4x4&);
Matrix4x4 operator+(const Matrix4x4&, const Matrix4x4&);
Matrix4x4 operator-(const Matrix4x4&, const Matrix4x4&);
Matrix4x4 operator*(const Matrix4x4&, const Matrix4x4&);
Matrix4x4 operator*(const Matrix4x4&, const float&);
Vector4D Mar4x4Vec(const Matrix4x4&, const Vector4D&);
Matrix4x4 ScaleMar4x4(float, float, float);
Matrix4x4 TranslationMar4x4(float, float, float);
Matrix4x4 RotateXMar4x4(float);
Matrix4x4 RotateYMar4x4(float);
Matrix4x4 RotateZMar4x4(float);
Matrix4x4 OrthoMar4x4(float, float, float, float);
Matrix4x4 ProjectMar4x4(float, float);
Matrix4x4 ViewportMar4x4(float, float);
Matrix4x4 CameraMar4x4(Vector3D&);
Matrix4x4 OPGLViewMar4x4(const int, const int);

#endif