#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


int g_windowsSizeX = 640;
int g_windowsSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_windowsSizeX = width;
    g_windowsSizeY = height;

    glViewport(0, 0, g_windowsSizeX, g_windowsSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) // closes the application
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
        std::cout << "You closed the application pressing the 'Escape' key" << std::endl;
    }
}

int main(void)
{
    GLFWwindow* pWindow;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit failed!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(640, 480, "BATTLE CITY", nullptr, nullptr);
    if (!pWindow)
    {
        std::cout << "GLFW is not working" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Callbacks are here ---
    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);


    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL())
    {
        std::cout << "ERROR:CAN'T LOAD GLAD" << std::endl;
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "openGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

    
    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}