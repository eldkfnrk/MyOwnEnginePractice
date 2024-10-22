#pragma once
#include "mfeGameObject.h"

namespace mfe {
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject player;

	public:
		Application();

		void Initialize(HWND hwnd); 
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		~Application();
	};
}