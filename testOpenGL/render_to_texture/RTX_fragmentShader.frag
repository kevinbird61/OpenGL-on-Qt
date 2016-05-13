#version 330
in vec2 TexCoords;

out vec4 color;

uniform sampler2D screenTexture;
uniform vec2 mouseLoc;
uniform float HEIGHT;
uniform mat3 GAUSSIAN;

void main()
{
	float offset = 1.0/HEIGHT;
	float diameter = 0.1;
	float distance = length(mouseLoc - TexCoords);
	
	vec2 offsets[9] = vec2[](
		vec2(-offset , offset), // Top-left
		vec2(0.0f , offset),	// Top-center
		vec2(offset , offset),	// Top-right
		vec2(-offset , 0.0f),	// center-left
		vec2(0.0f , 0.0f),		// center-center
		vec2(offset , 0.0f),	// center-right
		vec2(-offset , -offset),// buttom-left
		vec2(0.0f , -offset),	// bottom-center
		vec2(offset , -offset)	// bottom-right
	);

	float kernel[9] = float[](
    GAUSSIAN[0][2], GAUSSIAN[1][2],GAUSSIAN[2][2],
    GAUSSIAN[0][1], GAUSSIAN[1][1], GAUSSIAN[1][2],
    GAUSSIAN[0][0], GAUSSIAN[1][0], GAUSSIAN[2][0] 
	);

	vec3 sampleTex[9];
	for(int i = 0; i < 9;i++)
	{
		if(distance < diameter)
		{
			vec2 magnify = (mouseLoc + TexCoords) / 2.0f;
			sampleTex[i] = vec3(texture(screenTexture,magnify.st + offsets[i]));
			vec3 col = vec3(0.0);
			for(int j = 0; j < 9; j++)
				col += sampleTex[j] * kernel[j];
		
			color = vec4(col, 1.0);
		}
		else
		{
			color = texture(screenTexture,TexCoords);
		}
	}	
}
