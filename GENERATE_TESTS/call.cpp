#include <bits/stdc++.h>
#include <direct.h>
#include <chrono> 

using namespace std;
using namespace chrono;

void executeCommand(const string& command) {
    int ret = system(command.c_str());
    if (ret != 0) {
        cerr << "Command failed: " << command << "\n";
        exit(1);
    }
}

int main() {
    int numOfTest;
    string task;

    cout << "Enter number of tests: ";
    cin >> numOfTest;
    cin.ignore();

    cout << "Enter the name of the executable file (without .exe): ";
    getline(cin, task);

    string taskFile = task + ".exe";

    // Create the main directory using the task name
    string mainDir = task;
    _mkdir(mainDir.c_str());

    auto start = high_resolution_clock::now();

    for (int i = 1; i <= numOfTest; ++i) {
        auto testStart = high_resolution_clock::now(); 

        // Create subdirectory for each test case
        string dirName = mainDir + "/test" + to_string(i);
        _mkdir(dirName.c_str());

        string inpFile = dirName + "/" + task + ".inp";
        string outFile = dirName + "/" + task + ".out";

        string sinhinpCommand = "sinh.exe > " + inpFile + " " + to_string(i);
        executeCommand(sinhinpCommand);

        string taskCommand = taskFile + " < " + inpFile + " > " + outFile;
        executeCommand(taskCommand);

        // Measure the time taken for each test case
        auto testEnd = high_resolution_clock::now();
        auto testDuration = duration_cast<milliseconds>(testEnd - testStart);

        cout << "Generated test case " << i << " in " << dirName
             << " (Time taken: " << testDuration.count() << " ms)" << "\n";
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "All test cases generated successfully.\n";
    cout << "Total time taken: " << duration.count() << " ms\n";

    return 0;
}
