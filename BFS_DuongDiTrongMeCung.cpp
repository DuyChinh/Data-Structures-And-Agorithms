//                     @constant@
// ********   **      **    **   **      **   **      **
// **         **      **    **   ** *    **   **      **
// **         **********    **   **  *   **   **********
// **         **      **    **   **    * **   **      **
// ********   **      **    **   **      **   **      **
//                     _cinte_
//                ドアン　ズイ　チン               
#include<bits/stdc++.h>
#include<set>
#include<map>
#include <cmath>
#include <cstdio>
#include <vector>
#include<cstring>
#include <iostream>
#include <algorithm>
#define faster() ios_base :: sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define endl '\n'
typedef long long ll;
const long long int MOD = 1e9+7;
int n, m, x1, x2, k1, y2;
int a[1001][1001];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int cnt[1001][1001] = {0};

void BFS(int i, int j)
{
    queue<pair<int, int>> qe;
    qe.push({i, j});
    a[i][j] = 0;
    while(!qe.empty())
    {
        pair<int, int> st = qe.front();
        qe.pop();
        for(int k = 0; k < 8; k++)
        {
            int u = st.first + dx[k];
            int v = st.second + dy[k];
            if(u >= 1 && u <= n && v >= 1 && v <= n && a[u][v] == 1)
            {
                cnt[u][v] = cnt[st.first][st.second]+1;
                if(u == x2 && v == y2)
                {
                    return;
                }
                qe.push({u, v});
                a[u][v] = 0;
            }
        }
    }
}

int main()
{
    faster();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin >> n;
    cin >> x1 >> k1 >> x2 >> y2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    BFS(x1, k1);
    cout << cnt[x2][y2] << endl;
    return 0;
}                      