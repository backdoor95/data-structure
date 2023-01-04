#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;
treeNode* insertNode(int data, treeNode* left, treeNode* right)
{
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));
	v->data = data;
	v->left = left;
	v->right = right;
	return v;
}
void visit(treeNode* v)
{
	if (v == NULL)
		return;
	printf("%d ", v->data);
}
int isInternal(treeNode* v)
{
	return ((v->left != NULL) && (v->right != NULL));
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
	visit(v);
	/*if (isInternal(v))
	{
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}*/
	visit(v->left);
	visit(v->right);
}
int main() {

	int n;
	treeNode* f8 = insertNode(80, NULL, NULL);
	treeNode* f7 = insertNode(130, NULL, NULL);
	treeNode* f6 = insertNode(120, f7, f8);
	treeNode* f3 = insertNode(50, NULL, f6);
	treeNode* f4 = insertNode(70, NULL, NULL);
	treeNode* f5 = insertNode(90, NULL, NULL);
	treeNode* f2 = insertNode(30, f4, f5);
	treeNode* f1 = insertNode(20, f2, f3);

	scanf("%d", &n);

	switch (n)
	{
	case 1: 
		binaryPreOrder(f1);
		break;
	case 2:
		binaryPreOrder(f2);
		break;
	case 3:
		binaryPreOrder(f3);
		break;
	case 4:
		binaryPreOrder(f4);
		break;
	case 5:
		binaryPreOrder(f5);
		break;
	case 6:
		binaryPreOrder(f6);
		break;
	case 7:
		binaryPreOrder(f7);
		break;
	case 8:
		binaryPreOrder(f8);
		break;
	default:
		printf("-1\n");
		break;
	}




}