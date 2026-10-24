class Solution {
public:
    int returnDay(string date)
    {
        int day = stoi(date.substr(3, 2));
        return day;
    }

    int returnMonth(string date)
    {
        int month = stoi(date.substr(0, 2));
        return month;

    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) 
    {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix(13);

        prefix[0] = 0;
        for(int i=0; i<12; i++)
        {
            prefix[i+1] = prefix[i] + months[i];
        }

        int arriveA = prefix[returnMonth(arriveAlice)-1] + returnDay(arriveAlice);
        int leaveA = prefix[returnMonth(leaveAlice)-1] + returnDay(leaveAlice);
        int arriveB = prefix[returnMonth(arriveBob)-1] + returnDay(arriveBob);
        int leaveB = prefix[returnMonth(leaveBob)-1] + returnDay(leaveBob);
        int later_arrival_date, before_leave_date;

        later_arrival_date = max(arriveA, arriveB);
        before_leave_date = min(leaveA, leaveB);

        int days_spent = before_leave_date - later_arrival_date + 1;
        if(days_spent < 0)
        {
            return 0;
        }
        return days_spent;

    }
};