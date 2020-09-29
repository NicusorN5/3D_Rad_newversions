float4x4 View;
float4x4 World;
float4x4 Projection;

struct VS_Input
{
	float3 Position : POSITION0;
	float4 Color : COLOR0;
};

struct VS_Output
{
	float3 Position : POSITION0;
	float4 Color : COLOR0;
};

VS_Output VertexFunction(VS_Input input)
{
	VS_Output output;
	float4 worldPosition = mul(input.Position, World);
	float4 viewPosition = mul(worldPosition, View);
	output.Position = mul(viewPosition, Projection);
	output.Color = input.Color;
	return output;
}

float4 PixelFunction(VS_Output output) : COLOR0
{
	return output.Color;
}

technique SimpleTextured
{
	pass SimpleTextured
	{
		VertexShader = compile vs_2_0 VertexFunction();
		PixelShader = compile ps_2_0 PixelFunction();
	}
}