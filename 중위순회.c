#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
typedef struct TreeNode* element;
typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
void init(LinkedStackType* s)
{
	s->top = NULL;
}
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
int is_full(LinkedStackType* s)
{
	return 0;
}
void push(LinkedStackType* p, element e)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->item = e;
	temp->link = p->top;
	p->top = temp;
}
element pop(LinkedStackType* p)
{
	if (is_empty(p))
		fprintf(stderr, "스택이 비어있음\n");
	else
	{
		StackNode* temp = p->top;
		element data = temp->item;
		p->top = p->top->link;
		free(temp);
		return data;
	}
}

void inorder_iter(TreeNode* root)
{
	LinkedStackType* p;
	TreeNode* q;
	init(&p);

	while (1) {
		for (; root; root = root->left)
			push(&p, root);
		if (is_empty(&p))
			break;
		else
			root = pop(&p);
		printf("[%d]", root->data);
		root = root->right;
	}

}

int main(void)
{
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;

	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}
