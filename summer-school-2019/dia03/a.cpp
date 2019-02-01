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

ll fastexp (ll base, ll e, ll m) {
	ll ans = 1;

	while (e) {
		if (e & 1) 
			ans = (ans * base) % m;
		base = (base * base) % m;
		e >>= 1;
	}

	return ans % m;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	ll a, b, m;
	while (cin >> a >> b >> m) {
		cout << fastexp(a, b, m) << endl;
	}
	
    return 0;
}

