#include "mfeGameObject.h"

namespace mfe {
	GameObject::GameObject() :moveX(0.0f), moveY(0.0f), moveX1(0.0f), moveY1(0.0f) {

	}

	void GameObject::Update() {
		//방향기를 이용해서 이동(파란색 네모를 이동시킨다.)
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
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

		//WASD를 이용해서 이동(빨간색 원을 이동시킨다.)
		//아래와 같이 키보드의 철자 키는 VK로 지정되어 있지 않고 char형을 넣어주면 그에 맞는 ASCII코드로 변형되어 해석되기 때문에 ''사이에 특정 키를 넣어서 사용한다.
		//0x8000은 키를 누른 그 순간 함수가 리턴하는 값으로 누른 순간 동작을 인식하기 위해 사용하는 것이다.(없어도 되기 때문에 아래에서는 없이 사용하였다.
		if (GetAsyncKeyState('W')) {
			moveY1 -= 0.01f;
		}

		if (GetAsyncKeyState('A')) {
			moveX1 -= 0.01f;
		}

		if (GetAsyncKeyState('S')) {
			moveY1 += 0.01f;
		}

		if (GetAsyncKeyState('D')) {
			moveX1 += 0.01f;
		}
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) {
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		//키보드 입력에 따라 파란 네모를 이동시키도록 만들기
		Rectangle(hdc, 100 + moveX, 100 + moveY, 200 + moveX, 200 + moveY);

		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);

		/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldBrush);
		DeleteObject(redPen);*/

		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		//키보드 입력에 따라 빨간 원을 이동시키도록 만들기
		Ellipse(hdc, 700 + moveX1, 700 + moveY1, 800 + moveX1, 800 + moveY1);

		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
	}

	GameObject::~GameObject() {

	}
}