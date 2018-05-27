#include <stdio.h>
#define MAX_MONKEY 101

int T, N, M;
int A[MAX_MONKEY], B[MAX_MONKEY], C[MAX_MONKEY], D[MAX_MONKEY];
double a[MAX_MONKEY], b[MAX_MONKEY], c[MAX_MONKEY], d[MAX_MONKEY];
double a1, b1, a2, b2;
//int min= 0x7fffffff;
int answer = -1;

void makeFormula(){
	int i;
	for (i = 1; i <= N; i++){
		a1 += (double)1 / B[i];
		b1 += (B[i] - A[i]) / (double)B[i];
	}

	for (i = 1; i <= M; i++){
		a2 += (double)1 / D[i];
		b2 += (D[i] - C[i]) / (double)D[i];
	}
}

void makeArray(){
	int i;
	for (i = 1; i <= N; i++){
		a[i] = (double)1 / B[i];
		b[i] = (B[i] - A[i]) / (double)B[i];
	}

	for (i = 1; i <= M; i++){
		c[i] = (double)1 / D[i];
		d[i] = (D[i] - C[i]) / (double)D[i];
	}
}

int max(int a, int b){
	if (a >= b)
		return a;
	else
		return b;
}

int min(int a, int b){
	if (a <= b)
		return a;
	else
		return b;
}

void binarySearch(int start, int end){
	int X1, X2, comp1, comp2;
	int X1_prev, X1_post, X2_prev, X2_post;
	int mid;
	int i;

	while (start<=end){
		X1 = X2 = X1_prev = X1_post = X2_prev = X2_post = 0;
		mid = (start + end) / 2;

		for (i = 1; i <= N; i++){
			if (a[i] * mid + b[i] >= 1)
				X1 += (int)(a[i] * mid + b[i]);
				if (a[i] * (mid - 1) + b[i]>=1)
			X1_prev += (int)(a[i] * (mid-1) + b[i]);
			if (a[i] * (mid + 1) + b[i]>=1)
			X1_post += (int)(a[i] * (mid + 1) + b[i]);
		}

		for (i = 1; i <= M; i++){
			if (c[i] * (T - mid) + d[i] >= 1)
				X2 += (int)(c[i] * (T - mid) + d[i]);
			
			if (c[i] * (T - (mid - 1)) + d[i]>=1)
			X2_prev += (int)(c[i] * (T - (mid-1)) + d[i]);

			if (c[i] * (T - (mid + 1)) + d[i]>=1)
			X2_post += (int)(c[i] * (T - (mid + 1)) + d[i]);
		}

	/*	if ((min(X1, X2) > min(X1_prev, X2_prev)) && (min(X1, X2) > min(X1_post, X2_post))){
		printf("%d\n", mid);
		return;
		}

		else if (min(X1, X2) < min(X1_prev, X2_prev)){
		end = mid - 1;
		}

		else{
		start = mid + 1;
		}*/


		//printf("%d %d %d\n", mid, X1, X2);

		comp1 = X1_prev - X2_prev;
		comp2 = X1_post - X2_post;

		/*	X1 = (int)(a1*mid + b1);
		X2 = (int)(a2*(T - mid) + b2);

		comp1 = (int)(a1*(mid - 1) + b1) - (int)(a2*(T - (mid - 1)) + b2);
		comp2 = (int)(a1*(mid + 1) + b1) - (int)(a2*(T - (mid + 1)) + b2);*/

	

		//if (comp1*comp2 < 0 && X1<=X2){
		//	//printf("%d %d\n", X1, X2);
		//	printf("%d\n", mid);
		//	return;
		//}

		/*	if (comp1 == 0){
		printf("%d\n", mid - 1);
		return;
		}

		if (comp2 == 0){
		printf("%d\n", mid + 1);
		return;
		}*/

		/*if (X1 == X2){
			printf("%d\n", mid);
			return;
		}*/

		if (X1 <= X2){
			if (mid > answer)
				answer = mid;
			start = mid + 1;

		}
		else{
			end = mid - 1;
		}

	}


	//binarySearch(start, mid - 1);

	//binarySearch(mid+1, end);
}


int result;
int result1, result2;

int main(){


	int i, j;
	int X1, X2, X_temp;
	scanf("%d", &T);
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d %d", &A[i], &B[i]);
	}
	scanf("%d", &M);
	for (i = 1; i <= M; i++){
		scanf("%d %d", &C[i], &D[i]);
	}

	//makeFormula();
	makeArray();

	//printf("%f %f\n%f %f\n", a1, b1, a2, b2);

	/*for (j = 0; j <= T; j++){
	X1 = 0;
	for (i = 1; i <= N; i++){
	if (a[i] * j + b[i]>=1)
	X1 += (int)(a[i] * j + b[i]);
	}
	printf("%d ", X1);

	}
	printf("\n");
	for (j = 0; j <= T; j++){
	X2 = 0;
	for (i = 1; i <= M; i++){
	if (c[i] * (T - j) + d[i]>=1)
	X2 += (int)(c[i] * (T-j) + d[i]);
	}
	printf("%d ", X2);
	}
	printf("\n");*/

	binarySearch(0, T);

	printf("%d\n", answer);

	/*
	for (i = 0; i <= T; i++){
	printf("%d ", (int)(a1*i + b1));
	}
	printf("\n");
	for (i = 0; i <= T; i++){
	printf("%d ", (int)(a2*(T-i) + b2));
	}
	printf("\n");*/




	//for (i = 1; i <= T; i++){
	//	X1 = a1*i + b1;
	//	X2 = a2*(T - i) + b2;
	//	if (X1 <= 0 || X2 <= 0) continue;
	//	if (diff(X1, X2) < min){
	//		min = diff(X1, X2);
	//		result = i;
	//		//result1 = X1;
	//		//result2 = X2;
	//		//printf("%d %d\n", result1, result2);
	//	}
	//}

	//i = 6;
	//X1 = a1*i + b1;
	//X2 = a2*(T - i) + b2;
	//if (diff(X1, X2) < min){
	//	min = diff(X1, X2);
	//	result1 = X1;
	//	result2 = X2;
	//	printf("%d %d\n", result1, result2);
	//}

	//printf("%d %d\n", result1, result2);

	//printf("%f %f\n%f %f\n", a1, b1, a2, b2);

	//printf("%d\n", result);
}