#pragma once
#include "mfeComponent.h"

//���� ������Ʈ�� ��ġ ������ �����ϴ� ������Ʈ
namespace mfe {
	struct pos {  //���� ������Ʈ�� ��ġ ������ ������ ����ü
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	private:
		int mX;
		int mY;

	public:
		Transform();
		
		//�θ� Ŭ������ ���� �Լ��� �������̵� �ϰڴ� ���
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		//��ġ ������ �����ϰ� �ܺο��� ����ϱ� ���� Getter Setter
		void SetPos(int x, int y) {
			mX = x;
			mY = y;
		}
		int GetX() { return mX; }
		int GetY() { return mY; }

		~Transform();
	};
}
