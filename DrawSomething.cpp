#include "DrawSomething.h"
#include "Shader.h"
#include "Mesh.h"
#include <stdlib.h>
#include <iostream>

void DrawSomething::DrawTriangles(FrameBuffer& framebuffer, const Vertex* v)
{
	DrawImage(framebuffer, v);
}

void DrawSomething::DrawImage(FrameBuffer& framebuffer, const Vertex* v)
{
	Vector4D temp;
	int MAX_X = std::ceil(std::max(std::max(v[0].position.x, v[1].position.x), v[2].position.x));
	int MAX_Y = std::ceil(std::max(std::max(v[0].position.y, v[1].position.y), v[2].position.y));
	int MIN_X = std::floor(std::min(std::min(v[0].position.x, v[1].position.x), v[2].position.x));
	int MIN_Y = std::floor(std::min(std::min(v[0].position.y, v[1].position.y), v[2].position.y));

	for (int col = MIN_Y; col < MAX_Y; ++col)
	{
		for (int row = MIN_X; row < MAX_X; ++row)
		{
			if (InTriangle(v, Vector2D(row+0.5f, col+0.5f)))
			{
				Vector3D temp(row, col, 1.0f);
				std::tuple<float, float, float> item = ComputBarycen(v, temp);
				float alpha = std::get<0>(item);
				float beta = std::get<1>(item);
				float gamma = std::get<2>(item);

				float z_interploated = 1.0f / (alpha / v[0].position.z + beta / v[1].position.z + gamma / v[2].position.z);

				if (z_interploated <= framebuffer.getdepth_bufferValue(row, col))
				{
					Vertex inter_data;
					//inter_data.color = t.x * Color4D(255, 0, 0, 0) + t.y * Color4D(0, 255, 0, 0) + t.z * Color4D(0, 0, 255, 0);
					//inter_data.normal = t.x * v[0].normal + t.y * v[1].normal + t.z * v[2].normal;
					inter_data.texcoord = z_interploated * (alpha * v[0].texcoord / v[0].position.z + beta * v[1].texcoord / v[1].position.z + gamma * v[2].texcoord / v[2].position.z);
				
					framebuffer.WritePoint(row, col, FragmentShader(inter_data));
					framebuffer.depth_buffer[row + (col - 1) * SCR_WIDTH] = z_interploated;
				}


			}
		}

	}

	glDrawPixels(SCR_WIDTH, SCR_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, framebuffer.colorBuffer.data());
}

bool DrawSomething::InTriangle(const Vertex* v, const Vector2D& t)
{
	Vector3D A = Vector3D(v[0].position.x, v[0].position.y, 1.0f);
	Vector3D B = Vector3D(v[1].position.x, v[1].position.y, 1.0f);
	Vector3D C = Vector3D(v[2].position.x, v[2].position.y, 1.0f);
	Vector3D P = Vector3D(t.x, t.y, 1.0f);

	Vector3D PA = A - P;
	Vector3D PB = B - P;
	Vector3D PC = C - P;

	float a = PA.x * PB.y - PA.y * PB.x;
	float b = PB.x * PC.y - PB.y * PC.x;
	float c = PC.x * PA.y - PC.y * PA.x;

	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::tuple<float, float, float> DrawSomething::ComputBarycen(const Vertex* v, Vector3D& t) const
{
	Vector3D A(v[0].position.x, v[0].position.y, 1.0f),
		B(v[1].position.x, v[1].position.y, 1.0f),
		C(v[2].position.x, v[2].position.y, 1.0f),
		P(t.x, t.y, t.z);
	Vector3D AC = C - A;
	Vector3D AB = B - A;

	Vector3D PC = C - P;
	Vector3D PB = B - P;
	Vector3D PA = A - P;



	float s = crossProduct(AB, AC).getLength();

	float alpha = crossProduct(PB, PC).getLength() / s;
	float beta = crossProduct(PC, PA).getLength() / s;
	float gamma = crossProduct(PA, PB).getLength() / s;

	if (alpha > 0 && beta > 0 && gamma > 0)
	{
		return std::make_tuple(alpha, beta, gamma);
	}
	else
	{
		return std::make_tuple(0, 0, 0);
	}
}
