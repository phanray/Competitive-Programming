pair<int, int> num[maxn];
int val[maxn];

void Discretizing(){
	for (i = 1; i <= n; i++)
		num[i] = {a[i], i};

	sort(num + 1, num + n + 1);

	int numval = 0;

	for (i = 1; i <= n; i++){
		if (num[i].fi != val[numval])
			val[++numval] = num[i].fi;

		a[num[i].se] = numval;
	}
}
