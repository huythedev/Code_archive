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

string random_big_number(int min_digits, int max_digits) {
    string result;
    int len = random(min_digits, max_digits);
    
    // First digit (non-zero)
    result += char(random(1, 9) + '0');
    
    // Remaining digits
    for (int i = 1; i < len; i++) {
        result += char(random(0, 9) + '0');
    }
    
    return result;
}
// Function to generate a test case and write it to a file
void makeTest(const string &folderPath, const string &task)
{
    ofstream out(folderPath + "/" + task + ".INP");

    // Generate number between 10^50 and 10^(1e7)
    string num = random_big_number(50, (int)1e7);
    out << num << "\n";

    out.close();
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

    string task = "MATMA", folderName;
    cout << "Enter folder name: ";
    cin >> folderName;  // Prompt user to input a folder name

    int n;
    cout << "Enter the number of test cases you want to create: ";
    cin >> n;  // Prompt user to input the number of test cases to generate

    string parentFolder = folderName;

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
