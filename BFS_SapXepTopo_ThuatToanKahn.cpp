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
int n, m; 
vector<int> adj[1005];
int in[1005];
vector<int> topo;
void Kahn()
{
    queue<int> qe;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0)
        {
            qe.push(i);
        }
    }
    while(!qe.empty())
    {
        int v = qe.front();
        qe.pop();
        topo.push_back(v);
        for(int x : adj[v])
        {
            in[x]--;
            if(in[x] == 0)
            {
                qe.push(x);
            }
        }
    }
    for(auto x : topo)
    {
        cout << x << " ";
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
    for(int i = 0; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    Kahn();
    return 0;
}     
//input
// 7 7 
// 1 2
// 2 3
// 2 4
// 3 5
// 4 5
// 1 6
// 7 6    
// Output:
// 1 7 2 6 3 4 5                       