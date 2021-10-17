#include "Matrix4x4.h"
#include <cmath>
#define PI 3.141592653

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

std::ostream& operator<<(std::ostream& os, const Matrix4x4& v)
{
	os << v.mar[0] << " " << v.mar[1] << " " << v.mar[2] << " " << v.mar[3] << "\n"
		<< v.mar[4] << " " << v.mar[5] << " " << v.mar[6] << " " << v.mar[7] << "\n"
		<< v.mar[8] << " " << v.mar[9] << " " << v.mar[10] << " " << v.mar[11] << "\n"
		<< v.mar[12] << " " << v.mar[13] << " " << v.mar[14] << " " << v.mar[15];
	return os;
}

Matrix4x4::Matrix4x4()
{
	for (size_t i = 0; i < sizeof(mar) / sizeof(float); ++i)
	{
		mar[i] = 0;
	}
}

Matrix4x4::Matrix4x4(float e1, float e2, float e3, float e4,
	float e5, float e6, float e7, float e8,
	float e9, float e10, float e11, float e12,
	float e13, float e14, float e15, float e16)
{
	(*this).mar[0] = e1;
	(*this).mar[1] = e2;
	(*this).mar[2] = e3;
	(*this).mar[3] = e4;
	(*this).mar[4] = e5;
	(*this).mar[5] = e6;
	(*this).mar[6] = e7;
	(*this).mar[7] = e8;
	(*this).mar[8] = e9;
	(*this).mar[9] = e10;
	(*this).mar[10] = e11;
	(*this).mar[11] = e12;
	(*this).mar[12] = e13;
	(*this).mar[13] = e14;
	(*this).mar[14] = e15;
	(*this).mar[15] = e16;
}

Matrix4x4::Matrix4x4(const Matrix4x4& v)
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
	(*this).mar[9] = v.mar[9];
	(*this).mar[10] = v.mar[10];
	(*this).mar[11] = v.mar[11];
	(*this).mar[12] = v.mar[12];
	(*this).mar[13] = v.mar[13];
	(*this).mar[14] = v.mar[14];
	(*this).mar[15] = v.mar[15];
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& v)
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
	(*this).mar[9] = v.mar[9];
	(*this).mar[10] = v.mar[10];
	(*this).mar[11] = v.mar[11];
	(*this).mar[12] = v.mar[12];
	(*this).mar[13] = v.mar[13];
	(*this).mar[14] = v.mar[14];
	(*this).mar[15] = v.mar[15];
	return *this;
}

Matrix4x4 operator+(const Matrix4x4& v,const Matrix4x4& t)
{
	Matrix4x4 temp = v;
	temp += t;
	return temp;
}

Matrix4x4 operator*(const Matrix4x4& v,const float& t)
{
	Matrix4x4 temp = v;
	temp *= t;
	return temp;
}

