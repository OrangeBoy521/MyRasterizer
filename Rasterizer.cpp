#include "Header.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void DrawImagui();
void InitImagui(GLFWwindow* window);

extern TextureData texture("JPG/container.jpg");

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Window", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	//---

	std::vector<unsigned int> index = {
	0,1,2,
	1,2,3,

	1,3,4,
	1,4,5,

	4,5,7,
	5,6,7,

	0,1,5,
	0,5,6,

	2,3,4,
	2,4,7,

	0,2,7,
	0,6,7
	};

	Vertex vt[8] = {
	   {Vector4D(5.0f,5.0f,-5.0f,1.0f),   Color4D(255, 0, 0, 0),     Vector2D(0,0),  Vector3D(1,1,0)},//0
	   {Vector4D(5.0f,5.0f,5.0f,1.0f),    Color4D(0, 255, 0, 0),     Vector2D(1,0),  Vector3D(1,1,0)},//1
	   {Vector4D(5.0f,-5.0f,-5.0f,1.0f),  Color4D(0, 0, 255, 0),     Vector2D(0,1),  Vector3D(1,1,0)},//2
	   {Vector4D(5.0f,-5.0f,5.0f,1.0f),   Color4D(255, 255, 255, 0), Vector2D(1,1),  Vector3D(1,1,0)},//3

	   {Vector4D(-5.0f,-5.0f,5.0f,1.0f),  Color4D(255, 255, 255, 0), Vector2D(0,0),  Vector3D(1,1,0)},//4
	   {Vector4D(-5.0f,5.0f,5.0f,1.0f),   Color4D(255, 255, 255, 0), Vector2D(0,1),  Vector3D(1,1,0)},//5
	   {Vector4D(-5.0f,5.0f,-5.0f,1.0f),  Color4D(255, 255, 255, 0), Vector2D(1,1),  Vector3D(1,1,0)},//6
	   {Vector4D(-5.0f,-5.0f,-5.0f,1.0f), Color4D(255, 255, 255, 0), Vector2D(1,0),  Vector3D(1,1,0)},//7

	};

	const int vertexarray_size = sizeof(vt) / sizeof(Vertex);

	Mesh m(vertexarray_size, index);
	FrameBuffer framebuffer(SCR_WIDTH, SCR_HEIGHT);

	InitImagui(window);
	
	//---

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		//----

		for (int i = 0; i < vertexarray_size; ++i)
		{
			m.vertexInfo.push_back(VertexShader(vt[i]));
		}
	    
		m.DrawMesh(framebuffer);


		DrawImagui();
		//----

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	/*cam.processInputCam(window, deltaTime);*/
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}

void InitImagui(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void DrawImagui()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	{

		ImGui::Begin(" ");
		ImGui::Text("Delay: %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::SliderFloat("scaleX", &scaleX, 1.0f, 100.0f);
		ImGui::SliderFloat("scaleY", &scaleY, 1.0f, 100.0f);
		ImGui::SliderFloat("scaleZ", &scaleZ, 1.0f, 100.0f);
		ImGui::SliderFloat("RotateX", &RotateX, -180.0f, 180.0f);
		ImGui::SliderFloat("RotateY", &RotateY, -180.0f, 180.0f);
		ImGui::SliderFloat("RotateZ", &RotateZ, -180.0f, 180.0f);
		ImGui::SliderFloat("TransX", &TranX, -100.0f, 100.0f);
		ImGui::SliderFloat("TransY", &TranY, -100.0f, 100.0f);
		ImGui::SliderFloat("TransZ", &TranZ, -100.0f, 100.0f);
		ImGui::SliderFloat("fov", &fov, 1.0f, 90.0f);
		ImGui::SliderFloat("near", &nearDistance, 1.0f, 10.0f);
		ImGui::SliderFloat("far", &farDistance, 5.0f, 50.0f);

		ImGui::End();
	}

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
