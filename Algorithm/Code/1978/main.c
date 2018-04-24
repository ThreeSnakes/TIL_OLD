#include<stdio.h>

int main(void) {
	int cnt;
	int bucket[100];
	int prime_number_cnt = 0;
	int i = 0;
	
	scanf("%d", &cnt);

	//배열에 입력 받아서 저장해 놓는다.
	for (i = 0; i < cnt; i++) {
		scanf("%d", &bucket[i]);
	}

	//printf("cnt = %d\n", cnt);

	for (i = 0; i < cnt; i++) {
		for (int j = 2; j <= bucket[i]; j++) {
			// 1은 소수가 아니므로 제외, 1 이하도 제외.
			if (bucket[i] <= 1) {
				break;
			}
			
			// 2는 소수 이므로 prime_number_cnt 증가.
			if (bucket[i] == 2) {
				prime_number_cnt++;
				break;
			}
			// 나눠서 체크.
			if (bucket[i] % j == 0) {
				break;
			}

			// 자기 자신 -1 까지 무사통과 했으면 prime_number_cnt 증가.
			if (j == bucket[i] - 1) {
				printf("add Prime_Number_Cnt bucket = %d, i = %d, j = %d \n", bucket[i], i, j);
				prime_number_cnt++;
			}
		}
	}

	//마지막으로 출력.
	printf("%d", prime_number_cnt);
	
	return 0;
}