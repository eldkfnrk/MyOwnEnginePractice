#pragma once
#include "CommonInclude.h"

namespace mfe {
	class GameObject
	{
	private:
		//���� ������Ʈ(�Ķ� �׸�)�� �̵�
		 float moveX;
		 float moveY;

		 //���� ������Ʈ(���� ��)�� �̵�
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