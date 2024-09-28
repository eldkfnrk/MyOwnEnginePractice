#pragma once  //컴파일러에게 이 헤더 파일이 포함되어 있으면 더 이상 중복으로 선언하지 않게 도와주는 역할(헤더 파일의 중복으로 2번 불러오는 것을 방지하는 전처리기)
//#include "CommonInclude.h"  //아래의 #include 한 헤더 파일 안에 이 헤더 파일이 포함되어 있기 때문에 중복이 되는데 위의 전처리기가 중복되지 않게 처리해주게 된다.
//빌드 시간을 줄이기 위해 중복된 헤더 파일을 찾아서 삭제하는 경우도 있다.
#include "mfeGameObject.h"

//네임스페이스를 만드는 이유는 클래스의 이름이 겹칠 수 있기 때문에 구분을 위해 만들었다.
namespace mfe {
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;

		//플레이어 이동과 관련된 변수
		//float moveX;  //x좌표를 이동하는 속도
		//float moveY;  //y좌표를 이동하는 속도

		//플레이어도 게임 오브젝트니 게임 오브젝트 클래스로 관리
		//이렇게 객체를 통해 동작하도록 하는 것을 객체 지향이라고 하며 객체 지향은 객체가 적으면 장점을 못 느끼지만 객체가 많아질수록 장점을 발휘하게 된다.
		GameObject player;

	public:
		Application();

		void Initialize(HWND hwnd); 
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		~Application();
	};
}