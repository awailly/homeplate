#include "sleep_duration.h"

// Note: Day-of-week ranges must not wrap around the week boundary (e.g., start_dow=6, end_dow=2
// is not supported). Slots are matched in order; the first matching slot wins.
// Ensure slots are non-overlapping or ordered by priority.
uint getSleepDuration(SleepScheduleSlot sleepSchedule[], size_t size, TimeInfo time, SleepDefaults defaults, bool doQuickSleep)
{
    if (doQuickSleep) {
        return defaults.quickSleep;
    }

    uint timeInMinutes = time.hour * 60 + time.minute;

    for (int i = 0; i < size; i++) {
        SleepScheduleSlot b = sleepSchedule[i];

        if (time.dow >= b.start_dow && time.dow <= b.end_dow) {
            uint startTimeInMinutes = b.start_hour * 60 + b.start_minute;
            uint endTimeInMinutes = b.end_hour * 60 + b.end_minute;

            if (timeInMinutes >= startTimeInMinutes && timeInMinutes < endTimeInMinutes) {
                return b.sleep_in_seconds;
            }
        }
    }

    return defaults.normalSleep;
}
