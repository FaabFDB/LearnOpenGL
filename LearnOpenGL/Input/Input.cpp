#include "Input.h"

// Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window)
{

	// Close window on escape key
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		std::cout << "Escape key pressed" << std::endl;
		glfwSetWindowShouldClose(window, true);
	}
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		std::cout << "W key pressed" << std::endl;
		glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		std::cout << "A key pressed" << std::endl;
		glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		std::cout << "S key pressed" << std::endl;
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	}

	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		std::cout << "D key pressed" << std::endl;
		glClearColor(0.0f, 0.3f, 0.0f, 1.0f);
	}

}
