#include "mfeApplication.h"
#include "mfeInput.h"

namespace mfe {
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr){

	}

	void Application::Initialize(HWND hwnd) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		Input::Initailize();  //Ŭ������ �ʱ�ȭ�� �ʿ��ϱ� ������ Input Ŭ������ GameObject���� ����ϰ� �ʹٸ� �̰����� �ʱ�ȭ���־�� �Ѵ�.(�� �׷��� �ʱ�ȭ�� ���� ���� ���������� ���� �߻�)
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		//�Ʒ� �� ������ ������ �ٲ�� �� �ȴ�.
		//�ֳ��ϸ� Ű�� ���� üũ�ϰ� ������Ʈ�� üũ�ؾ��� Ű �Է°� ���ÿ� ������ �ϴµ� ������ �ٲ�� �Ǹ� Ű�� ������ ������Ʈ�� �̹� ������Ʈ�� �Ϸ�Ǿ ������ �� ������ �и��� �Ǵ� ���� �߻��Ѵ�.
		Input::Update();  //���� �ʱ�ȭ ����� �ƶ����� InputŬ������ ������Ʈ�� �� �Լ����� �������־�� ����ǰ� �ȴ�.
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