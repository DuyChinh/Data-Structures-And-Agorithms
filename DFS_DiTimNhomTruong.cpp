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
int leader;
void DFS(int u)
{
    visited[u] = true;
    if(adj[leader].size() < adj[u].size())
    {
        leader = u;
    }
    else if(adj[leader].size() == adj[u].size())
    {
        if(leader > u)
        {
            leader = u;
        }
    }
    sort(adj[u].begin(), adj[u].end());
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
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            leader = i;
            DFS(i);
            cout << leader << " ";
        }
    }
    return 0;
}    
//Thanh phan lien thong                  