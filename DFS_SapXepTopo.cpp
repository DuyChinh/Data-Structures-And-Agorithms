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
 vector<int> topo;

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
    topo.push_back(u);
}

int main()
{
    faster();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for(int v : topo)
    {
        cout << v << " ";
    }
    return 0;
}     
// Input:
// 7 7
// 1 2
// 2 3
// 2 4
// 3 5
// 4 5
// 1 6
// 7 6
// Output:
// 7 1 6 2 4 3 5     