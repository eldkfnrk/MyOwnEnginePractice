#pragma once
#include "CommonInclude.h"

//네임스페이스는 여러 파일에 걸쳐 존재 할 수 있기 때문에 네임스페이스를 지정할 때 동일한 이름으로 지정해주면 모두 같은 네임스페이스 안에 들어간다.
//즉, Application 클래스도 GameObject 클래스와 동일한 네임스페이스에 있다.
namespace mfe {
	//게임 오브젝트 -> 게임 속 오브젝트인 캐릭터, 소품, 배경 등을 일컬어 부르는 말(유니티에서 사용하는 단어이다.)
	//언리얼 엔진에서는 액터라고 부른다.
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

		//게임 오브젝트와 관련된 일련의 동작들을 이 클래스에서 정의하면 좀 더 구분이 되고 직관적이게 바꿔줄 수 있다.
		//Application에서 게임 오브젝트에 대한 동작을 일일히 구현하는 것보다 여기서 구현하고 실행시키는 것이 오류를 줄일 수 있다.
		void Update();
		void LateUpdate();
		void Render(HDC hdc);  //Application 클래스는 핸들을 멤버로 가지고 있으니 상관없지만 GameObject 클래스는 어느 핸들의 DC인지 알 수 없어 인자로 받아야하는 것이다.

		//아래와 같이 간단한 함수는 cpp에서 정의할 필요없이 헤더 파일에 바로 정의해도 성능에는 큰 문제가 없다.(이때 이 함수는 인라인 함수 취급을 받게 된다.)
		//void SetPosition(float x, float y) {  //private 멤버인 변수 값을 컨트롤하기 위한 함수
		//	moveX = x;
		//	moveY = y;
		//}

		//float GetPositionX() { return moveX; }
		//float GetPositionY() { return moveY; }

		//위의 Getter, Setter 함수는 클래스 외부에서 private 멤버 값을 컨트롤하는데 사용하는데 지금은 객체 관련 동작을 모두 객체 안에서 진행하기 때문에 따로 필요하지 않다.(필요하면 다시 작성하면 된다.)

		~GameObject();
	};
}