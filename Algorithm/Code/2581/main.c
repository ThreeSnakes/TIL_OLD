#include<stdio.h>

int main(void) {
	int min, max, sum = 0, min_primary_number = 0, i;
	
	scanf("%d", &min);
	scanf("%d", &max);

	for (min; min <= max; min++) {
		for (i = 2; i <= min; i++) {		
			if (min == 2) {
				min_primary_number = 2;
				sum = sum + 2;
				break;
			}

			if (min%i == 0) {
				break;
			}

			//마지막 전까지 통과한거면 그값은 소수.
			if (i == min - 1) {
				// min 값 등록. for문으로 돌기 때문에 처음 값이 입력되면
				// 그 이후로는 값 입력 X.
				if (min_primary_number == 0) {
					min_primary_number = min;
				}

				//printf("prime_number = %d\n", min);
				sum = sum + min;

				// 한번 더 돌필요 없다. break문으로 탈출.
				break;
			}
		}
	}

	if (sum != 0) {
		printf("%d\n", sum);
		printf("%d\n", min_primary_number);
	}
	else {
		printf("-1");
	}

	return 0;
}