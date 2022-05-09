#version 450 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 nrm;

layout (location=1) out vec3 NRM;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 FragPos;
out vec4 vColor;

void main(void) 
{
    gl_Position = projection * view * model * vec4(pos, 1.0);

    FragPos = vec3(model * vec4(pos, 1.0));

    NRM = mat3(transpose(inverse(model))) * nrm;

    vColor = vec4(abs(nrm),1.0);
}

