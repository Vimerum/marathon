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
	
	cout << "25000" << endl;
	fori(i,0,25000) {
		fori(j,0,20) {
			cout << (rand() % 122 + 97);
		}
		cout << endl;
	}

	cout << "22000" << endl;

	fori(i,0,22000) {
		int size = rand() % 20 + 1;
		fori(j,1,size) {
			cout << (char)(rand() % 122 + 97);
		}
		cout << endl;
	}
	
    return 0;
}

