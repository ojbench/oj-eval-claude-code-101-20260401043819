#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // a = seconds per minute
    // b = minutes per hour
    // c = hours per day
    // Current time: f hours, e minutes, d seconds

    // We need to find when hours == minutes == seconds
    // This means we need to find time t where:
    // - seconds value = t (mod a)
    // - minutes value = t (mod b)
    // - hours value = t (mod c)

    // Convert current time to total seconds
    long long current_seconds = f * b * a + e * a + d;

    // Total seconds in a day
    long long total_seconds_per_day = c * b * a;

    // We need to find the next time when h == m == s
    // This happens when the time value (in each unit) is the same
    // Specifically, we need: seconds_value == minutes_value == hours_value

    // Try all possible values from 0 to c-1 (valid hour/minute/second values)
    for (long long seconds_to_add = 1; seconds_to_add <= total_seconds_per_day; seconds_to_add++) {
        long long future_seconds = current_seconds + seconds_to_add;

        // Calculate h, m, s at this future time
        long long total = future_seconds % total_seconds_per_day;

        long long h = total / (b * a);
        long long m = (total % (b * a)) / a;
        long long s = total % a;

        if (h == m && m == s && h < c && m < b && s < a) {
            cout << seconds_to_add << endl;
            return 0;
        }
    }

    // Should never reach here if input is valid
    return 0;
}
