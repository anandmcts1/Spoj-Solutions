//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
#include<fstream>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#ifndef ONLINE_JUDGE
#define DEBUG 1
#include<conio.h>
#endif
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;
//power function
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
inline int mod(int a,int b){return (a < b ? a : a % b); }
long long powmod(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}
int dx[] = {0, 1, 0, -1};int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {1, 0, -1, 0,1,-1,-1,1};

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

////MAIN CODE BEGINS NOW...........
void generatetests(int N)
{
  srand(time(NULL));
  ofstream myfile;
  myfile.open ("in.txt");
  myfile<<N<<endl;
  for(int i=0;i<N;i++)
  myfile<<rand()<<" ";

  myfile.close();
}
int len1,len2,vall;
int dp[111][111];char a[111];char b[111];

int solve(int i,int j)
{
   // CO(i<<" "<<j)
	if(i==len1+1 || j==len2+1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
    	dp[i][j]=1+solve(i+1,j+1);
    	return dp[i][j];
    }
    else
    {
    	return dp[i][j]=max(solve(i+1,j),solve(i,j+1));
    }
    
}
char out[111];
int k;

int print(int i,int j,int left)
{
	//CO(i<<" "<<j<<" "<<left)
	if(left==0)
	{
		puts(out);
	///	ge
		return 0;
	}
	if(i==len1+1) return 0;
	if(j==len2+1) return 0;
	int flag1=0,flag2=0,flag3=0;
	int pos1=-1,pos2=-1;
	for(int ch='a';ch<='z';ch++)
	{
	  pos1=-1;
	  for(int it=i;it<=len1;it++)
	  {
	  	
	  	if(ch==a[it] )
	  	{
	  		pos1=it;
	  		break;
	  	}
	  }
	  pos2=-1;
	  for(int it=j;it<=len2;it++)
	  {
	  	if(ch==b[it] )
	  	{
	  		pos2=it;
	  		break;
	  	}
	  }  
	  //CO(ch<<" "<<pos1<<" "<<pos2)
	 // ge
	 if(pos1==-1 || pos2==-1)
	 {
//	 	CO(" Enterer ")
	 	continue;
	 }
	 if(solve(pos1+1,pos2+1)==left-1)
	 {
         out[k]=ch;k++;
		 //print(i+1,j+1,left-1);
         print(pos1+1,pos2+1,left-1);
	 	 k--;
		 out[k]='\0';
	 }
    }
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	//generatetests(1000);
	freopen("in.txt","r",stdin);
                  #endif
 int T;C(T);
 double cl = clock();
 while(T--)
 {
 	 k=0;
 	 SET(dp,-1)
 	 C(a+1)
 	 C(b+1)
 	 out[0]='\0';
 	 len1=strlen(a+1);len2=strlen(b+1);
 	 vall=solve(1,1);
 	 //CO(vall)
     print(1,1,vall);
 }
 fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
return 0;
}


