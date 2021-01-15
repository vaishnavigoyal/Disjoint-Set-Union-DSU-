// Question :City And Flood
// Question Link : https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/description/

// Solution using set

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
  int n,k;
  std::cin >> n>>k;
  set<int> s;
  for(int i=1;i<=n;i++)
  {
    s.insert(i);
  }
  int a,b;
  while(k--)
  {
    cin>>a>>b;
    s.erase(b);
  }
  cout<<s.size()<<endl;
}

// Solution using DSU

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int par[100001];

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
  par[a]=b;

}

int main()
{
  int n,k;
  std::cin >> n>>k;

  for(int i=1;i<=n;i++)
  {
    par[i]=-1;
  }

  int a,b;
  while(k--)
  {
    cin>>a>>b;
    merge(a,b);
  }

  int res=0;
  for(int i=1;i<=n;i++)
  {
    if(par[i]==-1)
    {
      res++;
    }
  }

  cout<<res<<endl;
}
