#include "Matrix3x3.h"
#include <cmath>
#define PI 3.141592653

Matrix3x3::Matrix3x3()
{
	for (size_t i = 0; i < sizeof(mar) / sizeof(float); ++i)
	{
		mar[i] = 0;
	}
}

Matrix3x3::Matrix3x3(float e1, float e2, float e3,
	float e4, float e5, float e6,
	float e7, float e8, float e9)
{
	mar[0] = e1;
	mar[1] = e2;
	mar[2] = e3;
	mar[3] = e4;
	mar[4] = e5;
	mar[5] = e6;
	mar[6] = e7;
	mar[7] = e8;
	mar[8] = e9;
}

Matrix3x3::Matrix3x3(const Matrix3x3& v)
{
	(*this).mar[0] = v.mar[0];
	(*this).mar[1] = v.mar[1];
	(*this).mar[2] = v.mar[2];
	(*this).mar[3] = v.mar[3];
	(*this).mar[4] = v.mar[4];
	(*this).mar[5] = v.mar[5];
	(*this).mar[6] = v.mar[6];
	(*this).mar[7] = v.mar[7];
	(*this).mar[8] = v.mar[8];
}

Matrix3x3& Matrix3x3::operator=(const Matrix3x3& v)
{
	(*this).mar[0] = v.mar[0];
	(*this).mar[1] = v.mar[1];
	(*this).mar[2] = v.mar[2];
	(*this).mar[3] = v.mar[3];
	(*this).mar[4] = v.mar[4];
	(*this).mar[5] = v.mar[5];
	(*this).mar[6] = v.mar[6];
	(*this).mar[7] = v.mar[7];
	(*this).mar[8] = v.mar[8];
	return *this;
}

