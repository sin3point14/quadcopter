#pragma once

#include <glad/glad.h>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    enum class ShaderType {
        NORMAL = 0,
        //ENV,
        END
    };

private:
    void checkShaderProgram(unsigned int shaderProgram);
    void checkShader(unsigned int shader);

    unsigned int m_ShaderProgram;

public:

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() { glUseProgram(m_ShaderProgram); }
    void setBool(const std::string& name, bool value) const { glUniform1i(glGetUniformLocation(m_ShaderProgram, name.c_str()), (int)value); }
    void setInt(const std::string& name, int value) const { glUniform1i(glGetUniformLocation(m_ShaderProgram, name.c_str()), value); }
    void setFloat(const std::string& name, float value) const { glUniform1f(glGetUniformLocation(m_ShaderProgram, name.c_str()), value); }
    void setMat4(const std::string& name, const glm::mat4& matrix) const;
};
