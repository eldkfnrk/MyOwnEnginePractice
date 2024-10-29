#include "mfeApplication.h"
#include "mfeInput.h"
#include "mfeTime.h"

namespace mfe {
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(NULL), mBackBitmap(NULL) {

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = {0, 0, width, height};  //실제 작업 영역을 알기 위해 RECT라는 자료 구조를 사용

		//현재 윈도우 크기, 윈도우 형태, 메뉴 여부 순으로 인자를 받는다.
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);  //이 프로그램이 만드는 윈도우 창의 작업 영역 크기를 정해주는 함수

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		//윈도우 위치 조정을 위한 세팅
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);  //윈도우의 위치를 정하는 함수(5~6번째 인자는 길이를 의미, 마지막 인자는 큰 의미없기에 0을 넣어준다.)
		ShowWindow(mHwnd, true);  //위치를 조정한 윈도우 창을 보여주기 위해 함수 호출

		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);  //인자로 DC, 너비, 높이를 넣어서 해당 DC에 넣어준 크기만큼의 비트맵을 생성한다.

		//원래는 위의 비트맵을 만들고 그것을 번갈아가면서 그리고 지우고를 해야 하는데 여기선 DC를 추가해서 그리고 적용하고 다시 그리고 적용하고를 반복
		//이 과정은 DC를 추가하면서 메모리 사용량은 증가하지만 연산을 줄여 프로그램의 동작 속도를 개선(물론 이것만이 정답은 아니고 원래 번갈아 그리는 것이 필요하면 그 방법을 사용)
		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		Input::Update();
		Time::Update();

		player.Update();
	}

	void Application::LateUpdate() {

	}

	void Application::Render() {
		//해결해야 할 문제점2
		//지금까지 프로그램은 도형의 이동 시 검은색 잔상이 남아있게 되는 문제가 있었다. 이러면 원하는 화면 출력을 할 수 없게 되는 문제가 생기기 때문에 이를 해결해야 한다.

		//해결 방안 
		//위의 문제를 해결하는 방법은 그리고 남은 잔상이 안 보이게 덮고를 반복하는 코드를 작성하는 것이다.
		//이것이 무슨 의미이냐 하면 프로그램이 동작하고 도형을 이동시키면 우리 눈에는 연결된 동작으로 보이게 되는데 컴퓨터는 도형을 그리고 이동한 위치에 다시 그리고를 반복하는 
		//동작을 수행한다. 이렇게 해서 남게 되는 검은색 잔상을 다른 화면으로 덮어주어서 우리 눈에 잔상을 안 보이게 하는 방법으로 이를 해결하겠다는 의미이다.
		
		//아무 코드없이 화면을 꽉 채우는 도형을 생성하면 깜빡깜빡거리는 문제가 발생하는데 이를 해결하기 위해 필요한 것이 더블 버퍼링이라는 것이다.
		//더블 버퍼링이란 도화지를 두 장을 놓고 쓰는 것이라고 생각하면 편하다.
		//이것이 무슨 의미인가 하면 기존의 프로그램은 하나의 도화지로만 그림을 그리고 지우고 다시 그리고를 반복했던 것인데 이런 식으로 그리면 잔상이 남게 되는 문제가 발생하는 것인데
		//두 개의 도화지를 가지고 그림을 그린다고 생각해보면 하나의 도화지에 그림을 그리고 화면에 보여주고 이동하면 다른 도화지에 이동한 위치에 그림을 그려서 이 도화지를 화면에 보여주는
		//방식으로 계속 두 도화지를 번갈아가면서 보여주는 방식이라고 생각하면 되기 때문에 도화지를 두 장 놓고 쓰는 것이라고 하는 것이다.
		//이렇게 되면 그림을 그린 후 지우고 다시 그리는 과정에서 지워지는 과정이 잔상으로 남는 것인데 이것을 안 보이게 숨기는 식으로 잔상이 남는 문제를 해결하는 것이다.
		//클라이언트 응용 프로그램에서 사용하는 방식으로 DirectX11 등에서도 이와 같은 과정을 거치게 된다.

		//여기서 주의해야 할 점이 있는데 화면 크기가 예를 들어 1600, 900이다라고 가정했을 때 이것이 화면이 출력되는 부분의 크기가 아니라 메뉴 표시줄과 제목 표시줄까지 포함이기 때문에 
		//실제 DC가 출력되는 화면의 상하폭 크기는 다르다는 점이다.(메뉴 표시줄과 제목 표시줄을 브라우저 상단 영역이라 하고 우리가 출력하는 화면은 실제 작업 영역이라 한다.)
		//우리는 그러면 전체 창 크기가 아니라 실제 작업 영역의 크기를 알아야 한다.

		//Rectangle(mHdc, 0, 0, mWidth, mHeight);

		//Time::Render(mHdc);
		//player.Render(mHdc);

		//위에서는 기존 DC에다가 그려주었는데 기존 DC는 출력만 하고 그리는 것은 새로 만든 백버퍼에다가 그리기 위해서 DC를 백버퍼로 변경
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);

		Time::Render(mBackHdc);
		player.Render(mBackHdc);

		//백버퍼에만 그림을 그리는 것이기 때문에 실제로 화면에 출력은 백지인 상태이다. 그러면 백버퍼에 있는 그림을 옮겨주어야 한다.
		//백버퍼에 있는 걸 원본에 복사(그려준다.)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);  //이 함수는 뒤에 인자로 들어오는 DC에 있는 그림을 앞에 인자로 들어오는 DC에 복사하여 출력시켜주는 함수이다.
		//마지막 인자는 옵션으로 여기선 소스 카피 즉, 그대로 복사 옵션을 사용
		//2~5번째까지의 인자는 복사 범위를 의미하며 복사를 전체 화면이 아니라 부분 복사를 하고 싶으면 그렇게도 할 수 있다.
	}

	Application::~Application() {

	}
}