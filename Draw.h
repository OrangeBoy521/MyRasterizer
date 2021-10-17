#pragma once
#ifndef DRAW_H
#define DRAW_H

template <typename T>
class Draw
{
	Draw() = default;
	Draw(const Draw&) = delete;
	Draw& operator=(const Draw&) = delete;
	~Draw() = default;

private:
	std::shared_ptr<std::vector<T>> meshData = nullptr;
	std::shared_ptr<std::vector<T>> pixelData = nullptr;
};

void DrawTriangles()
{
	
}

#endif