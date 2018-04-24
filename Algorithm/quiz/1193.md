#1193번 문제#

**분수찾기**

**문제**
> 무한히 큰 배열에 다음과 같이 분수들을 적혀있다.

>1/1	1/2	1/3	1/4	1/5	…
>2/1	2/2	2/3	2/4	…	…
>3/1	3/2	3/3	…	…	…
>4/1	4/2	…	…	…	…
>5/1	…	…	…	…	…
…	…	…	…	…	…
>이와 같이 나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> … 과 같은 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

>X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 X(1≤X≤10,000,000)가 주어진다.

**출력**
> 첫째 줄에 분수를 출력한다.

``` c
#include<stdio.h>

int main(void) 
	int input_number;

	int parent, child;
	
	int count = 1;
	int add = 2;

	scanf("%d", &input_number);

	if (input_number == 1) {
		printf("1/1");
		return 0;
	}

	while (1) {
		count = count + add;
		add++;
		if (input_number <= count) {
	//		printf("Count = %d, Last Add value = %d\n", count, add-1);
			break;
		}
	}

	if (add % 2 == 0) {
		parent = (add - 1) - (count-input_number);
		child = add - parent;
	}
	else {
		child = (add - 1) - (count - input_number);
		parent = add - child;
	}
	printf("%d/%d", child, parent);
	

	return 0;
}
```

| No      | ID        | Quest.NO | Result        | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|---------------|------------|------|-----------|-------------|
| 4535317 | select995 | 1193     | SUCCESS       | 944 KB     | 0 MS | C         | 616 B       |
| 4535278 | select995 | 1193     | COMPILE ERROR |            |      | C         | 616 B       |

>일단 그리 어렵게 풀지는 않았었고 처음 컴파일 에러는 scanf_s 를 썼더니 컴파일 에러로 나왔다. 
>그래서 scanf로 변경해주고 다시 실행하였더니 정상적으로 동작 했다. 