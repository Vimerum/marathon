#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
ll n;
vector<pair<int,int> > horarios;

ll get_next(int i) {
	fori(a, 0, n) {
		if (horarios[a].fi >= horarios[i].sec) return a;
	}

	return -1;
}
	
ll go (int i, int current) {
	int next = get_next(i);

	if (next == -1) return (current + 1);

	return go(next, current + 1);
}

bool comp (pair<int,int> a, pair<int,int> b) {
	if (a.sec <= b.sec) return true;
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		horarios.pb(mk(a, b));
	}

	sort(horarios.begin(), horarios.end(), comp);

	ll max = go(0,0);

	cout << max << endl;
    
    return 0;
}

