/* بسم الله الرحمن الرحيم */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <cmath>
#include <windows.h>
#include <cstdio>
#include <iomanip>
#include <numeric>
#include <cctype>
#include <fstream>
#include <random>
#include <ctime>
#include <chrono>
#include "clsDate.h"
#include "clsUtil.h"

#ifndef PROGRAM_H
#define PROGRAM_H

#include "C:\Users\qusai\Algo4\program.h"

// Add other declarations if needed

#endif // MYPROGRAM_H

using namespace std;

bool isPrime(int num) {
    // تحقق مما إذا كان الرقم هو عدد أولي أم لا
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimesUpToN(int N) {
    // طباعة الأعداد الأولية من 1 إلى N
    for (int i = 1; i <= N; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

bool isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

void printClassification(int num) {
    if (isPerfect(num)) {
        std::cout << num << " Perfect number." << std::endl;
    } else {
        std::cout << num << " not perf number." << std::endl;
    }
}

bool isPerfectUntelN(int num) {
    int sum = 1; 
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

void generateWords() {
    for (char i = 'A'; i <= 'Z'; ++i) {
        for (char j = 'A'; j <= 'Z'; ++j) {
            for (char k = 'A'; k <= 'Z'; ++k) {
                std::cout << i << j << k << std::endl;
            }
        }
    }
}

void guessPassword(const std::string& password) {
    bool found = false;
    int attempts = 0;

    for (char i = 'A'; i <= 'Z'; ++i) {
        for (char j = 'A'; j <= 'Z'; ++j) {
            for (char k = 'A'; k <= 'Z'; ++k) {
                ++attempts;
                std::string guess = {i, j, k};
                std::cout << "Trial [" << attempts << "]: " << guess << std::endl;
                if (guess == password) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) break;
    }

    if (found) {
        std::cout << "Password is " << password << std::endl 
         << "Found after " << attempts << " Trial(s)" << std::endl;
    } else {
        std::cout << "Password not found" << std::endl;
    }
}

std::string encrypt(const std::string& text, int shift) {
    std::string result = "";
    for (char c : text) {
        if (std::isalpha(c)) {
            char shifted = (std::isupper(c)) ? 'A' + (c - 'A' + shift) % 26 : 'a' + (c - 'a' + shift) % 26;
            result += shifted;
        } else {
            result += c;
        }
    }
    return result;
}

// Function to decrypt the text using a Caesar cipher
std::string decrypt(const std::string& text, int shift) {
    return encrypt(text, 26 - shift); // Decrypting is essentially shifting backwards
}

std::vector<int> generateRandomNumbers() {
    std::vector<int> numbers;
    for (int i = 1; i <= 10; ++i) {
        numbers.push_back(i);
    }

    std::random_shuffle(numbers.begin(), numbers.end());
    std::vector<int> result(numbers.begin(), numbers.begin() + 3);
    return result;
}

char getRandomLowerCase() {
    return 'a' + std::rand() % 26;
}

char getRandomUpperCase() {
    return 'A' + std::rand() % 26;
}

char getRandomSpecialChar() {
    char specialChars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    return specialChars[std::rand() % (sizeof(specialChars) - 1)];
}

char getRandomDigit() {
    return '0' + std::rand() % 10;
}

std::string generateKey() {
    std::string key;
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int keyLength = 16;

    for (int i = 0; i < keyLength; ++i) {
        key += charset[std::rand() % (sizeof(charset) - 1)];
        if ((i + 1) % 4 == 0 && i != keyLength - 1) {
            key += '-';
        }
    }

    return key;
}

void AddArrayElement(int* arr, int& size, int element) {
    arr[size++] = element;
}

bool isPalindrome(const std::vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int myAbs(int num) {
    return num < 0 ? -num : num;
}

int myRound(double num) {
    if (num < 0) {
        return int(num - 0.5);
    } else {
        return int(num + 0.5);
    }
}

int myFloor(double num) {
    if (num >= 0) {
        return int(num);
    } else {
        int intPart = int(num);
        return (num == intPart) ? intPart : intPart - 1;
    }
}

int myCeil(double num) {
    int intPart = int(num);
    if (num > 0 && num != intPart) {
        return intPart + 1;
    }
    return intPart;
}

// Custom square root function without using sqrt
double mySqrt(double num) {
    if (num == 0 || num == 1) {
        return num;
    }

    double precision = 0.00001; // Set the precision
    double x = num;
    double y = 1;

    // Iterative approach to find square root
    while (x - y > precision) {
        x = (x + y) / 2;
        y = num / x;
    }
    return x;
}

namespace Color {
    const std::string GREEN = "\033[1;32m";
    const std::string RED = "\033[1;31m";
    const std::string YELLOW = "\033[1;33m";
    const std::string RESET = "\033[0m";
}

void ringBell() {
    // Function to ring the bell (sound notification)
    std::cout << "\a";
}

int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

char getRandomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[rand() % 4];
}

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int calculate(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

void setColor(int color) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
#else
    std::cout << "\033[" << color << "m";
#endif
}

void resetColor() {
#ifdef _WIN32
    setColor(7);
#else
    std::cout << "\033[0m";
#endif
}

void askQuestion(int level) {
    int num1, num2;
    char operators[] = {'+', '-', '*', '/'};
    char op = operators[rand() % (level + 1)];

    num1 = rand() % (level * 10);
    num2 = rand() % (level * 5) + 1;

    int result = calculate(num1, num2, op);

    int answer;
    std::cout << "What is " << num1 << " " << op << " " << num2 << "? ";
    std::cin >> answer;

    if (answer == result) {
        setColor(10); // Green color
        std::cout << "Correct!" << "\a" << std::endl;
    } else {
        setColor(12); // Red color
        std::cout << "Wrong! The correct answer is " << result << std::endl;
    }

    resetColor();
}

void printNumbers(int M, int N) {
    if (M >= N) {
        std::cout << M << " ";
        printNumbers(M - 1, N);
    }
}

int power(int N, int M) {
    if (M == 0) {
        return 1;
    } else {
        return N * power(N, M - 1);
    }
}

void printtable(){
cout << "---------|--------------------------------|---------|"<<endl;    
cout << "  Code   |               Name             |   Mark  |"<<endl;
cout << "---------|--------------------------------|---------|"<<endl;

cout << setw(9) << "C101" << "|" << setw(32) << "introduction to Programming 1" << "|" << setw(9) << "95" << "|" << endl;
cout << setw(9) << "C102" << "|" << setw(32) << "Computer Hardware" << "|" << setw(9) << "88" << "|" << endl;
cout << setw(9) << "C1035243" << "|" << setw(32) << "Network" << "|" << setw(9) << "75" << "|" << endl;
cout <<"---------|--------------------------------|---------|" << endl;
}

struct Employee {
    static int nextID;
    int employeeID;
    std::string firstName;
    std::string lastName;
    double salary;
    // Add other details if needed (e.g., department, etc.)
};

int Employee::nextID = 1;

bool isIDExists(const std::vector<Employee>& employees, int id) {
    for (const auto& emp : employees) {
        if (emp.employeeID == id) {
            return true; // ID exists
        }
    }
    return false; // ID doesn't exist
}

void printHorizontalLine(int width) {
    for (int i = 0; i < width; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void printData(const std::string& data, int width) {
    std::cout << "|" << std::setw(width) << std::left << data;
}

void swap(int *n1, int *n2) {
int temp;
temp = *n1;
*n1 = *n2;
*n2 = temp;
}

void PrintFileContenet(string FileName){
fstream MyFile;
MyFile.open( FileName, ios ::in);//read Mode
if (MyFile.is_open()){
string Line;
while (getline(MyFile, Line))
{
cout << Line << endl;
}
MyFile.close();
}
}

void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
fstream MyFile;
MyFile.open(FileName, ios :: in);//read Mode
if (MyFile.is_open()){
string Line;
while (getline(MyFile, Line)){
vFileContent.push_back(Line);
MyFile.close();
}
}
}

void SaveVectorToFile(string FileName, vector <string> vFileContent){
fstream MyFile;
MyFile.open("MyFile.txt",ios::out);
if (MyFile. is_open()){
for (string Line : vFileContent){
if (Line != ""){
MyFile << Line << endl;
}
MyFile.close();
}}}

void DeleteRecordFromFile(string FileName, string Record) {
    vector<string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);
    for (string &Line : vFileContent) {
        if (Line == Record) {
            Line = "";
        }
    }
    SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(string FileName) {
    fstream MyFile;
    MyFile.open(FileName, ios::in); // Read Mode
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            cout << Line << endl;
        }
        MyFile.close();
    }
}

void PrintRowSums(int arr[3][3], short Rows, short Cols) {
    cout << "\nSum of each row:\n";
    for (short i = 0; i < Rows; i++) {
        int rowSum = 0;
        for (short j = 0; j < Cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }
}

void CalculateRowSums(int arr[3][3], int rowSums[3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        int rowSum = 0;
        for (short j = 0; j < Cols; j++) {
            rowSum += arr[i][j];
        }
        rowSums[i] = rowSum;
    }
}

void PrintRowSums(int rowSums[3], short Rows) {
    cout << "\nSum of each row:\n";
    for (short i = 0; i < Rows; i++) {
        cout << "Sum of row " << i + 1 << ": " << rowSums[i] << endl;
    }
}

void PrintRowsSumArray(int arr[3], short Rows){
cout << "\nThe the following are the sum of each row in the matrix: \n";
for (short i = 0; i < Rows; i++)
cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;}

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3]) {
    srand(static_cast<unsigned>(time(NULL))); // Seed the random number generator

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = rand() % 100 + 1; // Generate random numbers between 1 and 100
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

int CalculateColumnSum(int arr[3][3], short Col, short Rows) {
    int colSum = 0;
    for (short i = 0; i < Rows; i++) {
        colSum += arr[i][Col];
    }
    return colSum;
}

void PrintColumnSums(int arr[3][3], short Rows, short Cols) {
    cout << "\nSum of each column:\n";
    for (short j = 0; j < Cols; j++) {
        int colSum = CalculateColumnSum(arr, j, Rows);
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
}

void CalculateColumnSums(int arr[3][3], int colSums[3], short Rows, short Cols) {
    for (short j = 0; j < Cols; j++) {
        int colSum = 0;
        for (short i = 0; i < Rows; i++) {
            colSum += arr[i][j];
        }
        colSums[j] = colSum;
    }
}

void PrintColumnSums(int colSums[3], short Cols) {
    cout << "\nSum of each column:\n";
    for (short j = 0; j < Cols; j++) {
        cout << "Sum of column " << j + 1 << ": " << colSums[j] << endl;
    }
}

void FillOrderedMatrix(int arr[3][3]) {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = count++;
        }
    }
}

void PrintMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d   ", arr[i][j]); // Use printf to format the output
        }
        cout << "\n";
    }
}

void TransposeMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void MultiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void PrintMiddleRow(int arr[3][3]) {
    cout << "\nMiddle Row:\n";
    for (int j = 0; j < 3; j++) {
        cout << arr[1][j] << "   ";
    }
    cout << "\n";
}

void PrintMiddleColumn(int arr[3][3]) {
    cout << "\nMiddle Column:\n";
    for (int i = 0; i < 3; i++) {
        cout << arr[i][1] << "\n";
    }
}

int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols){
int Sum = 0;
for (short i = 0; i < Rows; i++){
for (short j = 0; j < Cols; j++){
Sum += Matrix1[i][j];
}}
return Sum;
}

bool AreMatricesEqual(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols){
return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
}

bool AreMatricesIdentical(int mat1[3][3], int mat2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                return false; // Matrices are not identical
            }
        }
    }
    return true; // Matrices are identical
}

bool IsIdentityMatrix(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Check if elements on the main diagonal are 1 and other elements are 0
            if ((i == j && arr[i][j] != 1) || (i != j && arr[i][j] != 0)) {
                return false; // Not an identity matrix
            }
        }
    }
    return true; // Identity matrix
}

bool IsScalarMatrix(int arr[3][3]) {
    int scalarValue = arr[0][0]; // Get the value of the first element (top-left corner)

    // Check if all elements on the main diagonal are equal to the scalar value
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == j && arr[i][j] != scalarValue) || (i != j && arr[i][j] != 0)) {
                return false; // Not a scalar matrix
            }
        }
    }
    return true; // Scalar matrix
}

int CountOccurrences(int arr[3][3], int rows, int cols, int number) {
    int count = 0;

    // Loop through the matrix and count occurrences of the given number
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == number) {
                count++;
            }
        }
    }

    return count;
}

bool IsSparseMatrix(int arr[3][3]) {
    int zeroCount = 0;
    int totalElements = 3 * 3; // Total elements in a 3x3 matrix

    // Count the number of zero elements in the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    // Calculate the ratio of zero elements to total elements
    double zeroRatio = static_cast<double>(zeroCount) / totalElements;

    // Set a threshold for sparsity (adjust as needed)
    double sparsityThreshold = 0.6; // For example, 60% zero elements

    // Check if the ratio exceeds the sparsity threshold
    return zeroRatio > sparsityThreshold;
}

bool NumberExistsInMatrix(int arr[3][3], int number) {
    // Loop through the matrix to find the number
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == number) {
                return true; // Number found
            }
        }
    }
    return false; // Number not found
}

void EnterMatrixElements(int matrix[3][3]) {
    cout << "Enter 3x3 matrix elements:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void FindIntersectedNumbers(int matrix1[3][3], int matrix2[3][3]) {
    unordered_set<int> numsSet; // Use a set to store unique numbers

    // Store elements of the first matrix in the set
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            numsSet.insert(matrix1[i][j]);
        }
    }

    cout << "\nIntersected Numbers in Both Matrices:\n";

    // Check and print common numbers from the second matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (numsSet.find(matrix2[i][j]) != numsSet.end()) {
                cout << matrix2[i][j] << " ";
                numsSet.erase(matrix2[i][j]); // Remove to avoid duplicates
            }
        }
    }
    cout << endl;
}

void FindMinMaxNumbers(int matrix[3][3]) {
    int minNum = numeric_limits<int>::max(); // Initialize min with maximum possible int value
    int maxNum = numeric_limits<int>::min(); // Initialize max with minimum possible int value

    // Find minimum and maximum numbers in the matrix
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] < minNum) {
                minNum = matrix[i][j];
            }
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
            }
        }
    }

    cout << "\nMinimum Number: " << minNum << endl;
    cout << "Maximum Number: " << maxNum << endl;
}

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool IsMatrixPalindrome(int matrix[3][3]) {
    string rowStr;

    // Check rows for palindrome
    for (int i = 0; i < 3; ++i) {
        rowStr = "";
        for (int j = 0; j < 3; ++j) {
            rowStr += to_string(matrix[i][j]);
        }
        if (!isPalindrome(rowStr)) {
            return false;
        }
    }

    // Check columns for palindrome
    for (int j = 0; j < 3; ++j) {
        rowStr = "";
        for (int i = 0; i < 3; ++i) {
            rowStr += to_string(matrix[i][j]);
        }
        if (!isPalindrome(rowStr)) {
            return false;
        }
    }

    return true;
}

void printFibonacci(int n) {
    int first = 1, second = 1, next;
    cout << first << " " << second << " "; // Print the first two numbers

    for (int i = 2; i < n; ++i) {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
}

void printFibonacciWithRecursion(int n, int a = 0, int b = 1, int count = 0) {
    if (count < n) {
        cout << a << "\n";
        printFibonacciWithRecursion(n, b, a + b, count + 1);
    }
}

void printFirstLetters(string str) {
    stringstream ss(str); // Create a stringstream to process the string
    string word;

    while (ss >> word) {
        cout << word[0] << " "; // Print the first character of each word
    }
    cout << endl;
}

void lowercaseFirstLetters(string str) {
    stringstream ss(str); // Create a stringstream to process the string
    string word;

    while (ss >> word) {
        if (!word.empty()) {
            word[0] = tolower(word[0]); // Convert the first character to lowercase
        }
        cout << word << " ";
    }
    cout << endl;
}

void uppercaseFirstLetters(string str) {
    stringstream ss(str); // Create a stringstream to process the string
    string word;

    while (ss >> word) {
        if (!word.empty()) {
            word[0] = toupper(word[0]); // Convert the first character to uppercase
        }
        cout << word << " ";
    }
    cout << endl;
}

void countLetters(string str) {
    int lowercaseCount = 0, uppercaseCount = 0;
    int length = str.length(); // Calculate the length of the string

    for (char c : str) {
        if (islower(c)) {
            lowercaseCount++;
        } else if (isupper(c)) {
            uppercaseCount++;
        }
    }

    cout << "String length: " << length << endl;
    cout << "Number of lowercase letters: " << lowercaseCount << endl;
    cout << "Number of uppercase letters: " << uppercaseCount << endl;
}

int countCharacter(const string& str, char ch) {
    int count = 0;

    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }

    return count;
}

int countCharacter(const string& str, char ch, bool matchCase) {
    int count = 0;

    for (char c : str) {
        if (matchCase) {
            if (c == ch) {
                count++;
            }
        } else {
            if (tolower(c) == tolower(ch)) {
                count++;
            }
        }
    }

    return count;
}

bool isVowel(char ch) {
    ch = tolower(ch); // Convert the character to lowercase for easy comparison

    // Check if the character is a vowel
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int countVowels(const string& str) {
    int vowelCount = 0;

    for (char c : str) {
        // Convert the character to lowercase for easy comparison
        char lowerC = tolower(c);

        // Check if the character is a vowel
        if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
            vowelCount++;
        }
    }

    return vowelCount;
}

