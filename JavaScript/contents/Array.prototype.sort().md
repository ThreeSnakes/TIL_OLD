# Array.prototype.sort()

이번에 신규 기능을 만드는데 영문/숫자가 섞여 있는 값을 정렬해야 하는데 sort() 기능을 이용해서 정렬을 시도 하였다. 내가 정렬을 시도한 값은 `영어 대문자 1글자 + 숫자` 이다. 즉 `A1, C1, C11, B3, G2, G11, C3, C2` 이런 코드값이 입력되고 이를 정렬해야 하는 것이다. 해당 코드값을 Array로 저장하고 있기 때문에 sort()함수로 정렬을 하면 값이 이상하게 나온다. 

``` JS
// 그냥 sort()를 적용 하였을 떄.
test1 = ['A1', 'C1', 'C11', 'B3', 'G2', 'G11', 'C3', 'C2']
test1.sort();
console.log(test1);
/*
결과
[ 'A1', 'B3', 'C1', 'C11', 'C2', 'C3', 'G11', 'G2' ]
*/ 
```

일단 내가 바라는 값은 `[ 'A1', 'B3', 'C1', 'C2', 'C3', 'C11', 'G2', 'G11' ]` 이다. 문자순, 그다음 숫자순으로 나와야 한다. 하지만 실제 결과를 보면 `[ 'A1', 'B3', 'C1', 'C11', 'C2', 'C3', 'G11', 'G2' ]` 으로 나온다. `C11`이 `C2`보다 먼저 나오는 것이다. 

## 이유
[MDN web doc](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)을 보면 다음과 같은 설명이 나와 있다.
> 정렬은 stable sort가 아닐 수 있습니다. 기본 정렬 순서는 문자열 유니 코드 코드 포인트에 따릅니다. .... 생략 ... 숫자 정렬에서는 9가 80보다 앞에 오지만 숫자는 문자열로 변환되기 때문에 "80"은 유니 코드 순서에서 "9"앞에옵니다.

기본 정렬의 경우 문자열 유니코드 포인트를 따른다고 나오며 친절하게 왜 11이 2보다 먼저 나오는지 알려 준다. 결국 문서에 나와 있는 것처럼 `compareFunction`을 설정 해줘야 한다. 그래야 내가 원하는 정렬을 사용 할 수 있다. 

## 수정
``` JS
// 그냥 sort()를 적용 하였을 떄.
test1 = ['A1', 'C1', 'C11', 'B3', 'G2', 'G11', 'C3', 'C2']
test1.sort((a,b) => {
    return a.localeCompare(b, 'en', { numeric: true })
});
console.log(test1);
/*
결과
[ 'A1', 'B3', 'C1', 'C2', 'C3', 'C11', 'G2', 'G11' ]
*/ 
```

이제 값이 제대로 나오는 것을 확인 할 수 있다. [localeCompare함수](https://msdn.microsoft.com/ko-kr/library/62b7ahzy(v=vs.94).aspx)는 해당 글자가 비교 대상이 되는 문자보다 앞에 나오는지 뒤에나오는지 비교하는 함수 이다. 자세한 것은 링크를 통해서 확인하자 -_-;;

## 출처
- [MDN web doc](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/sort)