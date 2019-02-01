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
const int T = 1e6;
int pi[T];

int n;
vector<int> a;
vector<int> b;

vector<int> v1;
vector<int> v2;

void pre() {
	v2.pb(-INF);

	pi[0] = pi[1] = 0;
	for(int i = 2; i <= v2.size(); i++) {
		pi[i] = pi[i-1];

		while(pi[i] > 0 and v2[pi[i]] != v2[i-1])
			pi[i] = pi[pi[i]];

		if(v2[pi[i]] == v2[i-1])
			pi[i]++;
	}
}

bool kmp() {
	pre();
	int k = 0;
	int m = v2.size() - 1;

	for(int i = 0; i < v1.size(); i++) {
		while(k > 0 and v2[k] != v1[i])
			k = pi[k];

		if(v2[k] == v1[i])
			k++;
		
		if(k == m)
			return true;
	}
	return false;
}


 
int main(){
    ios_base::sync_with_stdio(false);
	
	cin >> n;

	fori(i,0,n) {
		int tmp; cin >> tmp;
		a.pb(tmp);
	}

	fori(i,0,n) {
		int tmp; cin >> tmp;
		b.pb(tmp);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	fori(i,0,n) {
		int r = i + 1;
		if (r >= n)
			r = 0;

		int d1 = a[r] - a[i];
		if (d1 < 0)
			d1 = 360000 - a[i] + a[r];

		v1.pb(d1);
	}
	fori(i,0,n) {
		v1.pb(v1[i]);
	}
	
	fori(i,0,n) {
		int r = i + 1;
		if (r >= n)
			r = 0;

		int d1 = b[r] - b[i];
		if (d1 < 0)
			d1 = 360000 - b[i] + b[r];

		v2.pb(d1);
	}
	cout << (kmp()? "possible" : "impossible") << endl;
	return 0;
}

