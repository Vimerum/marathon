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
const double PRE = 0.0001;

ll n, pessoas;
vector<double> r;

bool serve (double a) {
	ll ans = 0;
	fori(i,0,n) {
		int b = (int)((pow(r[i],2)*PI)/a); 
		//if (b > 0)
		//	cout << a << " " << i << " " << r[i] << " " << b << endl;
		ans += b;
	}
	return ans >= pessoas;
}

double busca (double a, double b) {
	double mid = (a / 2) + (b / 2);

	if (abs(a-b) < PRE) return mid;

	int res = serve(mid);

	if (res) {
		//cout << a << " " << mid << " " << b << " TRUE" << endl;
		return busca(mid, b);
	}
	else {
		//cout << a << " " << mid << " " << b << " FALSE" << endl;
		return busca(a, mid);
	}

}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	ll t; cin >> t;

	while(t--) {
		cin >> n >> pessoas;
		pessoas++;

		r.clear();

		fori(i,0,n) {
			double tmp; cin >> tmp;
			r.pb(tmp);
		}

		cout << fixed << setprecision(4) << busca(0, 10e8) << endl;
	}
	
    return 0;
}

