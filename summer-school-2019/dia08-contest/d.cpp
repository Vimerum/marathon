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
const int T = 110;
const int N = 1e5;
int gol, ori;
int n;
int g[T][T];
ll dp[N][T];
vector<ii> entregas;

void floyd() {
	for(int i = 1; i <= n; i++) g[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

ll solve(int cidade, int mask) {
	if(mask == gol) return g[cidade][ori];

	ll ans = INF;
	ll &r = dp[mask][cidade];
	if(r != -1) return r;

	for(int i = 0; i < entregas.size(); i++) 
		if( (mask & (1<<i)) == 0)
			ans = min(ans, solve(entregas[i].sec, mask | (1 << i)) + g[cidade][entregas[i].fi] + g[entregas[i].fi][entregas[i].sec]);
	
	return r = ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	int m, u, v, d, z;
	while(tc--) {
		cin >> n >> m >> ori;
		memset(g, INF, sizeof g);
		entregas.clear();
		for(int i = 0; i < m; i++) {
			cin >> u >> v >> d;
			g[u][v] = min(g[u][v], d);
			g[v][u] = min(g[v][u], d);
		}
		floyd();
		cin >> z;
		int viagens = 0;
		for(int i = 0; i < z; i++) {
			cin >> u >> v >> d;
			viagens += d;
			while(d--) {
				entregas.pb({u,v});
			}
		}
		gol = pow(2,viagens) - 1;
		memset(dp, -1, sizeof dp);
		cout << solve(ori, 0) << endl;
	}
    return 0;
}

