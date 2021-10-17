//#include "Camera.h"
//
//Camera::Camera(float x, float y, float z, float f)
//{
//	camPos.x = x;
//	camPos.y = y;
//	camPos.y = y;
//	fov = f;
//}
//
//Matrix4x4 Camera::MartrixCam()
//{
//	Vector3D cameraTarget = Vector3D(0.0f, 0.0f, 0.0f);
//	Vector3D cameraDirection = camPos - cameraTarget;
//	cameraDirection.normalizeVec();
//	Vector3D camup(0.0f, 1.0f, 0.0f);
//	Vector3D camright = cameraDirection.crossProduct(camup).normalizeVec();
//	Matrix4x4 camLookAt(
//		camright.x, camright.y, camright.z, -camPos.x,
//		camup.x, camup.y, camup.z, -camPos.y,
//		cameraDirection.x, cameraDirection.y, cameraDirection.z, -camPos.z,
//		0.0f, 0.0f, 0.0f, 1.0f
//	);
//	return camLookAt;
//}
//
//void Camera::processInputCam(GLFWwindow* window,float deltaTime)
//{
//	Vector3D cameraFront(0.0f, 0.0f, -1.0f);
//	Vector3D cameraUp(0.0f, 1.0f, 0.0f);
//	Vector3D cameraRight = cameraFront.crossProduct(cameraUp).normalizeVec();
//	float cameraSpeed = 2.5f * deltaTime;
//	
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//	{
//		camPos += (cameraFront * cameraSpeed);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//	{
//		camPos -= (cameraFront * cameraSpeed);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//	{
//		camPos -= (cameraRight * cameraSpeed);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//	{
//		camPos += (cameraRight * cameraSpeed);
//	}
//
//}
//
//void Camera::processMouse(GLFWwindow* window, double xpos, double ypos)
//{
//
//}