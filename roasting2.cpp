#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // for random_shuffle / shuffle
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return 0;
    }

    vector<string> roasts = {
        "[name]'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be [name].",
        "[name] doesn’t debug code — they negotiate with bugs.",
        "[name]'s logic is like WiFi in a basement — weak and unreliable.",
        "If procrastination were an Olympic sport, [name] would win gold.",
        "[name] writes code like it's a mystery novel — no one understands it.",
        "[name]'s brain has too many tabs open and none are responding.",
        "Even AI needs extra time to understand [name]'s code.",
        "[name] treats deadlines like suggestions.",
        "[name]'s code has more drama than a TV serial."
    };

    srand(time(0));

    // Shuffle roasts to avoid repetition
    random_shuffle(roasts.begin(), roasts.end());

    int index = 0;
    char choice;

    do {
        // If all roasts are used, reshuffle again
        if (index == roasts.size()) {
            random_shuffle(roasts.begin(), roasts.end());
            index = 0;
        }

        string roast = roasts[index++];

        // Replace [name] with actual name
        size_t pos = roast.find("[name]");
        while (pos != string::npos) {
            roast.replace(pos, 6, name);
            pos = roast.find("[name]");
        }

        cout << "\n🔥 Roast: " << roast << endl;

        cout << "\nDo you want to change the roast? (Y/N): ";
        cin >> choice;
        choice = tolower(choice);

    } while (choice == 'y');

    cout << "\nNo more roasting 😌" << endl;

    return 0;
}