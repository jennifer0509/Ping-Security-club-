#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
void print_reverse(char* str, int end)
{

	char tmp;

	printf("%c", str[end]);

	if (end == 0)
		return;
	else
		print_reverse(str, end-1);

}
int main()
{
	char str[100];
	printf("Enter any string:");
	scanf("%s", str);
	printf("Reversed String is: ");
	print_reverse(str, strlen(str) - 1);
	return 0;
}

/*
이 문제는 문자열을 거꾸로 출력하되 재귀로 호출하는 문제였음. 중요한것은 이 문제도 return 형이 void 이기 때문에 종료조건이 아닌 다른 조건문에서는 그냥 부르기만 하면 됨. 문자열이기 때문에 먼저 출력해주고 밑의 조건문으로 부르면 됨
*/