Matrix4x4 operator-(const Matrix4x4& v, const Matrix4x4& t)
{
	Matrix4x4 temp = v;
	temp -= t;
	return temp;
}
Matrix4x4 operator*(const Matrix4x4& v, const Matrix4x4& t)
{
	return Matrix4x4(
		v.mar[0] * t.mar[0] + v.mar[1] * t.mar[4] + v.mar[2] * t.mar[8] + v.mar[3] * t.mar[12],
		v.mar[0] * t.mar[1] + v.mar[1] * t.mar[5] + v.mar[2] * t.mar[9] + v.mar[3] * t.mar[13],
		v.mar[0] * t.mar[2] + v.mar[1] * t.mar[6] + v.mar[2] * t.mar[10] + v.mar[3] * t.mar[14],
		v.mar[0] * t.mar[3] + v.mar[1] * t.mar[7] + v.mar[2] * t.mar[11] + v.mar[3] * t.mar[15],

		v.mar[4] * t.mar[0] + v.mar[5] * t.mar[4] + v.mar[6] * t.mar[8] + v.mar[7] * t.mar[12],
		v.mar[4] * t.mar[1] + v.mar[5] * t.mar[5] + v.mar[6] * t.mar[9] + v.mar[7] * t.mar[13],
		v.mar[4] * t.mar[2] + v.mar[5] * t.mar[6] + v.mar[6] * t.mar[10] + v.mar[7] * t.mar[14],
		v.mar[4] * t.mar[3] + v.mar[5] * t.mar[7] + v.mar[6] * t.mar[11] + v.mar[7] * t.mar[15],

		v.mar[8] * t.mar[0] + v.mar[9] * t.mar[4] + v.mar[10] * t.mar[8] + v.mar[11] * t.mar[12],
		v.mar[8] * t.mar[1] + v.mar[9] * t.mar[5] + v.mar[10] * t.mar[9] + v.mar[11] * t.mar[13],
		v.mar[8] * t.mar[2] + v.mar[9] * t.mar[6] + v.mar[10] * t.mar[10] + v.mar[11] * t.mar[14],
		v.mar[8] * t.mar[3] + v.mar[9] * t.mar[7] + v.mar[10] * t.mar[11] + v.mar[11] * t.mar[15],

		v.mar[12] * t.mar[0] + v.mar[13] * t.mar[4] + v.mar[14] * t.mar[8] + v.mar[15] * t.mar[12],
		v.mar[12] * t.mar[1] + v.mar[13] * t.mar[5] + v.mar[14] * t.mar[9] + v.mar[15] * t.mar[13],
		v.mar[12] * t.mar[2] + v.mar[13] * t.mar[6] + v.mar[14] * t.mar[10] + v.mar[15] * t.mar[14],
		v.mar[12] * t.mar[3] + v.mar[13] * t.mar[7] + v.mar[14] * t.mar[11] + v.mar[15] * t.mar[15]
	);
}


Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& v)
{
	(*this).mar[0] = (*this).mar[0] + v.mar[0];
	(*this).mar[1] = (*this).mar[1] + v.mar[1];
	(*this).mar[2] = (*this).mar[2] + v.mar[2];
	(*this).mar[3] = (*this).mar[3] + v.mar[3];
	(*this).mar[4] = (*this).mar[4] + v.mar[4];
	(*this).mar[5] = (*this).mar[5] + v.mar[5];
	(*this).mar[6] = (*this).mar[6] + v.mar[6];
	(*this).mar[7] = (*this).mar[7] + v.mar[7];
	(*this).mar[8] = (*this).mar[8] + v.mar[8];
	(*this).mar[9] = (*this).mar[9] + v.mar[9];
	(*this).mar[10] = (*this).mar[10] + v.mar[10];
	(*this).mar[11] = (*this).mar[11] + v.mar[11];
	(*this).mar[12] = (*this).mar[12] + v.mar[12];
	(*this).mar[13] = (*this).mar[13] + v.mar[13];
	(*this).mar[14] = (*this).mar[14] + v.mar[14];
	(*this).mar[15] = (*this).mar[15] + v.mar[15];
	return *this;
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& v)
{
	(*this).mar[0] = (*this).mar[0] - v.mar[0];
	(*this).mar[1] = (*this).mar[1] - v.mar[1];
	(*this).mar[2] = (*this).mar[2] - v.mar[2];
	(*this).mar[3] = (*this).mar[3] - v.mar[3];
	(*this).mar[4] = (*this).mar[4] - v.mar[4];
	(*this).mar[5] = (*this).mar[5] - v.mar[5];
	(*this).mar[6] = (*this).mar[6] - v.mar[6];
	(*this).mar[7] = (*this).mar[7] - v.mar[7];
	(*this).mar[8] = (*this).mar[8] - v.mar[8];
	(*this).mar[9] = (*this).mar[9] - v.mar[9];
	(*this).mar[10] = (*this).mar[10] - v.mar[10];
	(*this).mar[11] = (*this).mar[11] - v.mar[11];
	(*this).mar[12] = (*this).mar[12] - v.mar[12];
	(*this).mar[13] = (*this).mar[13] - v.mar[13];
	(*this).mar[14] = (*this).mar[14] - v.mar[14];
	(*this).mar[15] = (*this).mar[15] - v.mar[15];
	return *this;
}

Matrix4x4& Matrix4x4::operator*=(const float& t)
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
	(*this).mar[9] = (*this).mar[9] * t;
	(*this).mar[10] = (*this).mar[10] * t;
	(*this).mar[11] = (*this).mar[11] * t;
	(*this).mar[12] = (*this).mar[12] * t;
	(*this).mar[13] = (*this).mar[13] * t;
	(*this).mar[14] = (*this).mar[14] * t;
	(*this).mar[15] = (*this).mar[15] * t;
	return *this;
}

Vector4D Mar4x4Vec(const Matrix4x4& t, const Vector4D& v)
{
	Vector4D temp;
	temp =  Vector4D(
		t.mar[0] * v.x + t.mar[1] * v.y + t.mar[2] * v.z + t.mar[3] * v.w,
		t.mar[4] * v.x + t.mar[5] * v.y + t.mar[6] * v.z + t.mar[7] * v.w,
		t.mar[8] * v.x + t.mar[9] * v.y + t.mar[10] * v.z + t.mar[11] * v.w,
		t.mar[12] * v.x + t.mar[13] * v.y + t.mar[14] * v.z + t.mar[15] * v.w
	);

	return temp;
}

void Matrix4x4::IdentityMar4x4()
{
	(*this).mar[0] = 1;
	(*this).mar[5] = 1;
	(*this).mar[10] = 1;
	(*this).mar[15] = 1;
}

