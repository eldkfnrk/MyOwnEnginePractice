// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

//깃허브 테스트용 코드 변경

#include "framework.h"
#include "Editor_Window.h"
#include "CommonInclude.h"

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

    // 기본 메시지 루프입니다:
    //메시지 루프에서 메시지란 사용자나 시스템 내부적인 동작에 의해 발생된 일체의 변화에 대한 정보를 의미한다.
    //사용자가 종료할 때까지 계속 화면이 켜져 있어야 하기 때문에 다음과 같이 while문 등을 통해 프로그램이 계속 돌게 하여야 한다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

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
      CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);  //윈도우 창을 만드는 함수.(szTitle 변수에 들어오는 값을 이름으로 하는 윈도우 창을 생성)
   //1번째 인자에는 만들 윈도우 창에 대한 정보를 가지고 있는 클래스의 이름이 들어간다. 해당 이름으로 되어있는 정보들을 가지고 와서 윈도우 창에 기본 구성을 하게 된다.
   //4~5번째 인자는 창의 생성 위치, 6~7번째 매개변수는 창의 크기를 관장한다.(CW_USEDEFAULT, 0는 프로젝트 생성 시 설정된 기본 크기로 위와 같이 크기를 자기가 설정할 수도 있다.)

   //위에서 세 번째 인자로 들어가는 값은 옵션으로 값에 따라 윈도우 창의 형태를 값에 맞게 다르게 바꿀 수도 있다.(그러나 위의 윈도우를 만드는 코드를 크게 건드릴 필요가 없다.)
   //이번 강의에서는 바꿀 일이 없지만 상황에 맞게 해당 매개변수의 값을 바꿔 윈도우 창의 형태를 알맞게 바꾸면 된다.

   //CreateWindowW 함수가 정상적으로 윈도우 창을 생성하면 핸들 값을 반환한다.(여러 이유로 윈도우 창 생성에 실패할 경우 null을 반환)

   //HWND hWnd1 = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //    CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);  //CreateWindowW를 이렇게 또 한 번 하면 윈도우 창이 하나 더 생성된다.(물론 핸들 값을 저장하는 변수 이름은 다르게 해야 한다.)
   //즉, 이 프로그램을 실행시킬 때 무조건 윈도우 창은 하나만 뜨는 것이 아닌 여러 개를 뜨게 만들 수도 있다는 것이다.

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);  //위에서는 메모리 상에 윈도우 창을 만드는 것이고 이 만들어진 윈도우 창을 화면에 출력하기 위해 이 함수를 사용(이 함수가 호출이 되어야 창이 뜨게 된다.)
                                //이 함수 호출이 없는 경우 생성된 창은 화면에 출력이 되지 않고 메모리 상에만 존재하게 된다.
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  //메시지 루프 함수
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
            HDC hdc = BeginPaint(hWnd, &ps);  //첫 번째 인자로 핸들을 받아 어느 윈도우 창의 dc인지를 반환하여 변수에 저장하여 사용
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            //아래와 같이 코드를 브러쉬를 사용할 셩우 주의해야 할 것은 이 프로그램은 C++이기 때문에 순서가 중요하다. 
            //바꾸고 싶은 것이 있다면 맨 위에 적용하고 싶은 부분보다 blueBrush 관련 코드가 위에 있어야 하며 만약 아래에 간다면 변경이 되지 않는다.
            //컴파일러가 코드를 순차적으로 컴파일하기 때문에 이런 일이 생기게 된다.
            
            //도형 안 배경 색상 칠하기
            //1.파랑 브러쉬 생성
            HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));  //해당 rgb값의 색상 정보를 저장
            //SelectObject(hdc, blueBrush);
            //2.파랑 브러쉬 DC에 선택 그리고 하얀 브러쉬 반환 값 저장
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);  //SelectObject 함수를 사용해 2번째 인자로 받은 값을 적용
            //이때 SelectObject 함수는 변경되기 전의 값을 리턴하게 된다. 그러니까 화면에는 rgb값에 맞는 색상으로 아래 코드 도형이 칠해지면서 동시에 하얀 배경이라는 정보를 oldBrush 변수에 저장하는 것이다.

            //조금 더 자세하게 설명하자면 한 개의 DC에는 한 개의 브러쉬만 사용이 가능하다. 그렇다면 SelectObject로 브러쉬를 바꾼다면 다른 브러쉬는 사용하지 않고 메모리 상에 남아있게 된다.
            //이때 SelectObject함수는 이 바꾸기 전 브러쉬 값을 저장한 메모리 값을 반환하게 되는 것이다.
            //이렇게 저장해놓지 않으면 흰색 배경의 브러쉬의 메모리 값을 잃어버리게 돼서 원래 값으로 돌리려 해도 돌릴 수 없기에 저장해놓는 것이 좋다.

            //화면에 네모 그리기
            Rectangle(hdc, 100, 100, 200, 200);  //첫 번째 인자로 dc를 받게 되는데 여러 창을 만드는 경우 dc값에 맞는 윈도우 창에서 동작하게 되니 이를 실수하지 않게 유의하여 사용해야 한다.
            //2번째 인자부터 순서대로 좌, 상, 우, 하의 위치 정보를 얻어 네모의 좌상단과 우하단의 꼭지점 값을 얻어 이에 맞게 네모를 만든다.

            //3.다시 흰색 브러쉬 선택
            (HBRUSH)SelectObject(hdc, oldBrush);  //다시 도형 안의 색깔을 oldBrush에 저장된 흰색으로 변경한다.

            //4.파랑 브러쉬 삭제
            DeleteObject(blueBrush);
            //DeleteObject 함수는 WinApi에서 동적 할당의 delete 역할을 하는 함수이다.
            //위와 같은 과정이 필요한 이유는 blueBrush 변수에 있는데 blueBrush 변수는 메시지 루프가 반복될 때마다 계속 코드가 생기는데 이때 이 변수는 포인터이기 때문에 메모리 값을 동적 할당받게 된다.
            //그러면 루프가 한 번하고 끝난 이후에도 변수에 할당된 메모리는 계속 남아있는 상태로 다시 한 번 반복되면 호출 시 또 다시 메모리를 할당받는 것이 반복되게 되며 이러면 많은 메모리 손실이 발생하게 된다.
            //그렇기 때문에 할당된 메모리를 해제해주는 것이 필요하여 위와 같이 DeleteObject함수를 사용하는 과정을 거치는 것이다.
            //그렇게 되면 메모리를 할당받은 후 다 사용한 후 메모리가 해제되면서 메모리 손실이 일어나지 않게 되는 것이다.

            //도형 선 색깔 바꾸기
            //선 색깔 바꾸는 것도 브러쉬와 같이 일련의 과정을 거치게 된다.
            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));  //PS_SOLID - 기본선 ctrl+클릭으로 선 모양을 보고 알아서 선택 가능, 2번째 인자는 선의 굵기로 기본 값은 1, 3번째인자는 브러쉬와 같이 색상 값

            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

            //화면에 원 그리기
            Ellipse(hdc, 200, 200, 400, 400);
            //WinApi의 원 그리는 방식은 살짝 독특한데 좌상단과 우하단의 좌표값을 받고 네모를 그린 후 그 안에 딱 들어가는 원을 그리는 방식이다.(값에 따라 타원이 그려질 수도 있다.)

            (HPEN)SelectObject(hdc, oldPen);
            DeleteObject(redPen);

            //기본으로 자주 사용되는 GDI오브젝트를 미리 DC 안에 만들어두었는데 그 오브젝트들을 스톡 오브젝트라 한다.

            //스톡 오브젝트 사용 예시
            //스톡 오브젝트는 윈도우가 만들어질 때 기본으로 만들어져 있기 때문에 Create를 하지 않는다.(만들 필요가 없다는 의미)

            //스톡 오브젝트는 GetStockObject함수를 이용하여 불러온다.
            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);  //회색 브러쉬 호출

            //이제 지우는 과정을 뺀 나머지는 위의 두 오브젝트를 사용한 것과 같다.(스톡 오브젝트는 이미 있는 것을 사용하는 것이기 때문에 DeleteObject를 하면 안 된다.)
            oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);  //오브젝트를 DC에 선택해줘야 하는 것은 다른 만드는 오브젝트와 같다.

            Rectangle(hdc, 100, 100, 200, 200);

            SelectObject(hdc, oldBrush);  //이렇게 사용하고 다시 흰색으로 돌려놓는 것이 안전하게 WinApi 프로그램을 사용하는 방법이다.

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:  //창을 종료할 때
        PostQuitMessage(0);
        break;

    //아래의 두 case는 추가한 코드로 여러 상황을 상정하고 코드를 구성할 수 있음을 알 수 있다.
    //이런 메시지들은 필요한 경우에 하나하나 추가하여 사용하면 된다.
    //case WM_MOVE:  //윈도우 창을 움직일 때
    //{
    //    int a = 0;
    //}
    //    break;
    //case WM_LBUTTONDOWN:  //윈도우 안에서 좌클릭을 했을 때
    //{
    //    int a = 0;
    //}
    //    break;

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
