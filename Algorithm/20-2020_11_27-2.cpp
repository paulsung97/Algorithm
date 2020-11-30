#include <stdio.h>
#include <string.h>

int main() {
	char name[10];
	scanf_s("%d", name);

	if (strcmp(name, "±Ë¡¯º∫") == 0) {
		printf("%s, æ»≥Á \n", name);
	}
	else {
		printf("%s, ¥‘, æ»≥Á«œººø‰\n", name);   
	}
}