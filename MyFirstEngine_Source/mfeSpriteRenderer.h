#pragma once
#include "mfeComponent.h"

//���� ������Ʈ�� render�� �����ϴ� ������Ʈ
namespace mfe {
	class SpriteRenderer : public Component
	{
	private:

	public:
		SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		~SpriteRenderer();
	};
}
