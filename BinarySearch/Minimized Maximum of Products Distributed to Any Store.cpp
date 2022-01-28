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

bool is_valid(int mid, vector<int> q,int n,int num){
    for(int i=0;i<n;i++){
        if(q[i]>mid){
            num-= (q[i]/mid);
            if(q[i]%mid!=0){
                num-=1;
            }
        }
        else{
            num-= 1;
        }
    }
    return num>=0;
}

int minimizedMaximum(int num, vector<int>& q) {
    int n= q.size();
    int l=1;int h= 1e5+10;
    int ans=0;
    while(l<=h){
        int mid = l + (h-l)/2;
        // z(mid);z(l);z(h);
        if(is_valid(mid,q,n,num)){
            ans= mid;
            h= mid-1;
        }
        else{
            l= mid+1;
        }
    }
    return ans;
}


int main(){
    
    return 0;
}