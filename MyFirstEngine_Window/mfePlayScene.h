#pragma once
#include "..//MyFirstEngine_Source//mfeScene.h"

namespace mfe {
	class PlayScene : public Scene
	{
	private: 


	public:
		PlayScene();
 
		//�θ� Ŭ������ ���� �Լ��� �������̵��Ѵٴ� ���� �����Ϸ����� �˷��ֱ� ���� override�� ���־�� �Ѵ�.
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		~PlayScene();
	};
}