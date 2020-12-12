#include <stdio.h>
#include <time.h>

// Define arrays and variables
int a[] = {1,  3,  5,  7,  9,  11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39 };
int b[] = {3,  7,  11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79 };
int c[] = {2,  5,  8,  11, 14, 17, 20, 23, 26, 29, 32, 35, 38, 41, 44, 47, 50, 53, 56, 59 };
int d[] = {5,  10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
int e[] = {10, 25, 40, 55, 70, 85, 100,115,130,145,160,175,190,205,220,235,250,265,280,295};
int i, f, g = 0;

// Create timespec structs to record times before and after for loop
struct timespec req_start, req_end;

int main() {

	// Record start time into req_start
	clock_gettime(CLOCK_MONOTONIC_RAW, &req_start);

	// Run for loop
	for ( i = 0, f = 0, g = 0; i < 20; i++ )  {
		f = f + a[i] * b[i] + c[i] * d[i] - e[i];
		g = g + (a[i] + d[i]) * (b[i] - c[i]) * e[i];
	}

	// Record end time into req_end and store time difference (in ns) in loop_time
	clock_gettime(CLOCK_MONOTONIC_RAW, &req_end);
	double loop_time = (req_end.tv_nsec - req_start.tv_nsec);

	// Print results (time and final values of f and g)
	printf("The for loop took %lf milliseconds to complete.\n", loop_time/1000);
	printf("f is %d\n", f);
	printf("g is %d\n", g);

}

