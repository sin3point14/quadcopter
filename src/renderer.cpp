#include <glad/glad.h>
#include <iostream>
#include <cstdlib>

#include "renderer.h"

Renderer::Renderer() 
{
	m_Shaders.emplace_back(std::make_unique<Shader>("shaders/main.vert", "shaders/main.frag"));

	// VBO & VAO
	glGenBuffers(1, &m_VBO);
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s_Vertices), s_Vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(s_Indices), s_Indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
}

void Renderer::render(double deltaTime)
{
	m_Shaders[0]->use();
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
