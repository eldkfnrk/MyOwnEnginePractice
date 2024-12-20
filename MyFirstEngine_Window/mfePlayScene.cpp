#include "mfePlayScene.h"
#include "mfeGameObject.h"
#include "mfePlayer.h"
#include "mfeTransform.h"
#include "mfeSpriteRenderer.h"

namespace mfe {
	PlayScene::PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//for (size_t i = 0; i < 100; i++) {  //100���� ���� ������Ʈ ����
		//	GameObject* obj = new GameObject();
		//	obj->SetPosition(rand() & 1600, rand() % 900);  //��ġ�� �������� ����
		//	AddGameObject(obj);
		//}

		//�̷��� {}�� ������ ���� �Լ� �������� ������ ������ �۾��� �̷������ �ȴ�.
		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();

			tr->SetPos(800, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();

			tr->SetPos(300, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();

			tr->SetPos(100, 650);

			tr->SetName(L"TR");

			SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");

			AddGameObject(pl);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();  //�θ� Ŭ������ �Լ��� ������ ���� Ǯ������ ����Ͽ� ȣ��
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	PlayScene::~PlayScene()
	{
	}
}