/* a time of day (from class) */
struct tod {
  int hour, minute;
};

/* An event, with a start and end time;
   The start time is part of the event, but the end time isn't;
   an event running from 9:30 to 10:30 ends just before 10:30  */
struct event {
  struct tod start, end;
};

/* Returns 1 if the specified event does not conflict with the schedule (length n); returns 0 otherwise. */
int available (struct event schedule[], int n, struct event e);

/* Sorts the schedule (length n) in ascending order according to the start time. */
void sortSchedule (struct event schedule[], int n);