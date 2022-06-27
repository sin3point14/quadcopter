#pragma once

#include <vector>
#include <memory>

#include "object.h"

class Scene {
	std::vector<std::unique_ptr<Object>> m_RootChildren;
	//std::vector<Object*> m_Cameras;
	glm::mat4 m_View;
	glm::mat4 m_Projection;

	const static std::vector<float> s_CubeVertices;

public:
	Scene();
	const glm::mat4& getProjection() { return m_Projection; }
	const glm::mat4& getView() { return m_View; }
	const std::vector<std::unique_ptr<Object>>& getRootChildren() { return m_RootChildren; }
};
