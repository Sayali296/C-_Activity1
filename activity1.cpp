#include <iostream>
#include <vector>  // Include the vector library

using namespace std;

int main() {
    vector<int> numbers; // Declare an empty vector of integers

    // Add elements using push_back
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements
    cout << "First Element: " << numbers[0] << endl; // Outputs 10

    // Display all elements using a loop
    cout << "Vector Elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    // Remove last element
    numbers.pop_back(); // Removes 30

    cout << "\nSize of Vector: " << numbers.size() << endl; // Outputs 2

    return 0;
}
