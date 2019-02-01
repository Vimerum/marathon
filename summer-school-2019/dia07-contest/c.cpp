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

const int N = 5e7;
ll v[N];
vector<unsigned int> primes;
vector<ll> ans;
void crivo(ll n) {
	ll i;
	for(i = 2; i <= n; i++) {
		while(n%i == 0) {
			ans.pb(i);
			n /= i;
			if(ans.size() > 2) break;
		}
		if(ans.size() > 2) break;
	}
	if(n != 1) ans.pb(i);
}

bool ehPrimo(ll n) {
	if(n == 2) return true;
	if(n%2 == 0) return false;
	for(ll i = 3; i <= sqrt(n); i+=2) {
		if(n%i == 0) return false;
	}
	return true;
}

ll pot(ll i, ll j) {
	ll ans = 1;
	for(int k = 0; k < j; k++) {
		ans *= i;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	long long n;
	cin >> n;

	memset(v, -1, sizeof v);
	crivo(n);

	if(ehPrimo(n)) {
		cout <<'1' <<endl <<'0' <<endl;
		return 0;
	}

	vector<ll> ans;
	for(ll at:primes) {
		ll t = 3;
		if(at > 1e5) t = 2;
		for(ll j = 1; j <= t; j++) {
			if(n%(pot(at, j)) == 0) ans.pb(at);
		}
		if(ans.size() > 2) break;
	}
	
	if(ans.size() > 2) {
		cout <<'1' <<endl;
		cout <<ans[0]*ans[1] <<endl;
	} else {
		cout <<'2' <<endl;
	}

	
    return 0;
}

