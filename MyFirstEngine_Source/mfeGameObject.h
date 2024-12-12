#pragma once
#include "mfeEntity.h"

namespace mfe {
	//���� ������Ʈ ���� �۾��ϴ� ���� ����
	//���� ���������� ������Ʈ�� ����� �ÿ� �����ؾ� �� �͵� �� �ϳ��̱� ������ Entity Ŭ������ ��ӹް� �ȴ�.
	class GameObject : public Entity
	{
	private:
		//���� ������Ʈ�� ��ǥ
		float mX;
		float mY;

	public:
		GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);  

		void SetPosition(float x, float y) {
			mX = x;
			mY = y;
		}

		~GameObject();
	};
}