std::istream& operator>>(std::istream& is,Matrix3x3& v)
{
	float A00, A01, A02, A10, A11, A12, A20, A21, A22;
	is >> A00 >> A01 >> A02 >> A10 >> A11 >> A12 >> A20 >> A21 >> A22;
	if(is)
	{
		Matrix3x3 temp(A00, A01, A02, A10, A11, A12, A20, A21, A22);
		 v = temp;
	} 
	else
	{
		Matrix3x3 temp;
		v = temp;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix3x3& v)
{
	os << v.mar[0] << " " << v.mar[1] << " " << v.mar[2] << "\n"
		<< v.mar[3] << " " << v.mar[4] << " " << v.mar[5] << "\n"
		<< v.mar[6] << " " << v.mar[7] << " " << v.mar[8];
	return os;
}

Matrix3x3 operator+(const Matrix3x3& v,const Matrix3x3& t)
{
	Matrix3x3 temp = v;
	temp += t;
	return temp;
}

Matrix3x3 operator-(const Matrix3x3& v, const Matrix3x3& t)
{
	Matrix3x3 temp = v;
	temp += t;
	return temp;
}

Matrix3x3 operator*(const Matrix3x3& v,float& t)
{
	Matrix3x3 temp = v;
	temp *= t;
	return temp;
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& t)
{
	(*this).mar[0] = (*this).mar[0] + t.mar[0];
	(*this).mar[1] = (*this).mar[1] + t.mar[1];
	(*this).mar[2] = (*this).mar[2] + t.mar[2];
	(*this).mar[3] = (*this).mar[3] + t.mar[3];
	(*this).mar[4] = (*this).mar[4] + t.mar[4];
	(*this).mar[5] = (*this).mar[5] + t.mar[5];
	(*this).mar[6] = (*this).mar[6] + t.mar[6];
	(*this).mar[7] = (*this).mar[7] + t.mar[7];
	(*this).mar[8] = (*this).mar[8] + t.mar[8];
	return *this;
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& t)
{
	(*this).mar[0] = (*this).mar[0] - t.mar[0];
	(*this).mar[1] = (*this).mar[1] - t.mar[1];
	(*this).mar[2] = (*this).mar[2] - t.mar[2];
	(*this).mar[3] = (*this).mar[3] - t.mar[3];
	(*this).mar[4] = (*this).mar[4] - t.mar[4];
	(*this).mar[5] = (*this).mar[5] - t.mar[5];
	(*this).mar[6] = (*this).mar[6] - t.mar[6];
	(*this).mar[7] = (*this).mar[7] - t.mar[7];
	(*this).mar[8] = (*this).mar[8] - t.mar[8];
	return *this;
	return *this;
}

Matrix3x3& Matrix3x3::operator*=(const float& t)
{
	(*this).mar[0] = (*this).mar[0] * t;
	(*this).mar[1] = (*this).mar[1] * t;
	(*this).mar[2] = (*this).mar[2] * t;
	(*this).mar[3] = (*this).mar[3] * t;
	(*this).mar[4] = (*this).mar[4] * t;
	(*this).mar[5] = (*this).mar[5] * t;
	(*this).mar[6] = (*this).mar[6] * t;
	(*this).mar[7] = (*this).mar[7] * t;
	(*this).mar[8] = (*this).mar[8] * t;
	return *this;
}

Matrix3x3 MarProduct(const Matrix3x3& v, const Matrix3x3& t)
{
	return Matrix3x3(
		t.mar[0] * v.mar[0] * t.mar[1] * v.mar[3] * t.mar[2] * v.mar[6],
		t.mar[0] * v.mar[1] * t.mar[1] * v.mar[4] * t.mar[2] * v.mar[7],
		t.mar[0] * v.mar[2] * t.mar[1] * v.mar[5] * t.mar[2] * v.mar[8],

		t.mar[3] * v.mar[0] * t.mar[4] * v.mar[3] * t.mar[5] * v.mar[6],
		t.mar[3] * v.mar[1] * t.mar[4] * v.mar[4] * t.mar[5] * v.mar[7],
		t.mar[3] * v.mar[2] * t.mar[4] * v.mar[5] * t.mar[5] * v.mar[8],

		t.mar[6] * v.mar[0] * t.mar[7] * v.mar[3] * t.mar[8] * v.mar[6],
		t.mar[6] * v.mar[1] * t.mar[7] * v.mar[4] * t.mar[8] * v.mar[7],
		t.mar[6] * v.mar[2] * t.mar[7] * v.mar[5] * t.mar[8] * v.mar[8]
	);
}

void Matrix3x3::transposeMar()
{
	float temp;
	temp = (*this).mar[1];
	(*this).mar[1] = (*this).mar[3];
	(*this).mar[3] = temp;

	temp = (*this).mar[2];
	(*this).mar[2] = (*this).mar[6];
	(*this).mar[6] = temp;

	temp = (*this).mar[5];
	(*this).mar[5] = (*this).mar[7];
	(*this).mar[7] = temp;
}

void Matrix3x3::IndentityMar()
{
	Matrix3x3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
}

Matrix3x3 ScaleMar3x3(float sx, float sy)
{
	return Matrix3x3(
		sx, 0, 0,
		0, sy, 0,
		0, 0, 1
	);
}

Matrix3x3 ReflectionMar3x3(float sx, float sy)
{
	return Matrix3x3(
		sx, 0, 0,
		0, sy, 0,
		0, 0, 1
	);
}

Matrix3x3 ShearMar3x3(float ax)
{
	return Matrix3x3(
		1, ax, 0,
		0, 1, 0,
		0, 0, 1
	);
}

Matrix3x3 RotateMar3x3(float angle)
{
	float rad = angle * PI / 180;
	return Matrix3x3(
		cos(rad), -sin(rad), 0,
		sin(rad), cos(rad), 0,
		0, 0, 1
	);
}

Matrix3x3 TranlateMar3x3(float ax, float ay)
{
	return Matrix3x3(
		1, 0, ax,
		0, 1, ay,
		0, 0, 1
	);
}