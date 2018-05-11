#include "stdafx.h"

typedef struct node {
	int data;
	struct node * lChild;
	struct node * rChild;
}node;

node *newNode(int data);//��� ����
//void InitTree(Tree *bst);//Ʈ�� �ʱ�ȭ
int addData(node* bst, int data); //������ ����
void Preorder(node* sr);//���� ���� ����
void Inorder(node* sr);//���� ���� ����
void Postorder(node* sr);//���� ���� ����


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

	//Ʈ���� ������ �ڷ� Ȯ��
	printf("���� ���� ����:");
	Preorder(tree);
	printf("\n���� ���� ����:");
	Inorder(tree);
	printf("\n���� ���� ����:");
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
		if (gap == 0)//�����
		{
			return 0;
		}
		else if (gap>0)//���� �����Ͱ� Ŭ ��(�� �����Ͱ� ���� ��)
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
		else//���� �����Ͱ� ���� ��(�� �����Ͱ� Ŭ ��)
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

void Preorder(node* sr)//���� ���� ����
{
	if (sr)
	{
		printf("%d ", sr->data);
		Preorder(sr->lChild);
		Preorder(sr->rChild);
	}
}
void Inorder(node* sr)//���� ���� ����
{
	if (sr)
	{
		Inorder(sr->lChild);
		printf("%d ", sr->data);
		Inorder(sr->rChild);
	}
}
void Postorder(node* sr)//���� ���� ����
{
	if (sr)
	{
		Postorder(sr->lChild);
		Postorder(sr->rChild);
		printf("%d ", sr->data);
	}
}