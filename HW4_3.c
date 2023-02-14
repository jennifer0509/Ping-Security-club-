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
//Ž��(��ȯ)
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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return new_node(s);
	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (s.id < root->data.id)
		root->left = insert_node(root->left, s);
	else if (s.id > root->data.id)
		root->right = insert_node(root->right, s);
	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
	return root;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL) // �� ���� �ܸ� ��带 ã���� ������
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
// ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key)
{
	TreeNode* temp;
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->data.id)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->data.id)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
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
		// �� ��° ���
		temp = min_value_node(root->right);
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->data.id = temp->data.id;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�.
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
void inorder(TreeNode* root) // p271 �ڵ� ���� ������ȸ 
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("---------------------------------------\n");
		printf("�й� : %d\n", root->data.id);
		printf("�̸�: %s\n", root->data.name);
		printf("��ȭ��ȣ: %s\n", root->data.tel);
		printf("�а�: %s\n", root->data.dept);
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
			printf("�й� �Է�: ");
			scanf("%d", &data.id);
			printf("�̸� �Է�: ");
			scanf("%s", data.name);
			printf("��ȭ��ȣ �Է�: ");
			scanf("%s", data.tel);
			printf("�а� �Է�: ");
			scanf("%s", data.dept);
			root = insert_node(root, data);
			break;
		case 'd':
			printf("������ �й� �Է�: ");
			scanf("%d", &data.id);
			root = delete_node(root, data.id);
			break;
		case 's':
			printf("Ž���� �й� �Է�: ");
			scanf("%d", &data.id);
			tmp = search(root, data.id);
			if (tmp == NULL)
				printf("id�� %d�� �л��� �����ϴ�.\n", data.id);
			else
			{
				printf("---------------------------------------\n");
				printf("�й� : %d\n", tmp->data.id);
				printf("�̸�: %s\n", tmp->data.name);
				printf("��ȭ��ȣ: %s\n", tmp->data.tel);
				printf("�а�: %s\n", tmp->data.dept);
			}
			break;
		case 'p':
			printf("�л� ���� �й� �� ���\n");
			inorder(root);
			printf("\n");
			break;
		case 'c':
			printf("���� ����� �л��� �� ���� %d\n", get_node_count(root));
			break;
		case 'q':
			break;
		}
		while (getchar() != '\n');
	} while (choice != 'q');
}

