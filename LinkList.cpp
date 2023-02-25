#include<stdio.h>
#include"LinkList.h"
#include<stdlib.h>
//��ʼ��������
bool InitList(LinkList& L) {
	L = NULL;
	return true;
};
//�ж���ͷ�ڵ�ĵ������Ƿ�Ϊ��
bool isEmpty(LinkList& L) {
	if (L->next == NULL) {
		return true;
	}
	return false;
};
//��λ����루��ͷ�ڵ㣩
bool ListInsert(LinkList& L, int i, ElemType e) {
	//ͷ�ڵ��±���0
	LNode* p = L;
	if (i < 1) {
		return false;
	}
	//�ҵ�ֱ��ǰ������Ϊ��Ҫ��λ��n-1���ڵ��λ���ϣ�����ֻҪ��n-2���ڵ��next�ϾͿ����ˣ�j�ǵ�N���ڵ㣩
	for (int j = 0; j < i - 1 && p != NULL; j++) {
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	//��p�ڵ�֮�����eԪ��
	return InsertNextNode(p, e);
};
//��λ����루����ͷ�ڵ㣩
bool ListInsertWithoutHeader(LinkList& L, int i, ElemType e) {
	LNode* p = L;
	if (i < 1) {
		return false;
	}
	if (i == 1) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = p;
		L = s;
		return true;
	}
	int j = 1;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	//��p�ڵ�֮�����eԪ��
	return InsertNextNode(p, e);
}
//��λ��ɾ������ͷ�ڵ㣩
bool ListDelete(LinkList& L, int i, ElemType& e) {
	LNode* p = L;
	int j = 0;
	while (p != NULL & j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
//��p�ڵ�֮ǰ����eԪ��
bool InsertPreNode(LNode* p, ElemType e) {
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	s->data = p->data;
	p->data = e;
	s->next = p->next;
	p->next = s;
	return true;
};
//��p�ڵ�������eԪ��
bool InsertNextNode(LNode* p, ElemType e) {
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//��λ���ң���ͷ�ڵ㣩
LNode* GetElem(LinkList L, int i) {
	if (i < 1) {
		return NULL;
	}
	LNode* p = L;
	p = p->next;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
};
//��λ����(����ͷ�ڵ�)
LNode* GetElemWithoutHeader(LinkList L, int i) {
	if (i < 1) {
		return NULL;
	}
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
//��ֵ���ң���ͷ�ڵ㣩
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L;
	p = p->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
};
//��ֵ����(����ͷ�ڵ�)
LNode* LocateElemWithoutHeader(LinkList L, ElemType e) {
	LNode* p = L;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
};
//���ĳ���(��ͷ�ڵ�)
int Length(LinkList L) {
	int length = 0;
	//��ͷ�ڵ㿪ʼ��������ʱ�ڵ��ƶ��Ĵ����͵��ڱ�ĳ���
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
};
//���ĳ���(����ͷ�ڵ�)
int LengthWithoutHeader(LinkList L) {
	int length = 0;
	LNode* p = L;
	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
};
//��ӡ������(����ͷ���)
void printLinkWithoutHeader(LinkList L) {
	LNode* p = L;
	int num = 1;
	while (p->next!= NULL)
	{
		printf("��%d��Ԫ��ֵΪ%d\t", num++, p->data);
		p = p->next;
	}
}
//��ӡ��������ͷ�ڵ㣩
void printLinkWithHeader(LinkList L) {
	LNode* p = L->next;
	int num = 1;
	while (p!= NULL){
		printf("��%d��Ԫ��ֵΪ%d\t", num++, p->data);
		p = p->next;
	}
};
LinkList List_HeaderInsert(ElemType* arrays){
	if (arrays == NULL) {
		return NULL;
	}
	//��ͷ���
	LinkList L = (LNode*)malloc(sizeof(LNode));
	for (int i = 0; i < sizeof(arrays) / sizeof(ElemType); i++) {
		InsertNextNode(L, arrays[i]);
	}
	return L;
};
//β�巨����ͷ�ڵ㣩
LinkList List_LastInsert(ElemType* arrays, int length) {
	LinkList L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < length; i++) {
		InsertNextNode(L, arrays[i]);
	}
	return L;
};