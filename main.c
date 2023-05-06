#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

#include "gfx/shader.h"
#include "gfx/buffer.h"
#include "gfx/mesh.h"

#include "math/vec3.h"
#include "math/mat4.h"

#include "util/logging.h"

/* -----------------------------------------------------------------------------
  Useful Constants.
------------------------------------------------------------------------------*/
float c = 0.0;
const float WIDTH  = 800.0;
const float HEIGHT = 600.0;


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
    window = glfwCreateWindow(WIDTH, HEIGHT, "app", NULL, NULL);
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
    OrthoProjection proj = {
        .top = 0,
        .bottom = HEIGHT,
        .left = 0,
        .right = WIDTH,
        .near = 0.0001,
        .far = 1000.0
    };


    LOG("Creating Orthographic Projection Matrix");
    Mat4 orthoProj = Mat4OrthoProjection(&proj);

    LOG("Creating Position Vector");
    Vec3 v = Vec3Create(0,0,0);
    Vec3 pos = Vec3Create(0,0,0);

    Mat4 viewMatrix = Mat4LookAt((Vec3){0,0,-3}, pos, (Vec3){0,1,0});

    LOG("Creating Model Identity Matrix");
    Mat4 modelMatrix = Mat4Identity();

    LOG("Sending Model Matrix Uniform");
    gfxShaderSendUniformMat4(&shader, &modelMatrix, "model");


    LOG("Sending View Matrix Uniform");
    gfxShaderSendUniformMat4(&shader, &viewMatrix, "view");


    LOG("Sending Projection Matrix Uniform");
    gfxShaderSendUniformMat4(&shader, &orthoProj, "projection");


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        c += 0.1;
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2, 0.2, 0.2, sin(c));

        glUseProgram(shader.program);
        
        pos.x = cos(c);
        pos.y = sin(c);
        Mat4Translate(&modelMatrix, pos);

        viewMatrix = Mat4LookAt(
            (Vec3){0,0,0},
            (Vec3){0,0,0} ,
            (Vec3){0,1,0}
        );
        
        Mat4Print(orthoProj);

        gfxShaderSendUniformMat4(&shader, &modelMatrix, "model");
        gfxShaderSendUniformMat4(&shader, &viewMatrix,  "view");
        gfxShaderSendUniformMat4(&shader, &orthoProj,   "projection");
    

        glBindBuffer(buffer.bufferType, buffer.vbo);

        glDrawElements(
          GL_TRIANGLES,
          mesh.quad_index_count,
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

