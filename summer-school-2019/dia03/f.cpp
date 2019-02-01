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

struct team {
	int k, da, db;

	team (int k, int da, int db) {
		this->k = k;
		this->da = da;
		this->db = db;
	}
};

bool comp (team a, team b) {
	return (abs(a.da - a.db) > abs(b.da - b.db));
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int n, a, b;

	while (cin >> n >> a >> b) {
		if ((n + a + b) == 0) break;

		vector<team> v;

		fori(i,0,n) {
			int k, da, db; cin >> k >> da >> db;
			v.pb(team(k,da,db));
		}

		sort(v.begin(), v.end(), comp);

		int ans = 0;
		fori(i,0,n) {
			while(v[i].k) {
				if ((v[i].da < v[i].db and a > 0) or (b == 0)) {
					int ballons = min(a, v[i].k);
					a -= ballons;
					v[i].k -= ballons;
					ans += v[i].da * ballons;
				} else {
					int ballons = min(b, v[i].k);
					b -= ballons;
					v[i].k -= ballons;
					ans += v[i].db * ballons;
				}
			}
		}

		cout << ans << endl;
	}
	
    return 0;
}

