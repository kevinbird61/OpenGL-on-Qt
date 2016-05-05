#version 330

// Default color buffer location is 0
// If you create framebuffer your own, you need to take care of it
layout(location=0) out vec4 color;

uniform sampler2D uSampler;

flat in vec3 Result;
in vec2 ftexcoord;

void main()
{	
	color = vec4( Result*vec3(texture(uSampler,ftexcoord)), 1.0f);
}
