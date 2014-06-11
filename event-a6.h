  /* A time of the day (from class) */
  struct tod {
    int hour, minute;
  };
  
  /* An event, with a start and end time;
     The start time is part of the event, but the end time isn't;
     an event running from 9:30 to 10:30 ends just before 10:30  */
  struct event {
    struct tod start, end;
  };
  
  /* Returns 1 if the specified time (hour and minute) is not part of any
     scheduled event; returns 0 otherwise. The value n specifies the
     size of the array containing the schedule.  */
  int freetime (struct event schedule[], int n, int hour, int min);