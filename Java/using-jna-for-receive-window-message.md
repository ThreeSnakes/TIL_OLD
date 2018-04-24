# JNA 사용해서 윈도우 메세지 받기 
양산프로그램 개발에 있어서 RF Test 결과를 Window Message로 받아야 한다.
Window Message를 받으려면 JNA를 이용해서 개발 해야 한다. 
일단 아래 코드는 예제에서 Window Message를 받는 부분을 뽑아내서 적용한 결과 이다.

[JNA 라이브러리](https://github.com/java-native-access/jna)를 다운로드 받고 적용 시키자.

그다음은 실제 구현 코드이다.

``` java
package Function;
import com.sun.jna.WString;
import com.sun.jna.platform.win32.Kernel32;
import com.sun.jna.platform.win32.User32;
import com.sun.jna.platform.win32.WinDef.HMODULE;
import com.sun.jna.platform.win32.WinDef.HWND;
import com.sun.jna.platform.win32.WinDef.LPARAM;
import com.sun.jna.platform.win32.WinDef.LRESULT;
import com.sun.jna.platform.win32.WinDef.WPARAM;
import com.sun.jna.platform.win32.WinUser.MSG;
import com.sun.jna.platform.win32.WinUser.WNDCLASSEX;
import com.sun.jna.platform.win32.WinUser.WindowProc;

public class Win32WindowDemo implements WindowProc {
	public static final String TAG = "Win32WindowDemo"; 
	
	public static final int WM_USER = 0x0400;

	public RF_Test_Controller controller;
	
//	isMessageData messageData = RF_Test_Controller.messageData;

	/**
	 * Instantiates a new win32 window test.
	 */
	public Win32WindowDemo() {
		controller = RF_Test_Controller.getInstance();
		
		// define new window class
		WString windowClass = new WString("MyWindowClass");
		HMODULE hInst = Kernel32.INSTANCE.GetModuleHandle("");

		WNDCLASSEX wClass = new WNDCLASSEX();
		wClass.hInstance = hInst;
		wClass.lpfnWndProc = Win32WindowDemo.this;
		wClass.lpszClassName = windowClass;

		// register window class
		User32.INSTANCE.RegisterClassEx(wClass);
		getLastError();

		// create new window
		HWND hWnd = User32.INSTANCE
				.CreateWindowEx(
						User32.WS_EX_TOPMOST,
						windowClass,
						"My hidden helper window, used only to catch the windows events",
						0, 0, 0, 0, 0,
						null, // WM_DEVICECHANGE contradicts parent=WinUser.HWND_MESSAGE
						null, hInst, null);
		
		getLastError();
		System.out.println(TAG + ", [ hWnd = " + hWnd.getPointer().toString() + " ]");

		getLastError();
		
		MSG msg = new MSG();
		while (User32.INSTANCE.GetMessage(msg, hWnd, 0, 0) != 0) {
			User32.INSTANCE.TranslateMessage(msg);
			User32.INSTANCE.DispatchMessage(msg);
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * com.sun.jna.platform.win32.User32.WindowProc#callback(com.sun.jna.platform
	 * .win32.WinDef.HWND, int, com.sun.jna.platform.win32.WinDef.WPARAM,
	 * com.sun.jna.platform.win32.WinDef.LPARAM)
	 */
	public LRESULT callback(HWND hwnd, int uMsg, WPARAM wParam, LPARAM lParam) {
		if(uMsg == WM_USER + 865) {
			System.out.println( TAG + ", [-------------User Message---------------------]");
			System.out.println( TAG + ", [ " + wParam.toString() + " ]");
			System.out.println( TAG + ", [ " + lParam.toString() + " ]");
			System.out.println( TAG + ", [-------------User Message---------------------]");
			controller.getMessageData( wParam.intValue(), lParam.intValue());
//			messageData.getMessageData(wParam.intValue(), lParam.intValue());
			return new LRESULT(0);
		} 
		return new LRESULT(1);
	}

	/**
	 * Gets the last error.
	 * 
	 * @return the last error
	 */
	public int getLastError() {
		int rc = Kernel32.INSTANCE.GetLastError();

		if (rc != 0)
			System.out.println( TAG + ", [ error: " + rc + " ]");

		return rc;
	}
}

```

위 코드를 보면 실제 GPS Test를 진행상황을 보여주는 Frame을 말고 안보이는 Frame이 하나 더생긴다. 기본적으로는 GPS Test Frame에 JNA를 적용시켜야야 하는것이 맞는데 이상하게 적용이 안되서. 위에 소스처럼 Hiddned Frame을 만들었다. Window Message는 Hidden Frame에서 받아서 처리해준다. callback 을 통해서 메세지를 받은다음 Window Message의 값을 받아서 처리한다. 
