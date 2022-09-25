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
vector<pair<int, int>> edge;
vector<int> adj[1005];
bool visited[1005];

void DFS(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            DFS(v);
        }
    }
}

void DFS2(int u, int s, int t)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if((u == s && v == t) || (u == t && v == s))
        {
            continue;
        }
        if(!visited[v])
        {
            DFS2(v, s, t);
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
            edge.push_back({x, y});
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(visited, false, sizeof(visited));
        int res = 0, minn = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                ++minn;
                DFS(i);
            }
        }
        int cnt = 0;
        for(auto it : edge)
        {
            int s = it.first, t = it.second;
            memset(visited, false, sizeof(visited));
            cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(!visited[i])
                {
                    ++cnt;
                    DFS2(i, s, t);
                }
            }
            if(cnt > minn)
            {
                cout << s << " " << t << " ";
            }
        }
        cout << endl;
        edge.clear();
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}                      