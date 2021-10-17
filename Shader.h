#pragma once
#ifndef SHADER_H
#define SHADER_H

#include "Vector4D.h"
#include "Mesh.h"
#include "Matrix4x4.h"

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

class Shader
{
public:
	Shader() = default;
	~Shader() = default;
	friend Vertex VertexShader(Vertex v);
    friend Vector4D& FragmentShader(const Vertex&);
	
};

Vertex VertexShader(Vertex);
Vector4D& FragmentShader(const Vertex&);
#endif