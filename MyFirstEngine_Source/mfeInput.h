#pragma once
#include "CommonInclude.h"
namespace mfe {
	enum class eKeyState {
		Down,
		Pressed,
		Up, 
		None,
	};

	enum class eKeyCode {  //Ű ����(���� ���ĺ��� �ִ� Ű�� ����Ű �߰�)
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		End,
	};

	class Input 
	{
	public:
		struct Key
		{
			eKeyCode keyCode;  //� Ű�� �ԷµǴ��� �˱� ���� ����
			eKeyState state;  //Ű �Է� ���¸� ��Ÿ���� ����
			bool bPressed;  //Ű�� �����ִ��� �˱� ���� ����
		};

		static void Initailize();
		static void Update();

		
		static bool GetKeyDown(eKeyCode code) {  //down�̸� true ��ȯ
			return mKeys[(UINT)code].state == eKeyState::Down;  
		}
		static bool GetKey(eKeyCode code) {  //pressed�̸� true ��ȯ
			return mKeys[(UINT)code].state == eKeyState::Pressed;
		}
		static bool GetKeyUp(eKeyCode code) {  //up�̸� true ��ȯ
			return mKeys[(UINT)code].state == eKeyState::Up;
		}

	private:
		static std::vector<Key> mKeys;
	};
}
