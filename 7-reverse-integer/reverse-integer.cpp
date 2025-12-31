class Solution {
public:
    int reverse(int x) {
        int neg = (x < 0 ? -1 : 1);
        if (x == -2147483648) {
            return 0;
        }
        else if (x < 0) x *= -1;
        int digit_place = 1;
        int N = 0;
        bool at_lim = false;
        while (x / digit_place >= ((at_lim ? 10 : 1))) {
            cout << digit_place << endl;
            if (N < 9) {                
                digit_place *= 10;
            }
            else {
                if (at_lim) {
                    return 0;
                }
                at_lim = true;
            }
            N += 1;
            cout << "N:" << N << endl;
        }
        if (N <= 9) {
            digit_place/=10;
        }
        deque<int> digits;        
        for (int i = 0; i < N; i++) {
            int digit = x/digit_place;
            cout << digit << endl;
            x %= digit_place;
            digit_place /= 10;
            // if (i < 9) {
            //     x *= 10;
            // } else {
            //     break;
            // }
            digits.push_front(digit);
        }
        int out = 0;
        at_lim = false;
        for (int digit : digits) {
            cout << digit << endl;
            out += digit;
            if (out <= 214748364) out *= 10;
            else {
                if(at_lim == true) {
                    return 0;
                } 
                if (digit >= 7 && out == 214748364) {
                    return 0;
                }
                at_lim = true;
                continue;
            }
        }
        if (at_lim) return neg*out;
        else return neg*out/10;
    }
};