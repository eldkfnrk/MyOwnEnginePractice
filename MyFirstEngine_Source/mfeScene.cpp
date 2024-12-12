#include "mfeScene.h"

namespace mfe {
	Scene::Scene() : mGameObjects{}
	{

	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		//일반적인 for문
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	mGameObjects[i]->Update();
		//}

		//C++에 있는 범위 기반 for문
		for (GameObject* gameObj : mGameObjects) {  //:의 뒤에 있는 배열의 요소들을 :의 앞에 있는 변수에 넣고 정의한 동작을 수행하고 모든 요소를 다 돌면 for문을 탈출하게 된다.
			gameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects) {
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects) {  //:의 뒤에 있는 배열의 요소들을 :의 앞에 있는 변수에 넣고 정의한 동작을 수행하고 모든 요소를 다 돌면 for문을 탈출하게 된다.
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject) {
		mGameObjects.push_back(gameObject);
	}

	Scene::~Scene()
	{

	}
}