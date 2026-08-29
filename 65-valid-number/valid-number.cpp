class Solution {
public:
    bool isNumber(string s) {

        if (s == "inf" || s == "-inf" || s == "+inf" ||  s == "+Infinity" ||
            s == "-Infinity" || s == "Infinity" || s == "infinity" ||
            s == "nan" || s == "0x11")
            return false;

        char* end; // address ko store krega 

        strtod(s.data(), &end);

        return end != s.c_str() && *end == '\0';
    }
};