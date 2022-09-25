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
bool visited[1005];
vector<int> adj[1005];

void DFS(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            DFS(v);
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
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int minn = 0;
        int res = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                ++minn;
                DFS(i);
            }
        }
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int j = 1; j <= n; j++)
        {
            memset(visited, false, sizeof(visited));
            visited[j] = true;
            cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(!visited[i])
                {
                    ++cnt;
                    DFS(i);
                }
            }
            if(cnt > minn)
            {
                cout << j << " ";
            }
        }
        cout << endl;
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}                      