
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e)
{ 
	
	char c;
	for (int i = s; i < (s+e)/2; i++)
	{
		c = str[i];
		str[i] = str[e - i];
		str[e - i] = c;

	}
}
int main()
{ 
	char str[100];
	printf("Enter any string:");
	scanf("%s", str);
	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str); return 0;
} 

/*
* �迭 �Ųٷ� ������ ������

������ �ѰͰ� ������ ������� �ݺ��� �Ἥ Ǫ�� ������



*/
