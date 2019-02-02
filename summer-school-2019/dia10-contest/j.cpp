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
const int T = 6015;

ll dp[T][T];
int n, b, c;
ll houses[T];

ll solve (int cid, int ant) {
	if (cid >= n) return 0;

	ll &r = dp[cid][ant];
	if (r > 0) return r;

	ll L = solve(cid+1,ant);
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	
	
    return 0;
}

