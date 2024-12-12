#pragma once
#include "mfeScene.h"

namespace mfe {
	//씬은 굉장히 복합적인 동작을 수행하는 객체로 이 모든 씬들을 어플리케이션에서 작업하게 되면 어플리케이션의 코드가 증가하게 되고 어플리케이션이 하는 역할(목적)을
	//초과하여 목적성에 어긋나게 되어 역할 구분이 모호해질 수 있기에 씬들을 따로 관리해야 한다. 그러기 위해 만든 것이 바로 SceneManager 클래스이다.
	//여러 씬들의 복합적인 동작을 수행해야 하기 때문에 정적 변수나 전역 변수등을 만들어 사용하는 것이 좋아보인다.
	class SceneManager
	{
	private:
		//static std::vector<Scene*> mScene;
		static std::map<const std::wstring, Scene*> mScene;  //위의 vector를 트리 구조로 변경(<>안에서 앞에 있는 것이 키, 뒤에 있는 것이 값이다.)
		//기존 vector에서 트리 자료 구조로 바꾼 이유는 이것이 조금 더 빠르게 원하는 씬을 찾을 수 있는 방법이기 때문이다. 이것이 무슨 의미이냐 하면 기존 vector는 배열로
		//배열 안에 있는 씬을 찾을 때 앞 순서 있는 씬을 찾으면 별로 안 걸리고 금방 찾겠지만 마지막 정도에 있는 씬들을 찾으려면 시간이 오래 걸리게 된다. 배열에 저장된 씬이 많으면
		//많을수록 그 시간은 더 길어지고 이는 프로그램의 속도를 낮추는 문제가 되게 되는 것이다. 그런데 트리 구조는 원하는 데이터 여기서는 씬이 되는데 이 씬을 찾기 위해서 씬의 키 값
		//여기서는 씬에 붙은 이름이 될 것인데 이 키 값을 통해서 씬을 찾는 것이기 때문에 vector의 순서대로 찾는 것보다 빠르게 찾을 수 있는 장점이 있어서 이렇게 변경하는 것이다. 
		static Scene* mActiveScene;  //위의 vector(배열)가 모든 씬을 가지고 있겠지만 업데이트 즉, 동작하는 씬은 하나만 있어야 하기 때문에 변수 추가.

	public:
		static void Initialize();
		static void Update();  //씬은 하나씩만 업데이트 해주는 것이 맞다.(하나의 씬이 돌아가고 있는데 다른 씬도 돌아가고 있으면 게임 상 문제가 발생할 수 있기 때문이다.)
		static void LateUpdate();
		static void Render(HDC hdc);

		template <typename T>
		static Scene* CreateScene(const std::wstring& name) {
			T* scene = new T();  //T는 만들어지는 씬 클래스 자료형이 들어오게 된다.(템플릿으로 만든 이유이기도 한데 여러 씬들을 만들 것이기 때문에 각 씬 클래스 자료형이 여러 개가 생겨 그것들을 모두 대응하기 위해 사용)
			scene->SetName(name);
			scene->Initialize();  //씬마다 씬 안에서 초기화해야 할 작업들이 있을 것이기 때문에 초기화 함수 호출

			//위에서 이름을 지정하였으니 해당 씬을 map에다가 저장한다.
			mScene.insert(std::make_pair(name, scene));  //make_pair는 pair를 만들어주는 함수(pair는 map의 키,값 쌍을 의미한다.)

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name) {
			//map을 활용할 수 있게 구현된 함수 find는 키 값(Scene의 이름)을 넣어주면 해당되는 map의 주소 값을 반환하는 함수이다.
			std::map<std::wstring, Scene*>::iterator iter = mScene.find(name);  //반환된 map의 주소를 포인터에 저장

			if (iter == mScene.end()) {  //end는 맨 마지막 요소 뒤에 있는 메모리 칸을 의미한다. 실제 데이터가 있는 곳은 아니고 맨 마지막임을 알려주기 위해 할당된 공간이다.
				return nullptr;
			}

			mActiveScene = iter->second;  //first = 키, second = 실제 데이터 를 의미(즉, 씬을 대입한다는 의미)

			return iter->second;  
		}
	};
}