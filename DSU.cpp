#include <bits/stdc++.h>

using namespace std;

const int mxn = 1001;

int parent[mxn];

int siz[mxn];

int n;


void make_set(){
	for (int i = 1; i <=n;i++){
		parent[i] = i;
	}
}

int find(int v){
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
	a = find (a);
	b = find (b);
	if (a!=b){
		if (siz[a] > siz[b]) swap (a,b);
		parent[a] = b;
		siz[b] +=siz[a];
	}
}



int main(){
	memset(siz,1,mxn);
	make_set();
	Union(3,4);
	find(4);
	return 0;
}