void printVowels(const string& str) {
    bool foundVowel = false;
    cout << "Vowels in the string: ";
    
    for (char c : str) {
        switch (tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cout << c << " ";
                foundVowel = true;
                break;
            default:
                break;
        }
    }
    
    if (!foundVowel) {
        cout << "No vowels letters";
    }
    
    cout << endl;
}

void printWords(const string& str) {
    istringstream iss(str);

    cout << "Words in the string:" << endl;
    string word;
    while (iss >> word) {
        cout << word << endl;
    }
}

int countWords(const string& str) {
    istringstream iss(str);
    int wordCount = 0;
    string word;

    while (iss >> word) {
        wordCount++;
    }

    return wordCount;
}

vector<string> splitWords(const string& str) {
    istringstream iss(str);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

vector<int> countTokens(const string& str) {
    istringstream iss(str);
    vector<int> tokens;
    int wordCount = 0;
    string word;

    while (iss >> word) {
        wordCount++;
    }

    tokens.push_back(wordCount);
    return tokens;
}

vector<string> tokenizeString(const string& str, int& tokenCount) {
    istringstream iss(str);
    vector<string> tokens;
    string word;

    tokenCount = 0;
    while (iss >> word) {
        tokens.push_back(word);
        tokenCount++;
    }

    return tokens;
}

string trimLeft(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v"); // Find the first non-whitespace character
    return (start == string::npos) ? "" : str.substr(start);
}

string trimRight(const string& str) {
    size_t end = str.find_last_not_of(" \t\n\r\f\v"); // Find the last non-whitespace character
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}

string trimAll(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    if (start == string::npos) {
        return ""; // String is all whitespace
    }

    return str.substr(start, end - start + 1);
}

string joinStrings(const vector<string>& strings, const string& separator) {
    if (strings.empty()) {
        return ""; // Return an empty string if the vector is empty
    }

    string joinedString = strings[0]; // Initialize the joined string with the first element

    for (size_t i = 1; i < strings.size(); ++i) {
        joinedString += separator + strings[i]; // Append the separator and the next element
    }

    return joinedString;
}

string reverseWords(const string& str) {
    istringstream iss(str);
    vector<string> words;
    string word;

    // Tokenize the input string into words
    while (iss >> word) {
        words.push_back(word);
    }

    // Reverse the order of the words in the vector
    reverse(words.begin(), words.end());

    // Join the reversed words into a single string
    ostringstream oss;
    for (const string& w : words) {
        oss << w << " ";
    }

    return oss.str();
}

vector<string> generateWordList() {
    return {
        "apple", "orange", "banana", "grape", "pear",
        // ... add more words here ...
        "vanilla", "watermelon"
    };
}

// Function to split a string into words
vector<string> splitString(const string& str) {
    istringstream iss(str);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

string replaceWords(const string& str, unordered_map<string, string>& replacements) {
    vector<string> words = splitString(str);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, replacements.size() - 1);

    for (size_t i = 0; i < words.size(); ++i) {
        string placeholder = "word" + to_string(i + 1);
        auto it = replacements.find(placeholder);
        if (it != replacements.end()) {
            int randomIndex = dis(gen);
            words[i] = it->second;
            words[randomIndex] = it->second;
        }
    }

    ostringstream oss;
    for (const string& word : words) {
        oss << word << " ";
    }
    return oss.str();
}

bool isPunctuation(char c) {
    return ispunct(static_cast<unsigned char>(c));
}

std::string removePunctuation(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (!isPunctuation(c)) {
            result += c;
        }
    }
    return result;
}

struct ClientData {
    std::string accountNumber;
    std::string pinCode;
    std::string name;
    std::string phone;
    double accountBalance;
};

struct Client_ {
    std::string accountNumber;
    std::string pinCode;
    std::string name;
    std::string phone;
    double accountBalance;
};

void showClientList() {
    std::ifstream inputFile("clients.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    inputFile.close();
}

void addNewClient() {
    std::ofstream outputFile("clients.txt", std::ios::app);
    if (!outputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    // Gather client information
    std::string accountNumber, pinCode, name, phone, accountBalance;
    std::cout << "Enter Account Number: ";
    std::cin >> accountNumber;
    std::cout << "Enter PinCode: ";
    std::cin >> pinCode;
    std::cout << "Enter Name: ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, name);
    std::cout << "Enter Phone: ";
    std::cin >> phone;
    std::cout << "Enter AccountBalance: ";
    std::cin >> accountBalance;

    // Write the client information to the file
    outputFile << accountNumber << " | " << pinCode << " | " << name << " | " << phone << " | " << accountBalance << std::endl;
    outputFile.close();
}

void deleteClient() {
    std::ifstream inputFile("clients.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    std::string accountToDelete;
    std::cout << "Enter Account Number of the client to delete: ";
    std::cin >> accountToDelete;

    std::vector<std::string> tempLines;
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = line.find(accountToDelete);
        if (pos == std::string::npos) {
            tempLines.push_back(line);
        }
    }
    inputFile.close();

    std::ofstream outputFile("clients.txt");
    if (!outputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    for (const auto& line : tempLines) {
        outputFile << line << std::endl;
    }
    outputFile.close();

    std::cout << "Client with Account Number " << accountToDelete << " has been deleted.\n";
}

void updateClientInfo() {
    std::ifstream inputFile("clients.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    std::string accountToUpdate;
    std::cout << "Enter Account Number of the client to update: ";
    std::cin >> accountToUpdate;

    std::vector<std::string> tempLines;
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = line.find(accountToUpdate);
        if (pos == std::string::npos) {
            tempLines.push_back(line);
        }
    }
    inputFile.close();

    std::ofstream outputFile("clients.txt");
    if (!outputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    for (const auto& line : tempLines) {
        outputFile << line << std::endl;
    }

    Client_ updatedClient;
    updatedClient.accountNumber = accountToUpdate;
    std::cout << "Enter PinCode: ";
    std::cin >> updatedClient.pinCode;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, updatedClient.name);
    std::cout << "Enter Phone: ";
    std::cin >> updatedClient.phone;
    std::cout << "Enter AccountBalance: ";
    std::cin >> updatedClient.accountBalance;

    outputFile << updatedClient.accountNumber << " | " << updatedClient.pinCode << " | "
               << updatedClient.name << " | " << updatedClient.phone << " | "
               << updatedClient.accountBalance << std::endl;
    outputFile.close();

    std::cout << "Client with Account Number " << accountToUpdate << " has been updated.\n";
}

void findClient() {
    std::ifstream inputFile("clients.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file.\n";
        return;
    }

    std::string accountToFind;
    std::cout << "Enter Account Number of the client to find: ";
    std::cin >> accountToFind;

    std::string line;
    bool found = false;
    while (std::getline(inputFile, line)) {
        if (line.find(accountToFind) != std::string::npos) {
            found = true;
            std::istringstream ss(line);
            std::string account, pin, name, phone, balance;
            ss >> account >> pin >> name >> phone >> balance;
            std::cout << "Account Number: " << account << "\nPin Code: " << pin << "\nName: "
                      << name << "\nPhone: " << phone << "\nAccount Balance: " << balance << std::endl;
            break;
        }
    }
    inputFile.close();

    if (!found) {
        std::cout << "Client with Account Number " << accountToFind << " Not Found!\n";
    }
}

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

void ShowTransactionsMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;


};

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }


            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return false;


}

sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }


    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

void PrintClientRecordLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void PrintClientRecordBalanceLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowAllClientsScreen()
{


    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void ShowTotalBalances()
{

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;

            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;

}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n"
         << "-----------------------------------"
         << "\nAccout Number: " << Client.AccountNumber
         << "\nPin Code     : " << Client.PinCode
         << "\nName         : " << Client.Name
         << "\nPhone        : " << Client.Phone
         << "\nAccount Balance: " << Client.AccountBalance
         << "\n-----------------------------------\n";

}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;

}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;

}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}

void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        //system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";


        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients 
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
        return false;
    

}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }

            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
        return false;
    

}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{


    char Answer = 'n';


    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }

    }
        return false;
    

}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n"
         << "\tAdd New Clients Screen"
         << "\n-----------------------------------\n";

    AddNewClients();

}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n"
         << "\tFind Client Screen"
         << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";

}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n"
         << "\tProgram Ends :-)"
         << "\n-----------------------------------\n";

}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n"
         << "\tDeposit Screen"
         << "\n-----------------------------------\n";


    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();


    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }


    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);

}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n"
         << "\tWithdraw Screen"
         << "\n-----------------------------------\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();


    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    //Validate that the amount does not exceeds the balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);

}

void ShowTotalBalancesScreen()
{

    ShowTotalBalances();

}

enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4 };

enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eExit = 7 };

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();

}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();

}

short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowMainMenue:
    {

        ShowMainMenue();

    }
    }

}

void ShowTransactionsMenue()
{
    system("cls");
    cout << "===========================================\n"
         << "\t\tTransactions Menue Screen\n"
         << "===========================================\n"
         << "\t[1] Deposit.\n"
         << "\t[2] Withdraw.\n"
         << "\t[3] Total Balances.\n"
         << "\t[4] Main Menue.\n"
         << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowTransactionsMenue:
        system("cls");
        ShowTransactionsMenue();
        break;

    case enMainMenueOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }

}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n"
         << "\t\tMain Menue Screen\n"
         << "===========================================\n"
         << "\t[1] Show Client List.\n"
         << "\t[2] Add New Client.\n"
         << "\t[3] Delete Client.\n"
         << "\t[4] Update Client Info.\n"
         << "\t[5] Find Client.\n"
         << "\t[6] Transactions.\n"
         << "\t[7] Exit.\n"
         << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

vector<string> units = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> thousands = {"", "Thousand", "Million", "Billion"};

string convertThreeDigit(int num) {
    string words = "";
    int hundreds = num / 100;
    int tensAndOnes = num % 100;
    if (hundreds > 0) {
        words += units[hundreds] + " Hundred";
        if (tensAndOnes > 0) {
            words += " and ";
        }
    }
    if (tensAndOnes < 10) {
        words += units[tensAndOnes];
    } else if (tensAndOnes < 20) {
        words += teens[tensAndOnes - 10];
    } else {
        words += tens[tensAndOnes / 10];
        if (tensAndOnes % 10 != 0) {
            words += " " + units[tensAndOnes % 10];
        }
    }
    return words;
}

string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    string words = "";
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            string block = convertThreeDigit(num % 1000);
            if (!block.empty()) {
                words = block + (thousands[i] != "" ? " " + thousands[i] + " " : "") + words;
            }
        }
        num /= 1000;
        ++i;
    }

    return words;
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29; // Leap year, February has 29 days
        } else {
            return 28; // Non-leap year, February has 28 days
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30; // April, June, September, November have 30 days
    } else {
        return 31; // January, March, May, July, August, October, December have 31 days
    }
}

