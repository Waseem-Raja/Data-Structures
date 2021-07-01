//Array representation of sparse matrix
#include <iostream>
using namespace std;
int main()
{
    int rowsize, colsize, element, size = 0;
    cout << "Enter the dimensions rowsize and colsize of your matrix" << endl;
    cin >> rowsize >> colsize;
    int *arr = new int[rowsize * colsize]; //alloting memory at heap
    cout << "Enter the elements" << endl;
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {

            // Assign values to
            // the memory block
            cin >> element;
            if (element != 0)
                size++;

            *(arr + i * colsize + j) = element;
        }
    }
    //cout << size << endl;

    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int compactt[3][size]; //row,column and value as three rows and size as col size

    // Making of new matrix
    int k = 0;
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++) 
        {
            if (*(arr + i * colsize + j) != 0)
            {
                compactt[0][k] = i;                        //ith index
                compactt[1][k] = j;                        //jth index
                compactt[2][k] = *(arr + i * colsize + j); //i and jth index value
                k++;
            }
        }
    }
    delete[] arr;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << compactt[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
