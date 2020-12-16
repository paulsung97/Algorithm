#include <stdio.h>
#include "23-2020_12_07-2.h"
#include "25-2020_12_11.h"


typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (0)���� : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > DUMP);

	return(Menu)ch;
}

int main(void)
{
	Menu menu;				
	ClosedHash hash;		
	Initialize(&hash, 13);	

	do {
		int result;
		Member x;
		Bucket* temp;

		switch (menu = SelectMenu()) {
		case ADD: 
			x = ScanMember("�߰�", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result)
				printf("\a���� : �߰��� �����߽��ϴ�(%s).\n",
					(result == 1) ? "��� ��ħ" : "�޸� ����");
			break;

		case DELETE: 
			x = ScanMember("����", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("\a���� : �� ��ȣ�� �����ʹ� �������� �ʽ��ϴ�.\n");
			break;

		case SEARCH: 
			x = ScanMember("�˻�", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("\a�˻��� �����߽��ϴ�.\n");
			else {
				printf("�˻��� �����߽��ϴ�. : ");
				PrintLnMember(&temp->data);
			}
			break;

		case CLEAR: 
			Clear(&hash);
			break;

		case DUMP: 
			Dump(&hash);
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&hash); 

	return 0;
}