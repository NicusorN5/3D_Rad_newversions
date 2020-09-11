#pragma once
#include <windows.h>

namespace _3DRadSpaceDll
{
	namespace Input
	{
		void (*KeyDownEvent)(int key);
		void (*KeyUpEvent)(int key);
		static class __declspec(dllexport) Keyboard
		{
			int _lastKey;
		public:
			void SetLastKey(HINSTANCE hInstance,int wParamKey,bool up_down);
		};
	}
}

