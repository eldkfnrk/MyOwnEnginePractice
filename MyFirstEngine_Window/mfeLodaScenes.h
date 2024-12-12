#pragma once

#include "..//MyFirstEngine_Source//mfeSceneManager.h"  //�ٸ� ������Ʈ�� �ְ� �����ϰ� �ִ� ���°� �ƴ϶� ��Ȯ�� ������ ��ġ�� �����ؾ� �Ѵ�.
#include "mfePlayScene.h"

//������ ������ ��������� ����� �߰��Ǿ� �ֱ� ������ lib ���ϵ� �߰��Ͽ� c++�� ���ư����� ����(������ ������ ������� �ʾƵ� ������.)
//#ifdef _DEBUG
//#pragma comment(lib, "..//x64//debug//myfirstengine_window.lib")
//#else
//#pragma comment(lib, "..//x64//release//myfirstengine_window.lib")
//#endif

namespace mfe{
	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");  //�Լ� ���ø��̱� ������ �̷��� ������־�� �Ѵ�.

		SceneManager::LoadScene(L"PlayScene");
	}
}

//�߰��� ���� �� �� ���͸� ���� ������Ʈ �ȿ� ���� �ϳ��� ����� �ְ� �� ������ �̸��� Scenes��� ����.
//�̷��� �� ���͸� ���� ������ ���� ���� �⺻ ���븦 ��������� �� �⺻ ���븦 ��ӹ޾� ������ ����� �����ؾ� �ϴµ� ������ �ϳ� �ϳ��� ���� �ٸ� ������
//�ϱ� ������ �� ���ε��� ������ �ǹǷ� �װ͵��� ��Ƶξ� �����ϱ� ���� ���� �ʿ��߱� ������ �������.