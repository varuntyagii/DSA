class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int h = 0; h <= 11; h++){
            for(int m = 0; m <= 59; m++){
           int hcount = h, mcount = m;
                int hbits = 0, mbits = 0;
                while(hcount){
                    hcount = hcount & (hcount - 1);
                    hbits++;
                }
                while(mcount){
                    mcount = mcount & (mcount - 1);
                    mbits++;
                }

                if(mbits + hbits == turnedOn){
                 string hour = to_string(h);
                    string min = (m < 10 ? "0" : "") + to_string(m);
                 ans.push_back(hour + ":" +  min);
                }

            }
        }
        return ans;
    }
};