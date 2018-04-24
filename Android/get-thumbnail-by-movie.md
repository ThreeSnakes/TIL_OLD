# 동영상에서 Thumbnail 뽑아내서 jpeg로 저장하기.
-
동영상 파일에서 Thumbnail을 뽑아 낸다음 이를 .jpeg로 저장하는 코드이다.

``` java
public static final int getMovieThumbnail(String moviePath, String thumbnailPath, String thumbnailName) {
    int ret = LibResult.FAIL;

    int MovieCaptureTime = 0;

    if( moviePath == null || thumbnailPath == null || thumbnailName == null ) {
        SxDebug.d(TAG, "[ getMovieThumbnail ] => [ url or path or name is null ]");
        return ret;
    }

    MediaMetadataRetriever mediaMetadataRetriever = new MediaMetadataRetriever();

    try {
        mediaMetadataRetriever.setDataSource(moviePath);
    } catch (IllegalArgumentException e) {
        SxDebug.d(TAG, "[ getMovieThumbnail() ] => [ " + e.toString() + " ]");
        return ret;
    }

    Bitmap bitmap = mediaMetadataRetriever.getFrameAtTime(MovieCaptureTime);

    if(LibFileIO.makeDir(thumbnailPath)) {
        File movieThumbnail = new File(thumbnailPath + "/" + thumbnailName);
        OutputStream outputStream = null;

        try {
            movieThumbnail.createNewFile();

            outputStream = new FileOutputStream(movieThumbnail);
            bitmap.compress(Bitmap.CompressFormat.JPEG, 100, outputStream);
        } catch (Exception e) {
            SxDebug.d(TAG, "[ getMovieThumbnail() ] => [ " + e.toString() + " ]");
            return ret;
        } finally {
            try {
                if (outputStream != null) {
                    outputStream.close();
                }
            } catch (IOException | NullPointerException e) {
                SxDebug.d(TAG, "[ getMovieThumbnail() ] => [ " + e.toString() + " ]");
            }
        }
    } else {
        SxDebug.d(TAG, "[ getMovieThumbnail() ] => [ make Dirs fail.. ]");
        return ret;
    }

    ret = LibResult.SUCCESS;
    return ret;
}
```
   
> `LibfileIO.makeDir` 은 `File` 에서 `makeDir()`과 같은 함수이다. 
