#include <iostream>
using namespace std;

struct Node
{
	Node* lc,*rc,*par;
	int val,weight; //weight表示该值出现的次数
}*root;


//右旋的操作(以x为轴心)
void rRotate(Node* x)
{
	//先处理x的右孩子
	Node* y=x->par;
	y->lc=x->rc;
	//x的右孩子不为空时
	if(x->rc) x->rc->par=y;
	
	//处理x
	x->par=y->par;
	//当y有双亲时
	if(y->par)
	{
		if(y==y->par->lc)
			y->par->lc=x;
		else
			y->par->rc=x;
	}
	//处理y
	x->rc=y;
	y->par=x;
}


//左旋的操作(以x为轴心)
void lRotate(Node* x)
{
	//先处理x的右孩子
	Node* y=x->par;
	y->rc=x->lc;
	if(x->lc) x->lc->par=y;
	
	//处理x
	x->par=y->par;
	//当y有双亲时
	if(y->par)
	{
		if(y==y->par->lc)
			y->par->lc=x;
		else
			y->par->rc=x;
	}
	//处理y
	x->lc=y;
	y->par=x;
}

//将结点x调整到以y为双亲的位置
void Splay(Node* x,Node* y)
{
	while(x->par!=y)
	{
		//快结束时
		if(x->par->par==y)
		{
			//判断x是双亲的左孩子还是右孩子
			(x->par->lc==x)? rRotate(x):lRotate(x);
		}
		else
		{
			//如果x双亲是它双亲的左孩子时
			if(x->par->par->lc==x->par)
			{
				//左左结构
				if(x->par->lc==x)
				{
					//两次右旋
					rRotate(x->par);
					rRotate(x);
				}
				//左右结构
				else
				{
					//先左旋再右旋
					lRotate(x);
					rRotate(x);
				}
			}
			else
			{
				//右右结构
				if(x->par->rc==x)
				{
					//两次左旋
					lRotate(x->par);
					lRotate(x);
				}
				//右左结构
				else
				{
					//先右旋再左旋
					rRotate(x);
					lRotate(x);
				}
			}
		}
	}
	//如果y为空，则将x置为根
	if(0==y) root=x;
}


//查找结点的函数
bool find(Node* x,int key)
{
	if(!x) return false;

	//找到时
	if(x->val==key)
	{
		Splay(x,0); //将x伸展到树根
		return true;
	}
	else
	{
		//递归调用继续查找
		if(x->val>key)
			return find(x->lc,key);
		else
			return find(x->rc,key);
	}
}

//插入操作
void insert(int key)
{
	Node *ptr=root,*y=0;

	int lrChose=0; //判断新的结点应该为y的左孩子还是右孩子
	while(true)
	{
		//找到插入位置时
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

			Splay(ptr,0); //做伸展
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
				lrChose=0;//表示新的结点在y的左孩子位置插入
			}
			else
			{
				ptr=ptr->rc;
				lrChose=1; //表示新的结点在y的右孩子位置插入
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


//合并两棵树的函数
Node* join(Node* n1,Node* n2)
{
	//将n1和n2置为各自树的树根
	if(n1) n1->par=0;
	if(n2) n2->par=0;

	//当其中一棵树为空时直接返回另一棵
	if(!n1) return n2;
	if(!n2) return n1;

	n1->par=n2->par=0;

	Node* temp=n1;
	//找出n1树最大的结点(在最右边)
	while(temp->rc) temp=temp->rc; 

	Splay(temp,0); //将temp伸展到树根(此时temp所在树的树根temp无右子树)

	temp->rc=n2;
	n2->par=temp;

	return temp; //返回合并后的树根
}

//删除结点的函数
void remove(Node* x)
{
	Splay(x,0); //先将x伸展到树根
	root=join(x->lc,x->rc); //合并左右子树
	delete x; //最后释放x的空间
}

//删除最小值
void delMin(int& min,int& cnt)
{
	Node* x=root;
	//最小值在最左边
	while(x->lc) x=x->lc;
	//通过引用参数带回改结点的一些信息
	min=x->val;
	cnt=x->weight;

	remove(x);
}

//删除最大值
void delMax(int& max,int& cnt)
{
	Node* x=root;
	//最大值在最右边
	while(x->rc) x=x->rc;
	//通过引用参数带回改结点的一些信息
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

	preOrder(root); //前序遍历
	cout<<endl;

	cin.clear(); //恢复输入流


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
