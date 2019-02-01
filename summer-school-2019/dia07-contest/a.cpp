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
vector<int> lan[T];
int pai[T];
int peso[T];
int n, m;

void init() {
	for(int i = 0; i < T; i++) pai[i] = i;
}

int find(int x) {
	return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(peso[x] < peso[y]) swap(x,y);
	pai[y] = x;
	if(peso[y] == peso[x]) peso[x]++;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin >> n >> m;
	init();
	int k, l;
	for(int i = 0; i < n; i++) {
		cin >> k;
		if(k == 0) lan[k].pb(i);
		for(int j = 0; j < k; j++) {
			cin >> l;
			lan[l].pb(i);
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j < (lan[i].size()); j++) {
			join(lan[i][j], lan[i][j-1]);
		}
	}
	set<int> ans;
	for(int i = 0; i < n; i++) {
		ans.insert(find(i));
	}
	if(lan[0].size() == n) cout << ans.size() << endl;
	else cout << ans.size() - 1 << endl;


    return 0;
}

