#include<stdio.h>
#include"LinkList.h"
#include<stdlib.h>
//初始化单链表
bool InitList(LinkList& L) {
	L = NULL;
	return true;
};
//判断有头节点的单链表是否为空
bool isEmpty(LinkList& L) {
	if (L->next == NULL) {
		return true;
	}
	return false;
};
//按位序插入（带头节点）
bool ListInsert(LinkList& L, int i, ElemType e) {
	//头节点下标是0
	LNode* p = L;
	if (i < 1) {
		return false;
	}
	//找到直接前驱，因为需要定位到n-1个节点的位置上，所以只要到n-2个节点的next上就可以了（j是第N个节点）
	for (int j = 0; j < i - 1 && p != NULL; j++) {
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
		j++;
	}
	if (p == NULL) {
		return false;
	}
	//在p节点之后插入e元素
	return InsertNextNode(p, e);
}
//按位序删除（带头节点）
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
//在p节点之前插入e元素
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
//按位查找（带头节点）
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
//按位查找(不带头节点)
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
//按值查找（带头节点）
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L;
	p = p->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
};
//按值查找(不带头节点)
LNode* LocateElemWithoutHeader(LinkList L, ElemType e) {
	LNode* p = L;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
};
//求表的长度(带头节点)
int Length(LinkList L) {
	int length = 0;
	//从头节点开始，所以临时节点移动的次数就等于表的长度
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
};
//求表的长度(不带头节点)
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
//打印单链表(不带头结点)
void printLinkWithoutHeader(LinkList L) {
	LNode* p = L;
	int num = 1;
	while (p->next!= NULL)
	{
		printf("第%d个元素值为%d\t", num++, p->data);
		p = p->next;
	}
}
//打印单链表（带头节点）
void printLinkWithHeader(LinkList L) {
	LNode* p = L->next;
	int num = 1;
	while (p!= NULL){
		printf("第%d个元素值为%d\t", num++, p->data);
		p = p->next;
	}
};
LinkList List_HeaderInsert(ElemType* arrays){
	if (arrays == NULL) {
		return NULL;
	}
	//带头结点
	LinkList L = (LNode*)malloc(sizeof(LNode));
	for (int i = 0; i < sizeof(arrays) / sizeof(ElemType); i++) {
		InsertNextNode(L, arrays[i]);
	}
	return L;
};
//尾插法（带头节点）
LinkList List_LastInsert(ElemType* arrays, int length) {
	LinkList L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i < length; i++) {
		InsertNextNode(L, arrays[i]);
	}
	return L;
};