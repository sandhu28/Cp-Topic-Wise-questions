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

int maximumSum( int n,int m, vector<vector<int>> &v) {
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end());
    }
    bool t=1;int ans= v[n-1][m-1];
    int curr= ans;
    for(int i=n-2;i>=0;i--){
        bool is_br= 0;
        for(int j=m-1;j>=0;j--){
            if(v[i][j]<curr){
                ans+= v[i][j];
                curr= v[i][j];
                is_br=1;
                break;
            }
        }
        if(is_br==0){
            t=0;break;
        }
    }
    if(t){return ans;}
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    return 0;
}