#include "FrameBuffer.h"
#include <iostream>
extern const unsigned int SCR_WIDTH;
extern const  unsigned int SCR_HEIGHT;

FrameBuffer::FrameBuffer(const int& w = 800, const int& h = 600)
{
	width = w;
	height = h;
	colorBuffer.resize(w * h * 4);
	depth_buffer.assign(w * h, FLT_MAX);
}

void FrameBuffer::Resize(const int& w, const int& h)
{
	width = w;
	height = h;
	colorBuffer.resize(w * h * 4);
	depth_buffer.assign(w * h, FLT_MAX);
}

void FrameBuffer::ClearColorBuffer(const Color4D& color)
{
	unsigned char* p = colorBuffer.data();
	for (int i = 0;i < width*height*4; i+=4)
	{
		*(p + i) = color.x;
		*(p + i + 1) = color.y;
		*(p + i + 2) = color.z;
		*(p + i + 3) = color.w;
	}
}

void FrameBuffer::WritePoint(const int& x, const int& y, const Color4D& color)
{
	if (x < 0 || y < 0 || x > width || y > height)
	{
		return;
	}
	int pos =  y* SCR_WIDTH + x;
	colorBuffer[pos * 4] = color.x;
	colorBuffer[pos * 4 + 1] = color.y;
	colorBuffer[pos * 4 + 2] = color.z;
	colorBuffer[pos * 4 + 3] = color.w;
}

float FrameBuffer::getdepth_bufferValue(int x, int y) const
{
	return depth_buffer[x + (y-1) * SCR_WIDTH];
}

void FrameBuffer::ClearDepthBuffer()
{
	depth_buffer.assign(SCR_WIDTH * SCR_HEIGHT, FLT_MAX);
}
