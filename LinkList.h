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
//��λ����루����ͷ�ڵ㣩
bool ListInsertWithoutHeader(LinkList& L, int i, ElemType e);
//��p�ڵ�֮ǰ����eԪ��
bool InsertPreNode(LNode* p, ElemType e);
//��p�ڵ�������eԪ��
bool InsertNextNode(LNode* p, ElemType e);
//��λ����
LNode* GetElem(LinkList L, int i);
//��λ����(����ͷ�ڵ�)
LNode* GetElemWithoutHeader(LinkList L, int i);
//��ֵ����
LNode* LocateElem(LinkList L, ElemType e);
//��ֵ����(����ͷ�ڵ�)
LNode* LocateElemWithoutHeader(LinkList L, ElemType e);
//���ĳ���
int Length(LinkList L);
//���ĳ���(����ͷ�ڵ�)
int LengthWithoutHeader(LinkList L);
//��ӡ������(����ͷ���)
void printLinkWithoutHeader(LinkList L);
//��ӡ��������ͷ�ڵ㣩
void printLinkWithHeader(LinkList L);
//ͷ�巨������ͷ�ڵ㣩
LinkList List_HeaderInsert(ElemType* arrays);
//β�巨����ͷ�ڵ㣩
LinkList List_LastInsert(ElemType* arrays, int length);



