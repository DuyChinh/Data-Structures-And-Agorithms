//                     @constant@
// ********   **      **    **   **      **   **      **
// **         **      **    **   ** *    **   **      **
// **         **********    **   **  *   **   **********
// **         **      **    **   **    * **   **      **
// ********   **      **    **   **      **   **      **
//                     _cinte_
#include<bits/stdc++.h>
#define faster() ios_base :: sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define endl '\n'
typedef long long ll;
const long long int MOD = 1e9+7;
int main()
{
    faster();
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length(), m = s2.length();
	int cnt[n+1][m+1];
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				cnt[i][j] = cnt[i-1][j-1]+1;
			}
			else
			{
				cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1])
			}
		}
	}
	cout << cnt[i][j] << endl;
    return 0;
}

