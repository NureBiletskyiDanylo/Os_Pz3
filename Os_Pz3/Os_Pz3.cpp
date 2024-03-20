#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
struct employee {
    char* name;
    float salary;
    int stage;
};

//----------------------------Task 1 Method Pre-declaration----------------------------
void Task_1();
void ReplaceCharacters(std::string& str, int position);

//----------------------------Task 2 Method Pre-declaration----------------------------
void Task_2();
bool isPrime(int num);
int generateRandomPrime(int minVal, int maxVal);
void formArray(int* arr, int size);
void printArray(int* arr, int size);
void sortPrimes(int* arr, int size);
void shiftEvenRows(int** matrix, int rows, int cols, int d);

//----------------------------Task 3(1) Method Pre-declaration----------------------------
void Task_3p1();
void formAnArray(employee employees[100], int size);
employee generateAStructure();
void initializeRandomGenerator();
void printAnArray(employee arr[100], int actualSize);
void searchForALetter(employee employees[100], int size);
//----------------------------Task 3(2) Method Pre-declaration----------------------------
void Task_3p2();
int** generateDynamicArray(int numRows, int numCols);
void printDynamicArray(int** dynamicArray, int numRows, int numCols);
void addRowsToBeginning(int** dynamicArray, int& numRows, int numCols, int n);
int main()
{
    Task_3p2();
}

void replaceCharacters(std::string& str, int position) {
    for (int i = position; i < str.length(); ++i) {
        if (str[i] == '0') {
            str[i] = '1';
        }
        else if (str[i] == '1') {
            str[i] = '0';
        }
    }
}
void Task_1() {
    std::string inputStr;
    int replacePosition;

    std::cout << "Enter the string: ";
    std::getline(std::cin, inputStr);

    std::cout << "Enter the starting position for editing(starts from 0): ";
    std::cin >> replacePosition;

    std::cout << "String before change: " << inputStr << std::endl;

    replaceCharacters(inputStr, replacePosition);

    std::cout << "String after: " << inputStr << std::endl;
}




bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}


int generateRandomPrime(int minVal, int maxVal) {
    int prime;
    do {
        prime = rand() % (maxVal - minVal + 1) + minVal;
    } while (!isPrime(prime));
    return prime;
}


void formArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomPrime(-10, 10); 

    }
}


void printArray(int* arr, int size) {
    using namespace std;
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void sortPrimes(int* arr, int size) {
    using namespace std;
    sort(arr, arr + size, [](int a, int b) {
        if (isPrime(a) && isPrime(b)) return a < b;
        else if (isPrime(a)) return true;
        else return false;
        });
}


void shiftEvenRows(int** matrix, int rows, int cols, int d) {
    using namespace std;
    for (int i = 0; i < rows; i += 2) {
        int* row = matrix[i];
        rotate(row, row + cols - d, row + cols);
    }
}

void Task_2() {
    using namespace std;
    int choice;
    cout << "Enter 1 to input and sort an array, or 2 to input matrix size and shift: ";
    cin >> choice;

    if (choice == 1) {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;
        int* array = new int[size];

        formArray(array, size);
        cout << "Initial array with primes: ";
        printArray(array, size);

        sortPrimes(array, size);
        cout << "Sorted array with primes: ";
        printArray(array, size);

        delete[] array;
    }
    else if (choice == 2) {
        int rows, cols, shiftAmount;
        cout << "Enter the number of rows in the matrix: ";
        cin >> rows;
        cout << "Enter the number of columns in the matrix: ";
        cin >> cols;

        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }

        cout << "Enter the shift amount for even rows: ";
        cin >> shiftAmount;

        cout << "Original Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = i * cols + j;
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        shiftEvenRows(matrix, rows, cols, shiftAmount);

        cout << "Matrix after shifting even rows by " << shiftAmount << " elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    else {
        cout << "Invalid choice!";
    }
}




void Task_3p1() {
    employee employees[100];
    int size = 20;
    formAnArray(employees, size);
    printAnArray(employees, size);
    searchForALetter(employees, size);
}

void formAnArray(employee employees[100], int size) {

    initializeRandomGenerator();
    for (int i = 0; i < size; i++) {
        employees[i] = generateAStructure();
    }
}

employee generateAStructure() {
    const char firstNameLetter[] = { 'A', 'B', 'C', 'E', 'L' };
    employee newEmployee;



    int index = rand() % (sizeof(firstNameLetter) / sizeof(firstNameLetter[0]));

    newEmployee.name = new char[1]; 
    newEmployee.name[0] = firstNameLetter[index];

    newEmployee.salary = (float)(rand()) / (float)(RAND_MAX);
    newEmployee.salary *= 1000;

    int stage = rand() % 5 + 1;
    newEmployee.stage = stage;
    return newEmployee;
}

void initializeRandomGenerator() {
    srand(time(0));
}

void printAnArray(employee arr[100], int actualSize) {
    using namespace std;
    for (int i = 0; i < actualSize; i++) {
        cout << arr[i].name[0] << " " << arr[i].salary << " " << arr[i].stage << endl;
    }
}

void searchForALetter(employee employees[100], int size) {
    employee newArr[100];
    int newActualSize = 0;
    for (int i = 0; i < size; i++) {
        if (employees[i].name[0] == 'L') {
            newArr[newActualSize] = employees[i];
            newActualSize += 1;
        }
    }

    std::cout << "New array" << std::endl;
    printAnArray(newArr, newActualSize);
}

void Task_3p2()
{
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;


    int** myDynamicArray = generateDynamicArray(rows, cols);


    std::cout << "Generated Dynamic Array:" << std::endl;
    printDynamicArray(myDynamicArray, rows, cols);
    std::cout << "Let's add new rows to the begining, how many do you want? " << std::endl;
    int k;
    std::cin >> k;
    addRowsToBeginning(myDynamicArray, rows, cols, k);

}

int** generateDynamicArray(int numRows, int numCols)
{
    int** dynamicArray = new int* [numRows];


    for (int i = 0; i < numRows; ++i) {
        dynamicArray[i] = new int[numCols];
    }


    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            dynamicArray[i][j] = rand() % 100;
        }
    }

    return dynamicArray;
}

void printDynamicArray(int** dynamicArray, int numRows, int numCols)
{
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << dynamicArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void addRowsToBeginning(int** dynamicArray, int& numRows, int numCols, int n) {

    int** newArray = new int* [numRows + n];


    for (int i = 0; i < n; ++i) {
        newArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {

            newArray[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < numRows; ++i) {
        newArray[i + n] = new int[numCols];
        for (int j = 0; j < numCols; ++j) {
            newArray[i + n][j] = dynamicArray[i][j];
        }
        delete[] dynamicArray[i]; 
    }
    delete[] dynamicArray; 

    numRows += n;

    printDynamicArray(newArray, numRows, numCols);

}