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

// int dp[n][m][m];
// int recur(int i, int j1, int j2, vector<vector<int>> &v, int n, int m, vector<vector<vector<int>>> &memo)
// {
//     if (i < 0 || j1 < 0 || j2 < 0 || i >= n || j1 >= m || j2 >= m)
//     {
//         return 0;
//     }
//     if (i == n - 1)
//     {
//         if (j1 == j2)
//         {
//             return v[i][j1];
//         }
//         else
//         {
//             return v[i][j1] + v[i][j2];
//         }
//     }
//     if (memo[i][j1][j2] != -1)
//     {
//         memo[i][j1][j2];
//     }
//     int ans = INT_MIN;
//     for (int p = -1; p <= 1; p++)
//     {
//         for (int q = -1; q <= 1; q++)
//         {
//             if (j1 == j2)
//             {
//                 ans = max(ans, v[i][j1] + recur(i + 1, j1 + p, j2 + q, v, n, m));
//             }
//             else
//             {
//                 ans = max(ans, v[i][j1] + v[i][j2] + recur(i + 1, j1 + p, j2 + q, v, n, m));
//             }
//         }
//     }
//     return memo[i][j1][j2] = ans;
// }

int table(vector<vector<int>> &v, int n, int m)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m ; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = v[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = v[n - 1][j1] + v[n - 1][j2];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m ; j1++)
        {
            for (int j2 = 0; j2 < m ; j2++)
            {
                int ans=-1e8;
                for (int p = -1; p <= 1; p++)
                {
                    for (int q = -1; q <= 1; q++)
                    {
                        if(j1+p<0 || j2+q<0 || j1+p>=m || j2+q>=m){
                            // dp[i][j1][j2]= ans;
                            continue;
                        }
                        if (j1 == j2)
                        {
                            ans = max(ans, v[i][j1] + dp[i + 1] [j1 + p] [j2 + q]);
                        }
                        else
                        {
                            ans = max(ans, v[i][j1] + v[i][j2] + dp[i + 1] [j1 + p] [j2 + q]);
                        }
                    }
                }
                dp[i][j1][j2]= ans;
            }
        }
    }
    return dp[0][0][m-1];
}

int main()
{

    return 0;
}