int waviness(int num) {
    int count = 0;
    if (num < 100) return count;
    int a = num % 10;
    num /= 10;
    int b = num % 10;
    int c = (num / 10) % 10;
    if (a < b && b > c || a > b && b < c) count++;
    return count + waviness(num);
}

int totalWaviness(int num1, int num2) {
    int out = 0;
    for (int n = num1; n <= num2; n++) out += waviness(n);
    return out;
}