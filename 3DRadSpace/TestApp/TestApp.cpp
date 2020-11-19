#include <random>
#include <time.h>
#include <Windows.h>
int main()
{
	srand(time(nullptr));
	int* a = (int*)rand();
	RegisterClass((const WNDCLASSW*)a);
}