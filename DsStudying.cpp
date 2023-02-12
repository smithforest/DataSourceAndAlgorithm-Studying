#include<stdio.h>
#include"SeqList.h"

int main() {
	SeqList L;
	InitList(L);
	L.data[1] = 12;
	printf("%d\n", L.data[1]);
	L.length = 2;
	IncreaseSize(L, 5);
	printf("%d\n", L.data[1]);


}
