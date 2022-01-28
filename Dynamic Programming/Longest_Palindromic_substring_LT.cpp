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

string lpsub(string s){
    int n= s.size();
    string ans="";
    bool dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    int mxlen=0;
    int p=0;int q=0;
    for(int g=0;g<n;g++){
        int i=0;
        for(int j=g;j<n;j++){
            if(g==0){
                dp[i][j]=1;
                mxlen= max(1,mxlen);
                p=i;q=j;
            }
            else if(g==1){
                if(s[i]==s[j]){
                    dp[i][j]=1;
                    mxlen= max(mxlen,2);
                    p=i;q=j;
                }
            }
            else{
                if(s[i]==s[j]){
                    if(dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        mxlen= max(mxlen, j-i+1);
                        p=i;q=j;
                    }
                }
            }
            i++;
        }
    }
    for(int k=p;k<=q;k++){
        ans+= s[k];
    }
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    c(lpsub(s));

    return 0;
}