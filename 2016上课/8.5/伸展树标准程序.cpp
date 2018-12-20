#include <iostream>
using namespace std;

struct Node
{
	Node* lc,*rc,*par;
	int val,weight; //weight��ʾ��ֵ���ֵĴ���
}*root;


//�����Ĳ���(��xΪ����)
void rRotate(Node* x)
{
	//�ȴ���x���Һ���
	Node* y=x->par;
	y->lc=x->rc;
	//x���Һ��Ӳ�Ϊ��ʱ
	if(x->rc) x->rc->par=y;
	
	//����x
	x->par=y->par;
	//��y��˫��ʱ
	if(y->par)
	{
		if(y==y->par->lc)
			y->par->lc=x;
		else
			y->par->rc=x;
	}
	//����y
	x->rc=y;
	y->par=x;
}


//�����Ĳ���(��xΪ����)
void lRotate(Node* x)
{
	//�ȴ���x���Һ���
	Node* y=x->par;
	y->rc=x->lc;
	if(x->lc) x->lc->par=y;
	
	//����x
	x->par=y->par;
	//��y��˫��ʱ
	if(y->par)
	{
		if(y==y->par->lc)
			y->par->lc=x;
		else
			y->par->rc=x;
	}
	//����y
	x->lc=y;
	y->par=x;
}

//�����x��������yΪ˫�׵�λ��
void Splay(Node* x,Node* y)
{
	while(x->par!=y)
	{
		//�����ʱ
		if(x->par->par==y)
		{
			//�ж�x��˫�׵����ӻ����Һ���
			(x->par->lc==x)? rRotate(x):lRotate(x);
		}
		else
		{
			//���x˫������˫�׵�����ʱ
			if(x->par->par->lc==x->par)
			{
				//����ṹ
				if(x->par->lc==x)
				{
					//��������
					rRotate(x->par);
					rRotate(x);
				}
				//���ҽṹ
				else
				{
					//������������
					lRotate(x);
					rRotate(x);
				}
			}
			else
			{
				//���ҽṹ
				if(x->par->rc==x)
				{
					//��������
					lRotate(x->par);
					lRotate(x);
				}
				//����ṹ
				else
				{
					//������������
					rRotate(x);
					lRotate(x);
				}
			}
		}
	}
	//���yΪ�գ���x��Ϊ��
	if(0==y) root=x;
}


//���ҽ��ĺ���
bool find(Node* x,int key)
{
	if(!x) return false;

	//�ҵ�ʱ
	if(x->val==key)
	{
		Splay(x,0); //��x��չ������
		return true;
	}
	else
	{
		//�ݹ���ü�������
		if(x->val>key)
			return find(x->lc,key);
		else
			return find(x->rc,key);
	}
}

//�������
void insert(int key)
{
	Node *ptr=root,*y=0;

	int lrChose=0; //�ж��µĽ��Ӧ��Ϊy�����ӻ����Һ���
	while(true)
	{
		//�ҵ�����λ��ʱ
		if(!ptr)
		{
			ptr=new Node;
			ptr->lc=ptr->rc=0;
			ptr->val=key;
			ptr->weight=1;
			ptr->par=y;
			if(y!=0)
			{
				if(0==lrChose) y->lc=ptr;
				else y->rc=ptr;
			}

			Splay(ptr,0); //����չ
			break;
		}

		y=ptr;
		if(key==ptr->val)
		{
			++ptr->weight;
			Splay(ptr,0);
			break;
		}
		else
			if(key<ptr->val)
			{
				ptr=ptr->lc;
				lrChose=0;//��ʾ�µĽ����y������λ�ò���
			}
			else
			{
				ptr=ptr->rc;
				lrChose=1; //��ʾ�µĽ����y���Һ���λ�ò���
			}
	}
}

void preOrder(Node* r)
{
	if(r!=0)
	{
		for(int i=0;i<r->weight;++i)
			cout<<r->val<<" ";

		preOrder(r->lc);
		preOrder(r->rc);
	}
}


//�ϲ��������ĺ���
Node* join(Node* n1,Node* n2)
{
	//��n1��n2��Ϊ������������
	if(n1) n1->par=0;
	if(n2) n2->par=0;

	//������һ����Ϊ��ʱֱ�ӷ�����һ��
	if(!n1) return n2;
	if(!n2) return n1;

	n1->par=n2->par=0;

	Node* temp=n1;
	//�ҳ�n1�����Ľ��(�����ұ�)
	while(temp->rc) temp=temp->rc; 

	Splay(temp,0); //��temp��չ������(��ʱtemp������������temp��������)

	temp->rc=n2;
	n2->par=temp;

	return temp; //���غϲ��������
}

//ɾ�����ĺ���
void remove(Node* x)
{
	Splay(x,0); //�Ƚ�x��չ������
	root=join(x->lc,x->rc); //�ϲ���������
	delete x; //����ͷ�x�Ŀռ�
}

//ɾ����Сֵ
void delMin(int& min,int& cnt)
{
	Node* x=root;
	//��Сֵ�������
	while(x->lc) x=x->lc;
	//ͨ�����ò������ظĽ���һЩ��Ϣ
	min=x->val;
	cnt=x->weight;

	remove(x);
}

//ɾ�����ֵ
void delMax(int& max,int& cnt)
{
	Node* x=root;
	//���ֵ�����ұ�
	while(x->rc) x=x->rc;
	//ͨ�����ò������ظĽ���һЩ��Ϣ
	max=x->val;
	cnt=x->weight;

	remove(x);
}


int main()
{
	//test
	int val=0;

	while(cin>>val)
		insert(val);

	preOrder(root); //ǰ�����
	cout<<endl;

	cin.clear(); //�ָ�������


	int findNum=0;
	cout<<"Enter the integer you want to find:";
	cin>>findNum;
	if(find(root,findNum))
		cout<<"Have found!"<<endl;
	else
		cout<<"Have not found!"<<endl;


	int max=0,min=0,cnt=0;
	delMin(min,cnt);
	cout<<"min:"<<min<<",num:"<<cnt<<endl;

	delMax(max,cnt);
	cout<<"max:"<<max<<",num:"<<cnt<<endl;
}
