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

int table(vvi &v){
    int r= v.size();
    vvi dp(r,vi(r,INT_MAX));
    dp[0][0]= v[0][0];
    for(int i=1;i<r;i++){
        for(int j=0;j<i+1;j++){
            int mn= INT_MAX;
            if(j-1>=0){
                mn= dp[i-1][j-1];
            }
            mn= min(mn,dp[i-1][j]);
            dp[i][j]= v[i][j] + mn;
        }
    }
    int ans=INT_MAX;
    for(int j=0;j<r;j++){
        ans= min(ans,dp[r-1][j]);
    }
    // for(int i=1;i<r;i++){
    //     for(int j=0;j<i+1;j++){
    //         z(dp[i][j]);
    //     }
    //     nl;
    // }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vvi v;
    for(int i=0;i<n;i++){
        vi vec;
        for(int j=0;j<i+1;j++){
            int x;cin>>x;
            vec.push_back(x);
        }
        v.push_back(vec);
    }
    // for(int i=0;i<n;i++){
    //     // vi vec;
    //     for(int j=0;j<i+1;j++){
    //         z(v[i][j]);
    //     }
    //     // v.push_back(vec);/
    //     nl;
    // }
    c(table(v));
    return 0;
}