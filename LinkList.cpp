#include<stdio.h>
#include"LinkList.h"
#include<stdlib.h>
//��ʼ��������
bool InitList(LinkList& L) {
	L = NULL;
	return true;
};
//�жϵ������Ƿ�Ϊ��
bool isEmpty(LinkList& L) {
	if (L->next == NULL) {
		return true;
	}
	return false;
};
//��λ����루��ͷ�ڵ㣩
bool ListInsert(LinkList &L, int i, ElemType e) {
	//ͷ�ڵ��±���0
	LNode* p=L;
	if (i < 1) {
		return false;
	}
	//�ҵ�ֱ��ǰ������Ϊ��Ҫ��λ��n-1���ڵ��λ���ϣ�����ֻҪ��n-2���ڵ��next�ϾͿ����ˣ�j�ǵ�N���ڵ㣩
	for (int j = 0; j < i - 1&&p!=NULL; j++) {
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
	}
	if (p == NULL) {
		return false;
	}
	//��p�ڵ�֮�����eԪ��
	return InsertNextNode(p, e);
}
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