short NumberOfDaysInAMonth(short Month, short Year){
    if (Month < 1 || Month>12)
    return 0;
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

void printMonthCalendar(int year, int month) {
    std::tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = 1;
    std::mktime(&timeinfo);

    int daysInMonth = 32 - std::tm{year - 1900, month - 1, 32}.tm_mday;

    std::string monthName;
    switch (month) {
        case 1:  monthName = "January"; break;
        case 2:  monthName = "February"; break;
        case 3:  monthName = "March"; break;
        case 4:  monthName = "April"; break;
        case 5:  monthName = "May"; break;
        case 6:  monthName = "June"; break;
        case 7:  monthName = "July"; break;
        case 8:  monthName = "August"; break;
        case 9:  monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
        default: monthName = "Invalid month"; break;
    }

    int spaces = (20 - monthName.length()) / 2;
    std::string monthTitle = std::string(spaces + 4, '_') + monthName + std::string(spaces + 3, '_');

    std::cout << monthTitle << std::endl;
    std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;

    for (int i = 0; i < timeinfo.tm_wday; ++i) {
        std::cout << "    ";
    }

    for (int day = 1; day <= daysInMonth; ++day) {
        std::cout << std::setw(3) << std::setfill(' ') << std::left << day << " ";
        if ((timeinfo.tm_wday + day) % 7 == 0 || day == daysInMonth) {
            std::cout << std::endl;
        }
    }
    cout << "__________________________";
}

void printYearCalendar(int year) {
    for (int month = 1; month <= 12; ++month) {
        std::tm timeinfo = {0};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = 1;
        std::mktime(&timeinfo);

        int daysInMonth = 32 - std::tm{year - 1900, month - 1, 32}.tm_mday;

        std::string monthName;
        switch (month) {
            case 1:  monthName = "January"; break;
            case 2:  monthName = "February"; break;
            case 3:  monthName = "March"; break;
            case 4:  monthName = "April"; break;
            case 5:  monthName = "May"; break;
            case 6:  monthName = "June"; break;
            case 7:  monthName = "July"; break;
            case 8:  monthName = "August"; break;
            case 9:  monthName = "September"; break;
            case 10: monthName = "October"; break;
            case 11: monthName = "November"; break;
            case 12: monthName = "December"; break;
            default: monthName = "Invalid month"; break;
        }

        int spaces = (20 - monthName.length()) / 2;
        std::string monthTitle = std::string(spaces + 3, '_') + monthName + std::string(spaces + 3, '_');

        std::cout << monthTitle << std::endl;
        std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;

        for (int i = 0; i < timeinfo.tm_wday; ++i) {
            std::cout << "    ";
        }

        for (int day = 1; day <= daysInMonth; ++day) {
            std::cout << std::setw(3) << std::setfill(' ') << std::left << day << " ";
            if ((timeinfo.tm_wday + day) % 7 == 0 || day == daysInMonth) {
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
    }
}

int DaysInMonth(int month, int year) {
    int days[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

int calculateTotalDays(int day, int month, int year) {
    int totalDays = day;
    for (int i = 1; i < month; ++i) {
        totalDays += daysInMonth(i, year);
    }
    return totalDays;
}

void convertDaysToDate(int totalDays, int year) {
    int month = 1;
    while (totalDays > daysInMonth(month, year)) {
        totalDays -= daysInMonth(month, year);
        month++;
    }
    int day = totalDays;
    std::cout << "Date for [" << totalDays << "] is: " << day << "/" << month << "/" << year << std::endl;
}

struct Date {
    int day;
    int month;
    int year;
};

bool isDate1LessThanDate2(const Date& date1, const Date& date2) {
    if (date1.year < date2.year) {
        return true;
    } else if (date1.year == date2.year) {
        if (date1.month < date2.month) {
            return true;
        } else if (date1.month == date2.month) {
            return date1.day < date2.day;
        }
    }
    return false;
}

bool isLastDayOfMonth(int day, int month, int year) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return day == 29; // Leap year, February has 29 days
        } else {
            return day == 28; // Non-leap year, February has 28 days
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day == 30; // April, June, September, November have 30 days
    } else {
        return day == 31; // January, March, May, July, August, October, December have 31 days
    }
}

bool isLastMonthOfYear(int month) {
    return month == 12;
}

Date increaseByOneDay(Date inputDate) {
    int days = daysInMonth(inputDate.month, inputDate.year);
    if (inputDate.day < days) {
        inputDate.day++;
    } else {
        inputDate.day = 1;
        if (inputDate.month < 12) {
            inputDate.month++;
        } else {
            inputDate.month = 1;
            inputDate.year++;
        }
    }
    return inputDate;
}

int calculateDifference(Date date1, Date date2) {
    int days = 0;
    while (date1.day != date2.day || date1.month != date2.month || date1.year != date2.year) {
        days++;
        date1.day++;
        if (date1.day > daysInMonth(date1.month, date1.year)) {
            date1.day = 1;
            date1.month++;
            if (date1.month > 12) {
                date1.month = 1;
                date1.year++;
            }
        }
    }
    return days;
}

int calculateAgeInDays(Date dateOfBirth) {
    Date currentDate;
    std::cout << "Please enter the current date (Day Month Year): ";
    std::cin >> currentDate.day >> currentDate.month >> currentDate.year;

    int days = 0;
    while (dateOfBirth.day != currentDate.day || dateOfBirth.month != currentDate.month || dateOfBirth.year != currentDate.year) {
        days++;
        dateOfBirth.day++;
        if (dateOfBirth.day > daysInMonth(dateOfBirth.month, dateOfBirth.year)) {
            dateOfBirth.day = 1;
            dateOfBirth.month++;
            if (dateOfBirth.month > 12) {
                dateOfBirth.month = 1;
                dateOfBirth.year++;
            }
        }
    }
    return days;
}

int daysBetweenDates(Date date1, Date date2) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days1 = date1.year * 365 + date1.day;
    for (int i = 1; i < date1.month; ++i) {
        days1 += daysInMonth[i];
    }
    days1 += (date1.month > 2 && (date1.year % 4 == 0 && (date1.year % 100 != 0 || date1.year % 400 == 0)));

    int days2 = date2.year * 365 + date2.day;
    for (int i = 1; i < date2.month; ++i) {
        days2 += daysInMonth[i];
    }
    days2 += (date2.month > 2 && (date2.year % 4 == 0 && (date2.year % 100 != 0 || date2.year % 400 == 0)));

    int difference = std::abs(days2 - days1);

    return difference;
}

int minutesBetweenDates(Date date1, Date date2) {
    int daysDifference = daysBetweenDates(date1, date2);
    return daysDifference * 24 * 60;
}

void PrintDate(const Date& date) {
    std::cout << date.day << "/" << date.month << "/" << date.year;
}

int GetDaysInMonth(int month, int year) {
    int daysInMonth;

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    return daysInMonth;
}

void IncreaseDateByXDays(Date& date, int days) {
    int daysInMonth = GetDaysInMonth(date.month, date.year);

    date.day += days;
    while (date.day > daysInMonth) {
        date.day -= daysInMonth;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
        daysInMonth = GetDaysInMonth(date.month, date.year);
    }

    std::cout << "01-Adding " << days << " days is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByOneWeek(Date& date) {
    IncreaseDateByXDays(date, 7);
    std::cout << "02-Adding one week is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByXWeeks(Date& date, int weeks) {
    IncreaseDateByXDays(date, weeks * 7);
    std::cout << "03-Adding " << weeks << " weeks is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByXMonths(Date& date, int months) {
    date.month += months;
    while (date.month > 12) {
        date.month -= 12;
        date.year++;
    }

    std::cout << "06-Adding " << months << " months is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByXYears(Date& date, int years) {
    date.year += years;
    std::cout << "07-Adding " << years << " years is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByXDecades(Date& date, int decades) {
    date.year += decades * 10;
    std::cout << "10-Adding " << decades << " decades is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByOneMonth(Date& date) {
    IncreaseDateByXMonths(date, 1);
    std::cout << "04-Adding one month is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByOneYear(Date& date) {
    IncreaseDateByXYears(date, 1);
    std::cout << "06-Adding one year is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByXYearsFaster(Date& date, int years) {
    date.year += years;
    std::cout << "08-Adding " << years << " years (faster) is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByOneDecade(Date& date) {
    IncreaseDateByXDecades(date, 1);
    std::cout << "09-Adding one decade is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByXDecadesFaster(Date& date, int decades) {
    date.year += decades * 10;
    std::cout << "11-Adding " << decades << " decades (faster) is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByOneCentury(Date& date) {
    IncreaseDateByXYears(date, 100);
    std::cout << "12-Adding one century is: ";
    PrintDate(date);
    std::cout << std::endl;
}

void IncreaseDateByOneMillennium(Date& date) {
    IncreaseDateByXYears(date, 1000);
    std::cout << "13-Adding one millennium is: ";
    PrintDate(date);
    std::cout << std::endl;
}

int calculateActualVacationDays(const Date& startDate, const Date& endDate) {
    int actualVacationDays = 0;
    tm currentDate = {0, 0, 0, startDate.day, startDate.month - 1, startDate.year - 1900};
    tm finalDate = {0, 0, 0, endDate.day, endDate.month - 1, endDate.year - 1900};

    while (std::mktime(&currentDate) <= std::mktime(&finalDate)) {
        // Exclude weekends (Saturday and Sunday)
        if (currentDate.tm_wday < 5) {
            actualVacationDays++;
        }

        currentDate.tm_mday++;
        std::mktime(&currentDate); // Update the date after incrementing
    }

    return actualVacationDays;
}

Date getUserDateInput(const std::string& prompt) {
    Date date;
    std::cout << "Please enter a " << prompt << " Day? ";
    std::cin >> date.day;
    std::cout << "Please enter a " << prompt << " Month? ";
    std::cin >> date.month;
    std::cout << "Please enter a " << prompt << " Year? ";
    std::cin >> date.year;
    return date;
}

int calculateActualVacationDays(const Date& startDate, int vacationDays) {
    int actualVacationDays = 0;
    tm currentDate = {0, 0, 0, startDate.day, startDate.month - 1, startDate.year - 1900};

    while (actualVacationDays < vacationDays) {
        // Exclude weekends (Saturday and Sunday)
        if (currentDate.tm_wday < 5) {
            actualVacationDays++;
        }

        currentDate.tm_mday++;
        std::mktime(&currentDate); // Update the date after incrementing
    }

    return actualVacationDays;
}

bool isDateAfter(const Date& date1, const Date& date2) {
    if (date1.year > date2.year) {
        return true;
    } else if (date1.year < date2.year) {
        return false;
    } else {
        // Years are equal, check months
        if (date1.month > date2.month) {
            return true;
        } else if (date1.month < date2.month) {
            return false;
        } else {
            // Months are equal, check days
            return date1.day > date2.day;
        }
    }
}

int compareDates(const Date& date1, const Date& date2) {
    if (date1.year < date2.year) {
        return -1;
    } else if (date1.year > date2.year) {
        return 1;
    } else {
        // Years are equal, check months
        if (date1.month < date2.month) {
            return -1;
        } else if (date1.month > date2.month) {
            return 1;
        } else {
            // Months are equal, check days
            if (date1.day < date2.day) {
                return -1;
            } else if (date1.day > date2.day) {
                return 1;
            } else {
                // Dates are equal
                return 0;
            }
        }
    }
}

struct Period {
    Date start, end;
};

bool doPeriodsOverlap(const Period& period1, const Period& period2) {
    // Check if period1 ends before period2 starts or period1 starts after period2 ends
    if (period1.end.year < period2.start.year ||
        (period1.end.year == period2.start.year && period1.end.month < period2.start.month) ||
        (period1.end.year == period2.start.year && period1.end.month == period2.start.month && period1.end.day < period2.start.day) ||
        period1.start.year > period2.end.year ||
        (period1.start.year == period2.end.year && period1.start.month > period2.end.month) ||
        (period1.start.year == period2.end.year && period1.start.month == period2.end.month && period1.start.day > period2.end.day)) {
        return false;  // No overlap
    }

    return true;  // Periods overlap
}

Period getUserPeriodInput(const std::string& periodPrompt) {
    Period period;
    std::cout << periodPrompt << ":\n";
    period.start = getUserDateInput("Start Date");
    period.end = getUserDateInput("End Date");
    return period;
}

int calculatePeriodLength(const Period& period) {
    int days = 0;
    tm startDate = {0, 0, 0, period.start.day, period.start.month - 1, period.start.year - 1900};
    tm endDate = {0, 0, 0, period.end.day, period.end.month - 1, period.end.year - 1900};

    // Calculate the difference in seconds
    std::time_t startTime = std::mktime(&startDate);
    std::time_t endTime = std::mktime(&endDate);

    // Calculate the difference in days
    days = std::difftime(endTime, startTime) / (60 * 60 * 24);

    return days;
}

bool isDateWithinPeriod(const Date& date, const Period& period) {
    tm startDate = {0, 0, 0, period.start.day, period.start.month - 1, period.start.year - 1900};
    tm endDate = {0, 0, 0, period.end.day, period.end.month - 1, period.end.year - 1900};
    tm checkDate = {0, 0, 0, date.day, date.month - 1, date.year - 1900};

    std::time_t startTime = std::mktime(&startDate);
    std::time_t endTime = std::mktime(&endDate);
    std::time_t checkTime = std::mktime(&checkDate);

    return (checkTime >= startTime) && (checkTime <= endTime);
}

int calculateOverlapDays(const Period& period1, const Period& period2) {
    // Find the latest start date and the earliest end date
    Date overlapStart = {
        std::max(period1.start.day, period2.start.day),
        std::max(period1.start.month, period2.start.month),
        std::max(period1.start.year, period2.start.year)
    };

    Date overlapEnd = {
        std::min(period1.end.day, period2.end.day),
        std::min(period1.end.month, period2.end.month),
        std::min(period1.end.year, period2.end.year)
    };

    // Calculate the difference in days
    tm start = {0, 0, 0, overlapStart.day, overlapStart.month - 1, overlapStart.year - 1900};
    tm end = {0, 0, 0, overlapEnd.day, overlapEnd.month - 1, overlapEnd.year - 1900};

    std::time_t startTime = std::mktime(&start);
    std::time_t endTime = std::mktime(&end);

    int overlapDays = std::difftime(endTime, startTime) / (60 * 60 * 24);

    // If the overlap is negative, there is no overlap
    return std::max(0, overlapDays);
}

bool isValidDate(const Date& date) {
    // Function to validate a date
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1) {
        return false;  // Invalid month, day, or year
    }

    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year
    int daysInFeb = 28;
    if (date.month == 2 && isLeapYear(date.year)) {
        daysInFeb = 29;
    }

    return date.day <= daysInMonth[date.month];
}

Date getUserDateInput() {
    Date date;
    std::cout << "Please enter a Day? ";
    std::cin >> date.day;
    std::cout << "Please enter a Month? ";
    std::cin >> date.month;
    std::cout << "Please enter a Year? ";
    std::cin >> date.year;
    return date;
}

Date StringToDate(const std::string& dateString) {
    Date date;
    std::istringstream ss(dateString);
    char delimiter;

    ss >> date.day >> delimiter >> date.month >> delimiter >> date.year;

    return date;
}

std::string DateToString(const Date& date) {
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << date.day << '/'
       << std::setw(2) << std::setfill('0') << date.month << '/'
       << date.year;
    return ss.str();
}

std::string formatDate(const Date& date, const std::string& format) {
    std::ostringstream ss;

    if (format == "dd/mm/yyyy") {
        ss << std::setw(2) << std::setfill('0') << date.day << '/'
           << std::setw(2) << std::setfill('0') << date.month << '/'
           << date.year;
    } else if (format == "yyyy/dd/mm") {
        ss << date.year << '/'
           << std::setw(2) << std::setfill('0') << date.day << '/'
           << std::setw(2) << std::setfill('0') << date.month;
    } else if (format == "mm/dd/yyyy") {
        ss << std::setw(2) << std::setfill('0') << date.month << '/'
           << std::setw(2) << std::setfill('0') << date.day << '/'
           << date.year;
    } else if (format == "mm-dd-yyyy") {
        ss << std::setw(2) << std::setfill('0') << date.month << '-'
           << std::setw(2) << std::setfill('0') << date.day << '-'
           << date.year;
    } else if (format == "dd-mm-yyyy") {
        ss << std::setw(2) << std::setfill('0') << date.day << '-'
           << std::setw(2) << std::setfill('0') << date.month << '-'
           << date.year;
    } else if (format == "Day: dd, Month: mm, Year: yyyy") {
        ss << "Day:" << date.day << ", Month:" << date.month << ", Year:" << date.year;
    }

    return ss.str();
}

Date getUserDateInputS() {
    Date date;
    std::cout << "Please Enter Date dd/mm/yyyy? ";
    std::cin >> date.day;
    std::cin.ignore(); // Ignore the '/'
    std::cin >> date.month;
    std::cin.ignore(); // Ignore the '/'
    std::cin >> date.year;

    return date;
}

struct _Client{
    std::string name;
    int accountNumber;
    double balance;
};

struct User {
    std::string username;
    std::string password;
};

std::vector<User> _loadUserData(const std::string& fileName) {
    std::vector<User> users;
    std::ifstream file(fileName);

    if (file.is_open()) {
        User user;
        while (file >> user.username >> user.password) {
            users.push_back(user);
        }

        file.close();
    } else {
        std::cerr << "Error: Unable to open file '" << fileName << "'.\n";
    }

    return users;
}

// Function to authenticate a user
bool _authenticateUser(const std::vector<User>& users, const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(),
                           [username, password](const User& user) {
                               return user.username == username && user.password == password;
                           });

    return it != users.end();
}

// Structure to represent a client
struct Client {
    std::string name;
    int accountNumber;
    double balance;
};

// Function to load client data from a file
std::vector<Client> _loadClientData(const std::string& fileName) {
    std::vector<Client> clients;
    std::ifstream file(fileName);

    if (file.is_open()) {
        Client client;
        while (file >> client.name >> client.accountNumber >> client.balance) {
            clients.push_back(client);
        }

        file.close();
    } else {
        std::cerr << "Error: Unable to open file '" << fileName << "'.\n";
    }

    return clients;
}

// Function to save client data to a file
void _saveClientData(const std::string& fileName, const std::vector<Client>& clients) {
    std::ofstream file(fileName);

    if (file.is_open()) {
        for (const auto& client : clients) {
            file << client.name << " " << client.accountNumber << " " << client.balance << "\n";
        }

        file.close();
    } else {
        std::cerr << "Error: Unable to open file '" << fileName << "' for writing.\n";
    }
}

// Function to display the ATM main menu
void _displayMainMenu() {
    std::cout << "\nATM Main Menu Screen\n"
              << "[1] Quick Withdraw.\n"
              << "[2] Normal Withdraw.\n"
              << "[3] Deposit.\n"
              << "[4] Check Balance.\n"
              << "[5] Logout.\n"
              << "Choose what do you want to do? [1 to 5]? ";
}

// Function to perform a quick withdraw with predefined amounts
void _quickWithdraw(std::vector<Client>& clients, int accountNumber, double& balance, double quickWithdrawAmount);
// Declaration of _quickWithdraw
void _quickWithdraw(std::vector<Client>& clients, int accountNumber, double& balance, double quickWithdrawAmount){

    // Deduct the predefined withdrawal amount
    balance -= quickWithdrawAmount;

    std::cout << "Quick Withdraw\n";
    std::cout << "[1] 20 [2] 50\n";
    std::cout << "[3] 100 [4] 200\n";
    std::cout << "[5] 400 [6] 600\n";
    std::cout << "[7] 800 [8] 1000\n";
    std::cout << "[9] Exit\n";
    std::cout << "Your Balance is: $" << balance << "\n";

    int choice;
    std::cout << "Choose what to withdraw from [1] to [8] or [9] to exit? ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            // No need to deduct amount here, it's already done
            break;
        case 2:
            // No need to deduct amount here, it's already done
            break;
        // ... Handle other choices ...
        case 9:
            std::cout << "Exiting quick withdrawal menu.\n";
            return;
        default:
            std::cout << "Invalid choice.\n";
            return;
    }
    std::cout << "Withdrawal successful. New balance: $" << balance << "\n";
}

// Function to perform a normal withdraw
void _normalWithdraw(std::vector<Client>& clients, int accountNumber) {
    // Implement normal withdraw functionality here
    std::cout << "Normal Withdraw functionality to be implemented.\n";
}

// Function to perform a deposit
void _deposit(std::vector<Client>& clients, int accountNumber, double amount) {
    for (auto& client : clients) {
        if (client.accountNumber == accountNumber) {
            client.balance += amount;
            std::cout << "Deposit successful. New balance: $" << client.balance << "\n";
            return;
        }
    }

    std::cout << "Account not found.\n";
}

// Function to check balance
// Function to check balance
void _checkBalance(const std::vector<Client>& clients, int accountNumber) {
    std::cout << "DEBUG: Checking Balance for Account Number: " << accountNumber << "\n";

    for (const auto& client : clients) {
        std::cout << "DEBUG: Account in Clients Vector - Account Number: " << client.accountNumber << ", Balance: $" << client.balance << "\n";
        if (client.accountNumber == accountNumber) {
            std::cout << "Current Balance: $" << client.balance << "\n";
            return;
        }
    }

    std::cout << "DEBUG: Account not found for balance check.\n";
    std::cout << "Account not found for account number: " << accountNumber << std::endl;
}

class Calculator {
private:
    double result;

public:
    Calculator() : result(0.0) {}

    void Clear() {
        result = 0.0;
    }

    void Add(double value) {
        result += value;
    }

    void Subtract(double value) {
        result -= value;
    }

    void Multiply(double value) {
        result *= value;
    }

    // Check for division by zero before performing the operation
    bool Divide(double value) {
        if (value != 0.0) {
            result /= value;
            return true;  // Division successful
        } else {
            std::cout << "Error: Cannot divide by zero.\n";
            return false; // Division by zero error
        }
    }

    void PrintResult() const {
        std::cout << "Result: " << result << "\n";
    }
};

class clsPerson

{

private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
{
    _ID = ID;
    _FirstName = FirstName;
    _LastName = LastName;
    _Email = Email;
    _Phone = Phone;
}
//Read Only Property
int ID(){
    return _ID;
}
//Property Set
void setFirstName(string FirstName){

    _FirstName = FirstName;

}

//Property Get
string FirstName(){

    return _FirstName;
}
    
//Property Set
void setLastName(string LastName){

    _LastName = LastName;

}

//Property Set
void setEmail(string Email){

    _Email = Email;
}
//Property Get
string Email(){

    return _Email;
}

//Property Set
void setPhone(string Phone){

    _Phone = Phone;
}
//Property Get
string LastName(){

    return _LastName;
}

string Phone(){
    return _Phone;
}

string FullName(){

    return _FirstName + " " + _LastName;        
}

void Print(){

cout << "\nInfo:"
     << "\n_____________________________"
     << "\nID                   : "<<_ID
     << "\nFirstName: " << _FirstName
     << "\nLastName : " << _LastName
     << "\nFull Name: " << FullName()
     << "\nEmail      " <<_Email
     << "\nPhone      " <<_Phone
     << "\n___________________________\n";

}

void SendEmail(string Subject, string Body){

cout << "\nThe following message sent successfully to email: " << _Email
     << "\nSubject: " << Subject
     << "\nBody: " << Body << endl;

}

void SendSMS(string TextMessage){

    cout << "\nThe following SMS sent successfully to phone: "<<_Phone
         <<  "\n" << TextMessage << endl;
}

};

