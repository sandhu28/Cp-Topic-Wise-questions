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

int paths(int m,int n,vvi & v,vvi& dp){
    // c("yes");z(m);c(n);
    if(m<0 || n<0 || v[m][n]==1){return 0;}
    if(dp[m][n]!=-1){return dp[m][n];}
    return dp[m][n]=paths(m-1,n,v,dp) + paths(m,n-1,v,dp);
}

int uniquePathsWithObstacles(vector<vector<int>>& v) {
    int m= v.size();int n= v[0].size();
    vvi dp(m,vi(n,-1));
    if(v[0][0]==1){return 0;}
    dp[0][0]= 1;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         z(dp[i][j]);
    //     }
    //     nl;
    // }
    return paths(m-1,n-1,v,dp);
}
// int table(int m,int n){
//     vvi dp(m+1,vi(n+1,1));
//     for(int i=2;i<=m;i++){
//         for(int j=2;j<=n;j++){
//             dp[i][j]= dp[i-1][j] + dp[i][j-1];
//         }
//     }
//     return dp[m][n];
// }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n;cin>>m>>n;
    vvi v(m,vi(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    c(uniquePathsWithObstacles(v));
    return 0;
}