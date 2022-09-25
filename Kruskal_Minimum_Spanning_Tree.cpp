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
int parent[1005];
int sz[1005];
int n, m;
struct side
{
    int u, v;
    int val;
};
vector<side> edge;
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
    sz[a] += sz[b];
    parent[b] = a;
    return true;
}

bool cmp(side a, side b)
{
    return a.val < b.val;
}

void Kruskal()
{
    vector<side> res;
    sort(edge.begin(), edge.end(), cmp);
    int minVal = 0;
    for(int i = 0; i < m; i++)
    {
        if(res.size() == n - 1)
        {
            break;
        }
        side e = edge[i];
        if(Union(e.u, e.v))
        {
            res.push_back(e);
            minVal += e.val;
        }
    }
    cout <<  minVal << endl;
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
        cin >> n >> m;
        for(int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            side e;
            e.u = x; e.v = y; e.val = z;
            edge.push_back(e);
        }
        make_set();
        Kruskal();
        edge.clear();
    }
    return 0;
}                      