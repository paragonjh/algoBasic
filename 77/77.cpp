#include <iostream>
using namespace std;
int unf[1001] = {0, };

int Find(int v)
{
	if(v==unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	// your code goes here
	int n, m = 0;
	cin >> n >> m;
	//Initialize
	for(int i=1; i<=n; i++) {
		unf[i]=i;
	}
	
	//Union
	int a, b = 0;
	for(int i=1; i<=m; i++) {
		cin >> a >> b;
		Union(a,b);
	}
	
	//Find
	int x,y = 0;
	cin >> x >> y;
	int fx = Find(x);
	int fy = Find(y);
	
	//Check
	if(fx == fy)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
