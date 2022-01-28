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


int count(int n){
    vector<int> vis(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            int k= (n/2)+i;
            int p= i-(n/2);
            if(j!=k && vis[j]==0 && j!=p){
                ans++;
            }
        }
        vis[i]=1;
    }
    return ans;
}

int main(){
    
    return 0;
}