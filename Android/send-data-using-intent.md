# Intent로 데이터 전달 하기.
-
앱에서 인텐트(Intent)를 사용하여서 데이터를 전달하는 방법이다. 

1. Intent로 다른 Activity 이동하기.

   ``` java
   Intent intent = new Intent(getApplicationContext(), 이동할 Activity.class);
   startActivity(intent);
   ```
   
2. Intent에 Data를 포함하여서 전달하기.
   ``` java
   Intent intent = new Intent(getApplicationContext(), 전달할 Activity.class);
   intent.putExtra("name","Jonathan");
   intent.putExtra("age", "28");
   startActivity(intent);
   ```
   
3. Intet 받기.
   ``` java
   Intent intent = getIntent();
   String name = intent.getExtras().getString("name");
   int age = intent.getExtras().getInt("age");
   ```
  
아래 코드는 실제 프로젝트에서 구현한 코드이다. Noti를 클릭하면 각 Fragment로 이동해야 하는데 Fragment로 이동하기전에 Intro 를 거쳐서 가야 한다. 그렇기 때문에 `Noti` -> `Into` -> `MainActiviy 안에 개별 Fragment` 순이다. 기존에는 `개별 Fragment`로 바로 이동하였는데 Intro에서 Logo를 보여줘야 한다. 그렇기 때문에 `Intro`로 Fragment Num을 실어서 보낸다음 `Intro`에서 다시 `MainActivity의 개별 Fragemnet`로 이동하는 것이다.

   ``` java
   private void startMainActivity() {
		String version = mContext.getResources().getString(R.string.application_version);
		if(version == null) {
			version = "version invalid";
		}
		SxDebug.e(TAG, "===============================================================");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "===============================================================");

		Intent TmpIntent = getIntent();
		int MoveToFragment;
		try {
			MoveToFragment = TmpIntent.getExtras().getInt(MainActivity.INTENT_EXTRA_FRAGMENT_NAME);
		} catch (NullPointerException e) {
			SxDebug.d(TAG, " [ Intent is Null. Move Timeline MainFragment. ]");
			MoveToFragment = TIMELINE_MAIN_FRAGMENT;
		}

		if(MoveToFragment == TIMELINE_MAIN_FRAGMENT) {
			Intent intent = new Intent(mContext, MainActivity.class);
			intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			intent.putExtra(MainActivity.INTENT_EXTRA_FRAGMENT_NAME, MainButtonConfig.BUTTON_POSITION_TIMELINE);
			mContext.startActivity(intent);
		} else {
			SxDebug.d(TAG, " [ Intent is Not Null. Move Each Fragment. ]");
			Intent intent = new Intent(mContext, MainActivity.class);
			intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
			intent.putExtra(MainActivity.INTENT_EXTRA_FRAGMENT_NAME, getIntent().getExtras().getInt(MainActivity.INTENT_EXTRA_FRAGMENT_NAME));
			mContext.startActivity(intent);
		}
	}
   ```
   
   > 다음 코드는 선배가 다듬어준 코드이다. 내꺼와 비교해서 보도록 하자. 라인코드도 훨씬 간단하고 `method`도 훨씬 간결하고 좋은 코드를 사용했다. 이런 코드를 쓸 수있도록 다듬고 또 다듬어야 겠다.
   
   ``` java
   private void startMainActivity() {
		String version = mContext.getResources().getString(R.string.application_version);
		if(version == null) {
			version = "version invalid";
		}
		SxDebug.e(TAG, "===============================================================");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "=");
		SxDebug.e(TAG, "===============================================================");

		Intent TmpIntent = getIntent();
		int MoveToFragment = MainButtonConfig.BUTTON_POSITION_TIMELINE;
		try {
			if(TmpIntent != null) {
				MoveToFragment = TmpIntent.getIntExtra(MainActivity.INTENT_EXTRA_FRAGMENT_NAME, MainButtonConfig.BUTTON_POSITION_TIMELINE);
			}
		} catch (NullPointerException e) {
			MoveToFragment = MainButtonConfig.BUTTON_POSITION_TIMELINE;
		}

		Intent intent = new Intent(mContext, MainActivity.class);
		intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		intent.putExtra(MainActivity.INTENT_EXTRA_FRAGMENT_NAME, MoveToFragment);
		mContext.startActivity(intent);
	}
   ```
