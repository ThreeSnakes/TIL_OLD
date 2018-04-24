#include<stdio.h>

#define MAX_INPUT 100000
#define MAX(x,y) ((x > y) ? x:y)

void main() {
	int _input_cnt;
	int _number_bucket[MAX_INPUT];
	int i, _ret = -9999;

	scanf("%d", &_input_cnt);

	for (i = 0; i < _input_cnt; i++) {
		scanf("%d", &_number_bucket[i]);
	}

	// 배열에 잘 들어갔는지 확인용 출력.
	/*for (i = 0; i < _input_cnt; i++) {
		printf("[ %d ]", _number_bucket[i]);
	}*/

	/*printf("\n");*/

	// 끝에서 부터 풀면 쉽게 풀린다.
	// 연속된 숫자를 선택 하므로. 맨 마지막은 자기 자신만 선택할 수 있다.
	// 뒤에서 두번째 숫자는 자기 자신과 마지막 숫자를 선택 할 수 있는데
	// 여기서 자기 자신 + 마지막, 자기 자신을 비교해서 더 큰값을 저장하면
	// 그 수터 연속으로 선택할때 가장 큰 수를 저장하게 되는 것이다.
	for (i = _input_cnt - 2; i >= 0; i--) {
		_number_bucket[i] = MAX(_number_bucket[i], _number_bucket[i] + _number_bucket[i + 1]);
	}

	// 계산이 잘 됬느지 확인용 출력.
	/*for (i = 0; i < _input_cnt; i++) {
		printf("[ %d ]", _number_bucket[i]);
	}*/

	for (i = 0; i < _input_cnt; i++) {
		_ret = MAX(_ret, _number_bucket[i]);
	}

	printf("%d", _ret);
	
}