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
const int maxn = 1005;
vector<pair<int, int>> adj[maxn];
int n, m, s;
const int inf = 1e9;
void dijkstra(int s)
{
    vector<ll> d(n+1, inf);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
    //khoang cach, dinh
    Q.push({0, s});
    while(!Q.empty())
    {
        //Chon ra dinh co khoang cach tu s nho nhat
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int dis = top.first;
        if(dis > d[u])
        {
            continue;
        }
        //cap nhat khoang cach tu s den moi dinh ke voi u
        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
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
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dijkstra(s);
    return 0;
}                      