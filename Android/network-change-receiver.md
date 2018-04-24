Network Change Receiver.
-
앱에서 Network가 끊어진 상황에서 Network가 다시 연결되면 자동으로 로그인 하는 코드 이다. 

안드로이드 Menifest.xml 에 다음을 작성해준다.

``` java
<!-- Network State Receiver  -->
    <receiver
        android:name=".service.server.NetworkChangeReceiver">
        <intent-filter>
            <action android:name="android.net.conn.CONNECTIVITY_CHANGE" />
        </intent-filter>
    </receiver>
```

다음은 실제 class 파일이다.
``` java
public class NetworkChangeReceiver extends BroadcastReceiver{
    private static final String TAG = "NetworkChangeReceiver";

    private static LoginServiceManager.UserAccount mUserAccount = null;
    private static CReqLoginEmail EmailPacket = null;
    private static CReqLoginFacebook FacebookPacket = null;


    public NetworkChangeReceiver() {

    }

    public NetworkChangeReceiver(Context context) {
        WrapperListener.getInstance(context).addLoginDataListener(mLoginDataListenerByNetworkChangeReceiver);
    }

    public int deInit(Context context) {
        SxDebug.d(TAG, "[ deInit() ] ");

        if(mUserAccount != null) {
            mUserAccount = null;
        }

        if(EmailPacket != null) {
            EmailPacket = null;
        }

        if(FacebookPacket != null) {
            FacebookPacket = null;
        }

        WrapperListener.getInstance(context).removeLoginDataListener(mLoginDataListenerByNetworkChangeReceiver);

        return LibResult.SUCCESS;
    }

    @Override
    public void onReceive(Context context, Intent intent) {
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService(context.CONNECTIVITY_SERVICE);
        NetworkInfo wifi = connectivityManager.getNetworkInfo(ConnectivityManager.TYPE_WIFI);
        NetworkInfo mobile = connectivityManager.getNetworkInfo(ConnectivityManager.TYPE_MOBILE);

        boolean isNetworkConnected = (wifi != null && wifi.isConnected()) || (mobile != null && mobile.isConnected());
        if (isNetworkConnected) {
            SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==> Network is Connect. Using Network is Available.");

            if(mUserAccount != null) {
                if(EmailPacket != null) {
                    SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==>  Login Email.");
                    IPCActivity.requestApp2LoginManagerLoginEmail(EmailPacket);
                } else {
                    SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==>  Login Facebook.");
                    IPCActivity.requestApp2LoginMangerLoginFacebook(FacebookPacket);
                }
            } else {
                SxDebug.d(TAG, "[ NetworkChangeReceiver] ==> mUserAccount is null." );
            }
        } else {
            SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==> Network is not Connect. do not use Network.");

            //isNetworkConnectResult = false;
        }
    }

    private DataTypeLoginDataListener mLoginDataListenerByNetworkChangeReceiver = new DataTypeLoginDataListener() {

        @Override
        public int onDataReceived(int messageType, Object obj) {
            SxDebug.d(TAG, "[ NetworkChangeReceiver ] ===> get UserData");

            mUserAccount = (LoginServiceManager.UserAccount) obj;

            if( !mUserAccount.isLoginStatus() && mUserAccount.getErrorCode() == JsonValue.RESPONSE_ERROR_NETWORK_NOT_CONNECTED_TO_INT) {
                if (mUserAccount.getEmail() != null) {
                    SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==> Set Email Login Packet.");
                    EmailPacket = new CReqLoginEmail();
                    EmailPacket.setEmail(mUserAccount.getEmail());
                    EmailPacket.setPassword(mUserAccount.getPwd());
                } else {
                    SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==> Set Facebook Login Packet.");
                    FacebookPacket = new CReqLoginFacebook();
                    FacebookPacket.setToken(mUserAccount.getFacebookToken());
                    FacebookPacket.setId(mUserAccount.getFacebookId());
                    FacebookPacket.setName(mUserAccount.getName());
                }
            } else {
                SxDebug.d(TAG, "[ NetworkChangeReceiver ] ==> It is not NetworkError. This function do not work. ");
            }

            return 0;
        }
    };
}
```
Project 에서는 앱실행 도중에 wifi 및 Mobile이 끊어진 상황에서 다시 연결 되면 리시버를 통해서 연결상태를 받은 Network가 연결되면 로그인을 수행하고 Network가 여전히 끊어진 상태라면 아무런 작업을 수행하지 않는다. 
