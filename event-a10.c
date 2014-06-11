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

int available(struct event schedule[], int n, struct event e) {
	int exclusiveEndHour = e.end.minute == 0 ? e.end.hour - 1 : e.end.hour;
	int exclusiveEndMinute = e.end.minute == 0 ? 59 : e.end.minute - 1;
	exclusiveEndHour = exclusiveEndHour == -1 ? 23 : exclusiveEndHour;

	// If (event's start|end between schedule i's start & end)
	// or (schedule i's start|end between event's start & end): return false.

	if (!freetime(schedule, n, e.start.hour, e.start.minute))
		return 0;
	if (!freetime(schedule, n, exclusiveEndHour, exclusiveEndMinute))
		return 0;

	return 1;
}

/* Sorts the schedule (length n) in ascending order according to the start time. */
void sortSchedule(struct event schedule[], int n) {
	int i, j;
	struct event temp;

	for (i = 1; i < n; i++)
		for (j = 1; j <= n - i; j++)
			if (schedule[j - 1].start.hour > schedule[j].start.hour
					|| schedule[j - 1].start.hour == schedule[j].start.hour
							&& schedule[j - 1].start.minute
									> schedule[j].start.minute) {
				temp = schedule[j - 1];
				schedule[j - 1] = schedule[j];
				schedule[j] = temp;
			}
}
