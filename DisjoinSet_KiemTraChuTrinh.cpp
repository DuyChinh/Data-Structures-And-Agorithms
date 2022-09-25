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
struct side
{
    int u, v;
};
vector<side> edge;
int parent[1005];
int sz[1005];
int n, m;
void make_set()
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
    {
        return false;
    }
    if(sz[a] < sz[b])
    {
        swap(a, b);
    }
    sz[a]+=sz[b];
    parent[b] = a;
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
        side e;
        e.u = x; e.v = y;
        edge.push_back(e);
    }
    make_set();
    int ok = 0;
    for(int i = 0; i < m; i++)
    {
        side e = edge[i];
        if(!Union(e.u, e.v))
        {
            ok = 1;
            break;
        }
    }
    cout << ok << endl;
    return 0;
}                      