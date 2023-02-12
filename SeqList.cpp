#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"
//��ʼ��˳���
void InitList(SeqList& L) {
	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L.MaxSize = InitSize;
	L.length = 0;
};
//���Ӷ�̬���鳤��
void IncreaseSize(SeqList& L, int len) {
	ElemType* p = L.data;
	L.data = (ElemType*)malloc((L.MaxSize + len) * sizeof(ElemType));
	L.MaxSize += len;
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	free(p);
};
//��ӡ���Ա�
void PrintList(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("��[%d]��Ԫ��=%d\t", i + 1, L.data[i]);
	}
}

