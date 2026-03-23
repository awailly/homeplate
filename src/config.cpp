// Power saving sleep schedule
// Night (11pm-6am): Sleep 60 minutes to save battery
// Workweek (Mon-Fri, 9am-5pm): Sleep 60 minutes (work hours)
// Morning prep (Mon-Fri, 7am-7:30am): Sleep 5 minutes (pre-rush refresh)
// Morning rush (Mon-Fri, 7:30am-8am): Sleep 1 minute (frequent refresh)
// Other times: Sleep 20 minutes (normal refresh rate)

#include "config.h"

#ifdef CONFIG_CPP

SleepScheduleSlot sleepSchedule[] = {
    // Every day (Mon-Sun), midnight to 6am: sleep 60 minutes
    {
        .start_dow = 1,      // Monday
        .start_hour = 0,     // Midnight
        .start_minute = 0,
        .end_dow = 7,        // Sunday
        .end_hour = 6,       // 6am
        .end_minute = 0,
        .sleep_in_seconds = 3600,  // 60 minutes
    },
    // Workweek (Mon-Fri), 9am to 5pm: sleep 60 minutes
    {
        .start_dow = 1,      // Monday
        .start_hour = 9,     // 9am
        .start_minute = 0,
        .end_dow = 5,        // Friday
        .end_hour = 17,      // 5pm
        .end_minute = 0,
        .sleep_in_seconds = 3600,  // 60 minutes
    },
    // Weekdays (Mon-Fri), 7am to 7:30am: sleep 5 minutes (pre-rush refresh)
    {
        .start_dow = 1,      // Monday
        .start_hour = 7,     // 7am
        .start_minute = 0,
        .end_dow = 5,        // Friday
        .end_hour = 7,       // 7:30am
        .end_minute = 30,
        .sleep_in_seconds = 300,   // 5 minutes
    },
    // Weekdays (Mon-Fri), 7:30am to 8am: sleep 1 minute (morning rush refresh)
    {
        .start_dow = 1,      // Monday
        .start_hour = 7,     // 7am
        .start_minute = 30,  // 7:30am
        .end_dow = 5,        // Friday
        .end_hour = 8,       // 8am
        .end_minute = 0,
        .sleep_in_seconds = 60,    // 1 minute
    },
    // Weekdays (Mon-Fri), 6am to 9am: sleep 20 minutes (morning)
    {
        .start_dow = 1,      // Monday
        .start_hour = 6,     // 6am
        .start_minute = 0,
        .end_dow = 5,        // Friday
        .end_hour = 9,       // 9am
        .end_minute = 0,
        .sleep_in_seconds = 1200,  // 20 minutes
    },
    // Weekdays (Mon-Fri), 5pm to 11pm: sleep 20 minutes (evening)
    {
        .start_dow = 1,      // Monday
        .start_hour = 17,    // 5pm
        .start_minute = 0,
        .end_dow = 5,        // Friday
        .end_hour = 23,      // 11pm
        .end_minute = 0,
        .sleep_in_seconds = 1200,  // 20 minutes
    },
    // Weekend (Sat-Sun), 6am to 11pm: sleep 20 minutes
    {
        .start_dow = 6,      // Saturday
        .start_hour = 6,     // 6am
        .start_minute = 0,
        .end_dow = 7,        // Sunday
        .end_hour = 23,      // 11pm
        .end_minute = 0,
        .sleep_in_seconds = 1200,  // 20 minutes
    },
    // Every day (Mon-Sun), 11pm to midnight: sleep 60 minutes
    {
        .start_dow = 1,      // Monday
        .start_hour = 23,    // 11pm
        .start_minute = 0,
        .end_dow = 7,        // Sunday
        .end_hour = 24,      // Midnight
        .end_minute = 0,
        .sleep_in_seconds = 3600,  // 60 minutes
    },
};

const size_t sleepScheduleSize = sizeof(sleepSchedule) / sizeof(sleepSchedule[0]);

#endif
