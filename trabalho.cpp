#include <bits/stdc++.h>
using namespace std;



int main(){

	int n, m; cin >> n >> m;
	int a, b; cin >> a >> b; a--, b--;
	vector<pair<int,double>> g(n+1);
	for(int i=0;i<m;i++){
		int u, v; cin >> u >> v; u--, v--;
		double r; cin >> r;
		g[u].push_back({v, r});
		g[v].push_back({u, r});
	}


	// L
	auto mult = [&] (vector<double> v){

		vector<double> w(n-1);
		for(int j=0;j<n-1;j++){
			double soma = 0;
			for(auto [i, r] : g[j]){
				w[j] -= (1/r) * v[i];
				soma += (1/r);
			}
			w[j] += soma * v[j];
		}
		return w;
	};

}
