#pragma once
#ifndef DRAWSOMETHING_H
#define DRAWSOMETHING_H

#include "FrameBuffer.h"
#include "Mesh.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <tuple>

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

class DrawSomething
{
public:
    DrawSomething() = default;
    ~DrawSomething() = default;
    void DrawTriangles(FrameBuffer& framebuffer,const Vertex* v);
    void DrawImage(FrameBuffer& framebuffer, const Vertex* v);
    bool InTriangle(const Vertex* v, const Vector2D& t);  
    std::tuple<float,float,float> ComputBarycen(const Vertex* v, Vector3D& t) const;
};

#endif