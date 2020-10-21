struct VertexShaderInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
};

float4 main( VertexShaderInput inp ) : SV_POSITION
{
	return inp.pos;
}