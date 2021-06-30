//Array representation of sparse matrix
#include <iostream>
using namespace std;
int main()
{
    int size=0;
     int spMatrix[4][5] = {0, 0, 3, 0, 4, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 0, 2, 6, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (spMatrix[i][j] != 0)
            {
                size++; //number of non-zero elements
            }
        }
    }
    cout<<size<<endl;
    // number of columns in compactMatrix (size) must be
    // equal to number of non - zero elements in
    // sparseMatrix
    int traingulermat[3][size]; //row,column and value as three rows and size as col size

    // Making of new matrix
    int k = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            if (spMatrix[i][j] != 0)
            {
                traingulermat[0][k] = i;              //ith index
                traingulermat[1][k] = j;              //jth index
                traingulermat[2][k] = spMatrix[i][j]; //i and jth index value
                k++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << traingulermat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
