class Solution {
public:
    
    bool checkDivisibility(int n) {

        int product=1;
        int sum=0;
        int num=n;

        while(n){
            int rem=n%10;
            sum+=rem;
            product*=rem;

            n/=10;
        }

        return num %(sum+product)==0;

      




        
    }
};