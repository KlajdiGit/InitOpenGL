#include "Mesh.h"
#include "Shader.h"

vector<Mesh> Mesh::Lights;

Mesh::Mesh()
{
	m_shader = nullptr;
	m_texture = { };
	m_texture2 = { };
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_position = { 0, 0, 0 };
	m_rotation = { 0, 0, 0 };
	m_scale = { 1, 1, 1 };
	m_world = glm::mat4();
	m_cameraPosition = { 0, 0, 0 };
	m_lightPosition = { 0, 0, 0 };
	m_lightColor = { 1, 1, 1 };
}

Mesh::~Mesh()
{
}

void Mesh::Create(Shader* _shader)
{
	m_shader = _shader;

	m_texture = Texture();
	m_texture.LoadTexture("../Assets/Textures/MetalFrameWood.jpg");

	m_texture2 = Texture();	
	m_texture2.LoadTexture("../Assets/Textures/MetalFrame.jpg");

#pragma region VertexData

	m_vertexData = { 
		/* Position */ /* Normals */ /* Texture Coords	*/
	   -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
	   -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
	   -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
	
	   -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
	   -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	   -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		
	   -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	   -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	   -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	   -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	   -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	   -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		
	   -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	   -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
	   -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		
	   -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	   -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	   -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
	};
#pragma endregion

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

	/*m_indexData = {
		2, 0, 3, 2, 1, 0
	};
	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexData.size() * sizeof(GLubyte), m_indexData.data(), GL_STATIC_DRAW);*/

}

string Mesh::Concat(string _s1, int _index, string _s2)
{
	string index = to_string(_index);
	return (_s1 + index + _s2);
}

void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_indexBuffer);
	glDeleteBuffers(1, &m_vertexBuffer);
	m_texture.Cleanup();
	m_texture2.Cleanup();
}

void Mesh::BindAttributes()
{
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(m_shader->GetAttrVertices(), // The attribute we want to configure
		3,                   // size (3 vertices per primitive)
		GL_FLOAT,            // type 
		GL_FALSE,            // normalized?
		8 * sizeof(float),   // stride (8 floats per vertex definition)
		(void*)0);           // array buffer offset 
	

	// 2nd attribute buffer : normals
	glEnableVertexAttribArray(m_shader->GetAttrNormals());
	glVertexAttribPointer(m_shader->GetAttrNormals(), // The attribute we want to configure
		3,                   // size ( 3 components per color value)
		GL_FLOAT,            // type 
		GL_FALSE,            // normalized?
		8 * sizeof(float),   // stride (8 floats per vertex definition)
		(void*) (3 * sizeof(float)));           // array buffer offset 
	
	// 3rd  attribute buffer : texCoords
	glEnableVertexAttribArray(m_shader->GetAttrTexCoords());
	glVertexAttribPointer(m_shader->GetAttrTexCoords(), // The attribute we want to configure
		2,                   // size ( 2 components per color value)
		GL_FLOAT,            // type 
		GL_FALSE,            // normalized?
		8 * sizeof(float),   // stride (8 floats per vertex definition)
		(void*)(6 * sizeof(float)));           // array buffer offset 


	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); //Bind the vertex buffer

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture.GetTexture());
	glUniform1i(m_shader->GetSampler1(), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_texture2.GetTexture());
	glUniform1i(m_shader->GetSampler2(), 1);
}

void Mesh::CalculateTransform()
{
	m_world = glm::translate(glm::mat4(1.0f), m_position);
	m_world = glm::rotate(m_world, m_rotation.y, glm::vec3(0, 1, 0));
	m_world = glm::scale(m_world, m_scale);
}

void Mesh::SetShaderVariables(glm::mat4 _pv)
{
	m_shader->SetMat4("World", m_world);
	m_shader->SetMat4("WVP", _pv * m_world);
	m_shader->SetVec3("CameraPosition", m_cameraPosition);

	//Configure light
	for (unsigned int i = 0; i < Lights.size(); i++)
	{
		m_shader->SetFloat(Concat("light[", i, "].constant").c_str(), 1.0f);
		m_shader->SetFloat(Concat("light[", i, "].linear").c_str(), 0.009f);
		m_shader->SetFloat(Concat("light[", i, "].quadratic").c_str(), 0.032f);

		m_shader->SetVec3(Concat("light[", i, "].ambientColor").c_str(), { 0.1f, 0.1f, 0.1f });
		m_shader->SetVec3(Concat("light[", i, "].diffuseColor").c_str(), Lights[i].GetColor());
		m_shader->SetVec3(Concat("light[", i, "].specularColor").c_str(), { 3.0f, 3.0f, 3.0f });

		m_shader->SetVec3(Concat("light[", i, "].position").c_str(), Lights[i].GetPosition());
		m_shader->SetVec3(Concat("light[", i, "].direction").c_str(), glm::normalize(glm::vec3({ 0.0f + i * 0.1f, 0, 0.0f + i * 0.1f }) - Lights[i].GetPosition()));
		m_shader->SetFloat(Concat("light[", i, "].coneAngle").c_str(), glm::radians(5.0f));
		m_shader->SetFloat(Concat("light[", i, "].falloff").c_str(), 200);
	}


    //Configure material
	m_shader->SetFloat("material.specularStrength", 8);
	m_shader->SetTextureSampler("material.diffuseTexture", GL_TEXTURE0, 0, m_texture.GetTexture());
	m_shader->SetTextureSampler("material.specularTexture", GL_TEXTURE1, 1, m_texture2.GetTexture());
}

void Mesh::Render(glm::mat4 _pv)
{
	glUseProgram(m_shader->GetProgramID()); // Use our shader
	m_rotation.y += 0.005f;

	CalculateTransform();
	SetShaderVariables(_pv);
	BindAttributes();

	glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 8);
	glDisableVertexAttribArray(m_shader->GetAttrNormals());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrTexCoords());
}
