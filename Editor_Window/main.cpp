// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

//깃허브 테스트용 코드 변경

#include "framework.h"
#include "Editor_Window.h"
#include "..//MyFirstEngine_Source//mfeApplication.h"  //맨 앞에 ..은 상위 디렉토리를 의미하고 /를 2개씩 쓴 이유는 구분이 잘 되라고 해놓은 것이고 1개만 써도 된다.
//지금 여기서 include 한 파일은 현재 위치의 파일과 다른 폴더에 있는데 이런 경우에는 해당 파일의 경로를 정확하게 기입하여서 사용하여야 한다.

//#pragma comment (lib, "..//x64//Debug//MyFirstEngine_Window.lib")  //라이브러리를 사용할 수 있게 연결해주는 전처리로 이 구문을 추가하면 라이브러리 안에 있는 것 모두를 사용할 수 있다.
//이 방법은 코드를 사용해서 연결시키는 방법이다.
//위의 방법 말고도 라이브러리 프로젝트를 참조하는 다른 방법도 있다.(이 방법은 비주얼 스튜디오 옵션을 이용해 연결시킨 것으로 만약에 이런 옵션이 없다면 위의 방법을 사용하여 연결하여야 한다.)

//라이브러리를 연결해야 하는 이유는 다른 폴더에 있는 헤더 파일을 include를 할 수는 있지만 헤더 파일을 include한다고 해서 기능을 구현한 소스 파일을 가져오는 것은 불가능하기 때문에
//이것들을 모두 사용할 수 있게 빌드가 완료된 라이브러리를 가져와서 연결해야만 하는 것이다.

Application app;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

