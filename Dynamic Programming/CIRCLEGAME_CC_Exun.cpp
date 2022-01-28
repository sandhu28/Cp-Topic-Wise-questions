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
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        int m,x;
        cin>>m>>x;
        vi v(x+1,0);
        for(int n=1;n<=x;n++){
            if(n==1){
                v[1]=1;
                c(v[1]);continue;
            }
            int first= (m%n==0)?n: (m%n);
            if(v[n-1]>= first){
                v[n]= v[n-1]+1;
            }
            else{
                v[n]=v[n-1];
            }
            c(v[n]);
        }
    }
    return 0;
}