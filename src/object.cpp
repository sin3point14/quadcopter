#include "object.h"

Object::Object(const glm::mat4& model, const std::vector<float>& vertices, Shader::ShaderType shadertype)
	: m_Model(model)
	, m_Vertices(vertices)
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
