//                     @constant@
// ********   **      **    **   **      **   **      **
// **         **      **    **   ** *    **   **      **
// **         **********    **   **  *   **   **********
// **         **      **    **   **    * **   **      **
// ********   **      **    **   **      **   **      **
//                     _cinte_
//                ドアン　ズイ　チン               
//#include<bits/stdc++.h>
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
        int n;
        cin >> n;
        int a[n+1];
        ll sum[n+1];
        fill(sum, sum+n+1, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sum[0] = a[0];
        sum[1] = max(a[0], a[1]);
        for(int i = 2; i < n; i++)
        {
            sum[i] = max(sum[i-1], sum[i-2]+a[i]);
        }
        cout << sum[n-1] << endl;
    }
    return 0;
}                      
