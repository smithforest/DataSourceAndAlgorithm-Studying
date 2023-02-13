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
/*
* 插入顺序表(顺序表)
* i>=1
*/
bool ListInsert(SeqList& L, int i, ElemType e);
//顺序表删除
bool ListDelete(SeqList& L, int i, ElemType& e);
//按值查找
ElemType GetElem(SeqList& L, int i);
//按位查找
int LocateElem(SeqList& L, ElemType e);
//打印线性表
void PrintList(SeqList& L);

