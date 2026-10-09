#include<mutex>
#include<condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;

class FizzBuzz {
private:
    int n;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
       while(i<=n){
            unique_lock<mutex> lck(mtx);
            while(i<=n && (i% 3 ==0 && i %5 !=0 ) ==0) {
                cv.wait(lck);

            }
            if(i>n) break;
            printFizz();
            i++;
            cv.notify_all();
            
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
         while(i<=n) {
            unique_lock<mutex> lck(mtx);

            while(i<=n && (i % 5 ==0 && i%3 !=0) ==0 ){

                cv.wait(lck);
            }
              if(i>n) break;
            printBuzz();
            i++;
            cv.notify_all();
         }
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
         while(i<=n){
            unique_lock<mutex> lck(mtx);

            while(i<=n && (i % 3 ==0 && i % 5 ==0) ==0){
                cv.wait(lck);
            }
              if(i>n) break;
            printFizzBuzz();
            i++;
            cv.notify_all();
         }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lck(mtx);
            
            while(i<=n && (i % 3 !=0 && i % 5 !=0) == 0) {
                cv.wait(lck);
            }
            if(i>n) break;
            printNumber(i++);
            
            cv.notify_all();
        }
        
    }
};