#include "Counter.h"


int Counter::Increment(){
    std::cout << "Increment() called for counter" << id << std::endl;
    emit wasIncreased();
    return ++m_count;
}

int Counter::Decrement(){
    std::cout << "Decrement() called for counter" << id << std::endl;
    emit wasDecreased();
    return --m_count;
}

void Counter::Increase()
{
    std::cout << "Slot Increase() was called for counter" << id << std::endl;
    ++m_count;
}

void Counter::Decrease(){
    std::cout << "Slot Increase() was called for counter" << id << std::endl;
    --m_count;
}
