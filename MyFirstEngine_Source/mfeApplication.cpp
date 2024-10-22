#include "mfeApplication.h"
#include "mfeInput.h"

namespace mfe {
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr){

	}

	void Application::Initialize(HWND hwnd) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		Input::Initailize();  //클래스의 초기화가 필요하기 때문에 Input 클래스를 GameObject에서 사용하고 싶다면 이곳에서 초기화해주어야 한다.(안 그러면 초기화가 되지 않은 상태임으로 에러 발생)
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		//아래 두 구문의 순서가 바뀌면 안 된다.
		//왜냐하면 키를 먼저 체크하고 오브젝트를 체크해야지 키 입력과 동시에 반응을 하는데 순서가 바뀌게 되면 키를 눌러도 오브젝트는 이미 업데이트가 완료되어서 동작이 한 프레임 밀리게 되는 일이 발생한다.
		Input::Update();  //위의 초기화 비슷한 맥락으로 Input클래스의 업데이트는 이 함수에서 선언해주어야 진행되게 된다.
		player.Update();
	}

	void Application::LateUpdate() {

	}

	void Application::Render() {
		player.Render(mHdc);
	}

	Application::~Application() {

	}
}