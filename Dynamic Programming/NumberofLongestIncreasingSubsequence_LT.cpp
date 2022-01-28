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

int lis(vector<int> &v){
    int n=v.size();
    int dp[n];
    map<int,int> um;
    dp[0]=1;
    int ans=1;int mxlen=1;
    for(int i=1;i<n;i++){
        int curr_mx=0;int ct=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                if(dp[j]==curr_mx){
                    ct+= um[j];
                }
                else if(dp[j]>curr_mx){
                    curr_mx= dp[j];
                    ct=1;
                }
                else{
                    continue;
                }
            }
        }
        dp[i]= curr_mx + 1;
        um.insert({i,ct});
        if(dp[i]==mxlen ){
            ans+= ct;
        }
        else if(dp[i]>mxlen){
            ans= ct;
        }
        else{continue;}
    }
    return ans;
}
int main(){
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    c(lis(v));
    return 0;
}