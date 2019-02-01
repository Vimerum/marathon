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
const int sqrtT = sqrt(T);

ll bucket[sqrtT];
ll v[T];
int size;

ll query (int l, int r) {
	ll ans = 0;
	int primeiro = l / size;
	int segundo = r / size;

	while (l / size == primeiro and l <= r)
		ans += v[l++];
	
	while (l / size < segundo) {
		ans += bucket[l / size];
		l += size;
	}

	while (l <= r)
		ans += v[l++];
	
	return ans;
}

void update (int ind, int val) {
	v[ind] += val;
	int bloco = ind/size;
	bucket[bloco] = 0;
	for (int i = bloco; i/size == bloco; i++)
		bucket[bloco] += v[i];
}
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	size = (int)(sqrt(n));
	
    return 0;
}

