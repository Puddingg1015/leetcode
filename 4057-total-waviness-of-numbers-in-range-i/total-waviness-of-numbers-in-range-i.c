
int waviness(int num) {
    // goober question
    int iswave = 0;
    if (num < 100) return 0;
    int a = num % 10;
    num /= 10;
    int b = num % 10;
    int c = (num / 10) % 10;
    if (a < b && b > c || a > b && b < c) iswave++;
    return iswave + waviness(num);
}

int totalWaviness(int num1, int num2) {
    int out = 0;
    for (int n = num1; n <= num2; n++) out += waviness(n);
    return out;
}