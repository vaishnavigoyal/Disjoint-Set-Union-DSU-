// Question : Separating Numbers | July Circuits 2020 | HackerEarth
// Question Link : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/separating-numbers-6fe976a9/description/
// Solution using Union By Rank and Path Compression


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

ll par[300001];
map<ll,ll> mp[300001];


ll find(ll a)
{
  if(par[a]==-1)
  {
    return a;
  }
  return par[a]=find(par[a]);
}

ll merge(ll a,ll b)
{
  ll res=0;

  if(mp[a].size()>mp[b].size())
  {
    swap(a,b);
  }

  for(auto it=mp[a].begin();it!=mp[a].end();it++)
  {
    if(mp[b].find(it->ff)==mp[b].end())
    {
      mp[b][it->ff]=it->ss;
    }
    else
    {
      res+=(mp[b][it->ff]*it->ss);
      mp[b][it->ff]+=it->ss;
    }
  }
  par[a]=b;
  return res;
}

int main()
{
  ll n;
  std::cin >> n;

  for(ll i=1;i<=n;i++)
  {
    par[i]=-1;
  }

  vector<vector<ll>> list(n-1,vector<ll> (2));

  ll a,b;
  for(ll i=0;i<n-1;i++)
  {
    cin>>list[i][0]>>list[i][1];
  }

  vector<ll> col(n);
  for(ll i=0;i<n;i++)
  {
    cin>>col[i];
    mp[i+1][col[i]]=1;
  }

  vector<ll> operations(n-1);
  for(ll i=0;i<n-1;i++)
  {
    cin>>operations[i];
  }

  vector<ll> result(n-1);
  for(ll i=n-2;i>=0;i--)
  {
    result[i]=merge(find(list[operations[i]-1][0]),find(list[operations[i]-1][1]));
  }

  for(ll i=0;i<n-1;i++)
  {
    cout<<result[i]<<endl;
  }
}
