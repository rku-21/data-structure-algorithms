class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int dayCount[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int alice_in_month  = stoi(arriveAlice.substr(0,2));
        int alice_in_day = stoi(arriveAlice.substr(3,2));

        int alice_out_month = stoi(leaveAlice.substr(0,2));
        int alice_out_day = stoi(leaveAlice.substr(3,2));


        int bob_in_month = stoi(arriveBob.substr(0,2));
        int bob_in_day = stoi(arriveBob.substr(3,2));

        int bob_out_month = stoi(leaveBob.substr(0,2));
        int bob_out_day = stoi(leaveBob.substr(3,2));

        int month_start = max(alice_in_month, bob_in_month);
        int month_end = min(alice_out_month, bob_out_month);
       
        if(month_start > month_end) return 0;

        int day_start;
        int day_end;
        if(alice_in_month > bob_in_month) {
            day_start = alice_in_day;
        }
        else if(alice_in_month < bob_in_month){
            day_start = bob_in_day;
        }
        else day_start = max(alice_in_day, bob_in_day);
        
        if(alice_out_month  < bob_out_month) {
            day_end = alice_out_day;
        }
        else if(alice_out_month > bob_out_month){
            day_end = bob_out_day;
        }
        else day_end  = min(alice_out_day, bob_out_day);

         if(month_start == month_end) {

            return max(0,day_end - day_start +1);
        }
        cout<<"here";

        int  ans = dayCount[month_start-1]- day_start +1;
        for(int i=month_start+1; i<month_end; i++) {
            ans+=dayCount[i-1];
        }
        ans+=day_end;
        return ans;


        




       

        




        
    }
};