#include "mfeApplication.h"

//헤더 파일에서 네임스페이스 만들어 그 안에 클래스를 선언하면 cpp 파일에서는 아래와 같이 똑같은 이름의 네임스페이스로 둘러싸서 해당 클래스의 멤버를 정의하면 된다.
namespace mfe {
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr){

	}

	void Application::Initialize(HWND hwnd) {  //HWND 타입은 포인터이기 때문에 주소가 전달된다.(추가로 DC 또한 포인터이다.)
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);  //DC를 가지고 오는 함수(인자로 DC를 가지고 있는 프로그램의 핸들을 받는다.)

		//player.SetPosition(0.0f, 0.0f);
	}

	void Application::Run() {
		//같은 클래스 멤버들을 사용할 때는 범위 지정 연산자를 사용하지 않아도 된다.(같은 멤버라는 것을 이미 알고 있기 때문)
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		//GameObject 클래스로 이동
		//float x = player.GetPositionX();
		//float y = player.GetPositionY();

		////GetAsyncKeyState() 함수 -> 키보드 입력 상태를 체크하는 함수
		////VK_LEFT는 왼쪽 방향키를 의미하는데 이것을 정확히 보면 숫자인데 이를 통해 키보드 입력을 숫자로 관리한다는 것을 알 수 있다.(숫자에 이름을 붙여서 보기 쉽게 만든 것이다.)
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000) {  
		//	x -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		//	x += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000) {
		//	y -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		//	y += 0.01f;
		//}

		//player.SetPosition(x, y);

		//위의 동작을 하는 것을 GameObject 객체가 하도록 바꾸고 이를 호출하는 방식으로 변경
		player.Update();
	}

	void Application::LateUpdate() {

	}

	void Application::Render() {
		//GameObject 클래스로 이동
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		////키보드 입력에 따라 도형을 이동시키도록 만들기
		//float x = player.GetPositionX();
		//float y = player.GetPositionY();
		//Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

		//(HBRUSH)SelectObject(mHdc, oldBrush);

		//DeleteObject(blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		//SelectObject(mHdc, oldBrush);
		//DeleteObject(redPen);

		//위의 동작을 하는 것을 GameObject 객체가 하도록 바꾸고 이를 호출하는 방식으로 변경
		player.Render(mHdc);
	}

	Application::~Application() {

	}
}