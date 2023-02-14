#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100
typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
} element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;
TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
//탐색(순환)
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->data.id) return node;
	else if (key < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* insert_node(TreeNode* root, element s)
{
	// 트리가 공백이면 새로운 노드를 반환한다.
	if (root == NULL) return new_node(s);
	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (s.id < root->data.id)
		root->left = insert_node(root->left, s);
	else if (s.id > root->data.id)
		root->right = insert_node(root->right, s);
	// 변경된 루트 포인터를 반환한다.
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // 맨 왼쪽 단말 노드를 찾으러 내려감
		current = current->left;
	return current;
}
int get_height(TreeNode* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;

}
// 삭제 함수
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (key > root->data.id)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		temp = min_value_node(root->right);
		// 중외 순회시 후계 노드를 복사한다.
		root->data.id = temp->data.id;
		// 중외 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->data.id);
	}
	return root;
}
int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}
void inorder(TreeNode* root) // p271 코드 복사 전위순회 
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("---------------------------------------\n");
		printf("학번 : %d\n", root->data.id);
		printf("이름: %s\n", root->data.name);
		printf("전화번호: %s\n", root->data.tel);
		printf("학과: %s\n", root->data.dept);
		inorder(root->right);
	}
}
int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	element data;
	char choice;

	do {
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, c<ount>, q<uit>: ");
		scanf("%c", &choice);
		switch (choice)
		{
		case 'i':
			printf("학번 입력: ");
			scanf("%d", &data.id);
			printf("이름 입력: ");
			scanf("%s", data.name);
			printf("전화번호 입력: ");
			scanf("%s", data.tel);
			printf("학과 입력: ");
			scanf("%s", data.dept);
			root = insert_node(root, data);
			break;
		case 'd':
			printf("삭제할 학번 입력: ");
			scanf("%d", &data.id);
			root = delete_node(root, data.id);
			break;
		case 's':
			printf("탐색할 학번 입력: ");
			scanf("%d", &data.id);
			tmp = search(root, data.id);
			if (tmp == NULL)
				printf("id가 %d인 학생은 없읍니다.\n", data.id);
			else
			{
				printf("---------------------------------------\n");
				printf("학번 : %d\n", tmp->data.id);
				printf("이름: %s\n", tmp->data.name);
				printf("전화번호: %s\n", tmp->data.tel);
				printf("학과: %s\n", tmp->data.dept);
			}
			break;
		case 'p':
			printf("학생 정보 학번 순 출력\n");
			inorder(root);
			printf("\n");
			break;
		case 'c':
			printf("현재 저장된 학생의 총 수는 %d\n", get_node_count(root));
			break;
		case 'q':
			break;
		}
		while (getchar() != '\n');
	} while (choice != 'q');
}

