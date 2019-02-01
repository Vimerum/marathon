#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 1e3 + 10;
const int M = 12;
const int MASK = pow(2,10);
int dp[M][N];

int n,m;
int dough[M];
int stuf[M];
int money[M];
int precisa_stuf[M];

int solve(int tipo, int n) {
	if(tipo > m) return 0;

	int &r = dp[tipo][n];
	if(r != -1) return r;

	int ans = solve(tipo+1, n);

	for(int i = 1; n - (i*dough[tipo]) >= 0 and precisa_stuf[tipo] - (i * stuf[tipo]) >= 0; i++) 
		ans = max(ans, solve(tipo+1, n - (i*dough[tipo])) + (i*money[tipo]));
	
	return r = ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> dough[0] >> money[0];

	for(int i = 1; i <= m; i++) 
		cin >> precisa_stuf[i] >> stuf[i] >> dough[i] >> money[i];

	memset(dp, -1, sizeof dp);

	int ans = 0;

	for(int i = 0; n - (i * dough[0]) >= 0; i++) 
		ans = max(ans, solve(1, n - (i*dough[0])) + (i*money[0]));

	cout << ans << endl;
	return 0;
}

