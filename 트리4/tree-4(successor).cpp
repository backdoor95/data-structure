#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode {
	int elem;
	treeNode* root;
	treeNode* left;
	treeNode* right;
}treeNode;
treeNode* insertNode(int elem, treeNode* left, treeNode* right)
{
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->elem = elem;
	node->left = left;
	node->right = right;
	if (left != NULL)
		left->root = node;
	if (right != NULL)
		right->root = node;
	return node;
}
void visit(treeNode* v)
{
	printf("%c ", v->elem);
}
int isInternal(treeNode* v)
{
	return ((v->left != NULL) && (v->right != NULL));
}
int isExternal(treeNode* v)
{
	return((v->left == NULL) && (v->right == NULL));
}
treeNode* leftChild(treeNode* v)
{
	return v->left;
}
treeNode* rightChild(treeNode* v)
{
	return v->right;
}
void binaryPreOrder(treeNode* v)//전위
{
	visit(v);
	if (isInternal(v))
	{
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}
void binaryInOrder(treeNode* v)//중위
{
	if (isInternal(v))
		binaryInOrder(leftChild(v));
	visit(v);
	if (isInternal(v))
		binaryInOrder(rightChild(v));
}
void binaryPostOrder(treeNode* v)// 후위
{
	if (isInternal(v))
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
	}
	visit(v);
}
void invalidNodeException() {
	printf("invalidNodeException\n");
	exit(1);
}
treeNode* findID(treeNode* v, int id)
{
	if (v != NULL)
	{
		if (v->elem == id)return v;
		treeNode* p = NULL;
		p = findID(leftChild(v), id);
		if (p != NULL)return p;
		p = findID(rightChild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}
int isRoot(treeNode* v)
{
	if (v->root == NULL)
		return 1;
	else
		return 0;
}
treeNode* parent(treeNode* v)
{
	return v->root;
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
treeNode* preOrderSucc(treeNode* v)
{
	if (isInternal(v))
		return leftChild(v);
	treeNode* p = parent(v);
	while (leftChild(p) != v)
	{
		if (isRoot(p))
			invalidNodeException();
		v = p;
		p = parent(p);
	}
	return rightChild(p);
}
treeNode* inOrderSucc(treeNode* v)
{
	if (isInternal(v))
	{
		v = rightChild(v);
		while (isInternal(v))
			v = leftChild(v);
		return v;
	}
	treeNode* p = parent(v);
	while (leftChild(p) != v)
	{
		if (isRoot(p))
			invalidNodeException();
		v = p;
		p = parent(p);
	}
	return p;
}
treeNode* postOrderSucc(treeNode* v)
{
	if (isRoot(v))
		invalidNodeException();
	treeNode* p = parent(v);
	if (rightChild(p) == v)
		return p;
	v = rightChild(v);
	while (!isExternal(v))
		v = leftChild(v);
	return v;
}
int main() {
	treeNode* root = treeBuild();
	//binaryPreOrder(root);
	//A B D E H I C F G
	//binaryInOrder(root);
	//D B H E I A F C G
	//binaryPostOrder(root);
	//D H I E B F G C A

	treeNode* v1 = findID(root, 'I');
	v1 = preOrderSucc(v1);
	printf("%c\n", v1->elem);

	treeNode* v2 = findID(root, 'A');
	v2 = inOrderSucc(v2);
	printf("%c\n", v2->elem);

	treeNode* v3 = findID(root, 'C');
	v3 = postOrderSucc(v3);
	printf("%c\n", v3->elem);

	return 0;
}