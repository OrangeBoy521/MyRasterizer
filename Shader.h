

template <typename T> class Draw;
template <typename T> class Vector3D;

extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

namespace ShaderMethod {

#include "Matrix4x4.h"
#include "Vector3D.h"
	template <typename T>
	void VertexShader(Draw<T>& w)
	{
		Matrix4x4<T> finalMatrix = ViewportMat4x4<T>(SCR_WIDTH, SCR_HEIGHT) *
			OrthoMatrix4x4<T>(60.0f, SCR_WIDTH / SCR_HEIGHT, 1) * ProjectionMat4x4<T>(1, 10);
		std::vector<int>::iterator beg = *(w.meshData).begin();
		std::vector<int>::iterator start = beg;
		std::vector<int>::const_iterator last = *(w.meshData).end();
		while (beg != last)
		{
			Vector3D<T> temp(*beg, *(++beg), *(++beg));
			toVector4(temp);
			temp = Matrix4x4Vec4(finalMatrix, temp);
			*start = temp.x;
			*(++start) = temp.y;
			*(++start) = temp.z;
		}

	};

	
}
