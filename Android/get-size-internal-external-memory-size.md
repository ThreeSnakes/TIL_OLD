# Android Internal, External Memory size 구하기. 
-
Android Internal, External Memory size 구하는 방법이다.

AndroidMenifest.xml 에 다음 permission을 추가해준다.
``` java
    <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE"/>
    <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE"/>
    <uses-permission android:name="android.permission.WRITE_INTERNAL_STORAGE"/>
    <uses-permission android:name="android.permission.READ_INTERNAL_STORAGE"/>
```

실제 구현된 메소드는 다음과 같다. 

``` java
  public static final List<memorySize> getFreeMemorySize(Context context) {
		int ret = LibResult.FAIL;
		SxDebug.d(TAG, "[ getFreeMemorySize() ]");

		List<memorySize> MemorySize = null;
		memorySize tmpMemorySize = null;
		File[] Dirs = null;
		Dirs = context.getExternalFilesDirs(null);
		SxDebug.d(TAG, "[ getFreeMemorySize() ] => [ getExternalFilesDirs Count = " + Dirs.length + "]");

		if(Dirs.length > 1) {
			SxDebug.d(TAG, "[ getFreeMemorySize() ] => [ This Device have External Memory. ]");
		} else if (Dirs.length == 0 ) {
			SxDebug.d(TAG, "[ getFreeMemorySize() ] => [ This Device has not Memory. ]");
		}

		MemorySize = new ArrayList<>();

		for(int i = 0 ; i < Dirs.length ; i++) {
			if(tmpMemorySize == null) {
				tmpMemorySize = new memorySize();
			}

			if(Dirs[i] != null) {
				SxDebug.d(TAG, "[ getFreeMemorySize() ] =>  [ " + i + " ]");
				SxDebug.d(TAG, "[ getAbsolutePath() ] => [ " + Dirs[i].getAbsolutePath() + " ]");
				StatFs statFs = new StatFs(Dirs[i].getAbsolutePath());
				long totalBytes = statFs.getTotalBytes();
				long availableBytes = statFs.getAvailableBytes();
				tmpMemorySize.setTotalMemorySize(totalBytes / (1024 * 1024));
				tmpMemorySize.setAvailableMemorySize(availableBytes / (1024 * 1024));
				MemorySize.add(tmpMemorySize);
				tmpMemorySize = null;
				statFs = null;
			}
		}
		return MemorySize;
	}

	public static class memorySize {
		long totalMemorySize;
		long availableMemorySize;

		public memorySize() {

		}

		public long getTotalMemorySize() {
			return totalMemorySize;
		}

		public void setTotalMemorySize(long totalMemorySize) {
			this.totalMemorySize = totalMemorySize;
		}

		public long getAvailableMemorySize() {
			return availableMemorySize;
		}

		public void setAvailableMemorySize(long availableMemorySize) {
			this.availableMemorySize = availableMemorySize;
		}
	}
```

> 반환되는 리스트의 첫번째가 내부 SD카드의 메모리이고 그 이후는 외부 SD card 이다. 

> [안드로이 API 문서](https://developer.android.com/reference/android/content/Context.html#getExternalFilesDirs(java.lang.String)) 에 보면 `return`값으로 `null`을 줄수도 있다고 한다. 그러므로 `null` 체크 꼮 하도록 하자.
