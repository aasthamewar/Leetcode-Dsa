class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr1=stoi(startTime.substr(0,2));
        int min1=stoi(startTime.substr(3,2));
        int sec1=stoi(startTime.substr(6,2));
        int first=3600*hr1+60*min1+sec1;
        int hr2=stoi(endTime.substr(0,2));
        int min2=stoi(endTime.substr(3,2));
        int sec2=stoi(endTime.substr(6,2));

        int second=3600*hr2+60*min2+sec2;
        return second-first;
    }
};