#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int lower_bound, upper_bound;
	int lower_bound_flag = 0, upper_bound_flag = 0;

	for (int i = 0; i < argc; i++) {
		if (strncmp(argv[i], "--lower_bound=", 14) == 0) {
			lower_bound_flag = 1;
			sscanf(argv[i] + 14, "%d", &lower_bound);
		}
		if (strncmp(argv[i], "--upper_bound=", 14) == 0) {
			upper_bound_flag = 1;
			sscanf(argv[i] + 14, "%d", &upper_bound);
		}
	}

	if (!lower_bound_flag && !upper_bound_flag) {
		fprintf(stderr, "No flags found.");
		return 1;
	} else if (!lower_bound_flag) {
		fprintf(stderr, "Flag --lower_bound is missing.");
		return 1;
	} else if (!upper_bound_flag) {
		fprintf(stderr, "Flag --upper_bound is missing.");
		return 1;
	} else if (lower_bound > upper_bound) {
		fprintf(stderr, "The lower bound is greater than the upper bound.");
		return 1;
	}

	for (int i = lower_bound; i <= upper_bound; i++) {
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}