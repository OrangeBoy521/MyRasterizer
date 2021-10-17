#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//--
#include <stdlib.h>
#include <string>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "Matrix4x4.h"
#include "Camera.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"


#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_glfw.h"
#include "Imgui/imgui_impl_opengl3.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
using std::cout;
using std::endl;

extern const unsigned int SCR_WIDTH = 1000;
extern const unsigned int SCR_HEIGHT = 1000;

extern float scaleX = 3.0f;
extern float scaleY = 3.0f;
extern float scaleZ = 3.0f;
extern float RotateX = 0.0f;
extern float RotateY = 0.0f;
extern float RotateZ = 0.0f;
extern float TranX = 0.0f;
extern float TranY = 0.0f;
extern float TranZ = 0.0f;
extern float fov = 120.0f;
extern float nearDistance = 10.0f;
extern float farDistance = 30.0f;
extern Vector3D camPos{ 0,0,20.0f };

#endif