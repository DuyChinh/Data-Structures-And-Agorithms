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
int in[1005];
int n, m;
bool Kahn()
{
    queue<int> qe;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        {
            qe.push(i);
        }
    }
    int cnt = 0;
    while (!qe.empty())
    {
        int u = qe.front();
        qe.pop();
        cnt++;
        for(int v : adj[u])
        {
            in[v]--;
            if(in[v] == 0)
            {
                qe.push(v);
            }
        }
    }
    if(cnt == n)
    {
        return false;
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
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    if(Kahn())
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}                      