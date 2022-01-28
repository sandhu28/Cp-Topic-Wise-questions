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

int func(vi v){
    v.insert(begin(v),INT_MAX);
    v.push_back(INT_MAX);
    int n= v.size();
    int mn= INT_MAX;
    int l=1;int h=n-2;
    // z(l);c(h);
    while(l<=h){
        int mid= l + (h-l)/2;
        // c(mid);
        if(v[mid]<v[mid-1] && v[mid]<v[mid+1]){
            // c(mid);
            // mn= v[mid];
            mn= mid-1;
            break;
        }
        if(v[mid]>v[n-2]){
            l= mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return mn;
}
    int bs(vi& v,int l,int h,int t){
        while(l<=h){
            int mid= l + (h-l)/2;
            if(v[mid]==t){
                return mid;
            }
            if(v[mid]<t){
                l= mid+1;
            }
            else{
                h= mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int idx= func(nums);
        // c(idx);
        int a1= bs(nums,0,idx-1,target);
        int a2= bs(nums,idx,nums.size()-1,target);
        // c(a1);c(a2);
        if(a1==-1 && a2==-1){return -1;}
        if(a1==-1){
            return a2;
        }
        return a1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;cin>>target;
    c(search(v,target));
    return 0;
}
