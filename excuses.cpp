#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    // Ask for student name
    cout << "Enter student name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return 0;
    }

    // Store at least 10 excuses
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop installed updates for hours.",
        "{name} tried finishing the homework, but the Wi-Fi suddenly disappeared.",
        "{name} was about to submit the assignment when the file got deleted.",
        "{name}'s laptop battery died just before completion.",
        "{name} worked hard, but the system crashed unexpectedly.",
        "{name} couldn't complete the work due to a sudden power cut.",
        "{name} tried finishing the assignment, but the keyboard stopped working.",
        "{name} was ready to submit when the internet stopped responding.",
        "{name} saved the file, but it got corrupted somehow.",
        "{name} couldn't complete the assignment because the software froze."
    };

    // Generate random excuse
    srand(time(0));
    int index = rand() % excuses.size();
    string excuse = excuses[index];

    // Replace {name} with actual input
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    // Display result
    cout << "\n📌 Excuse: " << excuse << endl;

    return 0;
}