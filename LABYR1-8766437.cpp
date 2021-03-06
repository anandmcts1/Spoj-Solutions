//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
//#include<algorithm>
#include <stdio.h>
//////////definitions
#define dd cout<<"HERE"<<endl;
#define gg getch();
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
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define C(n) cin>>n;
#define DEBUG if(0)
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
////MAIN CODE BEGINS NOW...........
inline int max(int a,int b){if(a>=b){return a;}else return b;}
inline int min(int a,int b){if(a>=b){return b;}else {return a;}}


int a[1111][1111];int sx[5],sy[5];int W,H;int tempx,tempy;
int visit[1111][1111];int v[1111][1111];int anss;

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1}; 

int check(int xx,int yy)
{if(xx<0 || yy<0 || xx>=H || yy>=W || a[xx][yy]==-1)
{return 0;
}return 1;}

int dfs(int x,int y)
{
  int vall=v[x][y];anss=max(anss,vall);
  visit[x][y]=1;int newx,newy;
     forr(j,4)
	    { 
	        newx=x+dx[j];   
		    newy=y+dy[j];
            if(!check(newx,newy)){continue;;}
		if(visit[newx][newy]==0)
		  {
		  v[newx][newy]=max(v[newx][newy],vall+1);
		  visit[newx][newy]=1;
		  dfs(newx,newy);
         }
  }
  return 0;
}

int main()
{
//freopen("in.txt","r",stdin);
int T;S(T)
while(T--)
{

S(W) S(H)

//vector<pi>vec(W*H+1);

forr(i,H+1)
{
	forr(j,W+1)
	{visit[i][j]=0;v[i][j]=0;
	}
}

char str[1111];gets(str);int k=0;int cnt=0;int x,y;
forr(i,H)
{
  gets(str);
  ///CO(str)
  forr(j,W)
  {
    if(str[j]=='#'){a[i][j]=-1;}
    else if(str[j]=='.')
    {a[i][j]=0; x=i;y=j;
    }
  }
}

//sx[0]=0;sy[0]=0;
//solve(0,1);

//forr(i,cnt)
//int x=vec[0].ff;int y=vec[0].ss;
 
 dfs(x,y);
 
int maxi=-1;int maxx,maxy=-1;;

forr(i,H)
{
	forr(j,W)
	{                  
		if(v[i][j]>=maxi)
		{
			maxi=v[i][j];maxx=i;maxy=j;
		}
	}
} 
 
 forr(i,H+5)
 {
 	forr(j,W+5)
 	{
 		visit[i][j]=0;v[i][j]=0;;
 	}
 }
 
 anss=0;
 dfs(maxx,maxy);
            
  printf("Maximum rope length is %d.\n",anss);
}
return 0;
}


