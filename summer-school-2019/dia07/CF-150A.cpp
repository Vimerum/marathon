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
	
	ll q; cin >> q;

	vector<ll> divisores;
	for(ll i = 2; i*i <= q; i++) {
		while (q%i == 0) {
			divisores.pb(i);
			q /= i;
		}
	}

	if (q != 1) divisores.pb(q);

	if (divisores.size() == 2)
		cout << "2" << endl;
	else {
		cout << "1" << endl;
		if (divisores.size() <= 1)
			cout << "0" << endl;
		else
			cout << (divisores[0] * divisores[1]) << endl;
	}
	
    return 0;
}

