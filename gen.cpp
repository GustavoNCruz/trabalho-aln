#include <bits/stdc++.h>
using namespace std;


int main(){


	while(1){
		int n = 1000;
		int m = 300000;

		vector<tuple<int,int,double>> arestas;
		vector<vector<int>> g(n);
		for(int i=0;i<m;i++){
			int u, v;
			u = rand() % n;
			v = rand() % n;
			double d = (rand() % 100 + 1);
			//double d = 1;
			//cout << u << " " << v << " " << d << endl;
			g[u].push_back(v);
			g[v].push_back(u);
			arestas.push_back({u, v, d});
		}

		vector<int> marc(n);
		int tot = 0;
		auto dfs = [&] (auto&& self, int u) -> void{
			marc[u] = 1;
			tot++;
			for(auto v : g[u]) if(!marc[v]) self(self, v);
		};
		dfs(dfs, 0);

		if(tot != n){
			continue;
		}

		cout << n << " " << m << endl;
		for(auto [i, j, x] : arestas) cout << i+1 << " " << j+1 << " " << x << endl;


		cout << 1 << " " << 2 << endl;
		return 0;
	}
	
}
