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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;cin>>n;
    int sx=0;int sy=0;int sz=0;
    while(n--){
        int x,y,z;
        cin>>x>>y>>z;
        sx+=x;sy+=y;sz+=z;
    }
    if(sx==0 && sy==0 && sz==0){
        c("yes");

    }
    else{
        c("no");
    }
    return 0;
}