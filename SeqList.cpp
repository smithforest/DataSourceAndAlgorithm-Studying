#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"
//初始化顺序表
void InitList(SeqList& L) {
	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L.MaxSize = InitSize;
	L.length = 0;
};
//增加动态数组长度
void IncreaseSize(SeqList& L, int len) {
	ElemType* p = L.data;
	L.data = (ElemType*)malloc((L.MaxSize + len) * sizeof(ElemType));
	L.MaxSize += len;
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	free(p);
};
//打印线性表
void PrintList(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("第[%d]个元素=%d\t", i + 1, L.data[i]);
	}
}

