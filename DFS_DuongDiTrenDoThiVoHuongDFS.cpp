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
vector<int> adj[1005];
bool visited[1005];
int father[1005] = {0};
void DFS(int u)
{
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            father[v] = u;
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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    DFS(s);
    if(!visited[t])
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> res;
        while(t!=s)
        {
            res.push_back(t);
            t = father[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for(auto x : res)
        {
            cout << x << " ";
        }
    }
    return 0;
}                      