#pragma once
#ifndef DRAW_H
#define DRAW_H

#include <memory.h>
#include "Vector3D.h"
#include "Shader.h"
using ShaderMethod::VertexShader;

template <typename T> class Vector3D;
 
template <typename T>
class Draw
{
	 template<typename T> friend void writeMesh(std::vector<int>&, Draw<T>&);
public:
	Draw() = default;
	Draw(const Draw&) = delete;
	Draw& operator=(const Draw&) = delete;
	~Draw() = default;

private:
	std::shared_ptr<std::vector<T>> meshData = std::make_shared<std::vector<T>>();
	std::shared_ptr<unsigned int[600][800 * 4]> pixelData = std::make_shared<unsigned int[600][800 * 4]>(0);
};

template <typename T>
void writeMesh(std::vector<int>& points,Draw<T>& w)
{
	std::vector<int>::iterator beg = points.begin();
	std::vector<int>::const_iterator last = points.cend();
    while (!points.empty() && (beg != last))
    {
		(*(w.meshData)).push_back(*beg);
		++beg;
    }
	VertexShader<T>(w);
	DrawTriangles(w);
}

template <typename T>
void DrawTriangles(const Draw<T>& w)
{
	T minX = std::min(std::min((*(w.meshData))[0], (*(w.meshData))[3]), (*(w.meshData))[6]);
	T maxX = std::max(std::max((*(w.meshData))[0], (*(w.meshData))[3]), (*(w.meshData))[6]);
	T minY = std::min(std::min((*(w.meshData))[1], (*(w.meshData))[4]), (*(w.meshData))[7]);
	T maxY = std::max(std::max((*(w.meshData))[1], (*(w.meshData))[4]), (*(w.meshData))[7]);

	minX = std::floor(static_cast<float>(minX));
	maxX = std::ceil(static_cast<float>(maxX));

	minY = std::floor(static_cast<float>(minY));
	maxY = std::ceil(static_cast<float>(maxY));

	for (float col = minY; col <= maxY; ++col)
	{
		for (float row = minX; row <= maxX; ++row)
		{
			if (IsInTriangle(row,col,w))
			{
				int row1 = static_cast<int>(row);
				int col1 = static_cast<int>(col);
				 (w.pixelData) [col1][row1 * 4] = 255;
				 (w.pixelData)[col1][row1 * 4 + 1] = 0;
				 (w.pixelData)[col1][row1 * 4 + 2] = 0;
				 (w.pixelData)[col1][row1 * 4 + 3] = 0;
			}
		}
	}
}

template <typename T>
bool IsInTriangle(float x,float y,Draw<T>& w)
{
	Vector3D<T> A(*(w.meshData)[0], *(w.meshData)[1], *(w.meshData)[2]);
	Vector3D<T> B(*(w.meshData)[3], *(w.meshData)[4], *(w.meshData)[5]);
	Vector3D<T> C(*(w.meshData)[6], *(w.meshData)[7], *(w.meshData)[8]);

	Vector3D<T> P(x, y, 0);

	Vector3D<T> PA = A - P;
	Vector3D<T> PB = B - P;
	Vector3D<T> PC = C - P;

	return static_cast<int>(PA.x * PB.y - PA.y * PB.x) >> 31 ^
		static_cast<int>(PB.x * PC.y - PB.y * PC.x) >> 31 ^
		static_cast<int>(PC.x * PA.y - PC.y * PA.x) >> 31;
}

#endif