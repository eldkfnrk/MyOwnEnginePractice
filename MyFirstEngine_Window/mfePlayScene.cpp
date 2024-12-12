#include "mfePlayScene.h"

namespace mfe {
	PlayScene::PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++) {  //100개의 게임 오브젝트 생성
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() & 1600, rand() % 900);  //위치는 랜덤으로 설정
			AddGameObject(obj);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();  //부모 클래스의 함수를 가져올 때는 풀네임을 사용하여 호출
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