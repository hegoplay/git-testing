#include <bits/stdc++.h>
//xin chao cac ban minh la manh
using namespace std;

struct edge{
	int u,v;
	int w;
	edge(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	}
};

const int mxn = 1001;

int n,m;
vector <edge> canh;
int parent[mxn], sz[mxn];

void make_set(){
	for (int i = 1 ; i < n;i++){
		parent[i]= i;
		sz[i] = 1;
	}
}

int find(int v){
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union (int a, int b){
	a = find(a);
	b = find(b);
	if (a==b) return false; //khong the gop a b vs nhau
	if (sz[a] < sz[b]) swap(a,b);
	parent[b] = a;
	sz[a] +=sz[b];
	return true;
}

void inp(){
	cin >> n >> m;
	for (int i = 0;i <m;i++){
		int x,y,z; cin >> x >> y >> z;
		edge e = edge(x,y,z);
//		e.u = x; e.v = y; e.w = z;
		canh.push_back(e);
		
	}
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void kurskal(){
	vector <edge> mst;
	int d = 0;
	sort(canh.begin(),canh.end(),cmp);
	for (int i= 0;i < m;i++){
		if (mst.size() ==n-1) break;
		edge e = canh[i];
		if (Union(e.u,e.v)){
			mst.push_back(e);
			d+=e.w;
		}
	}
	if (mst.size()!=n-1) cout << "Do thi khong lien thong !\n";
	else{
		cout << "MST: " << d << endl;
		for (auto it : mst){
			cout << it.u << " " << it.v << " " << it.w << endl;
		}
	}
}

int main(){
//	freopen("input.txt","r",stdin);
	cout << fixed << setprecision(2) << 2.33333333;
	return 0;
}
