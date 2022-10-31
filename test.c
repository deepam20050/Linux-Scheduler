/* Deepam Sarmah
 * 2020050
 * deepam20050@iiitd.ac.in
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <time.h>

#define __MY_CALL 548
#define __NICE_LOG 549

void just_wait () {
	for (long long i = 0; i < 9999999999L; ++i);
}

int main () {
	nice(15);
	long long add_delay;
	printf("Enter delay in ms: ");
	scanf("%lld", &add_delay);
	add_delay *= 1000000ll;
	pid_t pid = fork();
	if (pid < 0) {
		puts("failed creating child process with fork");
		exit(EXIT_FAILURE);
	} 
	if (pid == 0) {
		printf("Modified's PID: %d\n", getpid());
		long x = syscall(__MY_CALL, getpid(), add_delay);
		if (x) {
			puts("Failed to add delay to vruntime!");
			exit(EXIT_FAILURE);
		}
	  clock_t t = clock();
		just_wait();
		t = clock() - t;
		printf("Modified one's execution time: %lf\n", (double)t / CLOCKS_PER_SEC);
		return 0;
	} else {
		printf("Original's PID: %d\n", getpid());
		clock_t t = clock();
		just_wait();
		t = clock() - t;
		printf("Original one's execution time: %lf\n", (double)t / CLOCKS_PER_SEC);
	}
	long y = syscall(__NICE_LOG, getpriority(PRIO_PROCESS, 0));
	if (y) {
		puts("Printing log failed!");
		exit(EXIT_FAILURE);
	}
	return 0;
}
