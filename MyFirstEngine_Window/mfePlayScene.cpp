#include "mfePlayScene.h"

namespace mfe {
	PlayScene::PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++) {  //100���� ���� ������Ʈ ����
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() & 1600, rand() % 900);  //��ġ�� �������� ����
			AddGameObject(obj);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();  //�θ� Ŭ������ �Լ��� ������ ���� Ǯ������ ����Ͽ� ȣ��
	}

	void PlayScene::LateUpdate()
	{
	}

	void PlayScene::Render(HDC hdc)
	{
	}

	PlayScene::~PlayScene()
	{
	}
}