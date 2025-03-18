# C-_Activity1
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void trafficSignal() {
    while (true) {
        cout << "RED LIGHT - STOP" << endl;
        this_thread::sleep_for(chrono::seconds(5));

        cout << "YELLOW LIGHT - GET READY" << endl;
        this_thread::sleep_for(chrono::seconds(2));

        cout << "GREEN LIGHT - GO" << endl;
        this_thread::sleep_for(chrono::seconds(5));

        cout << "---------------------------" << endl;
    }
}

int main() {
    cout << "Traffic Signal Simulation\n";
    cout << "---------------------------\n";
    trafficSignal();

    return 0;
}
