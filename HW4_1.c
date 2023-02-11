#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;
TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // 추가
TreeNode m4 = { 25, NULL, &m7 }; // 변경
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;
//p281 Quiz 01
int get_nonleaf_count(TreeNode* t) { 

	int count = 0;

	if (t != NULL)
	{
		if ((t->left == NULL) && (t->right != NULL))
			count = 1 + get_nonleaf_count(t->right);
		else if ((t->right) == NULL && (t->left != NULL))
			count = 1 + get_nonleaf_count(t->left);
		else if ((t->right != NULL) && (t->left != NULL))
			count =1+ get_nonleaf_count(t->left) + get_nonleaf_count(t->right);
		else
			count = 0;
	}

	return count;
}

//p281 Quiz 02
int equal(TreeNode* t1, TreeNode* t2) { 
	

	int min = INT_MAX;
	int left, right, d;

	if ((t1 != NULL) || (t2 != NULL))
	{
		if (t1->left->data != t2->left->data)
			return 0;
		else if (t1->right->data != t2->right->data)
			return 0;
		else
			return 1;

	}


}


//p308 #25
int get_oneleaf_count(TreeNode* node) { 
	int count = 0;

	if (node != NULL)
	{
		if ((node->left == NULL) && (node->right != NULL))
			count = 1 + get_oneleaf_count(node->right);
		else if ((node->right) == NULL && (node->left != NULL))
			count = 1 + get_oneleaf_count(node->left);
		else if ((node->right != NULL) && (node->left != NULL))
			count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
		else
			count = 0;
	}

	return count;
	
}

//p308 #26

int get_twoleaf_count(TreeNode* node) { 
	int count = 0;

	if (node != NULL)
	{
		if ((node->left == NULL) && (node->right != NULL))
			count = get_twoleaf_count(node->right);
		else if ((node->right) == NULL && (node->left != NULL))
			count = get_twoleaf_count(node->left);
		else if ((node->right != NULL) && (node->left != NULL))
			count = 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
		else
			count = 0;
	}

	return count;
}
//p308 #27

int get_max(TreeNode* node)
{
	/*
	if(node == NULL)
		return INT_MIN;
	else
		return max(max(node->data, get_max(node->left)), get_max(node->right));
	*/
	int max = INT_MIN;
	int left, right, d;

	if (node != NULL)
	{
		d = node->data;
		left = get_max(node->left);
		right = get_max(node->right);

		if (left > right)
			max = left;
		else
			max = right;

		if (d > max)
			max = d;
	}
	return max;

}

int get_min(TreeNode* node) { 


		int min = INT_MAX;
		int left, right, d;

		if (node != NULL)
		{
			d = node->data;
			left = get_min(node->left);
			right = get_min(node->right);

			if (left > right)
				min = right;
			else
				min = left;

			if (d < min)
				min = d;
		}
		return min;

	}


void node_increase(TreeNode* node) { 


		if (node != NULL)
		{
			if ((node->left == NULL) && (node->right != NULL))
			{
				node->right->data++;
				node_increase(node->right);
			}
			else if ((node->right) == NULL && (node->left != NULL))
			{
				node->left->data++;
				node_increase(node->left);
			}
			else if ((node->right != NULL) && (node->left != NULL))
			{
				node->left->data++;
				node->right->data++;
				node_increase(node->left);
				node_increase(node->right);
			}
		}



}

void preorder(TreeNode* root) // p271 코드 복사
{

	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
TreeNode* copy(TreeNode* t)
{
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	if (t == NULL)
		return NULL;
	else
	{
		p->data = t->data;
		p->left = copy(t->left);
		p->right = copy(t->right);
	}
	return p;

}
int main(void)
{
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;
	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));
	
	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
	
	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	
	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));
	
	

	
	printf("\n 다)\n");
	preorder(root);
	
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");
	
	printf("\n 라)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
	
}