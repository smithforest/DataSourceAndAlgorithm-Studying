#include<stdio.h>
#include"LinkList.h"
#include<stdlib.h>
//初始化单链表
bool InitList(LinkList& L) {
	L = NULL;
	return true;
};
//判断单链表是否为空
bool isEmpty(LinkList& L) {
	if (L->next == NULL) {
		return true;
	}
	return false;
};
//按位序插入（带头节点）
bool ListInsert(LinkList &L, int i, ElemType e) {
	//头节点下标是0
	LNode* p=L;
	if (i < 1) {
		return false;
	}
	//找到直接前驱，因为需要定位到n-1个节点的位置上，所以只要到n-2个节点的next上就可以了（j是第N个节点）
	for (int j = 0; j < i - 1&&p!=NULL; j++) {
			p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	//在p节点之后插入e元素
	return InsertNextNode(p, e);
};
//按位序插入（不带头节点）
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
	//在p节点之后插入e元素
	return InsertNextNode(p, e);
}
//在p节点后面插入e元素
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