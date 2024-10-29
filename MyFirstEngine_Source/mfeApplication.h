#pragma once
#include "mfeGameObject.h"

namespace mfe {
	class Application
	{
	private:
		HWND mHwnd;
		HDC mHdc;
		
		//DC를 하나 더 추가하는 이유
		//도화지를 두 개를 사용할 때 하나의 DC에서만 작업하는 경우에는 프레임마다 도화지를 바꿔가면서 그림을 그리게 되면 도형을 DC에 그려주는 SelectObject 함수를
		//프레임마다 호출해야 되고 그러면 효율성이 떨어지게 되기 때문에 이 과정을 생략하기 위한 약간의 꼼수를 부려서 조금이라도 효율성을 높이고자 DC를 하나 더 추가해서 
		//하나의 DC에서 그린 그림을 다른 DC에 덮어씌우고 출력하고 또 그린 후 덮어씌우고를 반복하는 꼼수를 이용한다.
		//원래는 도화지를 번갈아가면서 그리고 지우고 그리고를 하는 것이 더블 버퍼링이지만 이 과정에 약간 꼼수를 부려서 더블 버퍼링을 구현하는 것이다.
		HDC mBackHdc;

		//DC에서는 기본적으로 브러쉬와 펜이 있으면 그림을 그리기 위한 것이 필요하니 도화지를 지원하고 이 도화지의 자료형이 BITMAP이다.
		//DC는 처음부터 한 장의 도화지를 가지고 있고 우리는 지금까지 그 도화지 한 장에 그림을 그리고 있었는데 잔상을 지우기 위해 2개의 도화지를 사용하려
		//하기에 새로운 도화지를 하나 더 DC에 추가하는 것이다.
		HBITMAP mBackBitmap;  //BITMAP은 압축이 되어 있지 않은 다른 말로 원본 그대로의 그림 파일을 의미한다.

		//왜 도화지가 비트맵이냐 하면 사실 우리가 보는 화면은 우리 눈에 안 보일 정도로 작은 픽셀들로 이루어져있는데 이 픽셀들의 단위가 비트이고 그 픽셀에 저장된
		//비트 정보를 관리하고 그걸 출력하기 때문에 비트맵이 도화지 역할을 하는 것이다.

		//화면 크기(해상도)
		UINT mWidth;  //좌우폭
		UINT mHeight;  //상하폭
		
		GameObject player;

	public:
		Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		~Application();
	};
}