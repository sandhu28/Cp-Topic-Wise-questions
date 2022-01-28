#include <iostream>
#include <bits/stdc++.h>
#define ppi pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define vvi vector<vector<int>>
#define vppi vector<pair<int, int>>
#define rep(i, k, n) for (i = k; i < n; ++i)
#define Repr(i, k, n) for (i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

bool dfs(vector<vector<char>> &v, string &s, int i, int j, int idx, vppi &mov, vvi &vis,int r,int c,int pi,int pj)
{
    // z(i);c(j);
    vis[i][j]=1;
    if(idx==s.size()-1){
        return 1;
    }
    for (auto &e : mov)
    {
        int nr = i - e.first;
        int nc = j - e.second;
        if (nr < 0 || nr >= r || nc < 0 || nc >= c || vis[nr][nc]==1 || (nr==pi && nc== pj))
        {
            continue;
        }
        if(s[idx+1]== v[nr][nc]){
            if(dfs(v,s,nr,nc,idx+1,mov,vis,r,c,i,j)){
                return 1;
            }
        }
    }
    vis[i][j]=0;
    return 0;
}
bool exist(vector<vector<char>> &v, string s)
{
    vppi mov({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
    int n = s.size();
    int r = v.size();
    int c = v[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            vvi vis(r, vi(c, 0));
            if (v[i][j] == s[0])
            {
                if (dfs(v, s, i, j, 0, mov, vis,r,c,-1,-1))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c;cin>>r>>c;
    vector<vector<char>> v(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    string s;cin>>s;
    c(exist(v,s));
    return 0;
}