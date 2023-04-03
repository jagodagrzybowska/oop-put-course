// oop-lab-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Running
{
public:
    Running() {};
    virtual ~Running(){}
    virtual Running *AveragePace(float time, float distance) = 0;
    virtual string TimeUnit() = 0;
};

class Pace : public Running
{
private: 
    float time;
    float distance;
public: 
    float Value() { return time / distance; }
    Pace *AveragePace(float time, float distance) { return new Pace (time, distance); }
    string TimeUnit() { return "minutes"; }
    Pace(float time, float distance) {
        this->time = time;
        this->distance = distance;
    }
};

int main()
{
    Pace runnersTime(20.35f, 8.0f);
    Pace *runnersPace = runnersTime.AveragePace(5.0f, 6.9f);
    cout << runnersPace->Value() << endl;
    return 0;
}


