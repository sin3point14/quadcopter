#pragma once

#include <glad/glad.h>
#include <vector>
#include <memory>

#include "shader.h"
//#include "object.h"
#include "scene.h"

class Renderer {
private:

    std::vector<std::unique_ptr<Shader>> m_Shaders;

    Scene m_Scene;

    void draw(double time, const std::vector<std::unique_ptr<Object>>& objects, glm::mat4 currModel, Shader::ShaderType shader);


public:
    Renderer();
    void render(double time);
};
