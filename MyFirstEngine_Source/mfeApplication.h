#pragma once
#include "CommonInclude.h"

//네임스페이스를 만드는 이유는 클래스의 이름이 겹칠 수 있기 때문에 구분을 위해 만들었다.
namespace mfe {
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;

		float moveSpeed;  //실수로 속도를 제어하면 조금 더 상세하게 속도를 조절할 수 있어서 실수를 사용(상황에 맞게 알아서 사용하면 된다.)

		//플레이어 이동과 관련된 변수
		float moveX;  //x좌표를 이동하는 속도
		float moveY;  //y좌표를 이동하는 속도

	public:
		Application();  //생성자

		void Initialize(HWND hwnd);  //초기화
		void Run();  //동작 -> 게임에 돌아가는 모든 동작을 관리하는 함수(게임 실행과 관련된 모든 것을 포함시켜 관리한다.)
		void Update();  //업데이트 -> 매 프레임 게임 로직이 돌아가게 만드는 함수(게임 동작 담당1)
		void LateUpdate();  //위의 Update 함수가 업데이트 한 이후 나중에 업데이트하는 함수(게임 동작 담당2)
		void Render();  //렌더 -> 뭔가를 그리려 할 때 이 함수에서 관리(화면 출력 담당)

		//업데이트 함수가 여러 개로 쪼갠 이유는 필요에 의해 어떤 것은 앞에서 어떤 것은 뒤에서 업데이트가 되는 것이 필요하기 때문이다.

		~Application();  //소멸자
	};
}