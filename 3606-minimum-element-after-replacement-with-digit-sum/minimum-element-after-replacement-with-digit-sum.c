#define min(a, b) ({int _a = a; int _b = b; (_a > _b ? _b : _a);})

int sumDigits(int *np) {
    int sum = 0;
    int n = *np;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
        if (!n) break;
    }
    *np = sum;
    return sum;
}

int minElement(int* nums, int numsSize) {
    int min = 0x7fffffff;
    for (int i = 0; i < numsSize; i++) min = min(min, sumDigits((nums + i)));
    return min;
}