
struct VOutput
{
	float4 Position: SV_Position;
	float4 Color: COLOR0;
};

float4 BasicPixelShader(VOutput outp) : SV_TARGET
{
	return outp.Color;
}