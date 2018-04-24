# 1000단위마다 ,[cooma] 찍기.

금액 표시를 하거나 숫자를 표시할때 1000단위마다 , 를 찎어야 할때 사용하는 코드이다.

다음 코드를 공통 모듈에 담은 다음에 실제 코드에서 **class**에 _**.num-conversion**_ 를 넣어 주면 된다.

그러면 숫자데이터에서 1000단위마다 , 가 찍히는 것을 확인 할 수 있다.

``` js
$(document).ready(function(){

    //금액 콤마 적용 - load view
    $.fn.mkcommma = function(){ 
        return this.each(function(){ 
            $(this).text( $(this).text().replace(/(\d)(?=(\d\d\d)+(?!\d))/g, "$1,") ); 
        })
    }
    $('.num-conversion').mkcommma();
});
```