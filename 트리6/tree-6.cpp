#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct treeNode
{
	int id;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;
void visit(treeNode* v)
{
	printf(" %d", v->id);
}
int isInternal(treeNode* v)
{
	return((v->left != NULL) && (v->right != NULL));
}
treeNode* leftChild(treeNode* v)
{
	return v->left;
}
treeNode* rightChild(treeNode* v)
{
	return v->right;
}
void binaryPreOrder(treeNode* v)
{
	if (v != NULL)
	{
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
void binaryInOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryInOrder(leftChild(v));
		visit(v);
		binaryInOrder(rightChild(v));
	}
}
void binaryPostOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit(v);
	}
}
treeNode* findID(treeNode* v, int id)
{
	if (v != NULL)
	{
		if (v->id == id) return v;
		treeNode* p = NULL;
		p = findID(leftChild(v), id);
		if (p != NULL)return p;
		p = findID(rightChild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}
void insertNode(treeNode* v, char type, int id)
{
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->id = id;
	newNode->left = NULL;
	newNode->right = NULL;

	if (type == 'R')
	{
		v->right = newNode;
	}
	else if (type == 'L')
	{
		v->left = newNode;
	}
	else
	{
		printf("Check the type \n");
		exit(-1);
	}
}
treeNode* treeBuild()
{
	int num = 0;
	int flag = 1;
	int id = 0, left_id = 0, right_id = 0;
	
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->right = NULL;
	root->left = NULL;

	scanf("%d", &num);// 횟수
	while (num--)
	{
		scanf("%d %d %d", &id, &left_id, &right_id);
		if (flag == 1)// 처음 root
		{
			root->id = id;
			if (right_id != 0)insertNode(root, 'R', right_id);
			if (left_id != 0)insertNode(root, 'L', left_id);
			flag = 0;
		}
		else// root 이후
		{
			treeNode* vv = findID(root, id);
			if (right_id != 0)insertNode(vv, 'R', right_id);
			if (left_id != 0)insertNode(vv, 'L', left_id);
		}
	}
	return root;
}
void treeSearch(treeNode* root)
{
	int num = 0;
	scanf("%d", &num);
	while (num--)
	{
		char str[100] = "";
		scanf("%s", str);

		treeNode* v = root;
		printf(" %d", v->id);// root 출력

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'R')v = rightChild(v);
			else if (str[i] == 'L')v = leftChild(v);
			printf(" %d", v->id);
		}
		printf("\n");
	}
}
int main() 
{
	treeNode* root = treeBuild();
	treeSearch(root);
}