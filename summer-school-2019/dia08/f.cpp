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
const int T = 1e3 + 15;

ii dp[T][T];
vector<string> os;
vector<int> value;
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	while(t--) {
		memset(dp, -1, sizeof dp);

		int n; cin >> n;
		fori(i,0,n) {
			string name, o;
			int val;
			cin >> name >> o >> val;
			os.pb(o);
			value.pb(val);
		}
	}
	
    return 0;
}

