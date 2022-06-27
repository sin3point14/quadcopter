#pragma once

#include <glad/glad.h>
#include <string>

class Shader
{

    void checkShaderProgram(unsigned int shaderProgram);
    void checkShader(unsigned int shader);

    unsigned int m_ShaderProgram;

public:

    Shader(const char* vertexPath, const char* fragmentPath);
    void use() { glUseProgram(m_ShaderProgram); }
    //void setBool(const std::string& name, bool value) const;
    //void setInt(const std::string& name, int value) const;
    //void setFloat(const std::string& name, float value) const;
};