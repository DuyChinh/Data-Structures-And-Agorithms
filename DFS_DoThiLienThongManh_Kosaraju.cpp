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
vector<int> adj1[1005];
vector<int> adj2[1005];
vector<int> topo;

void DFS(int u)
{
    visited[u] = true;
    for(int v : adj1[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            DFS(v);
        }
    }
    topo.push_back(u);
}

void Kosaraju(int u)
{
    visited[u] = true;
    for(int v : adj2[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            Kosaraju(v);
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
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        int cnt = 0;
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj1[x].push_back(y);
            adj2[y].push_back(x);
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
        memset(visited, false, sizeof(visited));
        for(int v : topo)
        {
            if(!visited[v])
            {
                Kosaraju(v);
                cnt++;
            }
        }
        if(cnt == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO"<< endl;
        }
        for(int i = 1; i <= n; i++)
        {
            adj1[i].clear();
            adj2[i].clear();
        }
        topo.clear();
    }
    return 0;
}    
//B1: Tao vector luu cac dinh do thi theo Topo
//B2: Chuyen huong do thi
//B3: Dem so thanh phan lien thong manh                