#define InitSize 10
typedef int  ElemType;
typedef struct {
	ElemType* data;
	//˳�����������
	int MaxSize;
	//˳���ĵ�ǰ����
	int length;
}SeqList;
//��ʼ��˳���
void InitList(SeqList& L);
//���Ӷ�̬���鳤��
void IncreaseSize(SeqList& L, int len);
/*
* ����˳���(˳���)
* i>=1
*/
bool ListInsert(SeqList& L, int i, ElemType e);
//��ӡ���Ա�
void PrintList(SeqList& L);

