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
		//�Ϲ����� for��
		//for (size_t i = 0; i < mGameObjects.size(); i++) {
		//	mGameObjects[i]->Update();
		//}

		//C++�� �ִ� ���� ��� for��
		for (GameObject* gameObj : mGameObjects) {  //:�� �ڿ� �ִ� �迭�� ��ҵ��� :�� �տ� �ִ� ������ �ְ� ������ ������ �����ϰ� ��� ��Ҹ� �� ���� for���� Ż���ϰ� �ȴ�.
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
		for (GameObject* gameObj : mGameObjects) {  //:�� �ڿ� �ִ� �迭�� ��ҵ��� :�� �տ� �ִ� ������ �ְ� ������ ������ �����ϰ� ��� ��Ҹ� �� ���� for���� Ż���ϰ� �ȴ�.
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