class Developer {
private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _Title;
    std::string _Email;
    std::string _Phone;
    double _Salary;
    std::string _Department;
    std::string _MainProgrammingLanguage;

public:
    // Constructor
    Developer(int ID, const std::string& FirstName, const std::string& LastName,
              const std::string& Title, const std::string& Email, const std::string& Phone,
              double Salary, const std::string& Department, const std::string& MainProgrammingLanguage)
        : _ID(ID), _FirstName(FirstName), _LastName(LastName), _Title(Title),
          _Email(Email), _Phone(Phone), _Salary(Salary), _Department(Department),
          _MainProgrammingLanguage(MainProgrammingLanguage) {}

    // Read-only property
    int ID() const {
        return _ID;
    }

    // Properties with setters and getters
    void setFirstName(const std::string& FirstName) {
        _FirstName = FirstName;
    }

    std::string FirstName() const {
        return _FirstName;
    }

    void setLastName(const std::string& LastName) {
        _LastName = LastName;
    }

    std::string LastName() const {
        return _LastName;
    }

    void setTitle(const std::string& Title) {
        _Title = Title;
    }

    std::string Title() const {
        return _Title;
    }

    void setEmail(const std::string& Email) {
        _Email = Email;
    }

    std::string Email() const {
        return _Email;
    }

    void setPhone(const std::string& Phone) {
        _Phone = Phone;
    }

    std::string Phone() const {
        return _Phone;
    }

    void setSalary(double Salary) {
        _Salary = Salary;
    }

    double Salary() const {
        return _Salary;
    }

    void setDepartment(const std::string& Department) {
        _Department = Department;
    }

    std::string Department() const {
        return _Department;
    }

    void setMainProgrammingLanguage(const std::string& MainProgrammingLanguage) {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    std::string MainProgrammingLanguage() const {
        return _MainProgrammingLanguage;
    }

    // Methods
    void SendEmail(const std::string& Subject, const std::string& Body) const {
        std::cout << "Email sent to " << _Email << "\nSubject: " << Subject << "\nBody: " << Body << std::endl;
    }

    void SendSMS(const std::string& TextMessage) const {
        std::cout << "SMS sent to " << _Phone << "\nMessage: " << TextMessage << std::endl;
    }

    void Print() const {
        std::cout << "Developer Information:\n";
        std::cout << "ID: " << _ID << "\n";
        std::cout << "Name: " << _FirstName << " " << _LastName << "\n";
        std::cout << "Title: " << _Title << "\n";
        std::cout << "Email: " << _Email << "\n";
        std::cout << "Phone: " << _Phone << "\n";
        std::cout << "Salary: " << _Salary << "\n";
        std::cout << "Department: " << _Department << "\n";
        std::cout << "Main Programming Language: " << _MainProgrammingLanguage << "\n";
    }
};

class clsMan
{

public:

