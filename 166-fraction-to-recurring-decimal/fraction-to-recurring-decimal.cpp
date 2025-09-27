class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
       string result = "";
        unordered_map<int, int>mp;
        if(numerator == 0){
            return "0";
        }
         if ((long long)numerator * (long long)denominator < 0){
             result += "-"; 
             }
        // agr numerator or denominator mei se koi -ve hai toh usko +ve bna do
        long long absDenominator = labs(denominator);
        long long absNumerator = labs(numerator);
        long long value = absNumerator / absDenominator;
        result += to_string(value);
        long long remain = absNumerator % absDenominator;
        if(remain == 0){
            return result;
        }
        result += ".";
        while(remain != 0){
            if(mp.find(remain) != mp.end()){
                result.insert(mp[remain], "(");
                result += ")";
                break;
            }
        
        mp[remain] = result.size();
        remain *= 10;
        result += to_string(remain / absDenominator);
        //again reminder
        remain %= absDenominator;
        }
        return result;
    }
};