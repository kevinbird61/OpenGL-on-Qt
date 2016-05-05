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

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;


// 'out' means vertex shader output for fragment shader
// fNormal will be interpolated before passing to fragment shader
flat out vec3 Result;
out vec2 ftexcoord;

void main()
{
	// For Matrix Position 
	gl_Position=projection*vp*model*vec4(position, 1.0);
	// Get Fragment position
	vec3 FragPos = vec3(model*vec4(position , 1.0f));
	// Get Normal vector
	vec3 Normal = mat3(transpose(inverse(model)))*normal;
	
	/* Calculate for light for each vertex */
	
	// Ambient
	float ambientStrength = 0.1f;
	vec3 ambient = ambientStrength * lightColor;
	
	// Diffuse 
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(norm,lightDir),0.0);
	vec3 diffuse = diff * lightColor;
	
	// Specular 
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir , norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0),32);
	vec3 specular = specularStrength * spec * lightColor;
	
	vec3 result = (ambient+diffuse+specular);
	
	ftexcoord = texcoord;
	
	Result = result;
}
