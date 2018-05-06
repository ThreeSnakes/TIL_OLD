#include<stdio.h>

int main(void) {
	// 기존에 하던 방식으로 구현하면 
	// 시간 초과가 발생해서 문제를 다시 찾아 보았다.
	// 에라토스테네스의 체를 이용하면 쉽게 소수를 구할수 있다.
	// 1...n까지이 수 중에서 소수를 구한다고 한다면.
	// 1은 소수가 아니므로 제외한다.
	// 2는 소수이고 2의 배수는 소수가 아니다. 2의 배수 제외.
	// 3은 소수이고 3의 배수는 소수가 아니다. 3의 배수 제외.
	// 4는 소수가 아니므로 삭제....
	// 이런식으로 n까지 수를 삭제한뒤 남은수가 소수가 되는 것이다.

	int min, max;
	int i, j;
	// 배열은 0부터 시작이어서 쉽게 생각하기 위해서 1000001까지 선언.
	int max_number = 1000001;
	int *bucket;
	
	bucket = (int*)malloc(sizeof(int)*max_number);

	scanf("%d", &min);
	scanf("%d", &max);
	
	for (i = 0; i <= max; i++) {
		bucket[i] = 0;
		if (i == 1) {
			// 1은 소수가 아니므로 체크 안하기 위해서 -1로 할당.
			bucket[i] = -1;
		}
		if (i % 2 == 0 && i != 2) {
			//일단 2의 배수는 소수가 아니므로 체크 안하기 위해서 -1로 할당.
			//2는 소수가 맞으므로 남겨 놓는다.
			bucket[i] = -1;
		}
	}

	for (i = 3; i <= max; i++) {
		if (bucket[i] != -1) {
			for (j = i + i; j <= max; j = j + i) {
				bucket[j] = -1;
			}
		}
	}

	for (min; min <= max; min++) {
		if (min == 1000000) {
			break;
		}

		if (bucket[min] != -1) {
			printf("%d\n", min);
		}

	}
		

	return 0;
}