#include <stdio.h>
#include <malloc.h>
// 스택을 위한 타입 정의
typedef int element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s) // Stack 연산중의 하나라 남겨두었지만 항상 거짓을 반환. 즉 꽉 차있을 때는 없음
{
	return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
// 피크 함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}
void stack_print(LinkedStackType* s)
{
	StackNode* tmp;

	if (is_empty(s))
		printf("<empty>\n");
	else
	{
		for (tmp = s->top; tmp != NULL; tmp = tmp->link)
		{
				printf("%d", tmp->item);

				if (tmp == s->top)
					printf("<- top");
				printf("\n");
		}
	}
	printf("--\n");
}



// 주 함수
void main()
{
	LinkedStackType s;
	init(&s);
	stack_print(&s);
	push(&s, 10);
	stack_print(&s);
	push(&s, 20);
	stack_print(&s);
	push(&s, 30);
	stack_print(&s);
	push(&s, 40);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}