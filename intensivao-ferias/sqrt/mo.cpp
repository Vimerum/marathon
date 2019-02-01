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
const int T = 1e5;

// TODO: Adicionar a ideia de buckets do sqrt.cpp
int size;

int v[T];
int freq[T];
int resp[T];
int l = 0, r = 0;
int ans;

struct Qry {
	int l, r;
	int ind;

	bool operator<(const Qry &x) const{
		if (l/size == x.l/size)
			return (r < x.r);
		return (l/size < x.l/size);
	}
};

Qry queries[T];

void add (int val) {
	freq[val]++;
	if (freq[val] == 1) ans++;
}

void remove (int val) {
	freq[val]--;
	if (freq[val] == 0) ans--;
}

int query (int x, int y) {
	while (r < y) add(v[++r]);
	while (l > x) add(v[--l]);
	while (r > y) remove(v[r--]);
	while (l < x) remove(v[l++]);

	return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	fori(i,0,n) cin >> v[i];

	size = (int)sqrt(n);

	int q; cin >> q;
	fori(i,1,q+1) {
		int x, y; cin >> x >> y;
		queries[i] = Qry({x,y,i});
	}

	sort(queries, queries+q);

	for (int i = 1; i <= q; i++) {
		Qry aux = queries[i];
		resp[aux.ind] = query(aux.l,aux.r);
	}

	for (int i = 1; i <= q; i++) {
		cout << resp[i] << endl;
	}
	
    return 0;
}

