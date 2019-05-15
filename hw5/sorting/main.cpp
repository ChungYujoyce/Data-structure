#include <cstdio>
using namespace std;

#define maxn 1000010

unsigned int a[maxn], t[maxn];
long long ans;

void merge_sort(int l, int r) {
	if (l == r)
		return ;

	int mid = l + (r - l) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int x = l, y = mid + 1, idx = l;
	while (x <= mid || y <= r) {
		if (y > r || (x <= mid && a[x] <= a[y]))
			t[idx++] = a[x++];
		else {
			t[idx++] = a[y++];
			ans += mid - x + 1;
		}
	}
	for (int i = l; i <= r; i++)
		a[i] = t[i];
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++)
			scanf("%u", &a[i]);
		ans = 0;
		merge_sort(0, n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
