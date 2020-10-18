#include <stdio.h>
#include <stdlib.h>
#define swap(Type, x, y) do {Type t =x; x=y; y=t;}while(0)

void bubble(int a[], int n) {
	int k = 0;
	while (k < n - 1){
		int j;
		int last = n - 1;
		for (j = n - 1; j > k; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		k = last;
	}
}

int main() {
	int i, nx;
	int* x;

	puts("버블 정렬");
	printf("요소 개수 :");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d]; ", i);
		scanf_s("%d", &x[i]);
	}
	bubble(x, nx);

	puts("오름차순으로 정렬했습니다");
	for (i = 0; i < nx; i++)
		printf("x[%d]=%d\n", i, x[i]);

	free(x);
}
