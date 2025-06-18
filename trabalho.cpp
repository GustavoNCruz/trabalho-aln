#include <bits/stdc++.h>
using namespace std;


double dot(vector<double> a, vector<double> b){
	double x = 0;
	for(int i=0;i<a.size();i++) x += a[i] * b[i];
	return x;
}

vector<double> operator * (vector<double> a, double k){
	vector<double> b = a;
	for(auto& x : b) x *= k;
	return b;
}

vector<double> operator + (vector<double> a, vector<double> b){
	vector<double> c = a;
	for(int i=0;i<b.size();i++) c[i] += b[i];
	return c;
}

int main(){

	int n, m; cin >> n >> m;
	vector<vector<pair<int,double>>> g(n);

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
				if(i < n-1) w[j] -= (1/r) * v[i];
				soma += (1/r);
			}
			w[j] += soma * v[j];
		}
		return w;
	};

	vector<double> cur(n);

	int a, b; cin >> a >> b; a--, b--;
	cur[a] = 1, cur[b] = -1;
	cur.resize(n-1);

	// resolver Lv = cur 

	const int MAX_ITER = 1000;
	const double PRECISION = 1e-8;
	bool convergiu = false;
	vector<double> r = cur;
	vector<double> x(n-1);
	vector<double> p = r;
	double v = dot(r, r);
	for(int k=0; k < MAX_ITER; k++){
		auto q = mult(p);
		double mu = dot(p, q);
		double alpha = v / mu;
		x = x + p * alpha;
		r = r + q * (-alpha);
		double vp = dot(r, r);
		double beta = vp / v;
		p = r + p * beta;
		v = vp;
		if(abs(v) < PRECISION){
			convergiu = 1;
			break;
		}
	}

	if(!convergiu){
		cout << "Nao convergiu!!" << endl;
		exit(1);
	}

	x.push_back(0);
	cout << fixed << setprecision(8) << x[a] - x[b] << endl;
	
}
