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
int color[1005];

bool DFS(int u)
{
    color[u] = 1;
    for(int v : adj[u])
    {
        if(color[v] == 0)
        {
            color[v] = 1;
            if(DFS(v))
            {
                return true;
            }
        }
        else if(color[v] == 1)
        {
            return true;
        }
    }
    color[u] = 2;
    return false;
}

int main()
{
    faster();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m, ok = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= n; i++)
    {
        if(color[i] == 0)
        {
            if(DFS(i))
            {
                ok = 1;
                break;
            }
        }
    }
    cout << ok << endl;
    return 0;
}                      