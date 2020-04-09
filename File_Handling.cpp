#include <fstream>
#include <iostream>

using namespace std;

int main() {
    char arr[100];
    char newarr[100];
    cout << "Enter Array" << endl;
    cin.getline(arr, 100);

    ofstream myFile("xyz.txt", ios::app);

    //  myFile.open("xyz.txt"); by default opened in line 12

    myFile << arr;
    myFile.close();
    cout << "File Write operation successful" << endl
         << endl;

    cout << "Reading from File" << endl;
    ifstream readfile("xyz.txt");

    readfile.getline(newarr, 100);
    cout << "ARRAY IN TXT : " << newarr;
    readfile.close();

    return 0;
}