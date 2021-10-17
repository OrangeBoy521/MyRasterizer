#pragma once
#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "FrameBuffer.h"

struct Vertex
{
	Vector4D position;
	Vector4D color;
	Vector2D texcoord;
	Vector3D normal;
};

struct Texture
{
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh
{
public:
	Mesh() = default;
	Mesh(std::vector<Vertex> vertices,std::vector<unsigned int> indices,std::vector<Texture> textures)
	{
		this->vertexInfo = vertices;
		this->vertexIndex = indices;
		this->textures = textures;
	}

	Mesh(const int& vertexSize, const std::vector<unsigned int>& index);
	Mesh(const Mesh& m);
	Mesh& operator=(const Mesh& m);
	~Mesh() = default;

	Mesh& operator+=(const Mesh& m);
	void DrawMesh(FrameBuffer& framebuffer);
	void ClearMesh();

public:
	std::vector<Vertex> vertexInfo;
	std::vector<unsigned int> vertexIndex;
	std::vector<Texture> textures;
};

#endif