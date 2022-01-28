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

bool is_valid(int mid, vector<int> w, int d,int n){
    int my_days=1;
    int temp= mid;
    int test=0;
    for(int i=0;i<n;i++){
        
        if(w[i]>mid){
            // if(temp!=mid){
            //     my_days+=1;
            // }
            // int k= (w[i]/mid);
            // int p = k * mid;
            // my_days+= (w[i]/mid);
            // temp = mid- (w[i]- p);
            return false;
        }
        else{
            // added a comment 
            if(w[i]>temp){
                my_days+=1;
                temp= mid - w[i];
            }
            else{
                temp-= w[i];
            }
        }
    }
    // c(my_days);
    return my_days<= d;
}

int shipWithinDays(vector<int>& w, int d) {
    int n= w.size();
    int l= 1;
    int h= 1e7+2;
    int ans=0;
    while(l<=h){
        int mid = l + (h-l)/2;
        // z(mid);z(l);z(h);
        if(is_valid(mid,w,d,n)){
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
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        int i;
        rep(i,0,n){
            cin>>arr[i];
        }   
    }
    // cout<<"sukhman"<<endl;
    return 0;
}

