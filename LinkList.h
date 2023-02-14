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

