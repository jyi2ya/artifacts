#include <stdio.h>

int main()

{

	int i;
	int n;

	double s, t;

	s = t = 100.0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++){
		s /= 2;
		t += 2 * s;
	}
	t -= s * 2;

	printf("%.4f %.4f\n", t, s);

	return 0;

}
