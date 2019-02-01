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
const int T = 10e5 + 10;

int n;
int q;

int pai[T];
int tam[T];
stack<ii> old_pai;
stack<ii> old_tam;

void init () {
	fori(i,1,n+1) {
		pai[i] = i;
		tam[i] = 1;
	}
}

int find (int x) {
	if (pai[x] == x) return x;
	return find(pai[x]);
}

void join (int u, int v) {
	int a = find(u);
	int b = find(v);
	if (tam[a] > tam[b]) swap(a,b);
	old_pai.emplace(a, pai[a]);
	old_tam.emplace(b, tam[b]);
	pai[a] = b;
	tam[b] += tam[a];
}

void roolback () {
	pai[old_pai.top().fi] = old_pai.top().sec;
	tam[old_tam.top().fi] = old_tam.top().sec;
	old_pai.pop();
	old_tam.pop();
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	cin >> n >> q;
	init();
	while(q--) {
		int op; cin >> op;
		if (op == 1) {
			int u, v; cin >> u >> v;
			if (find(u) == find(v))
				cout << "1" << endl;
			else
				cout << "0" << endl;
		} else if (op == 2) {
			int u, v; cin >> u >> v;
			join(u,v);
		} else {
			roolback();
		}
	}
	
    return 0;
}

