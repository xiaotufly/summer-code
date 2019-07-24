#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct Node {
	int val;
	int pre, nxt;
}node[N]; //memory pool 

int n, k, tot;
int a[N], pos[N], vis[N], p, ans[N];
int head, tail;

void init() {
	tot = 2;
	head = 1, tail = 2;
	node[head].nxt = tail;
	node[tail].pre = head;
}

int insert(int p, int val) {
	int q = ++tot;
	node[q] = Node({val, p, node[p].nxt});
	node[node[p].nxt].pre = q;
	node[p].nxt = q;
	return q;
}

void remove(int p) {
	node[node[p].pre].nxt = node[p].nxt;
	node[node[p].nxt].pre = node[p].pre;
	vis[a[node[p].val]] = 1;
}

int main() {
	cin >> n >> k;
	p = n;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = insert(head, i);
	}
	int coach = 1;
	while (p != 0) {
		int now = pos[p];
		ans[node[now].val] = coach;
		
		int ps = node[now].pre;
		int tms = k;
		
		while (tms-- && ps != head) {
			ans[node[ps].val] = coach;
			remove(ps);
			ps = node[ps].pre;
		}
		
		ps = node[now].nxt;
		tms = k;
		
		while (tms-- && ps != tail) {
			ans[node[ps].val] = coach;
			remove(ps);
			ps = node[ps].nxt;
		}
		
		remove(now);
		while (vis[p]) p--;
		coach = 3 - coach;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
