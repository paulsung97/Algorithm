#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void makelotto(int lotto[6]);   // 로또 6개 랜덤으로 만드는 함수
void sort(int x[]);  // 정렬하는 함수
int main(void)
{
    int lotto[6]; int i;
    makelotto(lotto);
    sort(lotto);
    printf("로또 번호:");
    for (i = 0; i < 6; i++)
        printf(" %d", lotto[i]);
    printf("\n");
    return 0;
}

// 2.반복되는 값이 있으면 i의 값을 줄여 반복되는 숫자가 없이 6개 출력
void makelotto(int lotto[6])
{
    int i = 0, j, success = 0;
    srand(time(NULL));
    while (success < 6)
    {

        lotto[i] = rand() % 45 + 1;
        for (j = 0; j < i; j++)
            if (lotto[j] == lotto[i])
                break;

        if (i == j)   //   i와 그전 수를 비교한 후 같은 숫자가 없는게 체크가 됨.
        {                 // j는 i 이전 수까지의 배열과 비교를 한 후 for문을 나올땐 j가 i와 같은 숫자가 돼서 success와 i를 증가시킨다.
            success++;
            i++;
        }

    }
}

void sort(int x[6])
{
    int i; int j; int min, temp;
    for (i = 0; i < 5; i++)
    {
        min = i;             //처음 배열의 위치를 최소값으로 줌
        for (j = i + 1; j < 6; j++)    //최솟값의 숫자와 그다음 숫자 값들 비교
            if (x[min] > x[j])
                min = j;
        temp = x[i];    // temp에 원래 최솟값 저장
        x[i] = x[min];   // 원래 최솟값이 있던 위치에 새로 생긴 최솟값 저장
        x[min] = temp;      // temp에 저장했던 숫자를 원래 min값이 있던 위치에  저장

    }
}

