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

/*
* ����˳���(˳���)
* i>=1
*/
bool ListInsert(SeqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	if (L.length >= L.MaxSize) {
		return false;
	}
	//����д�� i����˼���ڵڼ�λ���в��룬�������ڵڼ�λ֮����в���
	/*for (int j = L.length - 1; j >= i; j--) {
		L.data[j + 1] = L.data[j];
	}
	L.data[i] = e;*/      
	//��ȷд����
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//˳���ɾ��
bool ListDelete(SeqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

//��ֵ����
ElemType GetElem(SeqList&L,int i){
	if (i<1 || i>L.length) {
		return NULL;
	}
	return L.data[i - 1];
}
//��λ����
int LocateElem(SeqList&L,ElemType e) {
	int result = -1;
	for (int i = 0; i < L.length; i++) {
		if (e == L.data[i]) {
			result = i + 1;
		}
	}
	return result;
}
//��ӡ���Ա�
void PrintList(SeqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("��[%d]��Ԫ��=%d\t", i + 1, L.data[i]);
	}
}

