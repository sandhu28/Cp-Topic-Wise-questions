
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
// #define c(n) cout<<n<<endl
#define z(n) cout<<n<<" "
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;


vector<pair<int,int>> mov= {{0,1},{0,-1},{1,0},{-1,0}};
int dfs(vector<vector<int>>& grid, int i,int j,int r,int c,int ct,int com){
    
    // z(i);z(j);z(ct);nl;
    if(i<0 || i>=r || j<0 || j>= c || grid[i][j]==-1){
        return 0;
    }
    
    if(grid[i][j]==2 ){
        if(ct-1==com){
            return 1;
        }
        return 0;
    }
    
    grid[i][j]=-1;
    ct++;
    int ans=0;
    for(int k=0;k<mov.size();k++){
        int tx= i- mov[k].first;
        int ty= j- mov[k].second;
        ans+= dfs(grid,tx,ty,r,c,ct,com);       
    }
    grid[i][j]=0;
    return ans;
}
int uniquePathsIII(vector<vector<int>>& grid) {
    int r= grid.size();
    int c= grid[0].size();
    // vector<vector<int>> vis(r,vector<int>(c,0));
    int ct_zeros= 0;
    int sx,sy;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                sx= i;sy=j;
            }
            if(grid[i][j]==0){
                ct_zeros++;
            }
        }
    }
    // z(ct_zeros);z(sx);cout<<(sy)<<endl;
    return dfs(grid, sx, sy,r,c,0,ct_zeros);
    
}
int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    // int t;cin>>t;
    int r,c;
    cin>>r>>c;
    // cout<<r<<" "<<c<<endl;
    vector<vector<int>> v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     nl;
    // }
    cout<<(uniquePathsIII(v));
    nl;
    return 0;
}





