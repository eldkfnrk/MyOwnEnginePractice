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
		//for (size_t i = 0; i < 100; i++) {  //100개의 게임 오브젝트 생성
		//	GameObject* obj = new GameObject();
		//	obj->SetPosition(rand() & 1600, rand() % 900);  //위치는 랜덤으로 설정
		//	AddGameObject(obj);
		//}

		//이렇게 {}로 묶으면 같은 함수 내에서라도 영역이 나누어 작업이 이루어지게 된다.
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
		Scene::Update();  //부모 클래스의 함수를 가져올 때는 풀네임을 사용하여 호출
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