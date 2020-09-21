#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void makelotto(int lotto[6]);   // �ζ� 6�� �������� ����� �Լ�
void sort(int x[]);  // �����ϴ� �Լ�
int main(void)
{
    int lotto[6]; int i;
    makelotto(lotto);
    sort(lotto);
    printf("�ζ� ��ȣ:");
    for (i = 0; i < 6; i++)
        printf(" %d", lotto[i]);
    printf("\n");
    return 0;
}

// 2.�ݺ��Ǵ� ���� ������ i�� ���� �ٿ� �ݺ��Ǵ� ���ڰ� ���� 6�� ���
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

        if (i == j)   //   i�� ���� ���� ���� �� ���� ���ڰ� ���°� üũ�� ��.
        {                 // j�� i ���� �������� �迭�� �񱳸� �� �� for���� ���ö� j�� i�� ���� ���ڰ� �ż� success�� i�� ������Ų��.
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
        min = i;             //ó�� �迭�� ��ġ�� �ּҰ����� ��
        for (j = i + 1; j < 6; j++)    //�ּڰ��� ���ڿ� �״��� ���� ���� ��
            if (x[min] > x[j])
                min = j;
        temp = x[i];    // temp�� ���� �ּڰ� ����
        x[i] = x[min];   // ���� �ּڰ��� �ִ� ��ġ�� ���� ���� �ּڰ� ����
        x[min] = temp;      // temp�� �����ߴ� ���ڸ� ���� min���� �ִ� ��ġ��  ����

    }
}

