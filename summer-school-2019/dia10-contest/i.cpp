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
	
	ll n; cin >> n;
	ll ant = 0;
	ll ans = 0;
	fori(i,0,n) {
		ll tmp; cin >> tmp;
		if (i == 0) {
			ans = abs(tmp);
		}
		else {
			ans += abs(ant-tmp);
		}
		ant = tmp;
	}

	cout << ans << endl;
	
    return 0;
}

