#ifndef MyClass_H
#define MyClass_H

#include <iostream>
#include <thread>
using namespace std;
class MyClass
{
public:
    void LongFunction()

    {
        for (int count = 0; count < 5; count++)
        {
            //sleep(1);
            this_thread::sleep_for(chrono::seconds(1));
            std::cout << "Ping long!" << std::endl;
        }
    }
};

#endif
