#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int sum[4];
long long picked[4];
int main() {
	int n; scanf("%d", &n);

	while (n--) {
		int ta, tb, tc;
		scanf("%d %d %d", &ta, &tb, &tc);
		picked[1] += pow(10, 3*(ta - 1)); sum[1] += ta;
		picked[2] += pow(10, 3*(tb - 1)); sum[2] += tb;
		picked[3] += pow(10, 3*(tc - 1)); sum[3] += tc;
	}

	int who = 0;
	long long maxV = 0;
	for (int i = 1; i <= 3; i++) {
		if (sum[i] > maxV) maxV = sum[who = i];
		else if (sum[i] == maxV) who = 0;
	}
	
	if (who) {
		printf("%d %d", who, sum[who]);
		return 0;
	}


	for (int i = 1; i <= 3; i++) {
		if (picked[i] > maxV) maxV = picked[who = i];
		else if (picked[i] == maxV) who = 0;
	}

	if (who) printf("%d %d", who, sum[who]);
	else printf("0 %d", max(max(sum[1], sum[2]), sum[3]) );
	return 0;
}