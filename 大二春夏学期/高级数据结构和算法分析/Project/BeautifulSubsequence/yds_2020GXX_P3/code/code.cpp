#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lowbit(x) x&(-x)
using namespace std;
/*Beautiful Subsequence
反向思维，先求出相邻两个数都大于m的子序列（姑且称之为丑子序列），再用子序列总个数减去，得到答案
具体用动态规划dp和树状数组实现，tree[x]中记录了以x结尾的丑子序列个数*/

const int mod = 1e9 + 7;            //题目要求 
const int maxn = 1e5 + 10;
int n,m;
int result;
int dp[maxn];                       //dp结果储存 
int inc[maxn];                      //将输入的序列递增排序后的数组 
int tree[maxn];                     //树状数组 
int a[maxn];                        //原数组 

//返回n个数的长度大于等于2的子序列总个数 
int count(int x)
{
	return pow(2, x) - x - 1;
}

//返回递增数列inc中<=x的数的最大位置 
int flag(int x)            
{
  int min = 1;
  int max = n;
  int mid;
  while(min <= max){
    mid = (min + max) / 2;
    if(inc[mid] > x) max = mid - 1;
    else  min = mid + 1;
  }
  return min - 1;
}

//下面两个是构建树状数组的函数
void update(int x, int dx)          //对树状数组中的tree[x] + dx 
{
	while(x < maxn)
    {
        tree[x] = (tree[x] + dx) % mod; 
        x += lowbit(x);
    }
}

int getsum(int x)                   //树状数组前x个元素求和 
{
	int sum = 0;
	while(x > 0)
    {
        sum = (sum + tree[x]) % mod;
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
	int i;
	int self, upper, lower;                               //原位 上界 下界
	int tip;                                              //记录子序列个数的一个中间值 
	cin >> n >> m;
	for(i = 1;i <= n;i++){
	    cin >> a[i];
		inc[i] = a[i]; 
	}
	sort(inc + 1, inc + 1 + n);                           //algorithm中的函数, 使数组递增排序
	dp[0] = 0;                                            //dp初始化 
	for(i = 1; i <= n; i++){
		self = flag(a[i]);
        upper = flag(a[i] + m);
		lower = flag(a[i] - m - 1);                    
        tip = getsum(n) - getsum(upper) + getsum(lower);   //关键一步 确定满足条件的范围 
        tip = (tip % mod + mod) % mod;
        update(self, tip + 1);                             //写入树状数组 
        dp[i] = (dp[i-1] + tip) % mod;                     //动态规划关系式 
	}
	result = count(n) - dp[n];
	cout << result << endl;
    system("PAUSE");
	return 0; 
}
