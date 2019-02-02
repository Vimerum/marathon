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
	int n,k,g,b;
	cin >> n >> k >> g >> b;
	string ans; 
	string maxi, mini;
	int maior, menor;
	if(g > b) {
		maxi = 'G';
		mini = 'B';
		maior = g;
		menor = b;
	} else {
		maxi = 'B';
		mini = 'G';
		maior = b;
		menor = g;
	}
	int seg = 0;
	bool flag = true;
	int round = 1;
	while(ans.size() < n and seg <= k) {
		if(round & 1 and flag and maior) {
			for(int i = 0; i < min(k,maior); i++) ans += maxi;
			maior -= min(k,maior);
			seg = 0;
			flag = false;
		} else {
			if(menor) {
				ans += mini;
				menor--;
				if(flag) seg++;
				else seg = 1;
				flag = true;
			} else break;
		}
		round++;
	}
	cout << (ans.size() == n and seg <= k? ans : "NO") << endl;
	//cout << seg << " " << ans << endl;

	
	
	
    return 0;
}

