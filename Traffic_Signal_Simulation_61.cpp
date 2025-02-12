#include <iostream>

using namespace std;

class TrafficSignal {
private:
    int signal_Id;
    string state;

public:
    // Parameterized Constructor
    TrafficSignal(int id) {
        signal_Id = id;
        state = "Red";  // Default state
    }

    // Function to change state
    void changeState() {
        if (state == "Red")
            state = "Green";
        else if (state == "Green")
            state = "Yellow";
        else
            state = "Red";
    }

    // Function to display signal state
    void displayState() {
        cout << "Signal ID: " << signal_Id << " - State: " << state << endl;
    }
};

int main() {
    const int numSignals = 3;  // Define number of signals
    TrafficSignal signals[numSignals] = { TrafficSignal(1), TrafficSignal(2), TrafficSignal(3) };

    // Simulate traffic signal changes
    for (int cycle = 0; cycle < 5; ++cycle) {  // Run for 5 cycles
        cout << "Traffic Signal System State (Cycle " << cycle + 1 << "):\n";
        for (int i = 0; i < numSignals; ++i) {
            signals[i].displayState();  // Show current state
            signals[i].changeState();   // Change state
        }
        cout << "--------------------------------------\n";
    }

    return 0;
}
