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
bool DFS(int u)
{
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            father[v] = u;
            if(DFS(v))
            {
                return true;
            }
        }
        else if(v!=father[u])
        {
            return true;
        }
    }
    return false;
}

bool BFS(int u)
{
    queue<int> qe;
    qe.push(u);
    visited[u] = true;
    while(!qe.empty())
    {
        int v = qe.front();
        qe.pop();
        for(int k : adj[v])
        {
            if(!visited[k])
            {
                father[k] = v;
                qe.push(k);
                visited[k] = true;
            }
            else if(v != father[k])
            {
                return true;
            }
        }
    }
    return false;
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
        int ok = 0;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(visited, false, sizeof(visited));
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                if(DFS(i))
                {
                    ok = 1;
                    break;
                }
            }
        }
        if(ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            father[i] = 0;
        }
    }
    return 0;
}                      