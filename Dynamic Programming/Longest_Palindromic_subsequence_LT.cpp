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


//// Longest_common_subsequence
// 1.Recursive code
int lcs(int x, int y, string s1, string s2)
{
    if(x==0 || y==0){
        return 0;
    }
    if(s1[x-1]==s2[y-1]){ 
        return 1 + lcs(x-1,y-1,s1,s2);
    }
    return max((lcs(x-1,y,s1,s2)),(lcs(x,y-1,s1,s2)));
}

///2. Memosization
const int N=1e3 + 10;
int lcs_memo_arr[N][N];
int lcs_memo(int x, int y, string s1, string s2)
{
    if(x==0 || y==0){
        return lcs_memo_arr[x][y]=0;
    }
    if(lcs_memo_arr[x][y]!=0){
        return lcs_memo_arr[x][y];
    }
    if(s1[x-1]==s2[y-1]){ 
        return lcs_memo_arr[x][y]=1 + lcs_memo(x-1,y-1,s1,s2);
    }
    return lcs_memo_arr[x][y]=max((lcs_memo(x-1,y,s1,s2)),(lcs_memo(x,y-1,s1,s2)));
}

/// 3. Dp top_down
int lcs_dp(int x, int y, string s1, string s2){
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}

int main(){
    
    return 0;
}