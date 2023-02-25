//单链表
typedef int ElemType; 
//Lode*等价于LinkList,第一个LNode为结构体名称，第二个LNode为结构体变量
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//初始化单链表
bool InitList(LinkList& L);
//判断单链表是否为空
bool isEmpty(LinkList& L);
//按位序插入（带头节点）
bool ListInsert(LinkList L, int i, ElemType e);
//按位序插入（不带头节点）
bool ListInsertWithoutHeader(LinkList& L, int i, ElemType e);
//在p节点之前插入e元素
bool InsertPreNode(LNode* p, ElemType e);
//在p节点后面插入e元素
bool InsertNextNode(LNode* p, ElemType e);
//按位查找
LNode* GetElem(LinkList L, int i);
//按位查找(不带头节点)
LNode* GetElemWithoutHeader(LinkList L, int i);
//按值查找
LNode* LocateElem(LinkList L, ElemType e);
//按值查找(不带头节点)
LNode* LocateElemWithoutHeader(LinkList L, ElemType e);
//求表的长度
int Length(LinkList L);
//求表的长度(不带头节点)
int LengthWithoutHeader(LinkList L);
//打印单链表(不带头结点)
void printLinkWithoutHeader(LinkList L);
//打印单链表（带头节点）
void printLinkWithHeader(LinkList L);
//头插法（不带头节点）
LinkList List_HeaderInsert(ElemType* arrays);
//尾插法（带头节点）
LinkList List_LastInsert(ElemType* arrays, int length);



