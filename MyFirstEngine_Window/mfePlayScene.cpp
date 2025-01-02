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
		{
			//Player* pl = new Player();
			//Transform* tr = pl->AddComponent<Transform>();

			//tr->SetPos(800, 450);

			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();

			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			//SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");

			sr->ImageLoad(L"D:\����\���� ���� ����\C++ ����\MyOwnEnginePractice\Resources\CloudOcean.png");
			
			//AddGameObject(pl);
			AddGameObject(bg);
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