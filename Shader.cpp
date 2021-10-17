#include "Shader.h"
#include "Matrix4x4.h"
#include "Texture.h"
#include "Mesh.h"

extern float scaleX;
extern float scaleY;
extern float scaleZ;
extern float RotateX;
extern float RotateY;
extern float RotateZ;
extern float TranX;
extern float TranY;
extern float TranZ;
extern float fov;
extern float nearDistance;
extern float farDistance;
extern Vector3D camPos;

extern TextureData texture;

Vertex VertexShader(Vertex v)
{
	Vertex tempVer = v;
	Matrix4x4 finalMar_temp =  CameraMar4x4(camPos) * TranslationMar4x4(TranX, TranY, TranZ)
		* RotateXMar4x4(RotateX) * RotateYMar4x4(RotateY)
		* RotateZMar4x4(RotateZ);

	v.position = Mar4x4Vec(finalMar_temp, v.position);

	Matrix4x4 finalMar = ViewportMar4x4(SCR_WIDTH, SCR_HEIGHT) * OrthoMar4x4(fov, SCR_WIDTH / SCR_HEIGHT, nearDistance, farDistance)
		* ProjectMar4x4(nearDistance, farDistance) * CameraMar4x4(camPos) * TranslationMar4x4(TranX,TranY,TranZ) 
		 * RotateXMar4x4(RotateX) * RotateYMar4x4(RotateY)
		* RotateZMar4x4(RotateZ);	

	tempVer.position = Mar4x4Vec(finalMar,tempVer.position);
	tempVer.position.normalizeVec4();
	tempVer.position.z = v.position.z;
	return tempVer;
	
}

Vector4D& FragmentShader(const Vertex& inter_data)
{
	Vector3D temp(texture.getTextureRGB(inter_data.texcoord.x, inter_data.texcoord.y));
	Vector4D tem(temp.x, temp.y, temp.z, 0.0f);
	return tem;
}