//WCHAR -> 2바이트짜리 글자를 담을 수 있는 자료형(1바이트짜리 자료형인 char로는 부족할 수 있으니 더 큰 자료형인 2바이트 짜리 wchar_t자료형을 WCHAR라는 별명을 붙여 사용)

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,  //프로그램의 인스턴스 핸들
                     _In_opt_ HINSTANCE hPrevInstance,  //바로 앞에 실행된 현재 프로그램의 인스턴스 핸들(없을 경우에는 NULL) -> 과거 개발자들이 사용하던 것으로 현재는 호환성을 문제로 아예 사용x
                     _In_ LPWSTR    lpCmdLine,  //명령행으로 입력된 프로그램 인수 -> 특정 프로그램을 실행할 때 특정 값을 넘겨줄 수 있는데 이때 값을 의미(거의 쓸 일 없다)
                     _In_ int       nCmdShow)  //프로그램이 실행될 형태로 보통 모양 정보 등이 전달(윈도우 창의 모양 정보)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    app.test();

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    //GetMessage(&msg, nullptr, 0, 0)
    //프로세스에서 발생한 메시지를 메시지 큐에서 가져오는 함수
    //메시지 큐에 아무것도 없다면 -> 아무 메시지도 가져오지 않음

    //PeekMessage 함수 -> 메시지 큐에 메시지 유무에 상관없이 함수가 리턴
    //                    리턴값이 true인 경우 메시지가 있다 리턴값이 false인 경우 메시지가 없다라고 가르켜준다.
    //인자로는 GetMessage함수와 동일하게 들어가는데 인자가 하나 더 들어가는데 그것은 메시지를 가져올 때마다 그 메시지를 처리를 해줄건지 안 해줄건지를 결정하는 값으로
    //이 함수는 메시지 큐에 메시지가 남아있어도 따로 아무것도 하지 않으면 그대로 남아있기 때문에 메시지를 읽으면 없애줘야해서 PM_REMOVE값을 인자로 전달해야 한다.

    //GetMessage 함수는 메시지가 없으면 멈춰있고 PeekMessage 함수는 메시지가 없어도 멈춰있지 않는다는 차이점이 있다.

    //게임을 동작시키기 위해서는 메시지 루프가 아닌 항상 반복하는 반복문이 필요해서 아래와 같이 만들게 된다.
    //이 과정을 마지막으로 WinApi main함수에서의 구조적인 변경은 마무리가 되었고 게임에 필요한 것을 추가해서 게임을 만들어나가면 된다.
    //구조적 변경이 끝난거지 동작에 관한 변경은 계속해서 이루어진다.
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {   //메시지가 들어오면 true 안 들어오면 false를 반환(메시지가 있으면 if문 실행 없으면 다시 반복문의 시작점으로 가는 것이다.)
            if (msg.message == WM_QUIT)  //메시지가 종료인 경우
                break;  //반복문 종료

            //메시지가 있다면 메시지 루프와 동일한 동작을 하게 된다.
            //메시지가 없어도 계속 프로그램이 동작하게 하기 위해서 반복문을 살짝 변형을 했지만 메시지 처리 방법은 기존 메시지 루프와 동일하다.
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else {
            //메시지가 없을 경우 여기서 처리
            //이 부분에 게임 로직이 들어가면 된다.(입력이 없어도 동작해야 하기 때문에)
        }
    }

    //프로젝트를 하나만 쓰는 것이 아니라 여러 개로 쪼개서 사용(빌드하는 시간을 구분시키기 위해서)
    //경로에 한글 이름이 들어가면 문제가 생길 가능성이 높아지니 최대한 지양하는 것이 좋다.
    //'빈 프로젝트'를 추가해주고 해당 프로젝트의 속성에 들어가서 구성은 '모든 구성', 플랫폼은 '모든 플랫폼'을 선택하고 일반 탭에서 구성 형식을 '정적 라이브러리'로 변경
    //새로 만드는 프로젝트는 실행하는 프로젝트가 아닌 소스코드를 모아두는 프로젝트이기 때문에 정적 라이브러리로 만들어야 한다.
    //이번에 만들어 볼 엔진의 새로 만든 프로젝트에서 외부 종속성 폴더를 제외한 나머지 폴더는 필요가 없기 때문에 삭제한다.

    //정적 라이브러리 - 프로그램이 시작하면 프로그램의 메모리 안에 있는 상태로 사용하는 라이브러리
    //장점
    //시스템 환경이 변해도 어플리케이션에 아무런 영향이 없다.(왜냐하면, 프로그램 자체에 라이브러리가 들어가 있는 것이기 때문에 외부의 환경에 영향을 받지 않는다.)
    //컴파일 시 필요한 라이브러리를 적재하기 때문에 이식성이 좋다.
    //런타임 시 외부를 참조할 필요가 없기 때문에 속도가 빠르다.
    //단점
    //같은 코드를 가진 프로그램이 2개 이상 실행할 경우 코드가 중복되면서 그만큼의 메모리를 낭비하게 된다.
    //라이브러리가 변경되면 변경된 라이브러리만 재배포하면 되는게 아니라 다시 컴파일해서 새로 빌드된 버전 전체를 배포해야 한다.(현재 시중에 나온 라이브 게임들이 이런 방식으로 나온다.)

    //위와 같은 단점이 있는 동적 라이브러리를 쓰지 않는 이유는 관리하기가 어렵고 테스트하기도 어렵기 때문이다.
    //테스트가 어려운 이유는 변경 사항을 빌드해봤을 때 라이브러리 관련 문제가 나오지 않아서 실제 실행시켰을 때 문제가 발생할 수 있기 때문이다.

    //동적 라이브러리 - 메모리 상에 존재하고 있는 상태로 프로그램들이 사용하려면 메모리 상에 있는 것을 접근해서 사용하는 라이브러리
    //장점
    //메모리 절약
    //보다 쉽게 업그레이드해서 배포 가능
    //서로 다른 프로그램에서 동일한 함수를 호출 가능
    //프로그램 변경 시 라이브러리만 재배포하면 되니까 유지보수가 쉽다.
    //단점
    //외부 의존도가 높기 때문에 이식성이 낮다.
    //공유 라이브러리를 메모리에 올려놓고 해당 라이브러리를 찾아서 접근해야되기 때문에 속도가 느리다.

    //이번에 만드는 것을 배포할 것도 아니고 다른 엔진에서 사용할 것도 아니기에 우리는 정적 라이브러리 사용

    //이번 프로그램에서 C++ 버전을 기존 14에서 20으로 올려서 사용할 예정
    //속성에 들어가서 구성 속성 안에 일반 탭에서 C++ 언어 표준에서 바꾸면 된다.(모든 프로젝트들이 이 작업이 실행되어야 한다.)

    //또 이번에는 소스 코드를 묶어놓기 위한 프로젝트를 하나 더 생성한다.
    //이번 프로젝트는 공유 항목 프로젝트라는 것으로 생성
    //정적 라이브러리에서 사용할 소스 코드를 따로 묶어놓는 역할을 하는 프로젝트이다.

    //헤더 파일 안에 클래스 선언하고 소스 코드 만들어서 기능 추가하는 것을 파일 만드는 과정에서 할 수 있는데 그것은 추가에서 클래스를 누르고 생성
    //클래스 이름은 상관없으나 파일의 이름은 통상적으로 사용하는 이름으로 하게 되면 문제가 발생할 수 있기 때문에 통상적인 이름을 쓰고 싶으면 앞이나 뒤에 따로 특징을 줄 수 있도록 해야 한다.

    //정적 라이브러리 프로젝트에서 공유 항목 프로젝트에 만들어진 파일들을 사용하기 위해서는 정적 라이브러리 프로젝트에서 참조를 우클릭하여 
    //참조 추가를 클릭한 후 공유 프로젝트에서 해당 프로젝트를 선택 후 확인을 눌러 참조를 시켜야 한다.

    //이렇게 프로젝트를 나누면 프로젝트마다 빌드가 되면서 구분이 된다.

    //메인 프로젝트(응용 프로그램)에서는 툴같은 것을 사용할 것이고 라이브러리 프로젝트는 게임 같은 것을 모아두게 될 것이다.

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)  //윈도우의 정보를 세팅해주는 함수
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;  //윈도우 정보를 세팅할 때 루프 함수의 이름이 인자로 들어가는 것을 알 수 있다.(이 클래스의 요소 lpfnWndProc은 함수 포인터이기 때문에 이렇게 함수의 값을 전달)
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);  //만드는 창의 커서의 모양을 지정(IDC_ARROW 매개변수 부분에 값을 바꾸면 해당 값의 커서로 모양이 변한다.)
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = szWindowClass;  //윈도우 창의 형태에 대한 정보를 가지는 클래스의 이름
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);  

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            
            HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));  
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);  

            Rectangle(hdc, 500, 500, 700, 700);  

            (HBRUSH)SelectObject(hdc, oldBrush);  

            DeleteObject(blueBrush);
            
            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  

            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

            Ellipse(hdc, 200, 200, 400, 400);
           
            (HPEN)SelectObject(hdc, oldPen);
            DeleteObject(redPen);

            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);

            oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);

            Rectangle(hdc, 100, 100, 200, 200);

            SelectObject(hdc, oldBrush);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:  //창을 종료할 때
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
