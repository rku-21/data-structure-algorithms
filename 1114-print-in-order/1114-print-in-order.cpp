#include<mutex>
#include<condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;

class Foo {
public:
   int turn;
    Foo() {
        this->turn=1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> lck(mtx);
        turn=2;
        printFirst();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lck(mtx);
        
        cv.wait(lck, [&]{
            return this->turn==2;
        });
        turn=3;

        printSecond();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lck(mtx);
        cv.wait(lck , [&]{
            return this->turn == 3;
        });
        turn =1;
        printThird();
        cv.notify_all();
    }
};