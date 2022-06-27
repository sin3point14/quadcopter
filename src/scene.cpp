#include "scene.h"

const std::vector<float> Scene::s_CubeVertices = {
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};

Scene::Scene() 
{
	m_View = glm::mat4(1.0f);
	m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f));

	m_Projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    const float R = 3.0f;
    glm::mat4 model = glm::identity<glm::mat4>();
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -20.0f));

    m_RootChildren.emplace_back(std::make_unique<Object>(model, s_CubeVertices, glm::vec3(0.3f, 0.3f, 0.3f)));

	m_RootChildren.emplace_back(std::make_unique<Object>([](double time) -> glm::mat4 {
        const float R = 3.0f;
        glm::mat4 model1 = glm::identity<glm::mat4>();
        model1 = glm::translate(model1, glm::vec3(0.0f, 0.0f, -20.0f));
        model1 = glm::translate(model1, glm::vec3(R * cos(glm::radians((float)time * 50.0f)), 0.0f, 0.0f));
        model1 = glm::translate(model1, glm::vec3(0.0f, R * sin(glm::radians((float)time * 50.0f)), 0.0f));
        return model1;
        }, s_CubeVertices, glm::vec3(0.8f, 0.2f, 0.2f)));

    Object* cube1 = m_RootChildren[0].get();
    cube1->addChild([](double time) -> glm::mat4 {
        glm::mat4 model2 = glm::identity<glm::mat4>();
        model2 = glm::rotate(model2, glm::radians((float)time * 50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model2 = glm::translate(model2, glm::vec3(-5.0f, 0.0f, 0.0f));
        return model2;
        }, s_CubeVertices, {0.2f, 0.8f, 0.2f});

    Object* cube2 = cube1->getChild(0);
    cube2->addChild([](double time) -> glm::mat4 {
        glm::mat4 model3 = glm::identity<glm::mat4>();
        model3 = glm::rotate(model3, glm::radians((float)time * 200.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        model3 = glm::translate(model3, glm::vec3(-3.0f, 0.0f, 0.0f));
        return model3;
        }, s_CubeVertices, {0.2f, 0.2f, 0.8f});
}
