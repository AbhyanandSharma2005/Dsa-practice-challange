class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>king;
        for(int hour=0;hour<12;hour++){
            for(int minutes=0;minutes<60;minutes++){
                int totaltime=__builtin_popcount(hour)+__builtin_popcount(minutes);
                if(totaltime==turnedOn){
                    string time;
                    if(minutes<10){
                        time=to_string(hour)+":0"+to_string(minutes);
                    }else{
                        time=to_string(hour)+":"+to_string(minutes);
                    }
                    king.push_back(time);
                }
            }
        }
        return king;
    }
};