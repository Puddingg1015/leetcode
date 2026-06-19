#define min(a, b) (a < b ? a : b)
#define abs(a) (a <= 0 ? -(a) : a)

double angleClock(int hour, int minutes) {
    double hr_a = ((double) hour + ((double)minutes)/60)/12 * 360;
    double min_a = ((double)minutes)/60 * 360;
    return min(abs(hr_a - min_a), abs(360 - abs(hr_a - min_a)));
}