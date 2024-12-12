#pragma once
#include "mfeEntity.h"

namespace mfe {
	//게임 오브젝트 관련 작업하는 역할 수행
	//씬과 마찬가지로 오브젝트도 디버깅 시에 구분해야 할 것들 중 하나이기 때문에 Entity 클래스를 상속받게 된다.
	class GameObject : public Entity
	{
	private:
		//게임 오브젝트의 좌표
		float mX;
		float mY;

	public:
		GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);  

		void SetPosition(float x, float y) {
			mX = x;
			mY = y;
		}

		~GameObject();
	};
}