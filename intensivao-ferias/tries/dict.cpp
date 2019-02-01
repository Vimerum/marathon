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

struct Trie {
	int cnt, wrd;
	map<char, Trie> m;

	Trie () {
		cnt = 0;
		wrd = 0;
		m.clear();
	}

	void add (string &s, int i) {
		cnt++;
		if (i == s.size()) {
			wrd++;
			return;
		}

		if (!m.count(s[i])) 
			m[s[i]] = Trie();

		m[s[i]].add(s, i+1);
	}

	void aipapai (string s) {
		cout << ">" << s << endl;
		if (wrd > 0) {
			cout << s << endl;
		}

		for (auto x : m) {
			x.sec.aipapai(s + x.fi);
		}
	}

	bool find (string &s, int i) {
		if (i == s.size()) {
			for (auto x : m) {
				x.sec.aipapai(s + x.fi);
			}

			return true;
		}

		if (!m.count(s[i])) return false;

		return m[s[i]].find(s, i+1);
	}
};
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int n; cin >> n;

	Trie t = Trie();

	fori(i,0,n) {
		string s; cin >> s;
		t.add(s, 0);
	}

	int k; cin >> k;
	fori(i,0,k) {
		string s; cin >> s;
		cout << "Case #" << (i+1) << ":" << endl;
		if (!t.find(s, 0))
			cout << "No match." << endl;
	}
	
    return 0;
}

