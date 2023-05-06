#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

#include "gfx/shader.h"
#include "gfx/buffer.h"
#include "gfx/mesh.h"

float c = 0.0;

#if MNR_DEBUG == 1
#define LOG(x) (printf("LOG: %s \n", x))
#else
#define LOG(x)
#endif

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    // Set OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "app", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    // ------------------------------------------------------------
    // SIMPLE TEST OPENGL SETUP

    Mesh mesh = CreateMeshFactory();

    Shader shader = gfxShaderCreate("../res/default-vsh.glsl", "../res/default-fsh.glsl");

    Buffer buffer = CreateGLBuffer(
            mesh.quad_verticies, 
            mesh.quad_vertex_count,
            mesh.quad_indicies,
            mesh.quad_index_count
            );

        
    // End of GL Setup
    // ------------------------------------------------------------

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        c += 0.1;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2, 0.2, 0.2, sin(c));

        glUseProgram(shader.program);

        glBindBuffer( buffer.bufferType, buffer.vbo);


        gfxShaderUniform3f("test", sin(c), cos(c), tan(c), &shader);

        glDrawElements(
          GL_TRIANGLES,
          buffer.idx_count,
          GL_UNSIGNED_INT,
          (void*)0
        );

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

