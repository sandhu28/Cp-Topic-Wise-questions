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

bool dfs(vector<vector<int> > &v,int i,int j,int n,vppi & mov,vvi& vis){
    // if(i==ex && j==ey){return 1;}
    vis[i][j]=1;
    if(v[i][j]==2){return 1;}
    if(v[i][j]==0){return 0;}
    for(auto& pr: mov){
        int nr= i- pr.first;
        int nc= j- pr.second;
        if(nr<0 || nr>=n || nc<0 || nc>=n || vis[nr][nc]==1){continue;}
        if(dfs(v,nr,nc,n,mov,vis)){return 1;}
    }
    return 0;
}

int checkPath(vector<vector<int> > &v) {
    int n= v.size();
    vppi mov({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
    int x=0,y=0;
    int ex=0;int ey=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1){
                x=i;y=j;
            }
            if(v[i][j]==2){ex=i;ey=j;}
        }
    }
    // z(x);c(y);z(ex);c(ey);
    vvi vis(n, vi(n, 0));
    return dfs(v,x,y,n,mov,vis)==1?1:0;

}
// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Blank Wall.
int main(){
    int n;cin>>n;
    vvi v(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    c(checkPath(v));
    return 0;
}