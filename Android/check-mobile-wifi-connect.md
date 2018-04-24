# Mobile, Wifi Connect Check하기.
-
Android이드에서 Mobile, Wifi 가 연결 되었는지 안되었는지 확인하는 코드이다. 

``` java
public final Boolean isNetworkConnected() {
    ConnectivityManager manager = (ConnectivityManager) mContext.getSystemService(mContext.CONNECTIVITY_SERVICE);

    NetworkInfo mobile = manager.getNetworkInfo(ConnectivityManager.TYPE_MOBILE);
    NetworkInfo wifi = manager.getNetworkInfo(ConnectivityManager.TYPE_WIFI);

    try {
        // MOBILE && WIFI both can use device.
        if (mobile.isConnected() || wifi.isConnected()) {
            return true;
        } else {
            return false;
        }
    } catch (NullPointerException e) {
        if (wifi.isConnected()) {
            return true;
        } else {
            return false;
        }
    }
}
```
   
크게 어려운 코드는 아니다.  `Menifest`에 추가해하는것 도 있는데 일단 여기까지만 적어 놓는다.  
