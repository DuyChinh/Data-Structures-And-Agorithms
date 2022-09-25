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
int n, m, s;
bool visited[1005];
vector<string> res;
void DFS(int u)
{
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            string s = to_string(u) + "->" + to_string(v);
            res.push_back(s);
            DFS(v);
        }
    }
}

void BFS(int u)
{
    visited[u] = true;
    queue<int> qe;
    qe.push(u);
    while(!qe.empty())
    {
        int st = qe.front();
        qe.pop();
        sort(adj[st].begin(), adj[st].end());
        for(int v : adj[st])
        {
            if(!visited[v])
            {
                visited[v] = true;
                string s = to_string(st) + "->" + to_string(v);
                res.push_back(s);
                qe.push(v);
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
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    BFS(s);
    for(auto x : res)
    {
        cout << x << endl;
    }
    return 0;
}                      