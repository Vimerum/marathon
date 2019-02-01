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

int hx, hy, ux, uy;

ll solve(ll a, ll b, ll c) {
	ll v1 = a*hx + b*hy + c;
	ll v2 = a*ux + b*uy + c;
	v1 /= abs(v1);
	v2 /= abs(v2);

	if(v1 != v2) return 1;
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>hx >>hy >>ux >>uy;

	int n; cin >>n;
	int ans = 0;
	while(n--) {
		ll a, b, c;
		cin >>a >>b >>c;
		ans += solve(a, b, c);
	}
		
	cout <<ans <<endl;
    return 0;
}

