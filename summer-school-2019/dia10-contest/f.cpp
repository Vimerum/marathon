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
 
int main(){
    ios_base::sync_with_stdio(false);
	
	string s;
	int n, l, r;
	cin >>n >>l >>r;
	cin >>s;
	l--;
	r--;

	int q; cin >>q;
	string ans = "";
	while(q--) {
		char op; cin >>op;

		if(op == 'Q') {
			char h; cin >>h;
			ans += (h == 'L'? s[l]:s[r]);
		}
		if(op == 'S') {
			char h, mov;
			cin >>h >>mov;
			if(mov == 'L') {
				if(h == 'L') {
					l = max(0, l-1);
				} else {
					r = max(0, r-1);
				}
			} else {
				if(h == 'L') {
					l = min(n-1, l+1);
				} else {
					r = min(n-1, r+1);
				}
			}
			
		}
		if(op == 'R') {
			int aux = l;
			l = r;
			r = aux;
		}
	}

	cout <<ans <<endl;
	
    return 0;
}

