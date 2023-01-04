#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode
{
	int data;
	int id;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;
treeNode* insertNode(int id, int data, treeNode* left, treeNode* right)
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
void visit(treeNode* v)
{
	printf("%d ", v->data);
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
void binaryPreOrder(treeNode* v)//순회는 visit의 위치만 바꿔주면된다.
{// 전위순회
	if (v != NULL)
	{
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
void binaryPostOrder(treeNode* v)
{// 중위순회
	if (v != NULL)
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit(v);
	}
}
void binaryInOrder(treeNode* v)
{// 후위순회
	if (v != NULL)
	{
		binaryInOrder(leftChild(v));
		visit(v);
		binaryInOrder(rightChild(v));
	}
}
treeNode* findID(treeNode* v, int id)
{
	if (v != NULL)
	{
		if (v->id == id) return v;
		treeNode* p = NULL;
		p = findID(leftChild(v), id);// 왼쪽 먼저 돈다.
		if (p != NULL) return p;
		p = findID(rightChild(v), id);
		if (p != NULL)return p;
	}
	return NULL;
}
int main() {
	int type, id;
	treeNode* root = treeBuild();

	scanf("%d %d", &type, &id);
	treeNode* p = findID(root, id);

	if (p != NULL)
	{
		if (type == 1)
			binaryPreOrder(p);
		else if (type == 2)
			binaryInOrder(p);
		else if (type == 3)
			binaryPostOrder(p);
	}
	else
	{
		printf("-1");
	}
	return 0;
}