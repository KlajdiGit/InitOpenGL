#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
using namespace std;
class Mesh
{
public:
	// Constructors / Destructors
	Mesh();
	virtual ~Mesh();

	// Methods
	void Create();
	void Cleanup();
	void Render();

private:
	GLuint m_vertexBuffer;
	vector<GLfloat> m_vertexData;
};

#endif // MESH_H