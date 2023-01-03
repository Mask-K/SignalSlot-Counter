#pragma once
#include <QObject>
#include <iostream>

class Counter : public QObject {
    Q_OBJECT
public:
    Counter(int startValue, unsigned id) : m_count(startValue), id(id){};
    int Increment();
    int Decrement();
    int Get() const{
        return m_count;
    }
    unsigned GetId()const{
        return id;
    }


public slots:
    void Increase();
    void Decrease();

signals:
    void wasIncreased();
    void wasDecreased();

private:
    int m_count;
    unsigned id;
};
