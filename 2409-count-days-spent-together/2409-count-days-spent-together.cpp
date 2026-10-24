class Solution {
public:
    int convert(string date) {
        int daysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));

        for(int i=0;i<month-1;i++) {
            day+=daysInMonth[i];
        }
        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a=convert(arriveAlice);
        int b=convert(leaveAlice);
        int c=convert(arriveBob);
        int d=convert(leaveBob);

        int start=max(a,c);
        int end=min(b,d);
        return max(0,end-start+1);
    }
};