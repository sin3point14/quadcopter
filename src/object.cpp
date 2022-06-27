#include "object.h"

Object::Object(const AnimatableModel& model, const std::vector<float>& vertices, const glm::vec3& baseColor, Shader::ShaderType shadertype)
	: m_Model(model)
	, m_Vertices(vertices)
	, m_BaseColor(baseColor)
	, m_ShaderType(shadertype)
{
	// VBO & VAO
	glGenBuffers(1, &m_VBO);
	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices[0]) * m_Vertices.size(), m_Vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
}

glm::mat4 Object::getModel(double time)
{
	if (glm::mat4* model = std::get_if<glm::mat4>(&m_Model))
	{
		return *model;
	}
	else
	{
		auto modelFunc = std::get<std::function<glm::mat4(double)>>(m_Model);
		return modelFunc(time);
	}
}
