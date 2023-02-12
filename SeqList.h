#define InitSize 10
typedef int  ElemType;
typedef struct {
	ElemType* data;
	//顺序表的最大容量
	int MaxSize;
	//顺序表的当前长度
	int length;
}SeqList;
//初始化顺序表
void InitList(SeqList& L);
//增加动态数组长度
void IncreaseSize(SeqList& L, int len);
//打印线性表
void PrintList(SeqList& L);

