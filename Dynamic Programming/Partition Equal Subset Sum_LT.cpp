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
#define z(n) cout << n <<

#define nl cout << endl;
#define INF INT_MAX
using namespace std;

bool exists(vector<int> &v, int k)
{

    vector<vector<int>> dp(v.size() + 1, vector<int>(k + 1, -1));
    for (int i = 0; i <= v.size(); i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                bool not_take = dp[i - 1][j];
                bool take = 0;
                if (v[i - 1] <= j)
                {
                    take = dp[i - 1][j - v[i - 1]];
                }
                dp[i][j] = take | not_take;
            }
        }
    }
    return dp[v.size()][k];
}

bool canPartition(vector<int> &v)
{
    int sm = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sm += v[i];
    }
    if (sm & 1)
    {
        return 0;
    }
    int half = sm / 2;

    return exists(v, half);
}

int main()
{

    return 0;
}