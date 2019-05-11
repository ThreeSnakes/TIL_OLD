# 디스커버리 Go 언어
## 날짜: 2019.05.11 18:40 ~ 
## Chapter2. 문자열 및 자료구조

### 목차

- [문자열](#문자열)
  - [유니코드 처리](#유니코드-처리)
  - [테스트](#테스트)
  - [바이트 단위 처리](#바이트-단위-처리)
  - [문자열 잇기](#문자열-잇기)
  - [문자열을 숫자로](#문자열을-숫자로)
- [배열과 슬라이스](#배열과-슬라이스)
  - [배열](#배열)
  - [슬라이스](#슬라이스)
  - [슬라이스 덧붙이기](#슬라이스-덧붙이기)
  - [슬라이스 용량](#슬라이스-용량)
  - [슬라이스의 내부구현](#슬라이스의-내부구현)
  - [슬라이스 복사](#슬라이스-복사)
  - [슬라이스 삽입 및 삭제](#슬라이스-삽입-및-삭제)
- [맵](#맵)
  - [맵 사용하기](#맵-사용하기)
  - [집합](#집합)
- [정리](#정리)

#### 문자열

- 문자열은 바이트들이 연속적으로 나열되어 있는 것
- `string`이라는 자료형 이용
- 바이트들의 연속을 나타내는 다른 방식은 `[]byte`가 있는데, 이것과 달리 `string`은 `읽기 전용`

##### 유니코드 처리

- `Go` 언어의 소스 코드는 `UTF-8`로 되어 있음. 따라서 코드 상에 표시된 문자열 역시 UTF-8로 인코딩됨.
- `rune`은 `int32`의 별칭
- 유니코드를 스트링으로 변경 하려면 `string(유니코드)` 해주면 문자열로 변경 가능

##### 테스트

- 테스트 파일은 `_test`를 붙여야 한다.
- 함수 이름은 `Example`로 시작해야 한다.
- `go test`는 `go run`과 유사하지만 테스트를 수행.
- `Output:` 밑에 예상 결과를 써주면 된다. 이를 테스트할때 비교 함.

``` Go
// 테스트 파일 예제

package hangul

import "fmt"

func ExampleHasConsonantSuffix() {
  fmt.Println(HasConsonantSuffix("Go 언어"))
  fmt.Println(HasConsonantSuffix("그럼"))
  fmt.Println(HasConsonantSuffix("우리 밥 먹고 합시다"))
  // Output:
  // false
  // true
  // false
}
```

- 다만 Go를 GVM으로 설치해서 그런지 `go test`로 실행시 에러가 발생.
- vs code 기능에서 Test 구동시 정상 작동. 이게 더 편한 거 같기도 하고...

![vscode test](Book/디스커버리 Go 언어/images/test.png)
![vscode test result](Book/디스커버리 Go 언어/images/test-result.png)

##### 바이트 단위 처리

- `printf` 류의 함수는 형식을 이용하여 출력함.
- 문자열을 어떻게 반복문에서 사용하는지에 따라서 유니코드 문자 단위 또는 바이트 단위로 동작한다.
- *`문자열은 읽기 전용이기 때문에 수정이 불가능 하지만 이를 바이트단위로 변경해서 수정처럼 보이게 할 수는 있다`*
- 어떤 문자들이 들어 있는지를 중시한다면 `string`, 실제 바이트 표현이 어떤지를 중요시 한다면 `[]byte`를 이용하는게 좋다.

##### 문자열 잇기

- 문자열은 읽기 전용. 문자열을 이어 붙이는것은 문자열을 수정하는 것이 아닌 두 문자열을 이어붙인 새로운 문자열을 만드는 것
- 문자열을 이어 붙이려면 `+`를 사용하면 됨.

##### 문자열을 숫자로

- 문자를 숫자로 변경할때 `int("5")`처럼 사용 할경우 5에 대한 유니코드가 나온다. 즉 예상 결과가 다를 수 있다.
- `strconv` 패키지에 있는 함수를 이용하여 형변환 할 수 있다.
- `strconv.Atoi()`는 문자열을 정수로 변환
- `strconv.ParseInt()`는 64비트 정수, 혹은 10진수가 아닌 수로 변환

``` go
package main

import (
  "fmt"
  "strconv"
)

func main() {
  var i int
  var k int64
  var f float64
  var s string
  var err error
  i, err = strconv.Atoi("350")
  fmt.Println(i, err)
  k, err = strconv.ParseInt("cc7fdd", 16, 32)
  fmt.Println(k, err)
  k, err = strconv.ParseInt("0xcc7fdd", 0, 32)
  fmt.Println(k, err)
  f, err = strconv.ParseFloat("3.14", 64)
  fmt.Println(f, err)
  s = strconv.Itoa(340)
  fmt.Println(s, err)
  s = strconv.FormatInt(13402077, 16)
  fmt.Println(s, err)
}

// Output
//350 <nil>
//13402077 <nil>
//13402077 <nil>
//3.14 <nil>
//340 <nil>
//cc7fdd <nil>
```

#### 배열과 슬라이스

##### 배열

- `배열`은 연속된 메모리 공간을 순차적으로 이용하는 자료구조
- 컴파일러가 배열의 개수를 알아내어서 넣게 만들고 싶으면 숫자 대신 `...`을 사용해도 된다.

``` go
games :=[3]{"리니지", "디아블로2", "디아블로3"}
games2 :=[...]{"리니지", "디아블로2", "디아블로3"}
```

##### 슬라이스

- `배열`은 잘 쓰이지 않음. `슬라이스`가 훨신 유연한 구조이기 때문
- `배열`은 크기가 자료형에 고정, `슬라이스`는 길이와 용량을 갖고 있고 길이가 변할수 있음.

``` go
games := make([]string, 3)
```

- `make`로 크기를 잡고 만든 슬라이스에는 해당 자료형의 기본값이 들어감. string은 `""`, 정수는 `0`
- `슬라이싱`은 `슬라이스`를 잘라내는 것을 뜻함.
- `슬라이싱`을 할때 범위가 넘어가지 않도록 주의하자.

``` go
// 슬라이싱 하는 법.
func Example_slicing() {
  nums := []int{1, 2, 3, 4, 5}
  fmt.Println(nums)
  fmt.Println(nums[1:3])
  fmt.Println(nums[2:])
  fmt.Println(nums[:3])
  fmt.Println(nums)
  // Output:
  //[1 2 3 4 5]
  //[2 3]
  //[3 4 5]
  //[1 2 3]
  //[1 2 3 4 5]
}
```

##### 슬라이스 덧붙이기

- `append` 함수를 사용하면 된다.
- 가변인자를 받을수 있기 때문에 한번에 여러개 추가 가능.
- 슬라이스끼리 이어 붙일때 `...`를 쓰면 된다.
- 슬라이싱 결과도 사용 가능!

``` go
nums = append(nums, 6)
nums = append(nums, 7, 8)

// 슬라이싱과 append를 이용한 덧붙이기.
func Example_slicing() {
  nums1 := []int{1, 2, 3, 4, 5}
  nums2 := []int{6, 7, 8}
  nums3 := append(nums1, nums2...)
  nums4 := append(nums1[2:4], nums2[:2]...)
  fmt.Println(nums1)
  fmt.Println(nums2)
  fmt.Println(nums3)
  fmt.Println(nums4)
  // Output:
  //[1 2 3 4 5]
  //[6 7 8]
  //[1 2 3 4 5 6 7 8]
  //[3 4 6 7]
}
```

##### 슬라이스 용량

- 슬라이스는 연속된 메모리 공간을 활용하는 것이라서 용량에 제한이 있을 수 밖에 없다. 남은 자리가 없는데 덧붙이려 한다면 더 넓은 메모리 공간으로 이사를 가야 하며, 이때 전에 있던 내용은 복사 된다. 그리고 새로 이사한 공간 맨뒤에 남는 공간에 덧붙이게 된다.
- `make([]int, 5)`와 같이 미리 할당받은 경우 길이 뿐만 아니라 용량도 5로 초기화된다. 만약 여기에 `append`로 덧붙이게 된다면 용량이 부족하므로 슬라이스 전체를 복사하여 더 넓은 공간으로 이동한다.
- 용량을 알아보려면 `cap(x)` 를 이용한다.

``` go
func ExampleSliceCap() {
  nums := []int{1, 2, 3, 4, 5}

  fmt.Println(nums)
  fmt.Println("len: ", len(nums))
  fmt.Println("cap: ", cap(nums))

  sliced1 := nums[:3]
  fmt.Println(sliced1)
  fmt.Println("len: ", len(sliced1))
  fmt.Println("cap: ", cap(sliced1))

  sliced2 := nums[2:]
  fmt.Println(sliced2)
  fmt.Println("len: ", len(sliced2))
  fmt.Println("cap: ", cap(sliced2))

  sliced3 := append(sliced2, 99)
  fmt.Println(sliced3)
  fmt.Println("len: ", len(sliced3))
  fmt.Println("cap: ", cap(sliced3))

  nums[2] = 100
  fmt.Println(nums, sliced1, sliced2, sliced3)

  //Output:
  //[1 2 3 4 5]
  //len:  5
  //cap:  5
  //[1 2 3]
  //len:  3
  //cap:  5
  //[3 4 5]
  //len:  3
  //cap:  3
  //[3 4 5 99]
  //len:  4
  //cap:  6
  //[1 2 100 4 5] [1 2 100] [100 4 5] [3 4 5 99]
}
```

- `sliced1` 처럼 슬라이스르 뒤에서 자를 경우에는 용량이 그대로이다.
- `sliced2` 처럼 슬라이스를 앞에서 자를 경우에는 용량이 줄어든다.
- 메로리를 기준으로 생각해보자. 슬라이스는 연속된 공간을 차지하는데 위에서 5개의 공간을 차지한다.
- 뒤에서 자를 경우 5개중에 뒤에 2개를 삭제하면 2개의 공간이 남는다. 앞에서 자를 경우 공간 5개를 다 차지한 상황에서 앞에서 2개를 차지하니 공간이 3으로 줄어든다.
- `sliced3`은 `sliced2`에서 `append`를 하였다. 흠.. len과 cap이 각각 4가 나올줄 알았는데.. 4, 6이 나왓다.. 왜이렇게 나올까...
- 마지막에 `nums[2]`를 바꾸었는데 `sliced1`, `sliced2` 모두 바뀌었는데 이는 모두 동일한 메모리를 보고 있기 때문이다. `sliced3`은 append를 하면서 메모리가 부족해져 다른 메모리로 이사를 가서 그렇다. 원본 데이터는 복사 한뒤 뒤에 99를 append를 하였기 떄문에 sliced1, sliced2와는 다르게 다른 메모리를 보고 있기때문에 값이 변하지 않는다.
- 슬라이스의 용량을 지정해서 생성 할때는 다음처럼 사용한다.

``` go
nums := make([]int, 3, 5)
```

- 슬라이스의 용량을 미리 알수 있다면 이를 설정해서 만들어주는 것이 좋다. 이는 append를 하면서 복사가 일어나지 않아서 성능에 도움이 된다.

##### 슬라이스의 내부 구현

- 슬라이스는 배열을 가리키고 있는 구조체라 볼수 있다.
- 슬라이스는 3개의 필드로 이루어져 있다. `시작주소`, `길이`, `용량` 이다.
- 이렇기 때문에 여러 슬라이스가 동일한 배열을 공유 할 수 있는 것이다.
- 복사가 이루어져서 이동이 이루어졌을 경우에는 서로 다른 배열을 보게 되는것이다. 배열은 크기가 변경될 수 없기 때문에 크기가 다른 배열을 하나 더 만들기 때문이다.

##### 슬라이스 복사

- `copy(dest, src)` 함수를 사용하면 쉽다.
- 단 `copy`함수는 dest는 복사 되상이 되는 slice의 길이만큼 복사된다. dest의 len만큼만 복사 되는 것이다. 완전히 복사하려면 src의 len보다 길어야 하는 것이다.

``` go
func ExampleSliceCopy() {
  dest := make([]int, 5)
  fmt.Println(dest)
  fmt.Println("len: ", len(dest))
  fmt.Println("cap: ", cap(dest))
  src := []int{10, 20, 30, 40, 50, 60}

  copy(dest, src)
  fmt.Println(dest)
  fmt.Println("len: ", len(dest))
  fmt.Println("cap: ", cap(dest))
  //Output:
  //[0 0 0 0 0]
  //len:  5
  //cap:  5
  //[10 20 30 40 50]
  //len:  5
  //cap:  5
}
```

- `copy`함수는 리턴값으로 복사된 값의 갯수를 넘겨는주는데 이를 이용해서 완전히 복사 되었는지 판별 할 수 있다.

``` go
if n := copy(dest, src); n != len(src) {
  fmt.Println("복사가 덜 되었습니다")
}
```

- `append`를 이용해서도 복사를 할 수 있다.

``` go
src := []int {10, 20, 30, 40, 50}
dest := append([]int(nil), src...)
```

##### 슬라이스 삽입 및 삭제
- 배열에서의 삽입과 삭제는 연속된 공간에 있어야 하기 떄문에 굉장히 비효율적인 과정을 거칠수 밖에 없다.
- 슬라이스에 값을 삽입하는 경우

``` go
// 방법1
if i < len(a) {
  a = append(a[:i+1], a[i:]...)
  a[i] = x
} else {
  a = append(a, x)
}

//방법 2
a = append(a, x)
copy(a[i+1:], a[i:])
a[i] = x
```

- 슬라이스에서 값을 삭제하는 경우

``` go
// 한개만 삭제하는 경우
a = append(a[:i], a[i+1:]...)

// 여러개를 삭제하는 경우
a = append(a[:i], a[i+k:]...)
```

- 슬라이스에서 값을 삭제 할 때 삭제되는 슬라이스 내부에 포인터가 있는 경우에는 이것이 뒤에 남아 공간에 남아 있으면 가비지 컬렉션이 일어나지 않기 때문에 메모리 누수가 발생 할 수 있다.
- 슬라이스 삭제 뒤에 길이 뒤에 잇는 공간에 있는 부분은 `nil`로 지워주어야 한다.
- 구조체 배열에서 구조체가 포인터를 갖고 있는 경우에도 동일한 문제가 발생 할 수 있다.
- 구조체 안에 포인터들을 `nil`로 초기화 시켜주거나 아니면 해당 구조체를 빈구조체로 덮어쓰어야 한다.

#### 맵

- `map`은 해시테이블로 구현된다.
- 해시맵은 키와 값으로 구현되며 값을 상수 시간에 가져 올수 있다.
- 해시맵은 순서가 없다.
- 맵은 생성이 되어야 값을 추가할 수 있다.

``` go
m := make(map[keyType]valueType)
// OR
m := map(KeyType)valueType{}
```

- 맵은 `m[key]` 형태로 읽을수 있으며 해당 값이 없을 경우 값이 자료형의 기본값을 반환한다.
- 맵을 읽을때 두개의 변수로 받게 되면, 두번째 변수에 해당 값의 존재 여부를 `bool`형태로 받을 수 있다.

``` go
value, ok := m[key]
// value = 값
// ok = 존재 여부
```

- 키를 삭제 하는 방법은 `delete()` 함수를 사용 하면 된다.
- 키를 삭제 할경우 len 값이 1 감소하게 된다.

``` go
delete(m, key)
```

##### 맵 사용하기

- 맵은 슬라이스와 달리 맵 변수 자체에 다시 할당하지 않으므로 포인터를 취하지 않아도 맵을 변경 할 수 있다.
- 맵은 순서가 없기 때문에 테스트 할때는 주의해야 한다.

#### 정리

- 문자열은 바이트의 나열로 `string`자료형이며 `[]byte`로 형변환할 수 있다.
- 문자열에 인덱스를 이용하면 해당 위치의 바이트를 가져올 수 있다.
- 문자열은 + 연산으로 이을 수 있다.
- 배열은 크기가 고정되어 있어서 슬라이스를 주로 사용한다.
- 슬라이스는 비열 포인터와 길이, 용량을 갖고 있는 구조체로 배열보다 유연하다.
- 슬라이스는 append를 이용하여 덧붙일 수 있다.
- 슬라이스는 copy를 이용하여 복사할 수 있다.
- 슬라이스는 잘라내어 사용할 수 있다.
- 맵은 키와 값으로 이루어져 있으며 순서가 없지만 상수 시간에 값을 찾을 수 있다.
- 맵은 동시에 여러 값을 쓸수 있다.