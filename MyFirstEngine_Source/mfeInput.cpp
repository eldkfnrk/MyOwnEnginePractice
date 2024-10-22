#include "mfeInput.h"

namespace mfe {
	std::vector<Input::Key> Input::mKeys = {};  //아무것도 안 들어있는 상태로 초기화
	//정적 멤버 변수는 클래스의 전역 변수이기 때문에 초기화가 되어야 하는데 클래스 내에서는 초기화하는 것이 안 되기 때문에 클래스 외에서 따로 초기화해주어야 한다.
	//정적 멤버 변수는 한 번 할당되면 프로그램이 종료되기 전까지는 사라지지 않는다.
	//Input::Key -> Key 구조체도 클래스 내에 있는 구조체이기 때문에 이와 같이 ::연산자로 어디 소속인지 확인해야 한다.
	
	//vector는 배열과 비슷하지만 정해진 크기가 없는 linked-list와 비슷한 자료형이다.

	int ASCII[(UINT)eKeyCode::End] = {  //아스키 코드를 따로 묶어놓은 배열(아래의 Update 함수에서 반복문을 만들 때 if문을 하나만 쓸 수 있게 하기 위해서 만든 배열이다.)
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
	{
		mKeys.resize((UINT)eKeyCode::End);  //resize -> vector의 크기를 바꿔주는 함수

		//UINT -> unsigned int의 별칭을 준 것으로 UINT=unsigned int라고 생각하면 된다.
		//size_t -> unsigned __int64
		//아래 for문은 vector형 정적 멤버 변수인 mKeys를 초기화하기 위한 반복문
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {  //enum은 자동으로 형 변환이 되기에 상관없지만 enum class는 그런 것이 없어 정수와 비교하기 위해서는 형 변환을 해주어야 한다.
			Key key = {};
			key.bPressed = false;  //초기화 단계에서는 키가 눌려있지 않기 때문에 false로 초기화
			key.state = eKeyState::None;  //초기화 단계에서는 키가 그 어떤 동작도 하지 않기 때문에 None으로 초기화
			key.keyCode = (eKeyCode)i;  //i에 맞는 키보드 알파벳을 할당(근데 enum class는 자동 형 변환이 안 되기 때문에 이와 같이 형 변환을 같이 해주어야 한다.)

			mKeys.push_back(key);  //push_back -> vector에 요소를 추가하는 함수
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++) {  //배열처럼 벡터도 size함수로 크기를 알 수 있다.
			//키가 눌렸는지 아닌지 확인하는 if문
			//위의 ASCII 배열이 있기 때문에 키 갯수만큼 아래처럼 if문을 만들어서 여러 개 만들어야 할 필요없이 하나의 if문만 만들어서 실행할 수 있게 되었다.
			//if (GetAsyncKeyState('W') & 0x8000) {

			//}

			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {  //키가 눌려져 있는 상태
				if (mKeys[i].bPressed == true) {  //이전에도 키가 눌려져 있었는지를 확인(눌려져 있었다면 계속 눌려져있는 것이기 때문에 pressed가 되는 것이고 아니였다면 지금 누른 거니까 down이 되는 것이다.)
					mKeys[i].state = eKeyState::Pressed;
				}
				else {
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].bPressed = true;  //눌려 있는 것이기 때문에 true가 되어야 한다.
			}
			else {  //키가 안 눌려져 있는 상태
				if (mKeys[i].bPressed == true) {  //이전에도 키가 눌려져 있었는지를 확인(눌려져 있었다면 이제 때는 것이기 때문에 up이 되는 것이고 아니였다면 아무것도 누르지 않은 상태니까 none이 되는 것이다.)
					mKeys[i].state = eKeyState::Up;
				}
				else {
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].bPressed = false;  //눌리지 않은 것이기 때문에 true가 되어야 한다.
			}
		}
	}
}
