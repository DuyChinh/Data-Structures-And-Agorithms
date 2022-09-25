//                      @constant@
// ********   **      **    **   **      **   **      **
// **         **      **    **   ** *    **   **      **
// **         **********    **   **  *   **   **********
// **         **      **    **   **    * **   **      **
// ********   **      **    **   **      **   **      **
//                       _cinte_
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
// void DFS(int u, int goal)
// {
//     visited[u] = true;
//     cout << u << endl;
//     ++cnt;
//     //sort(adj[u].begin(), adj[u].end());
//     for(int v : adj[u])
//     {
//         if(v == goal)
//         {
//             break;
//             return;
//         }
//         if(!visited[v])
//         {
//             DFS(v, goal);
//         }
//     }
// }
int res[1005] = {0};
void BFS(int u)
{
    visited[u] = true;
    queue<int> qe;
    qe.push(u);
    res[u] = 0;
    while(!qe.empty())
    {
        int st = qe.front();
        qe.pop();
        for(int v : adj[st])
        {
            if(!visited[v])
            {
                qe.push(v);
                visited[v] = true;
                res[v] = res[st] + 1;
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
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    // for(int i = 1; i <= n; i++)
    // {
    //     memset(visited, false, sizeof(visited));
    //     cnt = 0;
    //     DFS(1, i);
    //     cout << cnt << " ";
    // }
    //DFS(1, 3);
    //cout << cnt << " ";
    BFS(1);
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}                      