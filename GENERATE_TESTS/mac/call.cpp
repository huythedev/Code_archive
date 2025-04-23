#include <bits/stdc++.h>
#ifdef _WIN32
#include <direct.h>
#define CREATE_DIR(path) _mkdir(path)
#else
#include <sys/stat.h>
#define CREATE_DIR(path) mkdir(path, 0777)
#endif
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

    cout << "Enter the name of the executable file (without extension): ";
    getline(cin, task);

    string parentDir = task + "_testcases";

    // Remove file if it exists and is not a directory
    struct stat st;
    if (stat(parentDir.c_str(), &st) == 0 && !S_ISDIR(st.st_mode)) {
        remove(parentDir.c_str());
    }
    if (CREATE_DIR(parentDir.c_str()) != 0 && errno != EEXIST) {
        cerr << "Failed to create parent directory: " << parentDir << "\n";
        return 1;
    }

    string taskFile = "./" + task; // No .exe extension on macOS

    auto start = high_resolution_clock::now();

    for (int i = 1; i <= numOfTest; ++i) {
        auto testStart = high_resolution_clock::now(); 

        string dirName = parentDir + "/test" + to_string(i);
        if (CREATE_DIR(dirName.c_str()) != 0 && errno != EEXIST) {
            cerr << "Failed to create test directory: " << dirName << "\n";
            return 1;
        }

        string inpFile = dirName + "/" + task + ".inp";
        string outFile = dirName + "/" + task + ".out";

        string sinhinpCommand = "./sinh > " + inpFile + " " + to_string(i); // Use ./sinh for macOS
        executeCommand(sinhinpCommand);

        string taskCommand = taskFile + " < " + inpFile + " > " + outFile;
        executeCommand(taskCommand);

        // Đo thời gian kết thúc của test case
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
