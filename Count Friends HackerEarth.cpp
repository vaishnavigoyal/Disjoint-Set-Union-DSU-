// Question : Count Friends
// Question Link : https://www.hackerearth.com/problem/algorithm/count-friends-190fcb36/description/
// Solution using Union By Rank and Path Compression


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int par[100001];
int R[100001];

int find(int a)
{
  if(par[a]==-1)
  {
    return a;
  }
  return par[a]=find(par[a]);
}

void merge(int a,int b)
{
  a=find(a);
  b=find(b);

  if(a==b)
  {
    return ;
  }
  if(R[a]>R[b])
  {
    par[b]=a;
    R[a]+=R[b];
  }
  else
  {
    par[a]=b;
    R[b]+=R[a];
  }
  return;
}

int main()
{
  int n,m;
  std::cin >> n>>m;

  for(int i=1;i<=n;i++)
  {
    par[i]=-1;
    R[i]=1;
  }

  int a,b;
  while(m--)
  {
    cin>>a>>b;

    merge(a,b);
  }

  for(int i=1;i<=n;i++)
  {
    int x=find(i);
    cout<<R[x]-1<<" ";
  }
}
