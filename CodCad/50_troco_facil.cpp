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
 
ll n, troco;
int moedas[6] = {100, 50, 25, 10, 5, 1};

void go (int i) {
	if (n == 0) return;

	while (n >= moedas[i]) {
		troco++;
		n -= moedas[i];
	}

	go(i+1);
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n;
	troco = 0;

	go(0);

	cout << troco << endl;
    
    return 0;
}