    string FullName="Mohammed Abu-Hadhoud";
 
};

class clsSlave: public clsMan
{

public:
    string Title = "CEO";

};

int main(){

/* ه 5:44 21/11/2023 طباعة الأعداد الاولية من 1 الى n

    int N;
    std::cout << "Enter The Number : ";
    std::cin >> N;

    printPrimesUpToN(N);

    return 0;
    */
   
/*5:55 pm 21/11/2023 طباعة رسالة اذا كان العدد مثالي

او لا حتى يتم ادخال كلمة stop
    std::string input;
    
    while (true) {
        std::cout << "Enter the value of n Or enter stop ";
        std::cin >> input;

        if (input == "stop") {
            break;
        }

        int num = std::stoi(input);
        printClassification(num);
    }

    return 0;
    */

/*6:37 pm 21/11/2023 برنامج يطبع الاعداد المثالية من 1 الى n
    int N;
    std::cout << "enter the value of n. ";
    std::cin >> N;

    std::cout << "perfect numbers from 1 to n is." << N ;
    for (int i = 1; i <= N; ++i) {
        if (isPerfectUntelN(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
    */
    
/*6:45 pm طباعة العدد بشكل عكسي  ولكن يجب الإدخال عددا عددا
    std::vector<int> numbers;
    std::string input;

    // استمر في قبول الأعداد حتى يتم إدخال "STOP"
    while (true) {
        std::cout << "enter numbers to reverce Or enter stop";
        std::cin >> input;

        // تحقق من إدخال "STOP"
        if (input == "STOP" || input == "stop") {
            break;
        }

        // تحويل النص إلى عدد صحيح وإضافته إلى القائمة
        int number = std::stoi(input);
        numbers.push_back(number);
    }

    // طباعة الأعداد بشكل عكسي
    std::cout << "reverse is: ";
    for (int i = numbers.size() - 1; i >= 0; --i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    */

/* 7:37 pm 21/11/2023 يقوم بطباعة ناتج الاعداد حتى نكتب stop
    std::vector<int> numbers;
    std::string input;

    // استمر في قبول الأعداد حتى يتم إدخال "STOP"
    while (true) {
        std::cout << "enter a number Or enter Stop";
        std::getline(std::cin, input);

        // تحقق من إدخال "STOP"
        if (input == "STOP" || input == "stop") {
            break;
        }

        // استخدام stringstream لتحليل الأعداد من السلسلة النصية
        std::istringstream stream(input);
        int number;

        // قراءة الأعداد من السلسلة وإضافتها إلى القائمة
        while (stream >> number) {
            numbers.push_back(number);
        }
    }

    // حساب حاصل جمع الأعداد
    int sum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }

    // طباعة حاصل جمع الأعداد
    std::cout << "Sum of number is. " << sum << std::endl;

    return 0;
    */

/* 7:42 pm 21/11/2023 يقوم بطباعة العدد المدخل بشكل عكسي
    int num, reversedNum = 0;

    // Prompt the user to enter a number
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Reverse the digits of the number
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    // Print the reversed number
    std::cout << "The reversed number is: " << reversedNum << std::endl;

    return 0;
    */

/* 8:01 pm 21/11/2023 يقوم بمعرفة الرقم الاكثر تكرارا ويقوم بمعرفة
عدد التكرار
    int number;

    // Prompt the user to enter a number
    std::cout << "cheack the most number apper, Enter a number: ";
    std::cin >> number;

    // Create a map to store the frequency of each digit
    std::unordered_map<int, int> digitFrequency;

    // Calculate the frequency of each digit in the number
    while (number > 0) {
        int currentDigit = number % 10;
        digitFrequency[currentDigit]++;
        number /= 10;
    }

    // Find the digit with the maximum frequency
    int maxFrequencyDigit = -1;
    int maxFrequency = 0;

    for (const auto& entry : digitFrequency) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
            maxFrequencyDigit = entry.first;
        }
    }

    // Print the digit with the maximum frequency and its count
    std::cout << "The digit with the highest frequency is: " << maxFrequencyDigit << std::endl;
    std::cout << "It appears " << maxFrequency << " times in the number." << std::endl;

    return 0;
    */

/*8:09 pm 21/11/2023 التحقق من كل عدد كم مره تكررت كل خانة 
    int number;

    // Prompt the user to enter a number
    std::cout << " cheack every number how much times frequent, Enter a number: ";
    std::cin >> number;

    // Create a map to store the frequency of each digit
    std::unordered_map<int, int> digitFrequency;

    // Calculate the frequency of each digit in the number
    while (number > 0) {
        int currentDigit = number % 10;
        digitFrequency[currentDigit]++;
        number /= 10;
    }

    // Print the frequency of each digit
    std::cout << "Digit frequencies in the number are:" << std::endl;
    for (const auto& entry : digitFrequency) {
        std::cout << "Digit " << entry.first << ": " << entry.second << " times" << std::endl;
    }

    return 0;
    */

/* 8:19 pm 21/11/2023 طباعة الاعداد المدخلة بالترتيب 
    int number;

    // Prompt the user to enter a number
    std::cout << "printing numbers in order, Enter a number: ";
    std::cin >> number;

    // Store the digits in a vector
    std::vector<int> digits;

    // Extract the digits from the number
    while (number > 0) {
        int digit = number % 10;
        digits.push_back(digit);
        number /= 10;
    }

    // Print the digits from left to right
    std::cout << "Digits from left to right: ";
    for (int i = digits.size() - 1; i >= 0; --i) {
        std::cout << std::endl<< digits[i] ;
    }
    std::cout << std::endl;

    return 0;
    */

/*8:26 pm 21/11/2023 التحقق اذا كان الرقم جميل 
    int number, originalNumber, reversedNumber = 0;

    // Prompt the user to enter a number
    std::cout << "cheack if the number is palindrome, Enter a number: ";
    std::cin >> number;

    // Save the original number
    originalNumber = number;

    // Reverse the digits of the number
    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    // Check if the original number is equal to its reversed version
    if (originalNumber == reversedNumber) {
        std::cout << "The number is a palindrome." << std::endl;
    } else {
        std::cout << "The number is not a palindrome." << std::endl;
    }

    return 0;
    */

/*9:01 PM 21/11/2023 طباعة شكل هندسي حسب الرقم
    int number;

    // Prompt the user to enter a number
    std::cout << "draw a patern, Enter a number: ";
    std::cin >> number;

    // Print the inverted pattern
    for (int i = number; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

 
   return 0;

*/

/* 9:04 pm 21/11/2023 طباعة الاحرف بشكل عكسي حتى اخر رقم
    int number;

    // Prompt the user to enter a number
    std::cout << "USING letters from z to a to draw triangle, Enter a number: ";
    std::cin >> number;

    // ASCII value for 'A'
    int asciiValueA = 65;

    // Print the inverted letter pattern
    for (int i = number; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            char currentChar = static_cast<char>(asciiValueA + i - 1);
            std::cout << currentChar;
        }
        std::cout << std::endl;
    }

    return 0;
    */

/* 9:11 pm 21/11/2023 طباعة مثلث من a حتى z حتى نهاية الارقام
    int number;

    // Prompt the user to enter a number
    std::cout << "FROM A to z draw a triangle, Enter a number: ";
    std::cin >> number;

    // ASCII value for 'A'
    int asciiValueA = 65;

    // Print the letter pattern
    for (int i = 1; i <= number; ++i) {
        for (int j = 1; j <= i; ++j) {
            char currentChar = static_cast<char>(asciiValueA + i - 1);
            std::cout << currentChar;
        }
        std::cout << std::endl;
    }

    return 0;
    */

/* 12:33 PM 22/11/2023 طباعة AAA الى ZZZ
generateWords();
return 0;
*/

/* 12:37 pm 22/11/2023 تخمين كلمة مرور من 3 احرف كبيرة
    std::string targetPassword;
    std::cout << "Enter the 3-letter password in uppercase: ";
    std::cin >> targetPassword;

    if (targetPassword.length() != 3) {
        std::cout << "Please enter a 3-letter password in uppercase." << std::endl;
        return 1;
    }

    guessPassword(targetPassword);
    return 0;
*/

/*12:49 pm 22/11/2023 تشفير نص وفك تشفيره ب25مفتاح  
    std::string inputText;
    int shiftAmount;

    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin, inputText);

    std::cout << "Enter the shift amount for encryption (a number between 1 and 25): ";
    std::cin >> shiftAmount;

    std::string encryptedText = encrypt(inputText, shiftAmount);
    std::string decryptedText = decrypt(encryptedText, shiftAmount);

    std::cout << "Text Before Encryption: " << inputText << std::endl;
    std::cout << "Text After Encryption: " << encryptedText << std::endl;
    std::cout << "Text After Decryption: " << decryptedText << std::endl;

    return 0;

*/

/*1:00 pm 22/11/2023 طباعة 3 ارقام عشوائية
// Function to generate three unique random numbers between 1 and 10

    // Seed the random number generator once
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Get three unique random numbers between 1 and 10
    std::vector<int> randomNumbers = generateRandomNumbers();

    // Print the generated random numbers
    for (int num : randomNumbers) {
        std::cout << num << std::endl;
    }

    return 0;
*/

/*1:06 pm 22/11/2023 طباعة 3 ارقام عشوائيةى بكود اسرع واسهل
srand((unsigned)time(NULL));
cout <<RandomNumber(1,10) << endl;
cout <<RandomNumber(1,10) << endl;
cout << RandomNumber(1,10) <<endl;
return 0;

*/

/*1:20 pm 22/11/2023 طباعة 4 خانات عشوائية من امور مختلفة
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << getRandomLowerCase() << std::endl;
    std::cout << getRandomUpperCase() << std::endl;
    std::cout << getRandomSpecialChar() << std::endl;
    std::cout << getRandomDigit() << std::endl;

    return 0;
    */

/* 1:22 Pm 22/11/2023 طباعة n من الرموز التسلسلية
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int numKeys;
    std::cout << "Enter the number of keys to generate: ";
    std::cin >> numKeys;

    for (int i = 1; i <= numKeys; ++i) {
        std::cout << "Key [" << i << "] : " << generateKey() << std::endl;
    }

    return 0;


*/

/* 2:01 pm 22/11/2023 تخزين عدد من عناصر المصفوفة وطباعتهم
    std::vector<int> arr;
    int n, checkNum;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Input array elements
    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int element;
        std::cout << "Element [" << i + 1 << "]: ";
        std::cin >> element;
        arr.push_back(element);
    }

    // Display original array
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Input number to check
    std::cout << "Enter the number you want to check: ";
    std::cin >> checkNum;

    // Count occurrences of checkNum in the array
    int count = 0;
    for (int num : arr) {
        if (num == checkNum) {
            count++;
        }
    }

    // Display the count of occurrences
    std::cout << checkNum << " is repeated " << count << " time(s)" << std::endl;

    return 0;
    */

/* 2:09 pm 22/11/2023  طباعة عناصر مصفوفة عشوائية أقل من  100
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array Elements: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    */

/* 2:16 pm 22/11/2023 طباعة العدد الأكبر بين عناصر مصفوفة عشوائية
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array Elements: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Find the maximum number
    int maxNum = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }

    std::cout << "Max Number is: " << maxNum << std::endl;

    return 0;
    */

/* 3:20 pm 22/11/2023 معرفة الرقم الاصغر من مصفوفة عشوائية
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array Elements: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Find the minimum number
    int minNum = std::numeric_limits<int>::max();
    for (int i = 0; i < size; ++i) {
        if (arr[i] < minNum) {
            minNum = arr[i];
        }
    }

    std::cout << "Min Number is: " << minNum << std::endl;

    return 0;
    */

/* 3:23 pm 22/11/2023  حاصل جمع طباعة عدد n من عناصر المصفوفة
    const int maxSize = 100;
    int arr[maxSize];
    int size, sum = 0;

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array Elements: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr[i] << " ";
        sum += arr[i]; // Calculate sum while filling the array
    }
    std::cout << std::endl;

    std::cout << "Sum of all number is: " << sum << std::endl;

    return 0;
    */

/* 5:01 PM 22/11/2023 حساب متوسط اعداد مصفوفة عشوائية
    const int maxSize = 100;
    int arr[maxSize];
    int size, sum = 0;

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array Elements: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr[i] << " ";
        sum += arr[i]; // Calculate sum while filling the array
    }
    std::cout << std::endl;

    double average = static_cast<double>(sum) / size; // Calculate average

    std::cout << "Average of all numbers is: " << static_cast<int>(average + 0.5) << std::endl;

    return 0;
    */

/* 5:19 PM 22/11/2023 طباعة الاعداد الاولية في مصفوفة عشوائية
    const int maxSize = 100;
    int arr1[maxSize];
    std::vector<int> primes;

    int size;
    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array 1 elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr1[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr1[i] << " ";

        if (isPrime(arr1[i])) {
            primes.push_back(arr1[i]); // Store prime numbers in the vector
        }
    }
    std::cout << std::endl;

    std::cout << "Prime Numbers in Array1:" << std::endl;
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;

*/

/* 5:22 pm 22/11/2023   يطبع حاصل جمع مصفوفتين عشوائيتين 
    const int maxSize = 100;
    int arr1[maxSize], arr2[maxSize], sumArr[maxSize];
    int size;

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize) {
        std::cout << "Size exceeds the maximum limit of 100." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Array 1 elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr1[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr2[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sum of array1 and array2 elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        sumArr[i] = arr1[i] + arr2[i];
        std::cout << sumArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    */

/* 5:29 pm 22/11/2023 اعادة ترتيب عناصر مصفوفة عشوائية
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    if (size > maxSize || size < 1) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    // Fill the array with ordered numbers
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }

    // Printing the array before shuffle
    std::cout << "Array elements before shuffle:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Shuffling the array
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(arr, arr + size);

    // Printing the shuffled array
    std::cout << "Array elements after shuffle:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
    }
    std::cout << std::endl;

    return 0;
    */
 
/* 5:43 pm 22/11/2023 طباعة المصفوفة العشوائية الاولى بالمقلوب 
    const int maxSize = 100;
    int arr1[maxSize], arr2[maxSize];
    int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    if (size > maxSize || size < 1) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Filling arr1 with random numbers
    std::cout << "Array 1 elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr1[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Copying arr1 to arr2 in reverse order
    std::cout << "Array 2 elements after copying array 1 in reversed order:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr2[i] = arr1[size - i - 1]; // Copying in reverse order
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    */

/* تكوين مفاتيح عشوائية في كل عنصر من المصفوفة 
    int numKeys;

    std::cout << "Enter the number of keys to generate: ";
    std::cin >> numKeys;

    std::vector<std::string> keys;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generating keys and filling the array
    for (int i = 0; i < numKeys; ++i) {
        std::string key;
        for (int j = 0; j < 4; ++j) {
            key += static_cast<char>('A' + std::rand() % 26); // Capital letters
            key += static_cast<char>('A' + std::rand() % 26); // Capital letters
            key += static_cast<char>('A' + std::rand() % 26); // Capital letters
            key += static_cast<char>('A' + std::rand() % 26); // Capital letters
            key += "-";
        }
        key.pop_back(); // Removing the extra '-'
        keys.push_back(key);
    }

    // Printing the array of keys
    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < numKeys; ++i) {
        std::cout << "Array[" << i << "] : " << keys[i] << std::endl;
    }

    return 0;
    */

/* 6:09 pm البحث عن عدد n من العناصر العشوائية في المصفوفة
    const int maxSize = 100;
    int arr[maxSize];
    int size, num;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    if (size > maxSize || size < 1) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Filling the array with random numbers
    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100 + 1; // Generates a random number from 1 to 100
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Asking for a number to search for
    std::cout << "Please enter a number to search for: ";
    std::cin >> num;

    // Searching for the number in the array
    bool found = false;
    int index = -1;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            found = true;
            index = i;
            break;
        }
        ++count;
    }

    // Displaying the search result
    if (found) {
        std::cout << "Number you are looking for is: " << num << std::endl;
        std::cout << "The number found at position: " << index << std::endl;
        std::cout << "The number found its order: " << count + 1 << std::endl;
    } else {
        std::cout << "Number you are looking for is: " << num << std::endl;
        std::cout << "The number is not found :-(" << std::endl;
    }

    return 0;
    */

/* 6:20 pm تخزين عناصر بشكل ديناميكي داخل المصفوفة ثم طباعتهم
    int *arr = new int[100]; // Allocate initial memory for 100 elements
    int size = 0;
    int input;
    char choice;

    do {
        std::cout << "Please enter a number: ";
        std::cin >> input;

        arr[size++] = input;

        std::cout << "Do you want to add more numbers? [0]:No,[1]:yes? ";
        std::cin >> choice;

        // Check for valid input and whether to continue adding numbers
    } while ((choice == '1' || choice == 'y' || choice == 'Y') && size < 100);

    std::cout << "Array Length: " << size << std::endl;
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr; // Free allocated memory

    return 0;
*/

/* 6:45 pm طباعة عناصر المصفوفة الاولى العشوائية بعدد n الى اخرى
    int arr1[100];
    int arr2[100];
    int size = 0;
    int n;

    // Input: number of elements
    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> n;

    if (n <= 0 || n > 100) {
        std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
        return 1;
    }

    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Filling arr1 with random numbers
    for (int i = 0; i < n; ++i) {
        int randomNum = std::rand() % 100 + 1; // Random number between 1 and 100
        AddArrayElement(arr1, size, randomNum);
    }

    // Copying arr1 to arr2 using AddArrayElement function
    for (int i = 0; i < size; ++i) {
        AddArrayElement(arr2, i, arr1[i]);
    }

    // Printing arr1 elements
    std::cout << "Array 1 elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Printing arr2 elements after copy
    std::cout << "Array 2 elements after copy: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;

*/

/* 6:49 pm  نسخ العناصر الفردية من المصفوفة الاولى الى الاخرى
    int arr1[100];
    int arr2[100];
    int size1 = 0;
    int size2 = 0;
    int n;

    // Input: number of elements
    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> n;

    if (n <= 0 || n > 100) {
        std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
        return 1;
    }

    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Filling arr1 with random numbers
    for (int i = 0; i < n; ++i) {
        int randomNum = std::rand() % 100 + 1; // Random number between 1 and 100
        AddArrayElement(arr1, size1, randomNum);
    }

    // Copying odd numbers from arr1 to arr2 using AddArrayElement function
    for (int i = 0; i < size1; ++i) {
        if (arr1[i] % 2 != 0) {
            AddArrayElement(arr2, size2, arr1[i]);
        }
    }

    // Printing arr1 elements
    std::cout << "Array 1 elements: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Printing arr2 elements with odd numbers
    std::cout << "Array 2 Odd numbers: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    */

/* نسخ عناصر المصفوفة الاولى العشوائية (الأولية) الى الاخرى 
    int arr1[100];
    int arr2[100];
    int size1 = 0;
    int size2 = 0;
    int n;

    // Input: number of elements
    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> n;

    if (n <= 0 || n > 100) {
        std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
        return 1;
    }

    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Filling arr1 with random numbers
    for (int i = 0; i < n; ++i) {
        int randomNum = std::rand() % 100 + 1; // Random number between 1 and 100
        AddArrayElement(arr1, size1, randomNum);
    }

    // Copying prime numbers from arr1 to arr2 using AddArrayElement function
    for (int i = 0; i < size1; ++i) {
        if (isPrime(arr1[i])) {
            AddArrayElement(arr2, size2, arr1[i]);
        }
    }

    // Printing arr1 elements
    std::cout << "Array 1 elements: ";
    for (int i = 0; i < size1; ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    // Printing arr2 elements with prime numbers
    std::cout << "Array 2 Prime numbers: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
    */

/* 7:24 pm التحقق ما اذا كانت عناصر المصفوفة بيلندروم وطباعة ذلك
    int size;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    std::vector<int> array(size);
    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    // Printing Array Elements
    std::cout << "Array Elements:" << std::endl;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Check if array is a palindrome
    if (isPalindrome(array)) {
        std::cout << "Yes, array is Palindrome" << std::endl;
    } else {
        std::cout << "No, array is not Palindrome" << std::endl;
    }

    return 0;
    */

/* طباعة عدد الارقام الفردية في مصفوفة عشوائية وطباعة عناصرها 
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize || size <= 0) {
        std::cout << "Invalid input size!" << std::endl;
        return 1;
    }

    // Fill array with random numbers from 1 to 100
    std::cout << "Array Elements:";
    int oddCount = 0;
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1; // Generates a random number between 1 and 100
        std::cout << " " << arr[i];

        if (arr[i] % 2 != 0) { // Check if the number is odd
            oddCount++;
        }
    }
    std::cout << std::endl;

    // Display the count of odd numbers
    std::cout << "Odd Numbers count is: " << oddCount << std::endl;

    return 0;

*/

/* طباعة عدد الاعداد الزوجية في مصفوفة عشوائية
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize || size <= 0) {
        std::cout << "Invalid input size!" << std::endl;
        return 1;
    }

    // Fill array with random numbers from 1 to 100
    std::cout << "Array Elements:";
    int evenCount = 0;
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1; // Generates a random number between 1 and 100
        std::cout << " " << arr[i];

        if (arr[i] % 2 == 0) { // Check if the number is even
            evenCount++;
        }
    }
    std::cout << std::endl;

    // Display the count of even numbers
    std::cout << "Even Numbers count is: " << evenCount << std::endl;

    return 0;

*/

/* طباعة اعداد العدد الموجب من مصفوفة عشوائية وطباعة عناصرها
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize || size <= 0) {
        std::cout << "Invalid input size!" << std::endl;
        return 1;
    }

    // Fill array with random numbers from -100 to 100
    std::cout << "Array Elements:";
    int positiveCount = 0;
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 201 - 100; // Generates a random number between -100 and 100
        std::cout << " " << arr[i];

        if (arr[i] > 0) { // Check if the number is positive
            positiveCount++;
        }
    }
    std::cout << std::endl;

    // Display the count of positive numbers
    std::cout << "Positive Numbers count is: " << positiveCount << std::endl;

    return 0;
    */

/* طباعة عدد الاعداد السالبة من مصفوفة عشوائية 
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Enter the number of elements (max 100): ";
    std::cin >> size;

    if (size > maxSize || size <= 0) {
        std::cout << "Invalid input size!" << std::endl;
        return 1;
    }

    // Fill array with random numbers from -100 to 100
    std::cout << "Array Elements:";
    int negativeCount = 0;
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 201 - 100; // Generates a random number between -100 and 100
        std::cout << " " << arr[i];

        if (arr[i] < 0) { // Check if the number is negative
            negativeCount++;
        }
    }
    std::cout << std::endl;

    // Display the count of negative numbers
    std::cout << "Negative Numbers count is: " << negativeCount << std::endl;

    return 0;

*/

/* تغيير قيمة العدد السالب الى موجب  (القيمة المطلقة) عبر دالة غير جاهزة
    int num;
    
    std::cout << "Input a number: ";
    std::cin >> num;

    int myAbsResult = myAbs(num);

    std::cout << "My abs Result: " << myAbsResult << std::endl;
    std::cout << "C++ abs Result: " << abs(num) << std::endl;

    return 0;
    */

/* 8:22 PM دالة التقريب الى اقرب منزلة صحيحة 
    double num;
    
    std::cout << "Input a number: ";
    std::cin >> num;

    int myRoundResult = myRound(num);

    std::cout << "My Round Result: " << myRoundResult << std::endl;
    std::cout << "C++ Round Result: " << int(num + 0.5) << std::endl;

    return 0;
*/

/* دالة التقريب الى اقل منزلة صحيحة 
    double num;
    
    std::cout << "Input a number: ";
    std::cin >> num;

    int myFloorResult = myFloor(num);

    std::cout << "My Floor Result: " << myFloorResult << std::endl;
    std::cout << "C++ Floor Result: " << int(num) << std::endl;

    return 0;
*/

/* دالة الCIEL 
    double num;
    
    std::cout << "Input a number: ";
    std::cin >> num;

    int myCeilResult = myCeil(num);

    std::cout << "My Ceil Result: " << myCeilResult << std::endl;
    std::cout << "C++ Ceil Result: " << int(num + 0.999999999) << std::endl;

    return 0;
*/

/* دالة  SQRT 
    double num;

    std::cout << "Input a number: ";
    std::cin >> num;

    double mySqrtResult = mySqrt(num);

    std::cout << "My Sqrt Result: " << mySqrtResult << std::endl;
    std::cout << "C++ sqrt Result: " << sqrt(num) << std::endl;

    return 0;

*/

/* Stone-Paper-Scissor game طباعة النتيجنة على شاشة سوداء واللعب عبر الارقام



    int rounds;
    std::string userChoice;
    std::string computerChoice;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "How many rounds do you want to play? ";
    std::cin >> rounds;

    for (int roundNum = 1; roundNum <= rounds; ++roundNum) {
        std::cout << "\nRound " << roundNum << std::endl;
        std::cout << "Enter 'stone', 'paper', or 'scissor': ";
        std::cin >> userChoice;

        int randNum = std::rand() % 3;
        if (randNum == 0)
            computerChoice = "stone";
        else if (randNum == 1)
            computerChoice = "paper";
        else
            computerChoice = "scissor";

        std::cout << "Computer chose: " << computerChoice << std::endl;

        if (userChoice == computerChoice) {
            std::cout << Color::YELLOW << "It's a tie!" << Color::RESET << std::endl;
            continue;
        }

        if ((userChoice == "stone" && computerChoice == "scissor") ||
            (userChoice == "paper" && computerChoice == "stone") ||
            (userChoice == "scissor" && computerChoice == "paper")) {
            std::cout << Color::GREEN << "You win!" << Color::RESET << std::endl;
            ringBell();
        } else {
            std::cout << Color::RED << "Computer wins!" << Color::RESET << std::endl;
        }
    }

    std::cout << "\nGame Over!" << std::endl;
    std::string playAgain;
    std::cout << "Do you want to play again? (yes/no): ";
    std::cin >> playAgain;

    if (playAgain == "yes") {
        main();  // Recursive call to restart the game
    } else {
        std::cout << "Thank you for playing!" << std::endl;
    }

    return 0;
    */

 /* game math with 4 levels of qustions and asking for number of qustions

    srand(time(0));
    int numQuestions;
    int level;

    std::cout << "Enter the number of questions: ";
    std::cin >> numQuestions;

    std::cout << "Choose the level (1: Easy, 2: Medium, 3: Hard, 4: Mix): ";
    std::cin >> level;

    for (int i = 0; i < numQuestions; ++i) {
        askQuestion(level);
    }
    */

/* 1:07 PM 23/11/2023 VALIDATION if the input is number  
    int number;
    bool isValid = false;

    while (!isValid) {
        std::cout << "الرجاء إدخال رقم: ";
        if (std::cin >> number) {
            // تم إدخال رقم صحيح
            isValid = true;
        } else {
            // يحدث عند إدخال قيمة غير صحيحة
            std::cout << "خطأ! يجب أن يكون المدخل رقمًا." << std::endl;
            std::cin.clear(); // إعادة تهيئة حالة الإدخال
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // تفادي الإدخال المتبقي
        }
    }

    std::cout << "لقد تم إدخال الرقم: " << number << std::endl;
    return 0;
    */

/*4:59 pm  23/11/2023 طباعة ما بين رقمين 
    int M, N;
    std::cout << "Enter two numbers (M and N): ";
    std::cin >> M >> N;

    std::cout << "Numbers from " << M << " down to " << N << " are: ";
    printNumbers(M, N);
    return 0;
    */

/* دالة القوة 
    int N, M;
    std::cout << "Enter two numbers (N and M): ";
    std::cin >> N >> M;

    std::cout << "Result of " << N << " raised to the power " << M << " is: " << power(N, M);
    return 0;
*/

/* 6:00 pm 23/11/2023 طباعة جدول
printtable();
*/

/* 7:17 pm 23/11/2023 عمل مصفوفة ببعدين 
int x[2][2]={

{2,2}
,{2,2}
};
*/

/* طباعة محتوى مصفوفة ذات بعدين مع استخدام دالة التنسيق النصي 
    const int size = 10;
    int multiplicationTable[size][size];

    // Generate multiplication table
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            multiplicationTable[i][j] = (i + 1) * (j + 1);
        }
    }

    // Print formatted multiplication table
    std::cout << "Multiplication Table 10x10:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%02d\t", multiplicationTable[i][j]);
        }
        std::cout << std::endl;
    }

    return 0;
    */

/* 8:58 pm 23/11/2023 استعمال لل vectors
vector <int> vNumbers;
vNumbers.push_back(10);
vNumbers. push_back(20);
vNumbers. push_back(30);
vNumbers. push_back(40);
vNumbers. push_back(50);
vNumbers. push_back(60);
vNumbers. push_back(70);
vNumbers. push_back(80);
vNumbers. push_back(90);
cout << "Numbers Vector: \n\n";
// ranged Loop
for (int & Number : vNumbers) 
cout << Number << endl;
}
*/

/* طباعة العناصر المخزنة داخل ال vectors b n m,k,.x 
        std::vector<int> numbers;
        int num;
        char choice;
    
        do {
            std::cout << "Enter a number: ";
            std::cin >> num;
            numbers.push_back(num);
    
            std::cout << "Do you want to add more numbers? (Y/N): ";
            std::cin >> choice;
        } while (toupper(choice) == 'Y');
    
        std::cout << "Vector elements: ";
        for (int number : numbers) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
            return 0;
            */

/* نظام ادخال وطباعة رقم واسم الموظف باستعمال vector
    std::vector<Employee> employees;
    char addMore;

    do {
        Employee emp;
        bool idExists;

        do {
            std::cout << "Enter employee ID: ";
            std::cin >> emp.employeeID;

            idExists = isIDExists(employees, emp.employeeID);
            if (idExists) {
                std::cout << "ID already exists. Please enter a different ID.\n";
            }
        } while (idExists);

        std::cout << "Enter employee name: ";
        std::cin.ignore(); // Ignore the newline character from previous input
        std::getline(std::cin, emp.name);

        employees.push_back(emp);

        std::cout << "Do you want to add more employees? (Y/N): ";
        std::cin >> addMore;
    } while (addMore == 'Y' || addMore == 'y');

    std::cout << "\nEmployee records:\n";
    for (const auto& emp : employees) {
        std::cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << std::endl;
    }

    return 0;
*/

/* تعديل لنظام ادخال وطباعة معلومات الموظف مع تنسيق المخرجات
    std::vector<Employee> employees;
    char addMore;

    do {
        Employee emp;
        bool idExists;

        do {
            emp.employeeID = Employee::nextID++;
            idExists = isIDExists(employees, emp.employeeID);
        } while (idExists);

        std::cout << "Enter employee first name: ";
        std::cin >> emp.firstName;

        std::cout << "Enter employee last name: ";
        std::cin >> emp.lastName;

        std::cout << "Enter employee salary: ";
        std::cin >> emp.salary;

        employees.push_back(emp);

        std::cout << "Do you want to add more employees? (Y/N): ";
        std::cin >> addMore;
    } while (addMore == 'Y' || addMore == 'y');

    std::cout << "\nEmployee records:\n";
    std::vector<int> columnWidths = { 8, 20, 20, 8 };

    printHorizontalLine(3 + std::accumulate(columnWidths.begin(), columnWidths.end(), 0));
    std::cout << "| ID     | First Name         | Last Name          | Salary |\n";
    printHorizontalLine(3 + std::accumulate(columnWidths.begin(), columnWidths.end(), 0));

    for (const auto& emp : employees) {
        printData(std::to_string(emp.employeeID), columnWidths[0]);
        printData(emp.firstName, columnWidths[1]);
        printData(emp.lastName, columnWidths[2]);
        printData(std::to_string(emp.salary), columnWidths[3]);
        std::cout << "|" << std::endl;
    }

    printHorizontalLine(3 + std::accumulate(columnWidths.begin(), columnWidths.end(), 0));

    return 0;
    */

/*10:46 pm 24/11/2023 playing with pointers
int a = 10;
int b = 50;
cout << "a value";
cout << "a address";
int * p;
p = &a;
p = &b;
cout << "= " << a << endl;
cout <<"= " << & a << endl;
cout << "Pointer Value = " << p;
cout << endl;
return 0;
*/

/* 1:01 pm 24/11/2023 تبديل محتويات مؤشرين 
    int a = 1, b = 2;
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(&a, &b);
    cout << "\nAfter swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
*/

/* دوال متعلقة بتعديل الحروف من صيغرة الى كبيرة وبالعكس وتحديد نوعها 
    char x ;
    char w ;
    x = toupper('a');
    w = tolower('A');
    cout << "converting a to A: " << x << endl;
    cout << "converting A to a: " << w << endl;
    // Digits (A to Z)
    // returns zero if not, and non zero of yes
    cout << "isupper('A') " << isupper( 'A') << endl;
    // lower case (a to z)
    // returns zero if not, and non zero of yes
    cout << "islower('a') " << islower('a') << endl;
    // Digits (0 to 9)
    // returns zero if not, and non zero of yes
    cout << "isdigit('9') " << isdigit ('9') << endl;
    // punctuation characters are !"#$%&'()*+, -. / :;<= >?@[\]^_{|}~
    // punctuation characters are !"#$
    // returns zero if not, and non zero of yes
    cout << "ispunct(';') " << ispunct(';') << endl;
*/

/* new files with writing  
    fstream MyFile;
    MyFile.open("MyFile.txt", ios :: out);//Write Mode
    if (MyFile.is_open())
    MyFile << "Hi, this is the first line\n";
    MyFile << "Hi, this is the second line\n";
    MyFile << "Hi, this is the third line\n";
    MyFile.close();


fstream MyFile_;
MyFile_.open("MyFile_.txt", ios::out | ios::app );//append Mode
if (MyFile_.is_open())
MyFile_ << "Hi, this is a new line\n";
MyFile_ << "Hi, this is another new line\n";
MyFile_.close();
return 0;
*/

/* قراءة الملف عبر الشاشة
PrintFileContenet("MyFile.txt");
*/

/* حقظ محتويات ملف داخل vector
vector <string> vFileContenet;
LoadDataFromFileToVector("MyFile__.txt", vFileContenet);
for (string Line : vFileContenet)
cout << Line << endl;
*/

/* حفظ محتويات الvector داخل الملف 
vector <string> vFileContenet{ "Ali", "Shadi", "Maher", "Fadi", "Lama"};
SaveVectorToFile("MyFile.txt", vFileContenet);
return 0;
*/

/*6:32 pm 24/11/2023 حذف محتويات الملف
    cout << "File Content Before Delete. \n";
    PrintFileContent("MyFile.txt");
    DeleteRecordFromFile("MyFile.txt", "Ali");
    cout << "\n\nFile Content After Delete. \n";
    PrintFileContent("MyFile.txt");
    return 0;
    */

/* طباعة تاريخ اليوم الى الثواني
    time_t t = time(0);
    tm* now = localtime(&t);
    cout << "Year: " << now->tm_year + 1900 << endl;
     << "Month: " << now->tm_mon + 1 << endl;
     << "Day: " << now->tm_mday << endl;
     << "Hour: " << now->tm_hour << endl;
     << "Min: " << now->tm_min << endl;
     << "Second: " << now->tm_sec << endl;
     << "Week Day (Days since sunday): " << now->tm_wday << endl;
     << "Year Day (Days since Jan 1st): " << now->tm_yday << endl;
     << "hours of daylight savings time: " << now->tm_isdst << endl;
// get time now
*/

/* print Local date and time is ,UTC date and time is
time_t t = time(0);
char* dt = ctime(&t);
cout << "Local date and time is: " << dt << "\n";
tm* gmtm = gmtime(&t);
dt = asctime(gmtm);
cout << "UTC date and time is: " << dt;
// get time now
// convert in string form
// converting now to tm struct for UTC date/time
*/

/* طباعة عناصر مصفوفة عشوائية 
    // Define a 3x3 matrix
    int matrix[3][3];

    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Change range as needed

    // Fill the matrix with random numbers
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = dis(gen);
        }
    }

    // Display the filled matrix
    std::cout << "Random 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
    */

/* 7:58 pm 23/11/2023 طباعة عناصر مصفوفة عشوائية 3*3
//Seeds the random number generator in C++, called only once
  // Include for time()

    srand(static_cast<unsigned>(time(NULL)));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\n The following is a 3x3 random matrix: \n";

    PrintMatrix(arr, 3, 3);
    system("pause>0");
    return 0;
    */

/* طباعة حاصل جمع كل صف في مصفوفة
    srand(static_cast<unsigned>(time(NULL)));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    PrintRowSums(arr, 3, 3);

    return 0;
*/

/* طباعة حاصل جمع كل صف في المصفوفة بعد تخزينه في مصفوفة اخرى ذات بعد واحد
    srand(static_cast<unsigned>(time(NULL)));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    int rowSums[3];
    CalculateRowSums(arr, rowSums, 3, 3);
    PrintRowSums(rowSums, 3);

    return 0;
*/

/*حاصل جمع كل عامود في مصفوفة
    srand(static_cast<unsigned>(time(NULL)));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    PrintColumnSums(arr, 3, 3);

    return 0;
    */

/* حاصل جمع كل عامود وحفظه في مصفوفة اخرى وطباعته
    srand(static_cast<unsigned>(time(NULL)));

    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    int colSums[3];
    CalculateColumnSums(arr, colSums, 3, 3);
    PrintColumnSums(colSums, 3);

    return 0;
*/

/* ملئ المصفوفة باعداد فردية 
    int orderedMatrix[3][3];
    FillOrderedMatrix(orderedMatrix);

    cout << "The 3x3 matrix with ordered numbers:\n";
    PrintMatrix(orderedMatrix);

    return 0;
*/

/* طباعة ناتج تبديل الصف بالعامود في مصفوفة
    int orderedMatrix[3][3];
    FillOrderedMatrix(orderedMatrix);

    cout << "The 3x3 matrix with ordered numbers:\n";
    PrintMatrix(orderedMatrix);

    TransposeMatrix(orderedMatrix);

    cout << "\nTransposed matrix:\n";
    PrintMatrix(orderedMatrix);

    return 0;
*/

/*9:41 pm 24/11/2023 طباعة ناتج ضرب ما داخل مصفوفتين بعد تخزينه في مصفوفة ذات 3 ابعاد
    srand(static_cast<unsigned>(time(NULL)));

    int matrix1[3][3];
    int matrix2[3][3];
    int resultMatrix[3][3];

    FillMatrixWithRandomNumbers(matrix1,3,3);
    FillMatrixWithRandomNumbers(matrix2,3,3);

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1);

    cout << "\nMatrix 2:\n";
    PrintMatrix(matrix2);

    MultiplyMatrices(matrix1, matrix2, resultMatrix);

    cout << "\nResultant Matrix after multiplication:\n";
    PrintMatrix(resultMatrix);

    return 0;
    */

/* طباعة الصف الأوسط والعامود  في مصفوفة
    srand(static_cast<unsigned>(time(NULL)));

    int matrix[3][3];
    FillMatrixWithRandomNumbers(matrix);

    cout << "The 3x3 matrix with random numbers:\n";
    PrintMatrix(matrix);

    PrintMiddleRow(matrix);
    PrintMiddleColumn(matrix);

    return 0;
*/
    
/* 10:22 pm 24/11/2023 طباعة حاصل جمع جميع الارقام في المصفوفة 
    srand(static_cast<unsigned>(time(NULL)));

    int matrix1[3][3];
    int matrix2[3][3];

    FillMatrixWithRandomNumbers(matrix1);
    FillMatrixWithRandomNumbers(matrix2);

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1);

    cout << "\nMatrix 2:\n";
    PrintMatrix(matrix2);

    int sumMatrix1 = SumOfMatrix(matrix1);
    int sumMatrix2 = SumOfMatrix(matrix2);

    cout << "\nSum of numbers in Matrix 1: " << sumMatrix1 << endl;
    cout << "Sum of numbers in Matrix 2: " << sumMatrix2 << endl;

    return 0;
*/

/* التحقق اذا كانت مصفوفتان متساويتان 
    srand(static_cast<unsigned>(time(NULL)));

    int matrix1[3][3];
    int matrix2[3][3];

    FillMatrixWithRandomNumbers(matrix1);
    FillMatrixWithRandomNumbers(matrix2);

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1);

    cout << "\nMatrix 2:\n";
    PrintMatrix(matrix2);

    if (AreMatricesEqual(matrix1, matrix2,3,3)) {
        cout << "\nThe matrices are equal.\n";
    } else {
        cout << "\nThe matrices are not equal.\n";
    }

    return 0;
*/

/* 10:38 pm 24/11/2023 التحقق ما اذا كانت مصفوفتان متطابقتان
srand(static_cast<unsigned>(time(NULL)));

    int matrix1[3][3];
    int matrix2[3][3];

    FillMatrixWithRandomNumbers(matrix1);

    // To create a typical matrix, set matrix2 equal to matrix1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix2[i][j] = matrix1[i][j];
        }
    }

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1);

    cout << "\nMatrix 2 (Typical, identical to Matrix 1):\n";
    PrintMatrix(matrix2);

    if (AreMatricesIdentical(matrix1, matrix2)) {
        cout << "\nThe matrices are typical (identical).\n";
    } else {
        cout << "\nThe matrices are not typical (not identical).\n";
    }

    return 0;
*/

/* التحقق ما اذا كانت المصفوفة العشوائية متطابقة من حيث الشكل المعروف رياضيا
    int matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "Given Matrix:\n";
    PrintMatrix(matrix);

    if (IsIdentityMatrix(matrix)) {
        cout << "\nThe given matrix is an identity matrix.\n";
    } else {
        cout << "\nThe given matrix is not an identity matrix.\n";
    }

    return 0;
    */

/* التحقق ما اذا كانت المصفوفة العشوائية scaler 
    int matrix[3][3] = {
        {5, 0, 0},
        {0, 5, 0},
        {0, 0, 5}
    };

    cout << "Given Matrix:\n";
    PrintMatrix(matrix);

    if (IsScalarMatrix(matrix)) {
        cout << "\nThe given matrix is a scalar matrix.\n";
    } else {
        cout << "\nThe given matrix is not a scalar matrix.\n";
    }

    return 0;
    */

/* 11:20 pm 24/11/2023 التحقق من عدد عنصر موجود في مصفوفة مع إدخال عناصرها 
int matrix[3][3];
    int numberToCount;
    
    // Input matrix elements
    cout << "Enter 3x3 matrix elements:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Input the number to count
    cout << "Enter the number to count its occurrences: ";
    cin >> numberToCount;

    cout << "\nGiven Matrix:\n";
    PrintMatrix(matrix, 3, 3);

    int count = CountOccurrences(matrix, 3, 3, numberToCount);
    cout << "\nThe number of occurrences of " << numberToCount << " in the matrix is: " << count << endl;

    return 0;
    */

/* التحقق من مصفوفة عشوائية انها sparse (لديها 6 أصفار)
    int matrix[3][3] = {
        {1, 0, 0},
        {0, 5, 0},
        {0, 0, 0}
    };

    cout << "Given Matrix:\n";
    PrintMatrix(matrix);

    if (IsSparseMatrix(matrix)) {
        cout << "\nThe given matrix is sparse.\n";
    } else {
        cout << "\nThe given matrix is not sparse.\n";
    }

    return 0;

*/

/*التحقق ما اذا كان رقم موجود في مصفوفة عشوائية
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int numberToFind;
    cout << "Enter the number to find in the matrix: ";
    cin >> numberToFind;

    cout << "\nGiven Matrix:\n";
    PrintMatrix(matrix);

    if (NumberExistsInMatrix(matrix, numberToFind)) {
        cout << "\nThe number " << numberToFind << " exists in the matrix.\n";
    } else {
        cout << "\nThe number " << numberToFind << " does not exist in the matrix.\n";
    }

    return 0;
*/

/* معرفة المكرر في مصفوفة مع إعطاء القدرة على ملئ المصفوفة عشوائيا او بلإدخال
    int matrix1[3][3];
    int matrix2[3][3];

    char choice;
    cout << "Choose a method to enter the matrix elements (R for random, M for manual): ";
    cin >> choice;

    switch (choice) {
        case 'R':
        case 'r':
            FillMatrixWithRandomNumbers(matrix1);
            FillMatrixWithRandomNumbers(matrix2);
            break;
        case 'M':
        case 'm':
            EnterMatrixElements(matrix1);
            EnterMatrixElements(matrix2);
            break;
        default:
            cout << "Invalid choice! Exiting...\n";
            return 1;
    }

    PrintMatrix(matrix1);
    PrintMatrix(matrix2);

    FindIntersectedNumbers(matrix1, matrix2);

    return 0;
    */

/* طباعة المشترك بين مصفوفتين مع إعطاء القدرة على ملئ المصفوفة عشوائيا او بلإدخال
    int matrix1[3][3];
    int matrix2[3][3];

    char choice;
    cout << "Choose a method to enter the matrix elements (R for random, M for manual): ";
    cin >> choice;

    switch (choice) {
        case 'R':
        case 'r':
            FillMatrixWithRandomNumbers(matrix1);
            FillMatrixWithRandomNumbers(matrix2);
            break;
        case 'M':
        case 'm':
            EnterMatrixElements(matrix1);
            EnterMatrixElements(matrix2);
            break;
        default:
            cout << "Invalid choice! Exiting...\n";
            return 1;
    }

    cout << "Matrix 1:\n";
    PrintMatrix(matrix1);

    cout << "Matrix 2:\n";
    PrintMatrix(matrix2);

    FindIntersectedNumbers(matrix1, matrix2);

    return 0;
    */

/* finding the maximum and the minumim elements in the matrix with (abilty to randomlly/entering elements)
    int matrix[3][3];

    char choice;
    cout << "Choose a method to enter the matrix elements (R for random, M for manual): ";
    cin >> choice;

    switch (choice) {
        case 'R':
        case 'r':
            FillMatrixWithRandomNumbers(matrix);
            break;
        case 'M':
        case 'm':
            EnterMatrixElements(matrix);
            break;
        default:
            cout << "Invalid choice! Exiting...\n";
            return 1;
    }

    PrintMatrix(matrix);
    FindMinMaxNumbers(matrix);

    return 0;
    */

/* is the matrix is Palindrome
    int matrix[3][3] = {
        {1, 2, 1},
        {4, 5, 4},
        {7, 8, 7}
    };

    if (IsMatrixPalindrome(matrix)) {
        cout << "The matrix is a palindrome.\n";
    } else {
        cout << "The matrix is not a palindrome.\n";
    }

    return 0;
    */

/* print Fibonacci Series .
    cout << "Fibonacci Series of length 10:\n";
    printFibonacci(10);

    return 0;
*/

/* (استدعاء الدالة داخل نفسها ) طباعة متسلسلة فيبوناسي
    cout << "Fibonacci Series of length 10 using recursion:\n";
    printFibonacci(10);

    return 0;
    */

/* 1:13 am 25/11/2023 طباعة اول حرف من كل كلمة 
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "First letters of each word in the string: ";
    printFirstLetters(inputString);

    return 0;
    */

/* converting every frist letter in the string to lower case
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "String with the first letter of each word in lowercase: ";
    lowercaseFirstLetters(inputString);

    return 0;
*/

/* covirting string 's first letter to capital case 
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "String with the first letter of each word in uppercase: ";
    uppercaseFirstLetters(inputString);

    return 0;
*/

/* طباعة حالة تحويل كل الاحرف الى كبيرة والى صغيرة 
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    // Convert all characters to uppercase
    for (char &c : inputString) {
        c = toupper(c);
    }

    cout << "Uppercase string: " << inputString << endl;

    // Convert all characters to lowercase
    for (char &c : inputString) {
        c = tolower(c);
    }

    cout << "Lowercase string: " << inputString << endl;

    return 0;
*/

/* 1:38 am 25/11/2023 تغيير حالة الى صغيرة او كبيرة
    char inputChar;

    cout << "Enter a character: ";
    cin >> inputChar;

    // Check if the character is uppercase or lowercase and invert its case
    if (islower(inputChar)) {
        inputChar = toupper(inputChar);
    } else if (isupper(inputChar)) {
        inputChar = tolower(inputChar);
    }

    cout << "Inverted case character: " << inputChar << endl;

    return 0;
    */

/* تغيير حالة الحرف على مستوى الحرف الكبير الى صغير والعكس
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    // Invert the case of each character in the string
    for (char &c : inputString) {
        if (islower(c)) {
            c = toupper(c);
        } else if (isupper(c)) {
            c = tolower(c);
        }
    }

    cout << "Inverted case string: " << inputString << endl;

    return 0;
    */

/* حساب عدد الأحرف الصغيرة او الكبيرة وطول النص
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    countLetters(inputString);

    return 0;
*/

/* 12:14 pm 25/11/2023 البحث عن عدد اي حرف في أي نص 
    string inputString;
    char inputChar;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "Enter a character to count: ";
    cin >> inputChar;

    int occurrences = countCharacter(inputString, inputChar);
    cout << "The character '" << inputChar << "' appears " << occurrences << " times in the string." << endl;

    return 0;
*/

/* طباعة عدد حرف معين مع إعطاء القدرة على (التفرقة بين الحرف الكبير والصغير)
    string inputString;
    char inputChar;
    char matchCaseInput;

    cout << "Enter a string: ";
    getline(cin, inputString);

    cout << "Enter a character to count: ";
    cin >> inputChar;

    cout << "Match case? (Y/N): ";
    cin >> matchCaseInput;
    bool matchCase = (matchCaseInput == 'Y' || matchCaseInput == 'y');

    int occurrences = countCharacter(inputString, inputChar, matchCase);
    cout << "The character '" << inputChar << "' appears " << occurrences << " times in the string." << endl;

    return 0;
*/

/* معرفة اذا كان الحرف المدخل حرف عله
    char inputChar;

    cout << "Enter a character: ";
    cin >> inputChar;

    if (isalpha(inputChar)) {
        if (isVowel(inputChar)) {
            cout << inputChar << " is a vowel." << endl;
        } else {
            cout << inputChar << " is not a vowel." << endl;
        }
    } else {
        cout << "Invalid input. Please enter an alphabetic character." << endl;
    }

    return 0;
    */

/* حساب عدد حروف العله في نص
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    int vowels = countVowels(inputString);
    cout << "The number of vowels in the string is: " << vowels << endl;

    return 0;

*/

/*طباعة حروف العله في اي نص
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    printVowels(inputString);

    return 0;
*/

/* 1:04 pm 25/11/2023 طباعة كل كلمة في سطر
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    printWords(inputString);

    return 0;
    */

/* حساب عدد الكلمات في النص
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    int words = countWords(inputString);
    cout << "Number of words in the string: " << words << endl;

    return 0;
*/

/* read a string then make a function to split each word in vector. print each word in sentence
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    vector<string> wordVector = splitWords(inputString);

    cout << "Words in the vector:" << endl;
    for (const string& word : wordVector) {
        cout << word << endl;
    }

    return 0;
*/

/* حساب عدد الكلمات وطباعة كل كلمة في سطر
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    int tokens;
    vector<string> tokenizedWords = tokenizeString(inputString, tokens);

    cout << "Number of words (tokens) in the string: " << tokens << endl;
    cout << "Words in the sentence:" << endl;
    for (const string& word : tokenizedWords) {
        cout << word << endl;
    }

    return 0;
    */

/* Write a program to read a string then Trim Left, Right , All
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    string trimmedLeft = trimLeft(inputString);
    string trimmedRight = trimRight(inputString);
    string trimmedAll = trimAll(inputString);

    cout << "Trimmed Left: '" << trimmedLeft << "'" << endl;
    cout << "Trimmed Right: '" << trimmedRight << "'" << endl;
    cout << "Trimmed All: '" << trimmedAll << "'" << endl;

    return 0;
    */

/* 2:08 pm 25/11/2023 rinting the element sof the vector as a one string 
   : vector<string> words = {"Hello", "World", "from", "ChatGPT!"};
    string separator = " ";

    string result = joinStrings(words, separator);

    cout << "Joined string with separator '" << separator << "': " << result << endl;

    return 0;
    */

/* طباعة النص من الكلمة الاخيرة الى الكلمة الاولى
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    string reversedWords = reverseWords(inputString);

    cout << "String with reversed words: " << reversedWords << endl;

    return 0;
    */

/* تبديل كلمات النص المدخل بكلمات عشوائية 
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    unordered_map<string, string> replaceMap = {
        {"word1", ""}, {"word2", ""}, {"word3", ""}, {"word4", ""}, {"word5", ""}
        // Add more placeholders as needed
    };

    vector<string> wordList = generateWordList();
    for (size_t i = 0; i < wordList.size(); ++i) {
        string placeholder = "word" + to_string(i + 1);
        replaceMap[placeholder] = wordList[i];
    }

    string replacedString = replaceWords(inputString, replaceMap);

    cout << "Original String: " << inputString << endl;
    cout << "String after replacements: " << replacedString << endl;

    return 0;
    */

/* 3:26 pm 25/11/2023 ازالة اي علمات تنصيص من النص
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    std::cout << "Original String: " << std::endl;
    std::cout << inputString << std::endl;

    std::string withoutPunctuation = removePunctuation(inputString);
    std::cout << "Punctuation Removed: " << std::endl;
    std::cout << withoutPunctuation << std::endl;

    return 0;
    */

/* إدخال معلومات بنكية وطباعتها بتنسيق معين 
    ClientData client;

    std::cout << "Please Enter Client Data:" << std::endl;
    std::cout << "Enter Account Number? ";
    std::cin >> client.accountNumber;

    std::cout << "Enter PinCode? ";
    std::cin >> client.pinCode;

    std::cin.ignore();  // Ignore newline character in the input buffer

    std::cout << "Enter Name? ";
    std::getline(std::cin, client.name);

    std::cout << "Enter Phone? ";
    std::cin >> client.phone;

    std::cout << "Enter AccountBalance? ";
    std::cin >> client.accountBalance;

    std::cout << "Client Record for Saving is:" << std::endl;
    std::cout << client.accountNumber << "#//#" << client.pinCode << "#//#"
              << client.name << "#//#" << client.phone << "#//#"
              << std::fixed << std::setprecision(6) << client.accountBalance << std::endl;

    return 0;
    */

/* 4:13 pm 25/11/2023 إدخال معلومات بنكية بتنسيق معين للإستخلاص البيانات منها
    std::string lineData;
    std::cout << "Line Record is:" << std::endl;
    std::getline(std::cin, lineData);

    // Replace '#//#' with newline '\n'
    size_t pos = 0;
    while ((pos = lineData.find("#//#", pos)) != std::string::npos) {
        lineData.replace(pos, 4, "\n");
        pos += 1;  // Move past the replaced newline
    }

    std::cout << "The following is the extracted client record:" << std::endl;
    std::cout << lineData << std::endl;

    return 0;
    */

/* إدارة إدخال بيانات عملاء بنك واخراجها الى ملف 
    std::ofstream file("clients.txt", std::ios::app); // Open file in append mode
    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    char addMore;
    do {
        ClientData client;

        std::cout << "Adding New Client:" << std::endl;
        std::cout << "Enter Account Number: ";
        std::getline(std::cin, client.accountNumber);

        std::cout << "Enter Pin Code: ";
        std::getline(std::cin, client.pinCode);

        std::cout << "Enter Name: ";
        std::getline(std::cin, client.name);

        std::cout << "Enter Phone: ";
        std::getline(std::cin, client.phone);

        std::cout << "Enter Account Balance: ";
        std::cin >> client.accountBalance;
        std::cin.ignore(); // Ignore the newline in the input buffer

        file << client.accountNumber << '#' << client.pinCode << '#' << client.name << '#'
             << client.phone << '#' << client.accountBalance << std::endl;

        std::cout << "Client Added Successfully. Do you want to add more clients? (y/n): ";
        std::cin >> addMore;
        std::cin.ignore(); // Ignore the newline in the input buffer
    } while (addMore == 'y' || addMore == 'Y');

    file.close(); // Close the file
    return 0;
*/

/* طباعة محتويات ملف عن عملاء البنك بتنسيق معين ومع عداد يبين اعداد العملاء
    std::ifstream file("clients.txt");
    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::vector<ClientData> clients;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        ClientData client;

        std::getline(iss, client.accountNumber, '#');
        std::getline(iss, client.pinCode, '#');
        std::getline(iss, client.name, '#');
        std::getline(iss, client.phone, '#');
        iss >> client.accountBalance;

        clients.push_back(client);
    }
    file.close();

    std::cout << "_____________________________________________________________________________" << std::endl;
    std::cout << "Client List (" << clients.size() << ") Client(s)." << std::endl;
    std::cout << std::setw(17) << "| Account Number" << std::setw(12) << "| Pin Code" << std::setw(20)
              << "| Client Name" << std::setw(10) << "| Balance" << std::setw(15) << "| Phone" << std::endl;
    std::cout << "_____________________________________________________________________________" << std::endl;

    for (const auto& client : clients) {
        std::cout << std::setw(17) << client.accountNumber << std::setw(12) << client.pinCode
                  << std::setw(20) << client.name << std::setw(10) << client.accountBalance
                  << std::setw(15) << client.phone << std::endl;
    }

    std::cout << "_____________________________________________________________________________" << std::endl;

    return 0;
    */

/* إستخراج معلومات العميل عبر رقم الحساب عند القراءة من ملف
    std::ifstream file("clients.txt");
    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::vector<ClientData> clients;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        ClientData client;

        std::getline(iss, client.accountNumber, '#');
        std::getline(iss, client.pinCode, '#');
        std::getline(iss, client.name, '#');
        std::getline(iss, client.phone, '#');
        iss >> client.accountBalance;

        clients.push_back(client);
    }
    file.close();

    std::string searchAccountNumber;
    bool found = false;

    std::cout << "Please enter AccountNumber: ";
    std::cin >> searchAccountNumber;

    for (const auto& client : clients) {
        if (client.accountNumber == searchAccountNumber) {
            found = true;
            std::cout << "The following are the client details:" << std::endl;
            std::cout << "Account Number: " << client.accountNumber << std::endl;
            std::cout << "Pin Code: " << client.pinCode << std::endl;
            std::cout << "Name: " << client.name << std::endl;
            std::cout << "Phone: " << client.phone << std::endl;
            std::cout << "Account Balance: " << client.accountBalance << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Client with Account Number (" << searchAccountNumber << ") Not Found!" << std::endl;
    }

    return 0;
    */

/* حذف معلومات عميل عبر رقم الحساب ومع رسالة تأكيد 
    std::ifstream file("clients.txt");
    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::vector<ClientData> clients;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        ClientData client;

        std::getline(iss, client.accountNumber, '#');
        std::getline(iss, client.pinCode, '#');
        std::getline(iss, client.name, '#');
        std::getline(iss, client.phone, '#');
        iss >> client.accountBalance;

        clients.push_back(client);
    }
    file.close();

    std::string deleteAccountNumber;
    bool found = false;

    std::cout << "Please enter AccountNumber: ";
    std::cin >> deleteAccountNumber;

    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->accountNumber == deleteAccountNumber) {
            found = true;
            std::cout << "The following are the client details:" << std::endl;
            std::cout << "Account Number: " << it->accountNumber << std::endl;
            std::cout << "Pin Code: " << it->pinCode << std::endl;
            std::cout << "Name: " << it->name << std::endl;
            std::cout << "Phone: " << it->phone << std::endl;
            std::cout << "Account Balance: " << it->accountBalance << std::endl;

            char confirmation;
            std::cout << "Are you sure you want to delete this client? (y/n): ";
            std::cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                clients.erase(it);
                std::ofstream outFile("clients.txt");
                for (const auto& client : clients) {
                    outFile << client.accountNumber << "#//#" << client.pinCode << "#//#"
                            << client.name << "#//#" << client.phone << "#//#" << client.accountBalance << std::endl;
                }
                outFile.close();
                std::cout << "Client Deleted Successfully." << std::endl;
            } else {
                std::cout << "Client Deletion Cancelled." << std::endl;
            }
            break;
        }
    }

    if (!found) {
        std::cout << "Client with Account Number (" << deleteAccountNumber << ") Not Found!" << std::endl;
    }

    return 0;
    */

/* 11:50 am 26/11/2023 تحديث معلومات العميل في ملف عبر إدخال رقم الحساب 
   
    std::ifstream file("clients.txt");
    if (!file.is_open()) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::vector<ClientData> clients;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        ClientData client;

        std::getline(iss, client.accountNumber, '#');
        std::getline(iss, client.pinCode, '#');
        std::getline(iss, client.name, '#');
        std::getline(iss, client.phone, '#');
        iss >> client.accountBalance;

        clients.push_back(client);
    }
    file.close();

    std::string updateAccountNumber;
    bool found = false;

    std::cout << "Please enter AccountNumber: ";
    std::cin >> updateAccountNumber;

    for (auto& client : clients) {
        if (client.accountNumber == updateAccountNumber) {
            found = true;
            std::cout << "The following are the client details:" << std::endl;
            std::cout << "Account Number: " << client.accountNumber << std::endl;
            std::cout << "Pin Code: " << client.pinCode << std::endl;
            std::cout << "Name: " << client.name << std::endl;
            std::cout << "Phone: " << client.phone << std::endl;
            std::cout << "Account Balance: " << client.accountBalance << std::endl;

            char confirmation;
            std::cout << "Are you sure you want to update this client? (y/n): ";
            std::cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                std::cout << "Enter PinCode: ";
                std::cin >> client.pinCode;
                std::cout << "Enter Name: ";
                std::cin.ignore(); // Ignore newline character in buffer
                std::getline(std::cin, client.name);
                std::cout << "Enter Phone: ";
                std::cin >> client.phone;
                std::cout << "Enter AccountBalance: ";
                std::cin >> client.accountBalance;

                std::ofstream outFile("clients.txt");
                for (const auto& updatedClient : clients) {
                    outFile << updatedClient.accountNumber << "#//#" << updatedClient.pinCode << "#//#"
                            << updatedClient.name << "#//#" << updatedClient.phone << "#//#" << updatedClient.accountBalance << std::endl;
                }
                outFile.close();
                std::cout << "Client Updated Successfully." << std::endl;
            } else {
                std::cout << "Client Update Cancelled." << std::endl;
            }
            break;
        }
    }

    if (!found) {
        std::cout << "Client with Account Number (" << updateAccountNumber << ") Not Found!" << std::endl;
    }

    return 0;
    */

// Define other functions for deleteClient(), updateClientInfo(), findClient()...

/* 1:05 pm 26/11/2023 نظام إدارة حساب العملاء 6 وظائف أساسية
    
    int choice;
    do {
        std::cout << "Main Menu Screen\n";
        std::cout << "[1] Show Client List .\n";
        std::cout << "[2] Add New Client .\n";
        std::cout << "[3] Delete Client .\n";
        std::cout << "[4] Update Client Info .\n";
        std::cout << "[5] Find Client .\n";
        std::cout << "[6] Exit.\n";
        std::cout << "Choose what do you want to do? [1 to 6]: ";

        std::cin >> choice;
        switch (choice) {
            case 1:
                showClientList();
                break;
            case 2:
                addNewClient();
                break;
            case 3:
                deleteClient();
                break;
            case 4:
                updateClientInfo();
                break;
            case 5:
                findClient();
                break;
            case 6:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                break;
        }
    } while (choice != 6);

    return 0;
*/

/* Bank System Adminstration 
    char choice;
    do {
        ShowMainMenue();
        cout << "Choose what do you want to do? [1 to 6]? ";
        cin >> choice;

        switch (choice) {
            case '1':
                ShowAllCLientsScreen();
                break;
            case '2':
                ShowAddNewClientsScreen();
                break;
            case '3':
                ShowDeleteClientScreen();
                break;
            case '4':
                ShowUpdateClientScreen();
                break;
            case '5':
                ShowFindClientScreen();
                break;
            case '6':
                ShowEndScreen();
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
                break;
        }
    } while (choice != '6');

    return 0;
*/  

/* 2:07 pm 27/11/2023 a transaction extention to the bank Adminstraion system
vector <stClient> vClients = loadClientDataFromFile(clientFileName);
	mainMenueScreen(vClients);
*/

/* 5:44 pm 27/11/2023 addtion to bank adminstraion system
    ShowMainMenue();
    system("pause>0");
    return 0;
    */

/* 6:16 pm 27/11/2023 converting any number to text 
    int number;
    cout << "Enter a Number? ";
    cin >> number;

    string result = numberToWords(number);
    cout << result << endl;

    return 0;
*/

/* 7:00 pm 27/11/2023 chack if the the entering yeaer is a leap year
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    if (isLeapYear(year)) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }

    return 0;
    */

/* طباعة الايام والساعات والدقائق والثواني في سنة معينة (كبيسة او لا)
    int year;
    std::cout << "Please enter a year to check? ";
    std::cin >> year;

    int days = isLeapYear(year) ? 366 : 365;
    int hours = days * 24;
    int minutes = hours * 60;
    int seconds = minutes * 60;

    std::cout << "Number of Days in Year [" << year << "] is " << days << std::endl;
    std::cout << "Number of Hours in Year [" << year << "] is " << hours << std::endl;
    std::cout << "Number of Minutes in Year [" << year << "] is " << minutes << std::endl;
    std::cout << "Number of Seconds in Year [" << year << "] is " << seconds << std::endl;

    return 0;
    */

/* التحقق من عدد الأيام في شهر معين في أي سنة
    int year, month;

    std::cout << "Please enter a year to check? ";
    std::cin >> year;
    
    std::cout << "Please enter a Month to check? ";
    std::cin >> month;

    int days = daysInMonth(year, month);
    std::cout << "Number of Days in Month [" << month << "] is " << days << std::endl;

    return 0;
*/

/* 8:11 pm 27/11/2023 طباعة التاريخ واسم اليوم وعدده في الاسبوع
    int year, month, day;

    std::cout << "Please enter a year? ";
    std::cin >> year;

    std::cout << "Please enter a Month? ";
    std::cin >> month;

    std::cout << "Please enter a Day? ";
    std::cin >> day;

    struct std::tm timeinfo = {0};
    timeinfo.tm_year = year - 1900; // Years since 1900
    timeinfo.tm_mon = month - 1;    // Months start from 0
    timeinfo.tm_mday = day;        // Day of the month

    std::mktime(&timeinfo); // Normalize time structure

    // Get the day of the week (0 - Sunday, 1 - Monday, ..., 6 - Saturday)
    int dayOfWeek = timeinfo.tm_wday;

    const char* weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    std::cout << "Date : " << day << "/" << month << "/" << year << std::endl;
    std::cout << "Day Order : " << dayOfWeek << std::endl; // Day order (0 - Sun, 1 - Mon, ..., 6 - Sat)
    std::cout << "Day Name : " << weekdays[dayOfWeek] << std::endl; // Day name abbreviation (e.g., Sun, Mon, ...)
    
    return 0;
    */

/* 8:32 pm 27/11/2023 طباعة تقويم أي شهر تدخله
    int year, month;

    std::cout << "Please enter a year? ";
    std::cin >> year;

    std::cout << "Please enter a Month? ";
    std::cin >> month;

    printMonthCalendar(year, month);

    return 0;
    */

/* 9:08 pm 27/11/2023 طباعة تقويم السنة
    int year;

    std::cout << "Please enter a year? ";
    std::cin >> year;

    std::cout << "Calendar - " << year << std::endl;
    printYearCalendar(year);

    return 0;
    */

/* معرفة عدد الايام التي مرت في السنة منذ اي تاريخ
    int day, month, year;

    std::cout << "Please enter a Day? ";
    std::cin >> day;

    std::cout << "Please enter a Month? ";
    std::cin >> month;

    std::cout << "Please enter a Year? ";
    std::cin >> year;

    int totalDays = day;
    for (int i = 1; i < month; ++i) {
        totalDays += DaysInMonth(i, year);
    }

    std::cout << "Number of Days from the beginning of the year is " << totalDays << std::endl;

    return 0;
    */

/* Number of Days from the beginning of the year is 
    int day, month, year;

    std::cout << "Please enter a Day? ";
    std::cin >> day;

    std::cout << "Please enter a Month? ";
    std::cin >> month;

    std::cout << "Please enter a Year? ";
    std::cin >> year;

    int totalDays = calculateTotalDays(day, month, year);
    std::cout << "Number of Days from the beginning of the year is " << totalDays << std::endl;

    convertDaysToDate(totalDays, year);

    return 0;
*/

/* 5:48 PM 28/11/2023 check if Datel is Less than Date2

    Date date1, date2;

    std::cout << "Please enter Date1 (Day Month Year): ";
    std::cin >> date1.day >> date1.month >> date1.year;

    std::cout << "Please enter Date2 (Day Month Year): ";
    std::cin >> date2.day >> date2.month >> date2.year;

    if (isDate1LessThanDate2(date1, date2)) {
        std::cout << "Yes, Date1 is Less than Date2." << std::endl;
    } else {
        std::cout << "No, Date1 is not Less than Date2." << std::endl;
    }

    return 0;
    */

/* checks whether it's the last day of the month and the last month of the year.
    int day, month, year;

    std::cout << "Please enter a Day? ";
    std::cin >> day;

    std::cout << "Please enter a Month? ";
    std::cin >> month;

    std::cout << "Please enter a Year? ";
    std::cin >> year;

    bool lastDay = isLastDayOfMonth(day, month, year);
    bool lastMonth = isLastMonthOfYear(month);

    if (lastDay) {
        std::cout << "Yes, Day is Last Day in Month." << std::endl;
    } else {
        std::cout << "No, Day is not Last Day in Month." << std::endl;
    }

    if (lastMonth) {
        std::cout << "Yes, Month is Last Month in Year." << std::endl;
    } else {
        std::cout << "No, Month is not Last Month in Year." << std::endl;
    }

    return 0;
    */

/*  adding Date after one day is:
    Date date;

    std::cout << "Please enter a Day? ";
    std::cin >> date.day;

    std::cout << "Please enter a Month? ";
    std::cin >> date.month;

    std::cout << "Please enter a Year? ";
    std::cin >> date.year;

    Date nextDay = increaseByOneDay(date);

    std::cout << "Date after adding one day is: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << std::endl;

    return 0;
    */

/*حساب عدد الايام التي مرت منذ تاريخ معين الى تاريخ اخر 
    Date date1, date2;

    std::cout << "Please enter Date1 (Day Month Year): ";
    std::cin >> date1.day >> date1.month >> date1.year;

    std::cout << "Please enter Date2 (Day Month Year): ";
    std::cin >> date2.day >> date2.month >> date2.year;

    if (date1.year > date2.year || (date1.year == date2.year && (date1.month > date2.month || (date1.month == date2.month && date1.day > date2.day)))) {
        std::cout << "Date1 should be less than Date2." << std::endl;
        return 1;
    }

    int difference = calculateDifference(date1, date2);
    std::cout << "Difference is: " << difference << " Day(s)." << std::endl;
    std::cout << "Difference (Including End Day) is: " << difference + 1 << " Day(s)." << std::endl;

    return 0;
*/

/*حساب عمرك بلايام 
    Date dateOfBirth;

    std::cout << "Please enter Your Date of Birth (Day Month Year): ";
    std::cin >> dateOfBirth.day >> dateOfBirth.month >> dateOfBirth.year;

    int ageInDays = calculateAgeInDays(dateOfBirth);

    std::cout << "Your Age is: " << ageInDays << " Day(s)." << std::endl;

    return 0;
*/

/* عندما يكون الرقم الاول اقدم يكون الفارق بينهما بلايام وإن كان الثاني اقدم يكون الفارق بالدقائق
Date date1, date2;

    std::cout << "Please enter Date1 (Day Month Year): ";
    std::cin >> date1.day >> date1.month >> date1.year;

    std::cout << "Please enter Date2 (Day Month Year): ";
    std::cin >> date2.day >> date2.month >> date2.year;

    if (date1.year < date2.year || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)) {
        std::cout << "Difference is: " << daysBetweenDates(date1, date2) << " Day(s)." << std::endl;
        std::cout << "Difference (Including End Day) is: " << daysBetweenDates(date1, date2) + 1 << " Day(s)." << std::endl;
    } else {
        std::cout << "Difference is: " << minutesBetweenDates(date1, date2) << " Minute(s)." << std::endl;
        std::cout << "Difference (Including End Day) is: " << minutesBetweenDates(date1, date2) + 1 << " Minute(s)." << std::endl;
    }

    return 0;
*/

// Add the other functions for increasing dates here...

/* طباعة التاريخ بعد فترات معينة
    Date date;
    
    std::cout << "Please enter a Day? ";
    std::cin >> date.day;

    std::cout << "Please enter a Month? ";
    std::cin >> date.month;

    std::cout << "Please enter a Year? ";
    std::cin >> date.year;

    std::cout << "Date After:" << std::endl;

    // Call your functions here and print the results as described previously

    return 0;
    */

/* calculate the actual vacation days.
    Date startDate = getUserDateInput("Vacation Starts");
    Date endDate = getUserDateInput("Vacation Ends");

    // Calculate actual vacation days
    int actualDays = calculateActualVacationDays(startDate, endDate);

    // Display results
    std::cout << "\nVacation From: " << startDate.day << "/" << startDate.month << "/" << startDate.year << std::endl;
    std::cout << "Vacation To: " << endDate.day << "/" << endDate.month << "/" << endDate.year << std::endl;
    std::cout << "\nActual Vacation Days is: " << actualDays << std::endl;

    return 0;
*/

/* read Vacation Start DateFrom and VacationDays, then make afunction to calculate the vacation returnDate.
    Date startDate = getUserDateInput("Vacation Starts");
    int vacationDays;

    std::cout << "Please enter vacation days? ";
    std::cin >> vacationDays;

    // Calculate actual vacation days and return date
    int actualDays = calculateActualVacationDays(startDate, vacationDays);
    tm returnDate = {0, 0, 0, startDate.day + actualDays - 1, startDate.month - 1, startDate.year - 1900};
    std::mktime(&returnDate); // Update the date after calculation

    // Display results using strftime
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%a, %d/%m/%Y", &returnDate);
    std::cout << "\nReturn Date: " << buffer << std::endl;

    return 0;
    */

/* Yes, Date1 is After Date2.
    // Get user input for Date1 and Date2
    Date date1 = getUserDateInput("Date1");
    Date date2 = getUserDateInput("Date2");

    // Check if Date1 is after Date2
    if (isDateAfter(date1, date2)) {
        std::cout << "Yes, Date1 is After Date2." << std::endl;
    } else {
        std::cout << "No, Date1 is Not After Date2." << std::endl;
    }

    return 0;
    */

/*compare dates, it should return:
    // Get user input for Date1 and Date2
    Date date1 = getUserDateInput("Date1");
    Date date2 = getUserDateInput("Date2");

    // Compare the dates
    int result = compareDates(date1, date2);

    // Display the comparison result
    std::cout << "Compare Result = " << result << std::endl;

    return 0;
    */

/* check if the periods overlap
    // Get user input for Period 1 and Period 2
    Period period1 = getUserPeriodInput("Enter Period 1");
    Period period2 = getUserPeriodInput("Enter Period 2");

    // Check if the periods overlap
    if (doPeriodsOverlap(period1, period2)) {
        std::cout << "Yes, Periods Overlap" << std::endl;
    } else {
        std::cout << "No, Periods Do Not Overlap" << std::endl;
    }

    return 0;

*/

/* calculate period length in days? 
    // Get user input for the period
    Period period = getUserPeriodInput("Enter Period");

    // Calculate period length
    int periodLength = calculatePeriodLength(period);

    // Display the result
    std::cout << "Period Length is: " << periodLength << std::endl;
    std::cout << "Period Length (Including End Date) is: " << periodLength + 1 << std::endl;

    return 0;

*/

/* Period Length (Including End Date)
    // Get user input for the period
    Period period = getUserPeriodInput("Enter Period");

    // Calculate period length
    int periodLength = calculatePeriodLength(period);

    // Display the result
    std::cout << "Period Length is: " << periodLength << std::endl;
    std::cout << "Period Length (Including End Date) is: " << periodLength + 1 << std::endl;

    return 0;
*/

/* date is within this period or not?
    // Get user input for the period and date to check
    Period period = getUserPeriodInput("Enter Period");
    Date checkDate = getUserDateInput("Enter Date to check");

    // Check if the date is within the period
    if (isDateWithinPeriod(checkDate, period)) {
        std::cout << "Yes, Date is within period" << std::endl;
    } else {
        std::cout << "No, Date is not within period" << std::endl;
    }

    return 0;

*/

/* tow periods then count overlap days?
    // Get user input for Period 1 and Period 2
    Period period1 = getUserPeriodInput("Enter Period 1");
    Period period2 = getUserPeriodInput("Enter Period 2");

    // Calculate the number of overlapping days
    int overlapDays = calculateOverlapDays(period1, period2);

    // Display the result
    std::cout << "Overlap Days Count Is: " << overlapDays << std::endl;

    return 0;
    */

/* Date is a NOT valide date
    // Get user input for dates and validate each date
    for (int i = 0; i < 5; ++i) {
        Date inputDate = getUserDateInput();

        // Validate the entered date
        if (isValidDate(inputDate)) {
            std::cout << "Yes, Date is a valid date." << std::endl;
        } else {
            std::cout << "No, Date is NOT a valid date." << std::endl;
        }
    }

    return 0;
    */

/* dd/mm/yyyy? Coverting date from this type to each sentecnce type
    
    // Read Date String
    std::string dateString;
    std::cout << "Please Enter Date dd/mm/yyyy? ";
    std::cin >> dateString;

    // Convert it to Date Structure
    Date date = StringToDate(dateString);

    // Print Day, Month, Year separately
    std::cout << "Day: " << date.day << std::endl;
    std::cout << "Month: " << date.month << std::endl;
    std::cout << "Year: " << date.year << std::endl;

    // Convert Date Structure to String and print it
    std::string convertedDateString = DateToString(date);
    std::cout << "You Entered: " << convertedDateString << std::endl;

    return 0;

*/

/* طباعة التاريخ باشكال مختلفة 
    // Read Date
    Date date = getUserDateInputS();

    // Format and print the date in various ways
    std::cout << formatDate(date, "dd/mm/yyyy") << std::endl;
    std::cout << formatDate(date, "yyyy/dd/mm") << std::endl;
    std::cout << formatDate(date, "mm/dd/yyyy") << std::endl;
    std::cout << formatDate(date, "mm-dd-yyyy") << std::endl;
    std::cout << formatDate(date, "dd-mm-yyyy") << std::endl;
    std::cout << formatDate(date, "Day: dd, Month: mm, Year: yyyy") << std::endl;

    return 0;
*/

/* System With login page 
    system("cls");
    int choice;
    loadUsersFromFile();

    // Show the login screen first
    showLoginScreen();

    // Main Menu
    do {
        std::cout << "\nMain Menu Screen\n"
                  << "[1] Show Client List.\n"
                  << "[2] Add New Client.\n"
                  << "[3] Delete Client.\n"
                  << "[4] Update Client Info.\n"
                  << "[5] Find Client.\n"
                  << "[6] Transactions.\n"
                  << "[7] Manage Users.\n"
                  << "[8] Logout.\n"
                  << "Choose what Do you want to do? [1 to 8]? ";

        std::cin >> choice;

        switch (choice) {
            case 1: // Show Client List
                showClientList();
                break;
            case 2: // Add New Client
                addNewClient();
                break;
            case 3: // Delete Client
                deleteClient();
                break;
            case 4: // Update Client Info
                updateClientInfo();
                break;
            case 5: // Find Client
                findClient();
                break;
            case 6: // Transactions
                transactionsMenu();
                break;
            case 7: // Manage Users
                manageUsersMenu();
                break;
            case 8: // Logout
                std::cout << "Logout successful.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 8.\n";
                break;
        }
    } while (true);

    return 0;
    */

/* system With login page 
    // Function to load user data from a file

    double balance = 500.0;  // Assuming some initial balance value

    // Load user data from file
    std::vector<User> users = _loadUserData("users.txt");

    // Login loop
    std::string username, password;
    bool loggedIn = false;

    do {
        std::cout << "Login Screen\n";
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        loggedIn = _authenticateUser(users, username, password);

        if (!loggedIn) {
            std::cout << "Login failed. Invalid username or password. Please try again.\n";
        }

    } while (!loggedIn);

    std::cout << "Login successful. Welcome, " << username << "!\n";

    // Load client data from file
    std::vector<Client> clients = _loadClientData("clients.txt");

    // Placeholder account number (you might implement login functionality to get the actual account number)
   
    int accountNumber = 123456;
    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    // Main menu loop
    int choice;
    do {
        _displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: // Quick Withdraw
                double quickWithdrawAmount;
                std::cout << "Enter withdrawal amount: $";
                std::cin >> quickWithdrawAmount;
                _quickWithdraw(clients, accountNumber, balance, quickWithdrawAmount);
                break;
            case 2: // Normal Withdraw
                _normalWithdraw(clients, accountNumber);
                break;
            case 3: // Deposit
                double depositAmount;
                std::cout << "Enter deposit amount: $";
                std::cin >> depositAmount;
                _deposit(clients, accountNumber, depositAmount);
                break;
            case 4: // Check Balance
                _checkBalance(clients, accountNumber);
                break;
            case 5: // Logout
                // Save updated client data to file before exiting
                _saveClientData("clients.txt", clients);
                std::cout << "Logout successful.\n";
                return 0;   
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }

    } while (true);

    return 0;
}


*/

/* 10:16 pm 3/12/2023 Calculator with oop fucntions
    Calculator calculator;

    calculator.Clear();
    calculator.Add(10);
    calculator.PrintResult();

    calculator.Add(100);
    calculator.PrintResult();

    calculator.Subtract(20);
    calculator.PrintResult();

    // Example of division by zero
    calculator.Divide(0);
    calculator.PrintResult();

    calculator.Multiply(3);
    calculator.PrintResult();

    return 0;
*/

/* 10:49 pm sendEmail
clsPerson Person1(10, "Mohammed", "Abu-Hadhoud", "my@gmail.com", "0098387727");
Person1.Print();

Person1.SendEmail( "Hi", "How are you?");
Person1.SendSMS("How are you?");

system("pause>0");
return 0;
*/

/* printing develpoer information
    // Example usage
    Developer dev(1, "John", "Doe", "Software Engineer", "john@example.com", "123-456-7890", 80000.0, "IT", "C++");
    dev.Print();

    dev.SendEmail("Meeting", "There is a meeting tomorrow at 10 AM.");
    dev.SendSMS("Don't forget about the meeting!");

    return 0;
    */

/* printing by the pointers
    clsSlave Slave1;
  
    cout << Slave1.FullName << endl;

    ////upcasting
    //this will convert employee to person.
    clsMan * Man1 = &Slave1;
    cout << Man1->FullName << endl;
   

    //clsPerson Person2;
    //cout << Person2.FullName << endl;

    ////downcasting : you cannot convert person to employee
    //clsEmployee* Employee2 = &Person2;



    system("pause>0");
    return 0;
*/

/* printing the date
    clsDate Date1;
    Date1.Print();

    clsDate Date2("31/1/2022");
    Date2.Print();

    clsDate Date3(20, 12, 2022);
    Date3.Print();

    clsDate Date4(250,2022);
    Date4.Print();

    Date1.IncreaseDateByOneMonth();
    Date1.Print();

    //Date3.PrintYearCalendar();
    //cout << Date2.IsValid() << endl;
    
    /*cout << "My Age InDays:" <<
        clsDate::CalculateMyAgeInDays(  clsDate(6, 11, 1977) );
    //You can try any method at your own..

    
    system("pause>0");
    return 0;
*/

}





