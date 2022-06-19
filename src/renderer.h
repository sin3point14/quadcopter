#include <glad/glad.h>

class Renderer {
    constexpr static float s_Vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int m_ShaderProgram;
    unsigned int m_VAO;
    unsigned int m_VBO;

    void checkShader(unsigned int shader);
    void checkShaderProgram(unsigned int shaderProgram);

public:
    Renderer();
    void render();
};
