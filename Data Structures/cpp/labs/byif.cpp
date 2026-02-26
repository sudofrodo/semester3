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
    int m1_row_idx = 0;
    int m1_col_idx = 0;
    int m2_col_idx = 0;
    int m2_row_idx = 0;
    for(int i = 0 ; i < 12 ; i++){
        int num = m1.data[m1_row_idx][m1_col_idx] * m2.data[m2_col_idx][m2_row_idx];
    
        if(i % 3 != 0){
            m1_col_idx++;
            m2_row_idx++;
        } else {
            m1_col_idx = 0;
            m2_row_idx = 0;
        }
            cout << num << "   ";
    }
   // printMatrix(m3);
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