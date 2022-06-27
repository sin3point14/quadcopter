#include <glad/glad.h>
#include <iostream>
#include <cstdlib>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "renderer.h"

Renderer::Renderer()
{
	m_Shaders.emplace_back(std::make_unique<Shader>("shaders/main.vert", "shaders/main.frag"));

	for (auto&& shader : m_Shaders) {
		shader->use();
		shader->setMat4("projection", m_Scene.getProjection());
		shader->setMat4("view", m_Scene.getView());
	}
}

void Renderer::draw(double time, const std::vector<std::unique_ptr<Object>>& objects, glm::mat4 prevModel, Shader::ShaderType shader)
{
	for (auto&& object : objects)
	{
		if (object->getShaderType() == shader)
		{
			glm::mat4 currModel = object->getModel() * prevModel;
			m_Shaders[(int)shader]->setMat4("model", currModel);

			glBindVertexArray(object->getVAO());
			glDrawArrays(GL_TRIANGLES, 0, object->getVertexCount());
			draw(time, object->getChildren(), currModel, shader);
		}
	}
}

void Renderer::render(double time)
{
	m_Shaders[(int)Shader::ShaderType::NORMAL]->use();
	glm::mat4 identity = glm::identity<glm::mat4>();
	draw(time, m_Scene.getRootChildren(), identity, Shader::ShaderType::NORMAL);
	glBindVertexArray(0);
}
