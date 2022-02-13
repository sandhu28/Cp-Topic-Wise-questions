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
    int n;
    cin >> n;
    int t;
    cin >> t;
    string s;
    cin >> s;

    while (t)
    {
        bool check = 0;
        vi idx;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'B')
            {
                if (s[i + 1] == 'G')
                {
                    idx.push_back(i);
                }
            }
        }
            for (int i = 0; i < idx.size(); i++)
            {
                swap(s[idx[i]], s[idx[i]+1]);
                check = 1;
            }

            if (check == 0)
            {
                break;
            }
            t--;
            // for(int i=0;i<n-1;i++){
            // if(t==0){
            //     break;
            // }
            // if(s[i]=='B'){
            //     if(s[i+1]=='G'){
            //         swap(s[i],s[i+1]);
            //         t--;
            //         check=1;
            //     }
            // }
            // }
            // if(check==0){
            //     break;
            // }
    }
    c(s);
    return 0;
}