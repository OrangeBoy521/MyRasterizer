#pragma once
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <vector>
#include "Vector4D.h"

class FrameBuffer
{
public:
	FrameBuffer() = default;
	FrameBuffer(const int& w, const int& h);
	~FrameBuffer() = default;

	void Resize(const int& w, const int& h);
	void ClearColorBuffer(const Color4D& color);
	void WritePoint(const int& x, const int& y, const Color4D& color);
	float getdepth_bufferValue(int x, int y) const;
	void ClearDepthBuffer();

public:
	int width = { 0 };
	int height = { 0 };
	std::vector<unsigned char> colorBuffer;
	std::vector<float> depth_buffer;
};
#endif