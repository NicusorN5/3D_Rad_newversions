cbuffer CameraBuffer : register(b0) {
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
}

float4 DefaultColor = float4(1, 1, 1, 1);

struct VInput
{
	float4 Position: SV_Position;
};
struct VOutput
{
	float4 Position: SV_Position;
	float4 Color: COLOR0;
};

VOutput BasicVertexShader(VInput inp)
{
	VOutput outp;
	float4 a = mul(inp.Position, World);
	float4 b = mul(a, View);

	outp.Position = mul(b, Projection);
	outp.Color = DefaultColor;

	return outp;
}