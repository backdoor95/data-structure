#include<stdio.h>
#include<stdlib.h>
int k = 0;
typedef struct treeNode
{
	int elem;
	struct treeNode* left;
	struct treeNode* right;
	int kleft;
	int size;
}treeNode;
treeNode* insertNode(int elem, treeNode* left, treeNode* right)
{
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));
	v->elem = elem;
	v->kleft = 0;
	v->size = 0;
	v->left = left;
	v->right = right;
	return v;
}  
treeNode* treeBuild()
{
	treeNode* n1 = insertNode('H', NULL, NULL);
	treeNode* n2 = insertNode('I', NULL, NULL);
	treeNode* n3 = insertNode('E', n1, n2);
	treeNode* n4 = insertNode('D', NULL, NULL);
	treeNode* n5 = insertNode('B', n4, n3);
	treeNode* n6 = insertNode('F', NULL, NULL);
	treeNode* n7 = insertNode('G', NULL, NULL);
	treeNode* n8 = insertNode('C', n6, n7);
	treeNode* n9 = insertNode('A', n5, n8);
	return n9;
}
void visit(treeNode* v)
{
	printf("%c ", v->elem);
}
void visit_size(treeNode* v)
{
	printf("%d ", v->size);
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
	visit_size(v);
	if (isInternal(v))
	{
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
void binaryPostOrder(treeNode* v)
{
	if (isInternal(v))
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
	}
	visit_size(v);
}
void visitLeft(treeNode* v)
{
	k = k + 1;
	v->kleft = k;
}
void visitRight(treeNode* v)
{
	v->size = k - v->kleft + 1;
}
void visitBelow(treeNode* v)
{
	return;
}
void eulerTour(treeNode* v)
{
	visitLeft(v);// 선위
	if (isInternal(v))
		eulerTour(leftChild(v));
	visitBelow(v);// 중위
	if (isInternal(v))
		eulerTour(rightChild(v));
	visitRight(v);// 후위
}
void findSizeofSubtrees(treeNode* v)
{
	k = 0;
	eulerTour(v);
}
int main() {
	treeNode* root = treeBuild();
	eulerTour(root);
	binaryPreOrder(root);
	return 0;
}