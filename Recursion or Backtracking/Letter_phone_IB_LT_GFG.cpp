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

vector<string> func(vector<string> &s,string &dig,int i){
    vector<string> curr;
    if(i<0){curr.push_back("");return curr;}

    vector<string> get= func(s,dig,i-1);
    int k= dig[i]- '0';
    for(int p=0;p<get.size();p++){
        for(int j=0;j<s[k].size();j++){
            curr.push_back((get[p]+ s[k][j]));
        }
    }
    return curr;
}

vector<string> letterCombinations(string digits) {
    vector<string> s={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> v;
    if(digits.size()==0){return v;}
    return func(s,digits,digits.size()-1);
}
int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    string s;cin>>s;
    auto ans= letterCombinations(s);
    for(auto & e: ans){
        c(e);
    }
    return 0;
}