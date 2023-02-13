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

