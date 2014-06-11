#include "event.h"

int freetime(struct event schedule[], int n, int hour, int min) {
	int noClashes = 1, i;

	for (i = 0; i < n; i++)
		if (hour >= schedule[i].start.hour && min >= schedule[i].start.minute
				|| hour > schedule[i].start.hour)
			if (hour <= schedule[i].end.hour && min < schedule[i].end.minute
					|| hour < schedule[i].end.hour) {
				return 0;
			}

	return noClashes;
}
