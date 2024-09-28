#include "mfeApplication.h"

//헤더 파일에서 네임스페이스 만들어 그 안에 클래스를 선언하면 cpp 파일에서는 아래와 같이 똑같은 이름의 네임스페이스로 둘러싸서 해당 클래스의 멤버를 정의하면 된다.
namespace mfe {
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr), moveSpeed(0.0f), moveX(0.0f), moveY(0.0f) {

	}

	void Application::Initialize(HWND hwnd) {  //HWND 타입은 포인터이기 때문에 주소가 전달된다.(추가로 DC 또한 포인터이다.)
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);  //DC를 가지고 오는 함수(인자로 DC를 가지고 있는 프로그램의 핸들을 받는다.)
	}

	void Application::Run() {
		//같은 클래스 멤버들을 사용할 때는 범위 지정 연산자를 사용하지 않아도 된다.(같은 멤버라는 것을 이미 알고 있기 때문)
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		moveSpeed += 0.001f;  //움직이는 속도가 프레임마다 증가

		//내가 오른쪽 키를 입력받았다면 x좌표가 +로 왼쪽 키를 받았다면 x좌표가 -로
		//위쪽 키를 받았다면 y좌표가 -로 아래쪽 키를 받았다면 y좌표가 +로 도형이 이동하게 되게 된다.(OS에 따라서 좌표는 변형하기 때문에 절대적인 것은 아니다.)

		//GetAsyncKeyState() 함수 -> 키보드 입력 상태를 체크하는 함수
		//VK_LEFT는 왼쪽 방향키를 의미하는데 이것을 정확히 보면 숫자인데 이를 통해 키보드 입력을 숫자로 관리한다는 것을 알 수 있다.(숫자에 이름을 붙여서 보기 쉽게 만든 것이다.)
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {  //GetAsyncKeyState함수에 인자로 받은 키가 눌리면 이 함수는 0x8000이라는 값을 반환한다.(0x8000은 키가 눌린 정확한 시점에 반환하는 값, 이외에도 함수는 여러 값을 반환)
			//비트 연산자 &를 사용하여서 두 피연산자의 값이 같은 경우 참이 되어 조건문 속에 동작을 수행하도록 조건을 건 것이다.
			//그러나 이 조건에서 0x8000을 뺀다고 해서 문제가 생기는 것은 아니고 ms에서 그렇게 사용하라고 설명하고 있는데로 사용하는 것이기 때문에 큰 의미를 두지 않아도 된다.
			//특정 키가 입력되면 반복문에 걸려 동작을 실행하게 되는 원리이다.
			moveX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			moveX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			moveY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			moveY += 0.01f;
		}

		//위의 조건문은 Render 함수에서 실행하여도 정상적으로 동작하는데 굳이 Update 함수에서 정의하는 이유는 각 함수의 역할을 분명하게 분리하기 위해서이다.
		//Render 함수는 그리는 작업만을 Update 함수는 로직 업데이트(갱신)하는 작업만을 하도록 나누어 놓은 것이다.(이렇게 구분하는 이유는 코드가 복잡해지면서 발생할 수 있는 문제를 예방하기 위함이다.)
		//그러나 위의 조건문은 처음 보면 이게 무슨 동작을 하는지 바로 알기 힘든 모양으로 간단히 말해 가독성이 떨어지기 때문에 이를 약간 변형시켜야 하는데 이는 다음 커밋에서 해결할 예정이다.
		//또한, 컴퓨터의 성능에 따라 1초마다 동작하는 프레임의 수가 달라 같은 시간 키를 눌러도 이동한 거리가 다를 수 있는 문제가 있기 때문에 이것도 해결해야 한다.
	}

	void Application::LateUpdate() {

	}

	void Application::Render() {
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		//Rectangle(mHdc, 400, 400, 500, 500);
		//Rectangle(mHdc, 100 + moveSpeed, 100, 200 + moveSpeed, 200);  //도형을 점점 빠르게 이동시키도록 코드 변형
		//위의 코드는 프레임마다 이동하도록 만들었는데 이제 사용자의 입력에 따라 원하는 형태로 동작하게 만들면 게임의 기본이 갖추어지는 것이다.

		//키보드 입력에 따라 도형을 이동시키도록 만들기
		Rectangle(mHdc, 100 + moveX, 100 + moveY, 200 + moveX, 200 + moveY);

		//이렇게 하면 도형이 움직이기는 하지만 도형이 움직인 자리에 잔상이 남게되는 문제가 있는데 이는 다음 커밋에서 해결할 예정이다.

		(HBRUSH)SelectObject(mHdc, oldBrush);

		DeleteObject(blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		SelectObject(mHdc, oldBrush);
		DeleteObject(redPen);

		//기존에 화면을 출력하던 방법에서 이 함수에서 화면 출력에 대한 것을 관장하여 진행하는 이유는 기존 방법이 게임과 맞지 않기 때문이다.
		//기존에 방법은 최초로 WM_PAINT 메시지가 전달되면 그때 한 번 화면을 출력하고 더 이상의 화면 출력이 진행되지 않기 때문에 사용자의 입력에 맞게 동작한 것이 
		//화면에 적용되기 위해서는 이 방법이 아니라 매 플레임마다 화면이 그려지는 방식으로 진행해야 하기 때문에 기존 방법에서 Render함수로 이동해 이 함수가 화면 출력과
		//관련된 모든 것을 관리하게 하는 것이다.
	}

	Application::~Application() {

	}
}