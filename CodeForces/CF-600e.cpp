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
const int T = 1e5 + 10;

int n;
int colors[T];
vector<int> edges[T];

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	fori(i,1,n+1) {
		cin >> colors[i];
	}

	fori(i,0,n) {
		int a, b; cin >> a >> b;
		edges[a].pb(b);
	}

    return 0;
}

