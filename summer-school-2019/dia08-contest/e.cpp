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
typedef vector< vector<ll> > mat;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);

mat operator * (const mat &a, const mat &b) {
	mat ans(2, vector<ll>(2,0));
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) {
				ans[i][j] += (a[i][k] * b[k][j]) % MOD;
				ans[i][j] %= MOD;
			}
		}
	}
	return ans;
}

mat id() {
	mat x(2, vector<ll>(2,0));
	for(int i = 0; i < 2; i++) x[i][i] = 1LL;
	return x;
}

mat trans() {
	mat x(2, vector<ll>(2,1));
	for(int i = 0; i < 2; i++) x[i][i] = 3LL;
	return x;
}

mat exp(ll e) {
	mat ans = id();
	mat ele = trans();

	while(e) {
		if((e & 1)) ans = ans * ele;
		ele = ele * ele;
		e >>= 1;
	}
	return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	mat ans = exp(max(n,0LL));
	ll resp = (ans[0][0]) % MOD;
	cout << (resp) << endl;
	
    return 0;
}

