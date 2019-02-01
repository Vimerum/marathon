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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 100;

int v[T];
char s[T];

void reset() {
	memset(v, 0, sizeof v);
}

struct Trie {
	int cnt, wrd;
	int level;
	map<char, Trie> m;

	Trie () {
		wrd = 0; cnt = 0; level = 0;
		m.clear();
	}

	void add (int i, int niv) {
		cnt++;
		level = niv;
		v[level] = max(v[level], cnt);
		if (i == -1) {
			wrd++;
			return;
		}

		if (!m.count(s[i]))
			m[s[i]] = Trie();

		m[s[i]].add(i-1, niv + 1);
	}
};

void solve() {
	int n, q;
	scanf("%d %d", &n, &q);

	Trie t = Trie();

	fori(i,0,n) {
		scanf("%s", s);
		t.add(strlen(s)-1, 0);
	}
	
	fori(i,0,q) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", v[tmp]);
	}
}
 
int main(){
	int t; 
	scanf("%d",&t);
	while (t--) {
		reset();
		solve();
	}
    return 0;
}

