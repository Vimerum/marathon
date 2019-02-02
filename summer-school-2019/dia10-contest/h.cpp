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
const int T = 2e5 + 10;
ll v[T];
unordered_map<ll,set<int> >ind;
 
int main(){
    ios_base::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		ind[v[i]].insert(i);
	}
	int a; ll b;
	for(int i = 0; i < q; i++) {
		cin >> a >> b;
		ll tira = v[a];
		cout << tira << " " << a << " " << b << " | ";
		cout << *ind[tira].lower_bound(a-1) << endl;
		for(auto x : ind[tira]) cout << x << " ";
		cout << endl;
		ind[tira].erase(a);
		ind[b].insert(a);
	}
    return 0;
}

