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
 
int n, m;
vector<int> pinos;
int c;

void go (int i) {
	if (i >= n) return;

	int dif = m - pinos[i];
	pinos[i] += dif;
	pinos[i+1] += dif;
	c += abs(dif);

	go(i+1);
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
	fori(i, 0, n) {
		int a; cin >> a;
		pinos.pb(a);
	}

	c = 0;
	go(0);

	cout << c << endl;
    
    return 0;
}

