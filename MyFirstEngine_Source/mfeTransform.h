#pragma once
#include "mfeComponent.h"

//게임 오브젝트의 위치 정보를 관장하는 컴포넌트
namespace mfe {
	struct pos {  //게임 오브젝트의 위치 정보를 가지는 구조체
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	private:
		int mX;
		int mY;

	public:
		Transform();
		
		//부모 클래스의 가상 함수를 오버라이드 하겠다 명시
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//위치 정보를 설정하고 외부에서 사용하기 위한 Getter Setter
		void SetPos(int x, int y) {
			mX = x;
			mY = y;
		}
		int GetX() { return mX; }
		int GetY() { return mY; }

		~Transform();
	};
}
