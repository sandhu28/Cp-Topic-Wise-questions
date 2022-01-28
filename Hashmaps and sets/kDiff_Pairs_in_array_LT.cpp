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

int func(vi& v,int k){
    int n=v.size();
    unordered_map<int,int> um;
    map<ppi,int> check;
  
    // if(k==0){
    //     return n;
    // }

    // sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(k!=0 && um.find(v[i])==um.end()){
            um.insert({v[i],i});
        }
        else{
            um.insert({v[i],i});
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int to_find1= v[i] + k;
        int to_find2= v[i]- k;
        if(um.find(to_find1)!= um.end() && um[to_find1]!=i){
            ppi pr={v[i],to_find1};
            bool t=1;
            if(check.find(pr)!=check.end()){
                t=0;
            }
            else{
                check.insert({pr,i});
                check.insert({{to_find1,v[i]},i});
                ans++;
            }
        }
        if(um.find(to_find2)!= um.end() && um[to_find2]!=i){
            ppi pr={v[i],to_find2};
            bool t=1;
            if(check.find(pr)!=check.end()){
                t=0;
            }
            else{
                check.insert({pr,i});
                check.insert({{to_find2,v[i]},i});
                ans++;
            }
        }
    }

    return ans;
}
int main(){
    int n;cin>>n;
    vi v(n);
    int i;
    rep(i,0,n){
        cin>>v[i];
    }
    int k;cin>>k;
    int ans=func(v,k);
    c(ans);
    return 0;
}