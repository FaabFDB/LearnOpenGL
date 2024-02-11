#include "WinMain.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float vertices[] = {
	-0.5f,-0.5f, 0.0f, // X1,Y1,Z1
	 0.5f,-0.5f, 0.0f, // X2,Y2,Z2
	 0.0f, 0.5f, 0.0f  // X3,Y3,Z3
};

const char *vertexShaderSource = "#version 330 core\n"
								 "layout (location = 0) in vec3 aPos;\n" // the position variable has attribute position 0
								 "void main()\n"
								 "{\n"
								 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" // see how we directly give a vec3 to vec4's constructor
								 "}\0";

const char* fragmentShaderSource = "#version 330 core\n"
								 "out vec4 FragColor;\n"
								 "void main()\n"
								 "{\n"
								 "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
								 "}\n\0";

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::cout << "Creating Window" << std::endl;
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Create OpenGL viewport
	std::cout << "Creating OpenGL viewport" << std::endl;
	glViewport(0,0, SCR_WIDTH, SCR_HEIGHT);

	// Register callback functions
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	unsigned int VBO, VAO, EBO; // Vertex Buffer Object
	glGenBuffers(1, &VBO); // Generate 1 buffer, store ID in VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	
	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		// Input
		// -----
		processInput(window);

		// Render
		// ------
		// Clear the screen
		// glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // State-setting function
		glClear(GL_COLOR_BUFFER_BIT); // State-using function

		

		// Swap buffers and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	std::cout << "Closing Window" << std::endl;
	glfwTerminate();
	return 0;
}

//glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

