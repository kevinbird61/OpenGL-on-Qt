#version 330
layout(location=0) in vec3 position;
layout(location=1) in vec2 texcoord;
layout(location=2) in vec3 normal;

// uniform variable can be viewed as a constant
// you can set the uniform variable by glUniformXXXXXXXX
// HINT: I do not use model matrix here, but you might need it
uniform mat4 model;
uniform mat4 vp;
uniform mat4 projection;

// 'out' means vertex shader output for fragment shader
// fNormal will be interpolated before passing to fragment shader
out vec2 fTexcoord;
out vec3 Normal;
out vec3 FragPos;

void main()
{
	fTexcoord=texcoord;
	
	gl_Position=projection*vp*model*vec4(position, 1.0);
	FragPos = vec3(model*vec4(position , 1.0f));
	Normal = mat3(transpose(inverse(model)))*normal;
}
