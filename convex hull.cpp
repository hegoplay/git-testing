#include <bits/stdc++.h>

struct Point{
	long long x;
	long long y;
};

using namespace std;

long long n;

vector <Point> vt;

vector <Point> up;
vector <Point> down;


bool cmp(Point a , Point b){
	if (a.x < b.x) return true;
	if (a.x == b.x) return a.y < b.y;
	return false;
}

int CW (Point p1, Point a, Point b){
	Point u;
	u.x = p1.x - b.x;
	u.y = p1.y - b.y;
	Point v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
//	printf ("%lld",u.x*v.y);
	return (long long)((u.x)*(v.y)) -(long long) (v.x*u.y)>= 0; 
}

int CCW (Point p1, Point a, Point b){
	Point u;
	u.x = p1.x - b.x;
	u.y = p1.y - b.y;
	Point v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
//	printf ("%d %d\n%d %d\n",u.x,u.y,v.x,v.y);
//	printf ("%lld\n",u.x*v.y);
	return(long long)((u.x)*(v.y)) -(long long) (v.x*u.y)<= 0; 
}

void inp(){
	cin >> n;
	for (int i = 0 ; i < n;i++){
		int x1,y1;
		cin >> x1 >> y1;
		Point temp;
		temp.x = x1;
		temp.y = y1;
		vt.push_back(temp);
	}
	if (vt.size() > 1) sort(vt.begin(),vt.end(),cmp);
}

void solve(){
	up.push_back(vt[0]);
	down.push_back(vt[0]);
	Point end = *(vt.end()-1);
//	cout << "\n" << end.x << " " << end.y << "\n\n" << vt[0].x << " " << vt[0].y << "\n";
	for (int i = 1; i < vt.size();i++){
		
		while (up.size()>1&&!CW(vt[i],up[up.size()-2],up[up.size()-1])){
//			cout << "up: " << vt[i].x << " " << vt[i].y << endl;
			up.pop_back();
		}
		up.push_back(vt[i]);
		while (down.size()>1&&!CCW(vt[i],down[down.size()-2],down[down.size()-1])){
//			cout << "down: " <<  vt[i].x << " " << vt[i].y << endl;
//			printf("%d %d\n%d %d\n%d %d\n%d\n",vt[i].x,vt[i].y,down[down.size()-1].x,down[down.size()-1].y,down[down.size()-2].x,down[down.size()-2].y,CCW(vt[i],down[down.size()-2],down[down.size()-1]));
			down.pop_back();
		}
		down.push_back(vt[i]);
	}
}

void convert(string &s){
	cout << up.size() + down.size() - 2 << endl;
	for (Point t : up){
		cout << t.x << " " << t.y << "\n";
	}
	for (int i = 1 ; i < down.size()-1;i++){
		cout << down[i].x << " " << down[i].y << "\n";
	}
}

int main(){
//	freopen("test_input.txt","r",stdin);
	string s;
	inp();
	solve();
	convert(s);
	return 0;
}
