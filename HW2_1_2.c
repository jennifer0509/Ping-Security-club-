#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	char stackName[MAX_STRING_SIZE][MAX_STRING_SIZE];
	int top;
}StackType;

// 스택 초기화 함수
void init(StackType* s)
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
void stack_print(StackType* s)
{
	int i;

	if (is_empty(s) == 1)
		printf("<empty>\n");
	else
	{
		for (i = s->top; i >= 0; i--)
		{
			printf("%d %s", s->data[i],s->stackName[i]);

			if (i == s->top)
				printf("<- top");
			printf("\n");
		}
	}
	printf("--\n");
}

// 주함수
void main()
{
	StackType s;

	init(&s);
	stack_print(&s);
	push(&s, 10);
	strcpy(s.stackName[0], "ten");
	stack_print(&s);
	push(&s, 20);
	strcpy(s.stackName[1], "twenty");
	stack_print(&s);
	push(&s, 30);
	strcpy(s.stackName[2], "thirty");
	stack_print(&s);
	push(&s, 40);
	strcpy(s.stackName[3], "forty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	strcpy(s.stackName[2], "fifty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);

}

/*
* strcpy 를 통해서 문자열 복사해주기



구조체에서는 배열도 2개 만들어서 사용이 가능하다. 숫자도 넣고 문자열도 넣을 수 있음

*/