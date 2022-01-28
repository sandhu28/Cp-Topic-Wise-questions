#include <iostream>
#include <bits/stdc++.h>
#define ppi pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define merge(a, b) a##b
#define get(a) #a
#define rep(i, k, n) for (i = k; i < n; ++i)
#define Repr(i, k, n) for (i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF 1e9 + 10;
using namespace std;
const int N= 2e5 + 10;
vector<int> g[N];
bool vis[N];

int dfs(int node,int parent,string &s){
    vis[node]=1;
    int b= s[node]=='B'?1:0;
    for(auto e: g[node]){
        if(e==parent){continue;}
        if(b>1){return b;}
        b+= dfs(e,node,s);
    }
    return b;
}
void reset(){
    for(int i=0;i<N;i++){
        vis[i]=0;
        g[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        reset();
        int n;cin>>n;
        string temp,s=" ";
        cin>>temp;
        s+= temp;
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            if(s[x]=='G' && s[y]=='R'){continue;}
            if(s[x]=='R' && s[y]=='G'){continue;}
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){continue;}
            int check= dfs(i,-1,s);
            if(check>1){ans=0;break;}
        }
        if(ans>0){
            c("yes");
        }
        else{
            c("no");
        }
    }

    return 0;
}