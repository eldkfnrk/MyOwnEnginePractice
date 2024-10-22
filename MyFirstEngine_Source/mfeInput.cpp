#include "mfeInput.h"

namespace mfe {
	std::vector<Input::Key> Input::mKeys = {};  //�ƹ��͵� �� ����ִ� ���·� �ʱ�ȭ
	//���� ��� ������ Ŭ������ ���� �����̱� ������ �ʱ�ȭ�� �Ǿ�� �ϴµ� Ŭ���� �������� �ʱ�ȭ�ϴ� ���� �� �Ǳ� ������ Ŭ���� �ܿ��� ���� �ʱ�ȭ���־�� �Ѵ�.
	//���� ��� ������ �� �� �Ҵ�Ǹ� ���α׷��� ����Ǳ� �������� ������� �ʴ´�.
	//Input::Key -> Key ����ü�� Ŭ���� ���� �ִ� ����ü�̱� ������ �̿� ���� ::�����ڷ� ��� �Ҽ����� Ȯ���ؾ� �Ѵ�.
	
	//vector�� �迭�� ��������� ������ ũ�Ⱑ ���� linked-list�� ����� �ڷ����̴�.

	int ASCII[(UINT)eKeyCode::End] = {  //�ƽ�Ű �ڵ带 ���� ������� �迭(�Ʒ��� Update �Լ����� �ݺ����� ���� �� if���� �ϳ��� �� �� �ְ� �ϱ� ���ؼ� ���� �迭�̴�.)
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
	{
		mKeys.resize((UINT)eKeyCode::End);  //resize -> vector�� ũ�⸦ �ٲ��ִ� �Լ�

		//UINT -> unsigned int�� ��Ī�� �� ������ UINT=unsigned int��� �����ϸ� �ȴ�.
		//size_t -> unsigned __int64
		//�Ʒ� for���� vector�� ���� ��� ������ mKeys�� �ʱ�ȭ�ϱ� ���� �ݺ���
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {  //enum�� �ڵ����� �� ��ȯ�� �Ǳ⿡ ��������� enum class�� �׷� ���� ���� ������ ���ϱ� ���ؼ��� �� ��ȯ�� ���־�� �Ѵ�.
			Key key = {};
			key.bPressed = false;  //�ʱ�ȭ �ܰ迡���� Ű�� �������� �ʱ� ������ false�� �ʱ�ȭ
			key.state = eKeyState::None;  //�ʱ�ȭ �ܰ迡���� Ű�� �� � ���۵� ���� �ʱ� ������ None���� �ʱ�ȭ
			key.keyCode = (eKeyCode)i;  //i�� �´� Ű���� ���ĺ��� �Ҵ�(�ٵ� enum class�� �ڵ� �� ��ȯ�� �� �Ǳ� ������ �̿� ���� �� ��ȯ�� ���� ���־�� �Ѵ�.)

			mKeys.push_back(key);  //push_back -> vector�� ��Ҹ� �߰��ϴ� �Լ�
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++) {  //�迭ó�� ���͵� size�Լ��� ũ�⸦ �� �� �ִ�.
			//Ű�� ���ȴ��� �ƴ��� Ȯ���ϴ� if��
			//���� ASCII �迭�� �ֱ� ������ Ű ������ŭ �Ʒ�ó�� if���� ���� ���� �� ������ �� �ʿ���� �ϳ��� if���� ���� ������ �� �ְ� �Ǿ���.
			//if (GetAsyncKeyState('W') & 0x8000) {

			//}

			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {  //Ű�� ������ �ִ� ����
				if (mKeys[i].bPressed == true) {  //�������� Ű�� ������ �־������� Ȯ��(������ �־��ٸ� ��� �������ִ� ���̱� ������ pressed�� �Ǵ� ���̰� �ƴϿ��ٸ� ���� ���� �Ŵϱ� down�� �Ǵ� ���̴�.)
					mKeys[i].state = eKeyState::Pressed;
				}
				else {
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].bPressed = true;  //���� �ִ� ���̱� ������ true�� �Ǿ�� �Ѵ�.
			}
			else {  //Ű�� �� ������ �ִ� ����
				if (mKeys[i].bPressed == true) {  //�������� Ű�� ������ �־������� Ȯ��(������ �־��ٸ� ���� ���� ���̱� ������ up�� �Ǵ� ���̰� �ƴϿ��ٸ� �ƹ��͵� ������ ���� ���´ϱ� none�� �Ǵ� ���̴�.)
					mKeys[i].state = eKeyState::Up;
				}
				else {
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].bPressed = false;  //������ ���� ���̱� ������ true�� �Ǿ�� �Ѵ�.
			}
		}
	}
}
