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
int father[1005];

void DFS(int u)
{
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            DFS(v);
            father[v] = u;
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
    vector<int> a;
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    memset(visited, false, sizeof(visited));
    memset(father, false, sizeof(father));
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(s);
    if(!visited[e])
    {
        cout << -1;
    }
    else
    {
        while(e != s)
        {
            a.push_back(e);
            e = father[e];
        }
        a.push_back(s);
        reverse(a.begin(), a.end());
        for(auto x : a)
        {
            cout << x << " ";
        }
    }
    return 0;
}                      