#version 430 core
out vec4 FragColor;

uniform vec3 baseColor;

void main()
{
   FragColor = vec4(baseColor, 1.0f);
//   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
