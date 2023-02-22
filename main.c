#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

#include "gfx/shader.h"

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
    float verticies[] = {
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f   
    };

    int indicies[] = {
        0,1,3,
        1,2,3
    };

    GLuint vao;
    GLuint vbo;
    GLuint ibo;

    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );
    
    // VERTEX BUFFER
    glGenBuffers( 1, &vbo);
    glBindBuffer( GL_ARRAY_BUFFER, vbo);


    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(float) * 12 , verticies, GL_STATIC_DRAW );


    Shader shader = gfxShaderCreate("../res/default-vsh.glsl", "../res/default-fsh.glsl");

    // INDEX BUFFER
    glGenBuffers( 1, &ibo );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ibo );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * 6 , indicies, GL_STATIC_DRAW );
        
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

        glBindBuffer( GL_ARRAY_BUFFER, vbo);

        glDrawElements(
          GL_TRIANGLES,
          6,
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

