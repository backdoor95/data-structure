#include<stdio.h>
#include<stdlib.h>
int gFolderSize = 0;
typedef struct treeNode {
	int id;
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;
treeNode* insertNode(int id, int data, treeNode* left, treeNode*right)
{
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->id = id;
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}
treeNode* treeBuild()
{
	treeNode* n8 = insertNode(8, 80, NULL, NULL);
	treeNode* n7 = insertNode(7, 130, NULL, NULL);
	treeNode* n6 = insertNode(6, 120, n7, n8);
	treeNode* n3 = insertNode(3, 50, NULL, n6);
	treeNode* n4 = insertNode(4, 70, NULL, NULL);
	treeNode* n5 = insertNode(5, 90, NULL, NULL);
	treeNode* n2 = insertNode(2, 30, n4, n5);
	treeNode* n1 = insertNode(1, 20, n2, n3);
	return n1;
}
treeNode* leftChild(treeNode* v) {
	return v->left;
}
treeNode* rightChild(treeNode* v) {
	return v->right;
}
void visit(treeNode* v)
{
	printf("%d ", v->data);
}
int isInternal(treeNode* v)
{
	return ((v->left != NULL) && (v->right != NULL));
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
//void binaryPostOrder(treeNode* v)
//{
//	if (v != NULL)
//	{
//		binaryPostOrder(leftChild(v));
//		binaryPostOrder(rightChild(v));
//		visit(v);
//		
//	}
//}
void visit_sum(treeNode* v)
{
	gFolderSize += v->data;
}
void binaryPostOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit_sum(v);
	}
}
treeNode* findID(treeNode* v, int id)
{
	if (v != NULL)
	{
		if (v->id == id) return v;
		
		treeNode* p = NULL;
		p=findID(leftChild(v), id);
		if (p != NULL) return p;
		p = findID(rightChild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}

int main() {
	
	treeNode* root = treeBuild();
	int id;
	
	scanf("%d", &id);
	treeNode* target = findID(root, id);
	if (target != NULL)
	{	
		binaryPostOrder(target);
		printf("%d\n", gFolderSize);
	}
	else
	{
		printf("-1");
	}
	printf("\n");
}