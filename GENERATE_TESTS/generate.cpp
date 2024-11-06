#include <bits/stdc++.h>
#ifdef _WIN32
#include <direct.h>  // Header for Windows-specific functions
#define CREATE_DIR(path) _mkdir(path)  // Create directory on Windows
#else
#include <sys/stat.h>  // Header for POSIX-specific functions
#define CREATE_DIR(path) mkdir(path, 0777)  // Create directory on Linux/macOS with 0777 permissions
#endif

// Fast I/O settings for C++ to improve performance
#define thanchu() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long  // Use long long type for large integer values
using namespace std;

mt19937_64 rd(random_device{}());  // Random number generator initialized using random_device

// Function to calculate the greatest common divisor (GCD) of two numbers using Euclid's algorithm
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);  // Swap the values of a and b
    }
    return a;  // Return the GCD
}

// Function to generate a random number between l and r (inclusive)
ll random(ll l, ll r) { 
    return rd() % (r - l + 1) + l;  // Return a random number in the range [l, r]
}

// Function to generate a test case and write it to a file
void makeTest(const string &folderPath, const string &task)
{
    ofstream out(folderPath + "/" + task + ".INP");  // Create an input file for the test case

    int t = random(1, 20);  // Randomly choose the number of test cases (between 1 and 20)
    out << t << "\n";  // Write the number of test cases to the input file

    while (t--) {  // For each test case
        ll k = random(1, 1e12);  // Generate a random number k (up to 10^12)
        out << k << "\n";  // Write the generated number to the input file
    }

    out.close();  // Close the input file after writing
}

// Function to run an executable and transfer input/output between folders for testing
void run_exe(const string &folderPath, const string &task, int osType)
{
    // Copy input file from the generated folder to the current directory
    ifstream src(folderPath + "/" + task + ".INP", ios::binary);
    ofstream dst(task + ".INP", ios::binary);
    dst << src.rdbuf();  // Copy the contents of the input file
    src.close();
    dst.close();

    // Run the executable depending on the OS type
    if (osType == 1) {  // For macOS/Linux
        system(("./" + task).c_str());
    } else if (osType == 2) {  // For Windows
        system((task).c_str());
    }

    // Copy output file from the current directory to the generated folder
    ifstream src_out(task + ".OUT", ios::binary);
    ofstream dst_out(folderPath + "/" + task + ".OUT", ios::binary);
    dst_out << src_out.rdbuf();  // Copy the contents of the output file
    src_out.close();
    dst_out.close();

    // Remove the temporary input/output files from the current directory
    remove((task + ".INP").c_str());
    remove((task + ".OUT").c_str());
}

// Function to create a directory
bool createDirectory(const string &path) { 
    return CREATE_DIR(path.c_str()) == 0;  // Returns true if the directory was created successfully
}

// Function to validate the output by checking if the numbers in the output are non-negative
bool isValidOutput(const string &folderPath, const string &task) {
    ifstream outputFile(folderPath + "/" + task + ".OUT");
    ll m, n;
    outputFile >> m >> n;  // Read the two values from the output file
    return m >= 0 && n >= 0;  // Return true if both values are non-negative
}

int main()
{
    thanchu();  // Enable fast I/O
    srand(time(0));  // Seed the random number generator
    rd.seed(rand());  // Further seed the random device

    int osType;
    cout << "Enter 1 for macOS/Linux or 2 for Windows: ";
    cin >> osType;  // Prompt user to choose OS type (1 for macOS/Linux, 2 for Windows)

    string task = "CANARIUM", folderName;
    cout << "Enter folder name: ";
    cin >> folderName;  // Prompt user to input a folder name

    int n;
    cout << "Enter the number of test cases you want to create: ";
    cin >> n;  // Prompt user to input the number of test cases to generate

    string parentFolder = folderName;

    // Check if the OS is Windows or Unix-like (Linux/macOS) and remove the parent folder accordingly
    if (osType == 2) {  // Windows
        system(("rmdir /s /q " + parentFolder).c_str());  // Remove the folder and its contents on Windows
    } else {  // Linux/macOS
        system(("rm -rf " + parentFolder).c_str());  // Remove the folder and its contents on Linux/macOS
    }
    createDirectory(parentFolder);  // Create the parent folder

    string baseName = "Test";  // Base name for the generated test folders

    // Loop through the number of test cases to generate
    for (int i = 1; i <= n; i++)
    {
        // Generate a folder name for each test case (e.g., Test01, Test02, etc.)
        string folderName = baseName + (i < 10 ? "0" : "") + to_string(i);
        string folderPath = parentFolder + "/" + folderName;

        // Try to create the test case folder
        if (createDirectory(folderPath))
        {
            // Just use it if needed
            // bool validTest = false;
            // // Keep generating tests until a valid output is obtained
            // while (!validTest) {
            //     makeTest(folderPath, task);  // Generate a new test case
            //     run_exe(folderPath, task, osType);  // Run the executable with the test case
            //     validTest = isValidOutput(folderPath, task);  // Check if the output is valid
            // }
            cerr << "Generated valid test " << i << " in folder " << folderPath << "\n";  // Output confirmation
        }
        else
        {
            cout << "Failed to create directory: " << folderPath << "\n";  // Error message if folder creation fails
        }
    }

    cout << "DONE.\n";  // Indicate that the process is finished
    return 0;  // Exit the program
}
