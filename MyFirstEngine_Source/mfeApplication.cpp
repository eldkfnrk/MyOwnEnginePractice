#include "mfeApplication.h"

//��� ���Ͽ��� ���ӽ����̽� ����� �� �ȿ� Ŭ������ �����ϸ� cpp ���Ͽ����� �Ʒ��� ���� �Ȱ��� �̸��� ���ӽ����̽��� �ѷ��μ� �ش� Ŭ������ ����� �����ϸ� �ȴ�.
namespace mfe {
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr){

	}

	void Application::Initialize(HWND hwnd) {  //HWND Ÿ���� �������̱� ������ �ּҰ� ���޵ȴ�.(�߰��� DC ���� �������̴�.)
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);  //DC�� ������ ���� �Լ�(���ڷ� DC�� ������ �ִ� ���α׷��� �ڵ��� �޴´�.)

		//player.SetPosition(0.0f, 0.0f);
	}

	void Application::Run() {
		//���� Ŭ���� ������� ����� ���� ���� ���� �����ڸ� ������� �ʾƵ� �ȴ�.(���� ������ ���� �̹� �˰� �ֱ� ����)
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update() {
		//GameObject Ŭ������ �̵�
		//float x = player.GetPositionX();
		//float y = player.GetPositionY();

		////GetAsyncKeyState() �Լ� -> Ű���� �Է� ���¸� üũ�ϴ� �Լ�
		////VK_LEFT�� ���� ����Ű�� �ǹ��ϴµ� �̰��� ��Ȯ�� ���� �����ε� �̸� ���� Ű���� �Է��� ���ڷ� �����Ѵٴ� ���� �� �� �ִ�.(���ڿ� �̸��� �ٿ��� ���� ���� ���� ���̴�.)
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

		//���� ������ �ϴ� ���� GameObject ��ü�� �ϵ��� �ٲٰ� �̸� ȣ���ϴ� ������� ����
		player.Update();
	}

	void Application::LateUpdate() {

	}

	void Application::Render() {
		//GameObject Ŭ������ �̵�
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		////Ű���� �Է¿� ���� ������ �̵���Ű���� �����
		//float x = player.GetPositionX();
		//float y = player.GetPositionY();
		//Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

		//(HBRUSH)SelectObject(mHdc, oldBrush);

		//DeleteObject(blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		//SelectObject(mHdc, oldBrush);
		//DeleteObject(redPen);

		//���� ������ �ϴ� ���� GameObject ��ü�� �ϵ��� �ٲٰ� �̸� ȣ���ϴ� ������� ����
		player.Render(mHdc);
	}

	Application::~Application() {

	}
}