#include <QCoreApplication>
#include <iostream>

#include "Counter.h"



void Print(const Counter& c1, const Counter& c2){
    std::cout << "counter" << c1.GetId() << " val " << c1.Get() << " "
              << "counter" << c2.GetId() << " val " << c2.Get() << std::endl;
}



int main()
{
    //QCoreApplication a(argc, argv);

    Counter count1(5, 0), count2(14, 1);
    bool res1 = QObject::connect(&count1, &Counter::wasIncreased, &count2, &Counter::Increase);
    bool res2 = QObject::connect(&count2, &Counter::wasIncreased, &count1, &Counter::Increase);
    bool res3 = QObject::connect(&count1, &Counter::wasDecreased, &count2, &Counter::Decrease);
    bool res4 = QObject::connect(&count2, &Counter::wasDecreased, &count1, &Counter::Decrease);


    if(!res1 || !res2 || !res3 || !res4)
        return -1;

    std::cout << "Starting values are ";
    Print(count1, count2);
    count1.Increment();
    Print(count1, count2);
    count2.Increment();
    Print(count1, count2);
    count1.Decrement();
    Print(count1, count2);
    count2.Decrement();
    Print(count1, count2);

    return 0;
}
