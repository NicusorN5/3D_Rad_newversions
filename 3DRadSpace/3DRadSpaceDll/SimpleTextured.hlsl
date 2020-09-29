float4x4 View;
float4x4 World;
float4x4 Projection;

struct VS_Input
{
	float3 Position : POSITION;
	float2 TextureUV : TEXTURE;
};

texture ModelTexture;
sampler2D textureSampler = sampler_state {
	Texture = (ModelTexture);
	MinFilter = Linear;
	MagFilter = Linear;
	AddressU = Clamp;
	AddressV = Clamp;
};

struct VS_Output
{
	float3 Position : POSITION0;
	float2 TextureUV : TEXCOORD0;
};

VS_Output VertexFunction(VS_Input input)
{
	VS_Output output;
	float4 worldPosition = mul(input.Position, World);
	float4 viewPosition = mul(worldPosition, View);
	output.Position = mul(viewPosition, Projection);
	output.TextureUV = input.TextureUV;
	return output;
}

float4 PixelFunction(VS_Output output) : COLOR0
{
	return tex2D(textureSampler,output.TextureUV);
}

technique SimpleTextured
{
	pass SimpleTextured
	{
		VertexShader = compile vs_2_0 VertexFunction();
		PixelShader = compile ps_2_0 PixelFunction();
	}
}