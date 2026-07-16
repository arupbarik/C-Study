/* Q4. b) Write a program to convert current time (in 24-hour format) to total numbers of minutes. */

#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    int hour = now->tm_hour;
    int minute = now->tm_min;

    int totalMinutes = hour * 60 + minute;

    printf("Current time: %02d:%02d\n", hour, minute);
    printf("Total minutes since midnight: %d\n", totalMinutes);
    return 0;
}