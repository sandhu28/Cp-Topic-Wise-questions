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

// [0,1,0,2,1,0,1,3,2,1,2,1]

void prt(vi& vec){
    for(auto& e:vec){
        z(e);
    }
    nl;
}
int trap(vector<int>& h) {
    int n= h.size();
    vi pre(n);vi suff(n);
    pre[0]= h[0];suff[n-1]= h[n-1];
    for(int i=1;i<n;i++){
        pre[i]=max(h[i],pre[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        suff[i]= max(h[i],suff[i+1]);
    }
    // prt(pre);prt(suff);
    int ans=0;
    for(int i=1;i<n-1;i++){
        int ch= h[i];
        int prev= pre[i];int nxt= suff[i];
        if(prev>ch && ch<nxt){
            int k= min(prev,nxt);
            ans+= (k-ch);
        }
        else{
            continue;
        }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vi v(n);int i;
    rep(i,0,n){
        cin>>v[i];

    }
    c(trap(v));
    return 0;
}