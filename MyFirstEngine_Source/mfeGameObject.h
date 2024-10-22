#pragma once
#include "CommonInclude.h"

namespace mfe {
	class GameObject
	{
	private:
		//게임 오브젝트(파란 네모)의 이동
		 float moveX;
		 float moveY;

		 //게임 오브젝트(빨간 원)의 이동
		 float moveX1;
		 float moveY1;

	public:
		GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);  

		~GameObject();
	};
}