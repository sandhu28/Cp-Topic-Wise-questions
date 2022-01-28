#include <iostream>
#include <bits/stdc++.h>
#define ppi pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define vvi vector<vector<int>>
#define vppi vector<pair<int, int>>
#define rep(i, k, n) for (i = k; i < n; ++i)
#define Repr(i, k, n) for (i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n << " "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

// bool cm(ppi a, ppi b){
//     if(a.second!= b.second){
//         return a.second> b.second;
//     }
//     return a.first> b.first;
// }
vector<int> TopK(vector<int> &v, int k)
{
    int n= v.size();
    vi ans;
    auto cm=[](ppi a, ppi b){
    if(a.second!= b.second){
        return a.second< b.second;
    }
    return a.first< b.first;
    };
    priority_queue<ppi,vector<ppi>,decltype(cm)> pq(cm);
    // map<int,int,cm> m;
    vector<int> freq(1e5+2,0);
    for(int i=0;i<n;i++){
        // c(v[i]);
        freq[v[i]]++;
    }
    for(int j=1;j<1e5+2;j++){
        if(freq[j]>0){
            // c("yes");
            pq.push({j,freq[j]});
        }
    }
    while(k-- && !pq.empty()){
        ans.push_back(pq.top().first);
        // c(pq.top().second);
        pq.pop();
    }
    return ans;
}
int main()
{

    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    auto ans=TopK(v,2);
    for(auto it: ans){
        z(it);
    }
    return 0;
}