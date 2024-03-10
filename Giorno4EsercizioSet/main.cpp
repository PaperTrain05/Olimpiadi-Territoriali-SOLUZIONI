#include <bits/stdc++.h>

using namespace std;

int countFullyVaccinated(unordered_set<int> firstDose, unordered_set<int> secondDose) {
    int count = 0;
    for (auto id : secondDose) {
        if (firstDose.count(id)) {
            count++;
        }
    }
    return count;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N1, N2;
    inputFile >> N1 >> N2;

    unordered_set<int> firstDose;
    unordered_set<int> secondDose;

    int id;
    for (auto i = 0; i < N1; ++i) {
        inputFile >> id;
        firstDose.insert(id);
    }

    for (auto i = 0; i < N2; ++i) {
        inputFile >> id;
        secondDose.insert(id);
    }

    int fullyVaccinated = countFullyVaccinated(firstDose, secondDose);
    outputFile << fullyVaccinated << endl;

    return 0;
}
