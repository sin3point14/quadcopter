#include <glad/glad.h>
#include <vector>
#include <memory>
#include "shader.h"

class Renderer {
    constexpr static float s_Vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    constexpr static unsigned int s_Indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    std::vector<std::unique_ptr<Shader>> m_Shaders;

    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;

public:
    Renderer();
    void render(double deltaTime);
};
