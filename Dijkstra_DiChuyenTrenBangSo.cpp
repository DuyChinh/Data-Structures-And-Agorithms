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
const int inf = 1e9;
int n, m;
vector<pair<int, int>> adj[1005];
int parent[1005];
void Dijkstra(int s, int t)
{
    vector<ll> d(n+1, inf);
    //d[u] = inf
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qe;
    qe.push({0, s});
    //{dis, peak}
    while(!qe.empty())
    {
        pair<int, int> st = qe.top();
        qe.pop();
        int dis = st.first;
        int u = st.second;
        if(dis > d[u])
        {
            continue;
        }
        for(auto it : adj[u])
        {
            int v = it.first;
            int val = it.second;
            if(d[v] > d[u] + val)
            {
                d[v] = d[u] + val;
                qe.push({d[v], v});
                //parent[v] = u;
            }
        }
    }
    //vector<int> res;
    // int cnt = 0;
    // cnt+=d[s];
    // while(t != s)
    // {
    //     cnt+=d[t];
    //     //res.push_back(t);
    //     t = parent[t];
    // }
    // cout << d[t] << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}

int main()
{
    faster();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back({j, x});
            adj[j].push_back({i, x});
        }
    }
    Dijkstra(1, n);
    return 0;
}                      