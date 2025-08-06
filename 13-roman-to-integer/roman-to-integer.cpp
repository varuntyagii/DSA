class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        // Get value of current Roman numeral
        int current = 0, next = 0;

        // Value of current
        if (s[i] == 'I') current = 1;
        else if (s[i] == 'V') current = 5;
        else if (s[i] == 'X') current = 10;
        else if (s[i] == 'L') current = 50;
        else if (s[i] == 'C') current = 100;
        else if (s[i] == 'D') current = 500;
        else if (s[i] == 'M') current = 1000;

        // Value of next (if exists)
        if (i + 1 < n) {
            if (s[i + 1] == 'I') next = 1;
            else if (s[i + 1] == 'V') next = 5;
            else if (s[i + 1] == 'X') next = 10;
            else if (s[i + 1] == 'L') next = 50;
            else if (s[i + 1] == 'C') next = 100;
            else if (s[i + 1] == 'D') next = 500;
            else if (s[i + 1] == 'M') next = 1000;
        }

        // Subtraction case
        if (current < next) {
            total -= current;
        } else {
            total += current;
        }
    }

    return total;
    }
};