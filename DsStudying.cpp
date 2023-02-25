#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"
#include"LinkList.h"
int main() {
	//带头节点的尾插法
	ElemType arrays[] = { 1,2,3,4,5,6 };
	printLinkWithHeader(List_LastInsert(arrays,sizeof(arrays)/sizeof(ElemType)));
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p->next == NULL) {
		printf("%d", p->data);
	}
	else {
		printf("%d", 1);
	}

}