Matrix4x4& Matrix4x4::transposeMar4x4()
{
	float temp;
	temp = (*this).mar[1];
	(*this).mar[1] = (*this).mar[4];
	(*this).mar[4] = temp;

	temp = (*this).mar[2];
	(*this).mar[2] = (*this).mar[8];
	(*this).mar[8] = temp;

	temp = (*this).mar[3];
	(*this).mar[3] = (*this).mar[12];
	(*this).mar[12] = temp;

	temp = (*this).mar[6];
	(*this).mar[6] = (*this).mar[9];
	(*this).mar[9] = temp;

	temp = (*this).mar[7];
	(*this).mar[7] = (*this).mar[13];
	(*this).mar[13] = temp;

	temp = (*this).mar[11];
	(*this).mar[11] = (*this).mar[14];
	(*this).mar[14] = temp;

	return *this;
}

Matrix4x4 ScaleMar4x4(float sx, float sy, float sz)
{
	return Matrix4x4(
		sx, 0, 0, 0,
		0, sy, 0, 0,
		0, 0, sz, 0,
		0, 0, 0, 1
	);
}

Matrix4x4 TranslationMar4x4(float tx, float ty, float tz)
{
	return Matrix4x4(
		1, 0, 0, tx,
		0, 1, 0, ty,
		0, 0, 1, tz,
		0, 0, 0, 1
	);
}

Matrix4x4 RotateXMar4x4(float angle)
{
	float rad = angle * PI / 180.0;
	return Matrix4x4(
		1, 0, 0, 0,
		0, cos(rad), -sin(rad), 0,
		0, sin(rad), cos(rad), 0,
		0, 0, 0, 1
	);
}

Matrix4x4 RotateYMar4x4(float angle)
{
	float rad = angle * PI / 180.0;
	return Matrix4x4(
		cos(rad), 0, sin(rad), 0,
		0, 1, 0, 0,
		-sin(rad), 0, cos(rad), 0,
		0, 0, 0, 1
	);
}

Matrix4x4 RotateZMar4x4(float angle)
{
	float rad = angle * PI / 180.0f;
	return Matrix4x4(
		cos(rad), -sin(rad), 0, 0,
		sin(rad), cos(rad), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

Matrix4x4 OrthoMar4x4(float fov, float aspect, float nearDistance, float farDistance)
{
	float height = 2.0 * nearDistance * tan(PI * fov / (2.0 * 180));
	float width = aspect * height;

	Matrix4x4 OrthScale(
		static_cast<float>(2.0f / width), 0, 0, 0,

		0, static_cast<float>(2.0f / height), 0, 0,

		0, 0, static_cast<float>(2.0f / (nearDistance - farDistance)),0,

		0, 0, 0, 1
	);

	Matrix4x4 OrthTrans(
		1, 0, 0, 0,

		0, 1, 0, 0,

		0, 0, 1, -static_cast<float>((nearDistance + farDistance) / 2.0f),

		0, 0, 0, 1.0f
	);
	return OrthScale * OrthTrans;
}

Matrix4x4 ProjectMar4x4(float nearDistance, float farDistance)
{
	return Matrix4x4(
		nearDistance, 0, 0, 0,
		0, nearDistance, 0, 0,
		0, 0, nearDistance + farDistance, -nearDistance * farDistance,
		0, 0, 1, 0
	);
	
}

Matrix4x4 ViewportMar4x4(float width, float height)
{
	return Matrix4x4(
		width / 2.0f, 0, 0, width / 2.0,
		0, height / 2.0f, 0, height / 2.0f,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

Matrix4x4 CameraMar4x4(Vector3D& camPos)
{
	Vector3D CamDirection(-camPos.x, -camPos.y, -camPos.z);
	Vector3D up(0, 1, 0);
	Vector3D cameraX = crossProduct(CamDirection, up);
	Vector3D cameraY = crossProduct(cameraX, CamDirection);
	Schmidt(CamDirection, cameraX, cameraY);

	Matrix4x4 camCor{
		cameraX.x,cameraY.x,CamDirection.x,0,
		cameraX.y,cameraY.y,CamDirection.y,0,
		cameraX.z,cameraY.z,CamDirection.z,0,
		0,0,0,1
	};
	
	Matrix4x4 camTrans{
		1,0,0,-camPos.x,
		0,1,0,-camPos.y,
		0,0,1,-camPos.z,
		0,0,0,1
	};
	
	camCor.transposeMar4x4();
	
	Matrix4x4 finalMar;
	finalMar.IdentityMar4x4();
	finalMar = camCor * camTrans;
	return finalMar;
}

Matrix4x4 OPGLViewMar4x4(const int SCR_WIDTH, const int SCR_HEIGHT)
{
	return Matrix4x4(
		1.0f / (SCR_WIDTH / 2), 0.0f, -1.0f, 0.0f,
		0.0f, 1.0f / (SCR_HEIGHT / 2), -1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0, 0, 0, 0
	);
}



