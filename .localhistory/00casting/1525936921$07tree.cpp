#include "stdafx.h"

typedef struct node {
	int data;
	struct node * lChild;
	struct node * rChild;
}node;

node *newNode(int data);//노드 생성
//void InitTree(Tree *bst);//트리 초기화
int addData(node* bst, int data); //데이터 보관
void Preorder(node* sr);//전위 순위 운행
void Inorder(node* sr);//중위 순위 운행
void Postorder(node* sr);//후위 순위 운행


void main() {
	node* tree = NULL;
	addData(&tree, 10);
	addData(&tree, 6);
	addData(&tree, 9);
	addData(&tree, 5);
	addData(&tree, 15);
	addData(&tree, 25);
	addData(&tree, 3);
	addData(&tree, 19);
	addData(&tree, 14);

	//트리에 보관한 자료 확인
	printf("전위 순위 운행:");
	Preorder(tree);
	printf("\n중위 순위 운행:");
	Inorder(tree);
	printf("\n후위 순위 운행:");
	Postorder(tree);
}

int addData(node** bst, int data) {
	node * seek = *bst;
	int gap = 0;
	if (seek==NULL)
	{
		*bst = newNode(data);
		return 1;
	}
	while (true)
	{
		gap = seek->data - data;
		if (gap == 0)//재삽입
		{
			return 0;
		}
		else if (gap>0)//기존 데이터가 클 때(들어갈 데이터가 작을 때)
		{
			if (seek->lChild!=NULL)
			{
				seek = seek->lChild;
			}
			else
			{
				seek->lChild = newNode(data);
				return 1;
			}
		}
		else//기존 데이터가 작을 때(들어갈 데이터가 클 때)
		{
			if (seek->rChild!=NULL)
			{
				seek = seek->rChild;
			}
			else
			{
				seek->rChild = newNode(data);
				return 1;
			}
		}
	}
	return 1;
}

node *newNode(int data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->lChild = newNode->rChild = NULL;
	return newNode;
}

void Preorder(node* sr)//전위 순위 운행
{
	if (sr)
	{
		printf("%d ", sr->data);
		Preorder(sr->lChild);
		Preorder(sr->rChild);
	}
}
void Inorder(node* sr)//중위 순위 운행
{
	if (sr)
	{
		Inorder(sr->lChild);
		printf("%d ", sr->data);
		Inorder(sr->rChild);
	}
}
void Postorder(node* sr)//후위 순위 운행
{
	if (sr)
	{
		Postorder(sr->lChild);
		Postorder(sr->rChild);
		printf("%d ", sr->data);
	}
}