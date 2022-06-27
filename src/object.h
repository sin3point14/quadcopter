#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <memory>
#include <glad/glad.h>

#include "shader.h"

class Object {
	Shader::ShaderType m_ShaderType;
	glm::mat4 m_Model;
	std::vector<float> m_Vertices;
	std::vector<std::unique_ptr<Object>> m_Children;
	unsigned int m_VAO;
	unsigned int m_VBO;
public:
	Object(const glm::mat4& model, const std::vector<float>& vertices, Shader::ShaderType shadertype = Shader::ShaderType::NORMAL);

	void addChild(const glm::mat4& model, const std::vector<float>& vertices, Shader::ShaderType shadertype = Shader::ShaderType::NORMAL) { m_Children.emplace_back(std::make_unique<Object>(model, vertices)); }
	Object* getChild(int index) { return index < m_Children.size() ? m_Children[index].get() : nullptr; }
	const std::vector<std::unique_ptr<Object>>& getChildren() { return m_Children; }
	Shader::ShaderType getShaderType() { return m_ShaderType; }
	const glm::mat4& getModel() { return m_Model; }
	const unsigned int getVAO() { return m_VAO; }
	const unsigned int getVertexCount() { return m_Vertices.size() / 3; }
};
