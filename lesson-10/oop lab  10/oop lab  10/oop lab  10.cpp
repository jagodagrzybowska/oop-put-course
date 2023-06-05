// oop lab  10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atomic>
#include <thread>
#include <string>
#include <vector>

using namespace std;

atomic<int> a(0);
atomic<int> c(0);
atomic<int> g(0);
atomic<int> t(0);

void nucleotides(string sequence, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        char n = sequence[i];
        if (n == 'A')
            ++a;
        else if (n == 'C')
            ++c;
        else if (n == 'G')
            ++g;
        else if (n == 'T')
            ++t;
    }
}

int main()
{
    string sequence;
    cout << "Enter the sequence: ";
    cin >> sequence;

    int num_thread;
    cout << "Enter the number of threads: ";
    cin >> num_thread;

    int seq_length = (int)sequence.length();
    int seq_divide = seq_length / num_thread;
    vector<thread> threads;

    for (int i = 0; i < num_thread; ++i)
    {
        int start = i * seq_divide;
        int end = start + seq_divide;
        threads.emplace_back(nucleotides, sequence, start, end);
    }

    for (auto& t : threads)
    {
        t.join();
    }


    cout << "A total frequency: " << a << endl;
    cout << "C total frequency: " << c << endl;
    cout << "G total frequency: " << g << endl;
    cout << "T total frequency: " << t << endl;
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
