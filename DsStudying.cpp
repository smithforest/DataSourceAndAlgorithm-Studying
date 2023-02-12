#include<stdio.h>
#include"SeqList.h"

int main() {
	SeqList L;
	InitList(L);
	for (int i = 1; i <= 4; i++) {
		ListInsert(L, i, i);
	}
	PrintList(L);
}
