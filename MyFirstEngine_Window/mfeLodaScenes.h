#pragma once

#include "..//MyFirstEngine_Source//mfeSceneManager.h"  //다른 프로젝트에 있고 참조하고 있는 상태가 아니라 정확한 파일의 위치를 기입해야 한다.
#include "mfePlayScene.h"

//참조를 썼으면 상관없으나 헤더만 추가되어 있기 때문에 lib 파일도 추가하여 c++도 돌아가도록 설정(문제가 없으면 사용하지 않아도 괜찮다.)
//#ifdef _DEBUG
//#pragma comment(lib, "..//x64//debug//myfirstengine_window.lib")
//#else
//#pragma comment(lib, "..//x64//release//myfirstengine_window.lib")
//#endif

namespace mfe{
	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");  //함수 템플릿이기 때문에 이렇게 사용해주어야 한다.

		SceneManager::LoadScene(L"PlayScene");
	}
}

//추가를 누른 후 새 필터를 눌러 프로젝트 안에 필터 하나를 만들어 주고 이 필터의 이름을 Scenes라고 하자.
//이렇게 새 필터를 만든 이유는 지금 씬의 기본 뼈대를 만들었으니 이 기본 뼈대를 상속받아 씬들을 만들기 시작해야 하는데 씬들은 하나 하나가 각기 다른 동작을
//하기 때문에 다 따로따로 만들어야 되므로 그것들을 모아두어 관리하기 위한 것이 필요했기 때문에 만들었다.