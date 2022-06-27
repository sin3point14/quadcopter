#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <memory>
#include <functional>
#include <variant>
#include <glad/glad.h>

#include "shader.h"

class Object {
	using AnimatableModel = std::variant<std::function<glm::mat4(double)>, glm::mat4>;
	Shader::ShaderType m_ShaderType;
	AnimatableModel m_Model;
	std::vector<float> m_Vertices;
	std::vector<std::unique_ptr<Object>> m_Children;
	glm::vec3 m_BaseColor;
	unsigned int m_VAO;
	unsigned int m_VBO;
public:
	Object(const AnimatableModel& model, const std::vector<float>& vertices, const glm::vec3& baseColor = {1.0f, 1.0f, 0.0f}, Shader::ShaderType shadertype = Shader::ShaderType::NORMAL);

	void addChild(const AnimatableModel& model, const std::vector<float>& vertices, const glm::vec3& baseColor = { 1.0f, 1.0f, 0.0f }, Shader::ShaderType shadertype = Shader::ShaderType::NORMAL) { m_Children.emplace_back(std::make_unique<Object>(model, vertices, baseColor, shadertype)); }
	Object* getChild(int index) { return index < m_Children.size() ? m_Children[index].get() : nullptr; }
	const std::vector<std::unique_ptr<Object>>& getChildren() { return m_Children; }
	Shader::ShaderType getShaderType() { return m_ShaderType; }
	glm::mat4 getModel(double time);
	const unsigned int getVAO() { return m_VAO; }
	const unsigned int getVertexCount() { return m_Vertices.size() / 3; }
	const glm::vec3& getBaseColor() { return m_BaseColor; };
};
