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
//��ӡ���Ա�
void PrintList(SeqList& L);

