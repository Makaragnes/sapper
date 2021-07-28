#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define mapW 10
#define mapH 10

typedef struct {

};

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

void initialize();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {

    initialize();

    GLFWwindow * glfWwindow = glfwCreateWindow
            (SCREEN_WIDTH,
            SCREEN_HEIGHT,
            "Sapper",
            NULL,
            NULL);

    if(glfWwindow == NULL){
        std::cout<<"Error window creating";
        return -1;
    }
    glfwMakeContextCurrent(glfWwindow);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"Error glad loader";
        return -1;
    }

    glfwSetFramebufferSizeCallback(glfWwindow, framebuffer_size_callback);

    while (!glfwWindowShouldClose(glfWwindow)){
        // User input
        //processInput(glfWwindow);
        // After it we rendering something here

        //clearColor();

        glfwSwapBuffers(glfWwindow);
        glfwPollEvents();
    }

    return 0;
}

void initialize(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width,height);
}

