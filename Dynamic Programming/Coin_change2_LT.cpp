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


/// This memoised version shows TLE on Leetcode :)
int recur(int k,vi &coins,int i,vvi & memo){
    if(k==0){return 1;}
    if(k<0 || i<0){return 0;}
    if(memo[i][k]>0){return memo[i][k];}
    int ans= 0;
    if(coins[i]<=k){
        ans+= recur(k-coins[i],coins,i,memo);
    }
    ans+= recur(k,coins,i-1,memo);
    return memo[i][k]=ans;
}

// passed on Leetcode
int table(int k,vi &coins){
    int n= coins.size();
    vvi dp(n,vi(k+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){dp[i][j]=1;continue;}
            if(coins[i]<=j){
                dp[i][j]+= dp[i][j- coins[i]];
            }
            if(i-1>=0){
                dp[i][j]+= dp[i-1][j];
            }
        }
    }
    return dp[n-1][k];
}

int change(int amount, vector<int>& coins) {
    // vvi memo(coins.size(),vi(amount + 1,0));
    return table(amount,coins);
}

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vi v(n);
    int i;
    rep(i,0,n){
        cin>>v[i];
    }
    int k;cin>>k;
    c(change(k,v));
    return 0;
}