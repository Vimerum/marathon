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
 
int main(){
    ios_base::sync_with_stdio(false);
	ll n, k;
	ll ans = 0;
	while(cin >> n >> k) {
		ans = 0;
		ll cheio = n;
		while(cheio >= k) {
			ll sobra =  (cheio%k) + (cheio/k);
			cheio = (cheio/k) * k;
			ans += cheio;
			cheio = sobra;
			//cout << cheio << " " << sobra << " " << ans << endl;
		}	
		ans += cheio;
		cout << ans << endl;
	}
    return 0;
}

