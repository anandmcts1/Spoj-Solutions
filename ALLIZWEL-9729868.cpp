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
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define sti set<int>
#define qui queue<int>
#define l long
#define ll long long
#define qull queue<ll>
#define vill vector<ll>
#define stll set<ll>
#define mll map<ll,ll>
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define forrb(i,n) for(int i=n;i>0;i--)
#define forrrb(i,n,v)  for(int i=n;i>v;i--)
#define s(n) scanf("%d",&n);
#define p(n) printf("%d\n",n);
#define sll(n) scanf("%lld",&n);
#define pll(n) printf("%lld\n",n);
#define c(n) cin>>n;
#define pause system("pause");
#define set(a,val) memset(a,val,sizeof a);
#define pb push_back
#define co(n) cout<<n<<endl;
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
int dx[] = {0, 1, 0, -1};int dx2[] = {1, 0, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {0, 1, -1, 0,1,-1,-1,1};

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

int N;int M;;pi pos[5];

int check(int x,int y)
{
     if(x<N &&  x>=0 && y<M && y>=0)
     {
          return 1;
     }
     return 0;
}

int T;string str[222];string ch="ALLIZZWELL"; 
int cnt;;
int hash[222][222];

int dfs(int x,int y,int ptrr)
{  
        //co(x<<" "<<y<<" "<<ptrr<<" here ")
       // ge
        if(ptrr+1==ch.length())
        {
          co("YES")
          return 1;
        }
        //co("")
        int newx,newy;
        ///co(str[x][y]<<" parent "<<ch[ptr])
        forr(j,8)
        {
             newx=x+dx2[j];newy=y+dy2[j];
             if(check(newx,newy)==0) {continue;}
             //co(newx<<" "<<newy<<" new points "<<ptrr<<" "<<x<<" "<<y)
             if(  hash[newx][newy]!=cnt && hash[newx][newy]!=cnt &&( ch[ptrr+1]==str[newx][newy] ))
             {

               {
                //visit[newx][newy][ptrr+1]=cnt;;
                hash[newx][newy]=cnt;
                if(dfs(newx,newy,ptrr+1)) 
                {return 1;;}
                hash[newx][newy]=-cnt;
               }
               //co(" back again  ")
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
 c(T);int tot=0;;
 while(T--)
 {
   //   co(" fffffere ")
      c(N>>M) tot=0;
     // co(N<<" fef "<< M)
      //set(a,0)
      //set(arr,0)
      forr(i,N)
      {
           c(str[i])
      //     co(str[i])
       //    ge
           
      }
      //co("")
    ;
    cnt=cnt-T-1;
    //co(" fffffere "<<cnt)
    forr(i,N)
    {
         forr(j,M)
         {
              if(str[i][j]=='A')
              {
                  cnt--;
                  if(dfs(i,j,0))
                  {
                     goto xx;
                  }  
              }
         }
    }
    co("NO")
    xx:;
 }
 return 0;
}

