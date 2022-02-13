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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int a,b,n;
    cin>>a>>b>>n;
    bool t=0;
    for(int i=0;i<=9;i++){
        int k= a*10 + i;
        if(k%b==0){
            a= k;
            n--;
            t=1;
            break;
        }
    }
    if(t==0){
        c("-1");
        return 0;
    }
    // c(a);
    string s="";
    for(int k=6;k>=0;k--){
        // c(pow(10,k));
        int div= int(pow(10,k));
        // c((a/int(pow(10,k))));
        if((a/div)!=0){
            int d= (a/div)%10;
            s += to_string(d);
        }
    }
    // c(s);
    
    while(n--){
        s+= '0';
    }
    c(s);

    return 0;
}