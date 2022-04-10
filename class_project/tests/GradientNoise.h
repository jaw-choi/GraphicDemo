/*!
@file    ValueNoise.h
@author  Hyosang Jung, Jaewoo.choi
@date    04/04/2022

Note : This file contains the declaration Noise class member function
and this class inherited by Test, So it has all function what Test class have.
Also, there is a enum state for what is now demo showing.


*//*__________________________________________________________________________*/
#pragma once
#include"Test.h"
#include <GL/glew.h> 
#include"../glslshader.h"
#include"../Mesh.h"
class Gradient_Noise : public Test
{
public:
	Gradient_Noise();
	~Gradient_Noise();
	void init() override;
	void Update(float deltaTime)  override;
	void Draw() override;
	void OnImGuiRender() override;
	void UnLoad() override;
	void setup_shdrpgm(std::string shader);
	float lerp(float min, float max, float t);
	float smoothstep(const float& t);
	float cosinestep(const float& t);
	float quinticstep(const float& t);
	void generate_random_value();
	void setup_opengl();
	float evalute(glm::vec2 p);
	void generate_value_noise(float dt);
	Mesh create_gradient_plane(int stacks, int slices);
private:

	GLuint EBO;


	glm::mat4  view;
	glm::mat4  projection;
	glm::vec3 eye;
	//GLint modelLoc;
	//GLint viewLoc;
	//GLint   projectionLoc;


	unsigned int texture;

	static constexpr unsigned int stack = 30;
	static constexpr unsigned int slice = 30;
	static constexpr unsigned int size = 100;


	float frequency = 0.1f;
	float frequencyMult = 1.8;
	float amplitudeMult = 0.35;
	int numLayers = 5;

	float max = 1.f;
	float random_values[size][size];
	float data[stack+1][slice+1] = { 0 };

	float offset = 0.f;
	bool animated = false;

	Mesh plane;
};