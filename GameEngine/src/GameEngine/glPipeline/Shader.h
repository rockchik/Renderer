#pragma once

#include <fstream>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "GameEngine/CommonValues.h"

class Shader
{
public:
	Shader();

	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
	void CreateFromFiles(const char* vertexLocation, const char* geometryLocation, const char* fragmentLocation);

	void Validate();

	std::string ReadFile(const char* fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetShininessLocation();
	GLuint GetEyePositionLocation();
	GLuint GetFarPlaneLocation();
	GLuint GetSkyboxLocation();

	void SetTexture(GLuint textureUnit);

	void UseShader();
	void ClearShader();

	~Shader();

private:

	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess, 
		uniformTexture, uniformFarPlane, skybox;
	

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void CompileShader(const char* vertexCode, const char* geometryCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);

	void CompileProgram();
};

