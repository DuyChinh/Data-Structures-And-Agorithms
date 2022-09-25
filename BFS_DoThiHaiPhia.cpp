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
int color[1005];
vector<int> adj[1005];

bool BFS(int u)
{
    queue<int> qe;
    color[u] = 1;
    qe.push(u);
    while(!qe.empty())
    {
        int st = qe.front();
        qe.pop();
        for(int v : adj[st])
        {
            if(color[v] == 0)
            {
                color[v] = 3 - color[st];
                // if(color[v] == 1)
                // {
                //     color[v] = 2;
                // }
                // else if(color[v] == 2)
                // {
                //     color[v] = 1;
                // }
                qe.push(v);
            }
            else if(color[v] == color[st])
            {
                return false;
            }
        }
    }
    return true;
}

bool DFS(int u, int cmp)
{
    color[u] = 3 - color[cmp];
    for(int v : adj[u])
    {
        if(color[v] == 0)
        {
            if(!DFS(v, u))
            {
                return false;
            }
        }
        else if(color[v] == color[u])
        {
            return false;
        }
    }
    return true;
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
        adj[y].push_back(x);
    }
    memset(color, 0, sizeof(color));
    int ok = 1;
    color[0] = 2;
    for(int i = 1; i <= n; i++)
    {
        if(color[i] == 0)
        {
            if(!DFS(i, 0))
            {
                ok = 0;
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
    return 0;
}                      