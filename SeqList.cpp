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
/*
* 插入顺序表(顺序表)
* i>=1
*/
bool ListInsert(SeqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	if (L.length >= L.MaxSize) {
		return false;
	}
	//错误写法 i的意思是在第几位进行插入，而不是在第几位之后进行插入
	/*for (int j = L.length - 1; j >= i; j--) {
		L.data[j + 1] = L.data[j];
	}
	L.data[i] = e;*/
	//正确写法：
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
//打印线性表
void PrintList(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("第[%d]个元素=%d\t", i + 1, L.data[i]);
	}
}

