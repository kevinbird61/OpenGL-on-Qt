#version 330

// Default color buffer location is 0
// If you create framebuffer your own, you need to take care of it
layout(location=0) out vec4 color;

in vec2 fTexcoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D uSampler;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;


void main()
{
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
	vec3 replace_reflect = normalize(lightDir+viewDir);
	float spec = pow(max(dot(viewDir,replace_reflect),0.0),64);
	vec3 specular = specularStrength * spec * lightColor;
	
	vec3 result = (ambient+diffuse+specular) * vec3(texture(uSampler,fTexcoord));
	
	color = vec4(result , 1.0f);
}
