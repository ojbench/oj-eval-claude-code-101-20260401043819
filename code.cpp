#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // a = seconds per minute
    // b = minutes per hour
    // c = hours per day
    // Current time: f hours, e minutes, d seconds

    // We need to find when hours == minutes == seconds
    // The target value must be valid in all three units
    long long max_target = min({a - 1, b - 1, c - 1});

    // Convert current time to total seconds
    long long current_seconds = f * b * a + e * a + d;

    // Total seconds in a day
    long long total_seconds_per_day = c * b * a;

    long long min_seconds = total_seconds_per_day + 1;

    // Try each possible target value where h == m == s
    for (long long target = 0; target <= max_target; target++) {
        // Calculate the total seconds when h == m == s == target
        long long target_seconds = target * b * a + target * a + target;
        target_seconds = target_seconds % total_seconds_per_day;

        // Calculate time to reach this target
        long long seconds_to_add;
        if (target_seconds > current_seconds) {
            seconds_to_add = target_seconds - current_seconds;
        } else {
            seconds_to_add = total_seconds_per_day - current_seconds + target_seconds;
        }

        min_seconds = min(min_seconds, seconds_to_add);
    }

    cout << min_seconds << endl;
    return 0;
}
