/*!
@file    Shadow.h
@author  Hyosang Jung, Jaewoo.choi
@date    05/19/2022

Note : This file contains the declaration Shadow_test class member function
and this class inherited by Test, So it has all function what Test class have.

*//*__________________________________________________________________________*/
#pragma once

#include"Test.h"
#include"../Mesh.h"
#include"../Camera.h"

class PointShadow : public Test
{
public:
	PointShadow();
	~PointShadow();
	void init() override;
	void Update(float deltaTime)  override;
	void Draw() override;
	void OnImGuiRender() override;
	void DepthMap_Setup();
	void Setup_shadowTransform();
	void MakeMeshes();
	void Setup_shdrpgm();

	void Depth_Draw();
	void Scene_Draw();

	
	void RenderScene(GLSLShader shader, glm::mat4 transform);
	const GLfloat bgColor[4] = { 0.0f, 0.6f, 0.0f, 1.0f };
	const GLfloat one = 1.0f;
	const Vec4 useNormal = Vec4(1, 1, 1, 1.0);

private:
	Camera camera;
	glm::mat4 projection;
	std::vector<Mesh> meshes;
	GLSLShader depth_shader;
	GLSLShader scene_shader;
	//for light
	std::vector<glm::mat4> shadowTransforms;
	glm::mat4 lightProjection;

	glm::vec3 light;
	float light_Fov;
	float light_near;
	float light_far;
	float polygonFactor;
	float polygonUnit;
	unsigned int SHADOW_WIDTH = 1024;
	unsigned int SHADOW_HEIGHT = 1024;
	unsigned int depthMapFBO;
	unsigned int depthCubemap;

};