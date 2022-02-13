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
    vvi v(5,vi(5));
    int i,j;
    int p=0;int q=0;
    rep(i,0,5){
        rep(j,0,5){
            cin>>v[i][j];
            if(v[i][j]==1){
                p= i;q=j;
            }
        }
    }
    int ans= abs(q-2) + abs(p-2);
    c(ans);
    
    return 0;
}