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
const int T = 1e5 + 15;

struct Union {
	int pai[T + 1];
	int tam[T + 1];

	Union () {
		fori(i,1,T) {
			pai[i] = i;
			tam[i] = 1;
		}
	}

	int find (int x) {
		if (pai[x] == x)
			return x;
		return find(pai[x]);
	}
	
	void merge (int u, int v) {
		int a = find(u);
		int b = find(v);
		if (a == b) return;
		if (tam[a] > tam[b]) swap(a,b);
		pai[a] = b;
		tam[b] += tam[a];
	}
};
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	while (t--) {
		Union above = Union();
		Union same  = Union();
		Union under = Union();

		int n, k; cin >> n >> k;
		int ans = 0;
		while (k--) {
			int op, x, y;
			cin >> op >> x >> y;

			if (x > n || y > n) {
				ans++;
			}
			else if (op == 1) {
				if (above.find(x) == same.find(y) || above.find(y) == same.find(x)) {
					ans++;
				} else if (under.find(x) == same.find(y) || under.find(y) == same.find(x)) { 
					ans++;
				} else if (under.find(x) == above.find(y) || under.find(y) == above.find(x)) {
					ans++;
				} else {
					above.merge(x,y);
					same.merge(x,y);
					under.merge(x,y);
				}
			}
			else {
				if (above.find(x) == under.find(y)) { 
					ans++;
				} else if (under.find(x) == above.find(y) || under.find(y) == above.find(x)) {
					ans++;
				} else {
					above.merge(y,same.find(x));
					under.merge(x,same.find(y));
				}
			}
		}

		cout << ans << endl;
	}
	
    return 0;
}

