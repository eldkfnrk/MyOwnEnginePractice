#pragma once
#include "CommonInclude.h"
namespace mfe {
	//enum은 숫자에 별칭을 주는 것이라고 볼 수 있다.(각 상수에 이름이 붙는 것이기 때문이다.)
	//enum은 별도의 이름공간을 가지고 있지 않기 때문에 이름이 중복되는 문제가 발생할 수 있는데 이를 enum class라는 문법으로 해결(enum들을 정확하게 구분시켜주기 위해 사용)
	//enum의 이름 공간이라고 생각하면 조금 더 이해하기 쉽다.(실제로 사용할 때도 ::연산자를 사용해서 열거자를 사용한다.)
	enum class eKeyState {  //키의 입력 상태
		Down,
		Pressed,
		Up, 
		None,
	};

	enum class eKeyCode {  //키 구분(숫자 등의 키는 후에 추가 예정, 일단 알파벳만)
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End,
	};

	class Input  //입력과 관련된 것을 모아놓은 클래스
	{
	public:
		struct Key  //키 하나당 가지고 있는 정보
		{
			//char KeyCode;  //이렇게 문자로 처리하면 대소문자 구분을 시켜줘야 하는 문제가 있어 enum을 활용하여 구분
			eKeyCode keyCode;  //어떤 키가 입력되는지 알기 위한 변수
			eKeyState state;  //키 입력 상태를 나타내는 변수
			bool bPressed;  //키가 눌려있는지 알기 위한 변수
		};

		static void Initailize();
		static void Update();

		//정적 멤버 함수 -> 클래스 내의 전역 함수라고 볼 수 있다.(정적 멤버 변수에 저장된 값을 가져오기 위한 함수)
		//함수의 이름은 유니티에서 사용하는 이름과 동일하게 사용
		static bool GetKeyDown(eKeyCode code) {  //down이면 true 반환
			//삼항 연산자는 '조건식 ? 반환값1 : 반환값2' 형태로 쓰고 조건식이 참이면 반환값1을 거짓이면 반환값2를 반환하는 연산자이다.
			//return (mKeys[(UINT)code].state == eKeyState::Down) ? true : false;  
			//그러나 굳이 return에서 조건문을 사용할 때에는 삼항 연산자를 사용하지 않아도 된다.
			return mKeys[(UINT)code].state == eKeyState::Down;  //이 조건식이 참이면 true를 거짓이면 false를 반환할 것이기 때문이다.
		}
		static bool GetKey(eKeyCode code) {  //pressed이면 true 반환
			return mKeys[(UINT)code].state == eKeyState::Pressed;
		}
		static bool GetKeyUp(eKeyCode code) {  //up이면 true 반환
			return mKeys[(UINT)code].state == eKeyState::Up;
		}

	private:
		//입력 상태 종류 - 키를 눌렀을 때(down), 키를 누르고 있을 때(pressed), 누른 키를 뗐을 때(up)
		//int mState;  //0 - down, 1 - pressed, 2 - up, 3 - none(아무것도 하지 않는 상태)
		//위와 같이 int형 변수로 상태를 체크하려고 코드를 작성하면 작성자는 이를 알고 작성하지만 다른 사람들은 이게 무엇을 의미하는지 모를 수 있는 문제가 발생할 수 있다.
		//eKeyState mState;  //위의 int형 변수를 enum 자료형으로 변경한 것(enum class는 이렇게 자료형처럼 사용한다.)

		//키보드에는 수 십 개의 키가 존재하기 때문에 모든 키의 상태를 알고 있어야 하므로 배열을 사용하여야 한다.
		//이를 위하여 vector 사용
		static std::vector<Key> mKeys;  //정적 멤버 변수(객체 지향의 캡슐화를 지켜주는 문법) -> 외부에서 데이터를 건드는 것은 막기 위하여 이와 같이 사용
		//정적 멤버 변수로 선언한 이유는 키 입력이 하나의 대상에서만 사용하는 것이 아닐 수 있기 때문에 어디서든 사용 가능하게 하려면 전역 변수로 선언하여야 하는데 그러면 
		//어디서든 접근이 가능해지면서 문제가 발생할 수 있기 때문에 같은 클래스 타입만 접근이 가능한 전역 변수처럼 만들기 위해 정적 멤버 변수로 선언한 것이다.
		//정적 멤버 변수는 해당 클래스 타입에 해당하는 것만 접근할 수 있는 전역 변수처럼 사용할 수 있는 그런 문법이다.
	};
}
