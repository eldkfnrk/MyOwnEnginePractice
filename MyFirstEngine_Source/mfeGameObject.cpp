#include "mfeGameObject.h"
#include "mfeInput.h"
#include "mfeTime.h"

namespace mfe {
	GameObject::GameObject() :moveX(0.0f), moveY(0.0f), moveX1(0.0f), moveY1(0.0f) {

	}

	void GameObject::Update() {
		const float speed = 100.0f;

		//����⸦ �̿��ؼ� �̵�(�Ķ��� �׸� �̵���Ų��.)
		if (Input::GetKey(eKeyCode::Left)) {
			//�̷��� �ӵ��� �����ϰ� DeltaTime�� ���ϰ� �Ǹ� ���ɿ� ������� ������ ������ ��� ��ǻ�Ͱ� ������ ����� ��� �ȴ�.
			//��� ������ ������ �� �� �ε巴�� ���̰� �ȴ�.
			moveX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right)) {
			moveX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up)) {
			moveY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down)) {
			moveY += speed * Time::DeltaTime();
		}

		//WASD�� �̿��ؼ� �̵�(������ ���� �̵���Ų��.)
		if (Input::GetKey(eKeyCode::W)) {
			moveY1 -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::A)) {
			moveX1 -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S)) {
			moveY1 += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D)) {
			moveX1 += speed * Time::DeltaTime();
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