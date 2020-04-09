#include <iostream>
using namespace std;

int main() {
    int sparseMatrix[4][5] = {
        {0, 0, 5, 0, 4},
        {0, 0, 7, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 3, 9, 0, 0}};

    int size = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    int compactMatrix[size][3];

    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
    cout << "ROW   "
         << " COL  "
         << "  VALUE " << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++)
            cout << compactMatrix[i][j] << "\t";

        cout << endl;
    }

    return 0;
}