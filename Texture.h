#pragma once

#include <string>

#include "stb_image.h"

class TextureData
{
public:
	TextureData() = default;
	TextureData(const TextureData&) = delete;
	TextureData& operator =(const TextureData&) = delete;
	~TextureData()
	{
		stbi_image_free(data);
	}
	TextureData(const std::string& filename)
	{
		data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
	}

	Vector3D getTextureRGB(float x, float y) const
	{
		x *= width;
		y *= height;

		x = std::ceil(x);
		y = std::ceil(y);
		int pos = ((y - 1) * width + x) * 3;

		auto R = data[pos];
		auto G = data[pos + 1];
		auto B = data[pos + 2];
		Vector3D textureColor(R, G, B);
		return textureColor;
	}

public:
	int width;
	int height;
	int nrChannels;
	unsigned char* data = nullptr;
};