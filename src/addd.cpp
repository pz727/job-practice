//n give the sum of a list,and start give the first number of the list
#include <iostream>
#include <list>
using namespace std;

void print_list(list<int>::const_iterator iter_begin,list<int>::const_iterator iter_end)
{
		for (; iter_begin!=iter_end;++iter_begin)
		{
			cout<<*iter_begin<<'+';//输出前缀，最后一个后缀单独输出
		}
}
/*
	这个函数会打印N的所有加法组合
	打印时将重复的组合去掉，只剩下N = m1+m2+m3的形式
	其中m1<=m2<=m3
	N:待打印的数
	list1:临时变量，用于存放动态的子序列
	start:m1开始打印(默认从m1=1开始打印，m1会自动增大到N完成全部打印)，如果m1=N，则只打印N本身
*/
void f(int n,list<int>& list1,int start) 
{
	if (n==1)//当函数递归到n=1的时候，说明n已经被拆分成N=m1+m2+...+mk+n的时候了，
	{
		//输出前缀，当然前缀肯定也全部都是1
		print_list(list1.begin(),list1.end());
		//换行
		cout<<1<<endl;
		return;
	} 
	else
	{
		//1+2 和 2+1 认为是同一种情况 ,所以只输出n1+n2+n3+..., n1<=n2<=n3... 
		// 只输出后续组合从start开始的那些组合（1+2）（ + 3+3=6）=9
		//(1)
		for (int i=start; i<=n/2 ;i++ )
		{
			//（ + 3+3=6）
			list1.push_back(i); 
			//print 1+f(n-1)   print 2+f(n-2)...
			//每个函数打印它自己的所有子情况，
			//同时借助上层函数遗留的链表作为前缀，
			//有start决定从哪一个数字开始打印

			f(n-i,list1,i); 
			//the loop goto a new number at the end of the list
			//（1+2）                        =9 为进入下一个循环迭代做好准备
			list1.pop_back();   
		}

		//for循环之外的情况，即n自身的输出（当然也要先输出前缀）
		print_list(list1.begin(),list1.end());
		//输出自己，单独输出一行
		cout << n << endl;
	}
}

void get(int N)
{
	list<int> list1;
	f(N,list1,1);
}


//计算和为n的，最大加法数为k的加法数目

int fun(int n, int k)
{
	int rst(0);
	int tim = n/k;
	for(size_t i=1;i<=tim;i++)
	{
		int tmp = n-i*k;
		rst += fun(tmp,k );
	} 
}


int main( void ) 
{
	get(9);
	return 0;
}