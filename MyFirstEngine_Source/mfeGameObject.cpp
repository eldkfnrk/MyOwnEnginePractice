#include "mfeGameObject.h"
#include "mfeInput.h"
#include "mfeTime.h"

namespace mfe {
	GameObject::GameObject() : mX(0), mY(0) {

	}

	void GameObject::Update() {
		const float speed = 100.0f;

		//방향기를 이용해서 이동(파란색 네모를 이동시킨다.)
		if (Input::GetKey(eKeyCode::Left)) {
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right)) {
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up)) {
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down)) {
			mY += speed * Time::DeltaTime();
		}

		if (Input::GetKeyDown(eKeyCode::Space)) {

		}
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) {
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));  //색깔을 랜덤으로 설정 
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
	}

	GameObject::~GameObject() {

	}
}