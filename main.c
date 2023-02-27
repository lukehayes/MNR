#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

#include "gfx/shader.h"

#include "math/vec3.h"
#include "math/mat4.h"

/* -----------------------------------------------------------------------------
  Useful Constants.
------------------------------------------------------------------------------*/
float c = 0.0;
const float WIDTH  = 800.0;
const float HEIGHT = 600.0;

/* -----------------------------------------------------------------------------
  Macros
------------------------------------------------------------------------------*/
#if DEV_DEBUG == 1
#define LOG(x) (printf("LOG: %s \n", x))
#else
#define LOG(x)
#endif


float* Mat4ArrayFromValues(Mat4 m, float matrixArray[16])
{
    matrixArray[0] =  m.m0;
    matrixArray[1] =  m.m1;
    matrixArray[2] =  m.m2;
    matrixArray[3] =  m.m3;

    matrixArray[4] =  m.m4;
    matrixArray[5] =  m.m5;
    matrixArray[6] =  m.m6;
    matrixArray[7] =  m.m7;

    matrixArray[8] =  m.m8;
    matrixArray[9] =  m.m9;
    matrixArray[10] =  m.m10;
    matrixArray[11] =  m.m11;

    matrixArray[12] =  m.m12;
    matrixArray[13] =  m.m13;
    matrixArray[14] =  m.m14;
    matrixArray[15] =  m.m15;

    return matrixArray;
}



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

    float modelMatArray[16];
    Mat4ArrayFromValues(modelMatrix, modelMatArray);

    LOG("Sending Model Matrix Uniform");
    GLuint modelLoc = glGetUniformLocation(shader.program,"model");
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, 
                      modelMatArray);

    float viewMatArray[16];
    Mat4ArrayFromValues(viewMatrix, viewMatArray);

    LOG("Sending View Matrix Uniform");
    GLuint viewLoc = glGetUniformLocation(shader.program,"view");
    glUniformMatrix4fv(viewLoc, 1, GL_TRUE, 
                      viewMatArray);

    float projMatArray[16];
    Mat4ArrayFromValues(orthoProj, projMatArray);

    LOG("Sending Projection Matrix Uniform");
    GLuint projectionLoc = glGetUniformLocation(shader.program,"projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, 
                      projMatArray);


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
        
        // Mat4Print(orthoProj);

    
    float modelMatArray[16];
    Mat4ArrayFromValues(modelMatrix, modelMatArray);

    GLuint modelLoc = glGetUniformLocation(shader.program,"model");
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, 
                      modelMatArray);

    float viewMatArray[16];
    Mat4ArrayFromValues(viewMatrix, viewMatArray);

    GLuint viewLoc = glGetUniformLocation(shader.program,"view");
    glUniformMatrix4fv(viewLoc, 1, GL_TRUE, 
                      viewMatArray);

    float projMatArray[16];
    Mat4ArrayFromValues(orthoProj, projMatArray);

    GLuint projectionLoc = glGetUniformLocation(shader.program,"projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, 
                      projMatArray);





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

