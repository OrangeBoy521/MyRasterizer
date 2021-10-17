#include "Mesh.h"
#include "DrawSomething.h"
#include <vector>
#include <iostream>

Mesh::Mesh(const int& vertexSize, const std::vector<unsigned int>& index)
{
	vertexIndex = index;
}

Mesh::Mesh(const Mesh& m)
{
	*this = m;
}

void Mesh::DrawMesh(FrameBuffer& framebuffer)
{
	DrawSomething draw;
	Vertex v[3];
	for (int i = 0; i < vertexIndex.size(); i += 3)
	{
		v[0] = vertexInfo[vertexIndex[i]];
		v[1] = vertexInfo[vertexIndex[i + 1]];
		v[2] = vertexInfo[vertexIndex[i + 2]];
		draw.DrawTriangles(framebuffer, v);
	}		
	ClearMesh();
	framebuffer.ClearDepthBuffer();
	framebuffer.ClearColorBuffer(Color4D(0.0f, 0.0f, 0.0f, 1.0f));
}

void Mesh::ClearMesh()
{
	vertexInfo.clear();
	//vertexIndex.clear();
	
}

Mesh& Mesh::operator+=(const Mesh& m)
{
	for (int i = 0; i < m.vertexInfo.size(); ++i)
	{
		vertexInfo.push_back(m.vertexInfo[i]);
	}

	for (int j = vertexIndex.size(); j < vertexIndex.size(); ++j)
	{
		vertexIndex.push_back(j);
	}
	return *this;
}

Mesh& Mesh::operator=(const Mesh& m)
{
	vertexInfo = m.vertexInfo;
	vertexIndex = m.vertexIndex;
	return *this;
}
