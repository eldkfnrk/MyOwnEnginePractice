#include "mfeGameObject.h"
#include "mfeInput.h"

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
		if (Input::GetKey(eKeyCode::W)) {
			moveY1 -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::A)) {
			moveX1 -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S)) {
			moveY1 += 0.01f;
		}

		if (Input::GetKey(eKeyCode::D)) {
			moveX1 += 0.01f;
		}
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) {
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Rectangle(hdc, 100 + moveX, 100 + moveY, 200 + moveX, 200 + moveY);

		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);

		/*HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldBrush);
		DeleteObject(redPen);*/

		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		Ellipse(hdc, 700 + moveX1, 700 + moveY1, 800 + moveX1, 800 + moveY1);

		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
	}

	GameObject::~GameObject() {

	}
}