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

bool isPalindrome(string &s){
    int i=0;int j= s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){return 0;}
        i++;j--;
    }
    return 1;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    int n= words.size();
    int i;
    unordered_map<string,int> um;
    rep(i,0,n){
        um.insert({words[i],i});
    }
    if(um.find("")!=um.end()){
        int idx= um[""];
        rep(i,0,n){
            if(i!= idx && isPalindrome(words[i])){
                vi v1,v2;
                v1= {i,idx};v2= {idx,i};
                ans.push_back(v1);ans.push_back(v2);
            }
        }
    }

    rep(i,0,n){
        string temp= words[i];
        reverse(temp.begin(),temp.end());
        if(um.find(temp)!=um.end()){
            int idx= um[temp];
            if(idx!=i){
                vi v1;
                v1= {i,idx};
                ans.push_back(v1);
            }
        }
    }

    rep(i,0,n){
        for(int j=1;j<words[i].size();j++){
        
            if(isPalindrome(words[i].substr(0,j))){
                string temp= words[i].substr(j);
                reverse(temp.begin(),temp.end());
                if(um.find(temp)!=um.end()){
                    int idx= um[temp];
                    vi v= {idx,i};
                    ans.push_back(v);
                }
            }
            if(isPalindrome(words[i].substr(j))){
                string temp= words[i].substr(0,j);
                reverse(temp.begin(),temp.end());
                if(um.find(temp)!=um.end()){
                    int idx= um[temp];
                    vi v= {i,idx};
                    ans.push_back(v);
                }
            }
        }
    }
    return ans;
}

int main(){
    
    return 0;
}