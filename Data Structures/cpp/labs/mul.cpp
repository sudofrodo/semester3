#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int rows;
    int cols;
    vector<vector<int>> data;
} matrix;

void printMatrix(matrix m);
void multiply(matrix m1 , matrix m2);

int main() {

    matrix m1;
    m1.rows = 2;
    m1.cols = 3;
    m1.data = {{1,2,3},{4,5,6}};
    
    matrix m2;
    m2.rows = 3;
    m2.cols = 2;
    m2.data = {{1,2},{3,4},{5,6}};

    multiply(m1,m2);

}

void multiply(matrix m1 , matrix m2){
matrix m3;
m3.rows = m1.rows;
m3.cols = m2.cols;
m3.data.resize(m3.rows, vector<int>(m3.cols, 0));
if(m1.rows == m2.cols){
    for(int i = 0 ; i < m1.rows ; i++){
        for(int j = 0 ; j < m2.rows ; j++){
            for(int k = 0 ; k < m2.cols ; k++){
                m3.data[i][k] +=   m1.data[i][j] * m2.data[j][k];               
            }
        }
    }
    printMatrix(m3);
} else {
    cout << "Not feasible." << endl;
}

}

void printMatrix(matrix m){
    for(int i = 0 ; i < m.rows ; i++){
        for(int j = 0 ; j < m.cols ; j++){
            cout << m.data[i][j] << "  ";
        }
        cout << endl;
    }
}