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
char a[1005][1005];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
bool DFS(int i, int j, int cmp, int cnt)
{
    if(cnt > 2)
    {
        return false;
    }
    for(int k = 0; k < 4; k++)
    {
        int u = i + dx[k];
        int v = j + dy[k];
        if(u < 1 ||v < 1 || u > n || v > m) continue;
        if(a[u][v] == '.')
        {
            a[u][v] = '*';
            int tmp = cnt;
            if(k !=cmp && a[i][j] != 'S')
            {
                tmp++;
            }
            if(DFS(u, v, k, tmp))
            {
                return true;
            }
            a[u][v] = '.';
        }
        else if(a[u][v] == 'T')
        {
            if(k!= cmp)
            {
                cnt++;
            }
            if(cnt <= 2)
            {
                return true;
            }
        }
    }
    return false;
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
        int u, v;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'S')
                {
                    u = i;
                    v = j;
                }
            }
        }
        if(DFS(u, v, 1, 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}                      