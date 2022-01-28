#include<iostream>
#include<bits/stdc++.h>
#define ppi pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define vvi vector<vector<int>>
#define vppi vector<pair<int,int>>
#define rep(i,k,n) for (i = k; i < n; ++i)
#define Repr(i,k,n) for (i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" "
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

int minStepToReachTarget(vector<int> &st, vector<int> &en, int n)
{
    vppi mov({{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}});
    vvi lev(n,vi(n,INT_MAX));
    queue<ppi> q;
    q.push({st[0]-1,st[1]-1});
    lev[st[0]-1][st[1]-1]=0;
    while(!q.empty()){
        auto pr= q.front();
        q.pop();
        for(auto& e: mov){
            int nr= pr.first-e.first;
            int nc= pr.second- e.second;
            if(nr<0 || nr>=n || nc<0 || nc>=n){continue;}
            if(lev[nr][nc]>lev[pr.first][pr.second] + 1){
                lev[nr][nc]=lev[pr.first][pr.second] + 1;
                q.push({nr,nc});
            }
        }
        if(lev[en[0]-1][en[1]-1]!= INT_MAX){
            return lev[en[0]-1][en[1]-1];
        }
    }
    return lev[en[0]-1][en[1]-1]== INT_MAX?-1: lev[en[0]-1][en[1]-1];
}

int main()
{

    return 0;
}