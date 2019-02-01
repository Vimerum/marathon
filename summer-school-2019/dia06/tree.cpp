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
const int T = 10e6 + 15;

int n;

int color[T];
int ans[T];
int vis[T];
vector<int> adj[T];
set<int> colors[T];

void dfs (int v) {
	if (vis[v]) return;
	colors[v].insert(color[v]);
	vis[v] = 1;
	for (int w : adj[v]) {
		dfs(w);
		if (colors[w].size() > colors[v].size())
			swap(colors[v],colors[w]);
		for (int c : colors[w])
			colors[v].insert(c);
	}
	ans[v] = colors[v].size();
}

bool comp (ii a, ii b) {
	if (a.fi != b.fi)
		return a.fi < b.fi;
	return a.sec < b.sec;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	cin >> n;
	vector<ii> v;
	int root = -1;
	fori(i,1,n+1) {
		int p, c; cin >> p >> c;
		adj[p].pb(i);
		color[i] = c;
		if (p == 0) root = i;
	}

	dfs(root);

	fori(i,1,n+1) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
    return 0;
}

