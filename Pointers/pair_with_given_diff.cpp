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

int diff(vi& v,int d){
    unordered_map<int,int> um;
    set<ppi> s;
    // vi ans;
    int n=v.size();
    if(d==0){
        return n;
    }

    // sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(um.find(v[i])==um.end()){
            um.insert({v[i],i});
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int to_find1= v[i] + d;
        int to_find2= v[i]- d;
        if(um.find(to_find1)!= um.end() ){
            if(s.find({v[i],to_find1})== s.end() && s.find({to_find1,v[i]})== s.end()){
                ans++;
            }
        }
        if(um.find(to_find2)!= um.end() ){
            ans++;
        }
    }

    return ans;
}
int main(){
    
    return 0;
}