#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include <string.h>

#define MAXLINE 4096
#define CMD_NOT_FOUND 127

void die(const char *msg, ...);
int scream(void);

static int do_scream = 0;
static uint64_t scream_size = 3;

void sig_int(int signo) {
	scream_size *= 2;
	do_scream = 1;
}

int main(void) {
	// Construct sigaction handler
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sig_int;
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) < 0) {
		die("sigaction() failed\n");
	}

	do_scream = 1;

	printf("aboutta scream:");

	while (1) {
		if (do_scream) {
			if (scream()) {
				return 0;
			}
			do_scream = 0;
		}
	}

	return 0;
}

void die(const char *msg, ...) {
	va_list argptr;
	va_start(argptr, msg);
	vfprintf(stderr, msg, argptr);
	va_end(argptr);
	die(0);
}

int scream(void) {
	int i;
	
	if (scream_size >= MAXLINE) {
		printf("\nyou killed it\n");
		return 1;
	}
	
	printf("\n");
	for (i = 0; i < scream_size; i++) {
		printf("a");
	}
	printf("h\n");

	return 0;
}

