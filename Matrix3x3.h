#pragma once
#ifndef Matrix3x3_H
#define Matrix3x3_H

#include <iostream>

class Matrix3x3
{
	friend std::istream& operator>>(std::istream&, Matrix3x3&);
	friend std::ostream& operator<<(std::ostream&, const Matrix3x3&);
	friend Matrix3x3 operator+(const Matrix3x3&, const Matrix3x3&);
	friend Matrix3x3 operator-(const Matrix3x3&, const Matrix3x3&);
	friend Matrix3x3 operator*(const Matrix3x3&,const float&);
	friend Matrix3x3 ScaleMar3x3(float, float);
	friend Matrix3x3 ReflectionMar3x3(float, float);
	friend Matrix3x3 ShearMar3x3(float);
	friend Matrix3x3 RotateMar3x3(float);
	friend Matrix3x3 TranlateMar3x3(float, float);
	friend Matrix3x3 MarProduct(const Matrix3x3&, const Matrix3x3&);

public:
	Matrix3x3();
	Matrix3x3(float e1, float e2, float e3,
		float e4, float e5, float e6,
		float e7, float e8, float e9);
	Matrix3x3(const Matrix3x3& v);
	Matrix3x3& operator=(const Matrix3x3& v);
	~Matrix3x3() = default;

	Matrix3x3& operator+=(const Matrix3x3& t);
	Matrix3x3& operator-=(const Matrix3x3& t);
	Matrix3x3& operator*=(const float& t);

	void transposeMar();
	void IndentityMar();

public:
	float mar[9];
};

std::istream& operator>>(std::istream&, Matrix3x3&);
std::ostream& operator<<(std::ostream&, const Matrix3x3&);
Matrix3x3 operator+(const Matrix3x3&, const Matrix3x3&);
Matrix3x3 operator-(const Matrix3x3&, const Matrix3x3&);
Matrix3x3 operator*(const Matrix3x3&, const float&);
Matrix3x3 ScaleMar3x3(float, float);
Matrix3x3 ReflectionMar3x3(float, float);
Matrix3x3 ShearMar3x3(float);
Matrix3x3 RotateMar3x3(float);
Matrix3x3 TranlateMar3x3(float, float);
Matrix3x3 MarProduct(const Matrix3x3&, const Matrix3x3&);
#endif