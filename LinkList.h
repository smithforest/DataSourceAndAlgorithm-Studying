//������
typedef int ElemType; 
//Lode*�ȼ���LinkList,��һ��LNodeΪ�ṹ�����ƣ��ڶ���LNodeΪ�ṹ�����
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//��ʼ��������
bool InitList(LinkList& L);
//�жϵ������Ƿ�Ϊ��
bool isEmpty(LinkList& L);
//��λ����루��ͷ�ڵ㣩
bool ListInsert(LinkList L, int i, ElemType e);

