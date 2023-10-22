#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Matrix
{
private:
    int rows;
    int cols;
    T** matrix = NULL;

    void init();
    void freeMatrix();
public:
    void rand_matrix();
    void print_matrix();
    T Get_matrix(int, int);
    void Set_matrix(int, int, T);

    Matrix& operator = (const Matrix &other)
    { 
    freeMatrix();
    this->rows = other.rows;
    this->cols = other.cols;
    init();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = other.matrix[i][j];
    return *this;
    }
    
    Matrix();
    Matrix(int , int );
    Matrix(const Matrix &other);
    ~Matrix();
   
};

template <typename T>
Matrix<T>::Matrix()
{
    rows = 0;
    cols = 0;
    init();
}

template <typename T>
Matrix<T>::Matrix(int m, int n)
{   
    rows = m;
    cols = n;
    init();
}

template <typename T>
Matrix<T>::Matrix(const Matrix &other)
{
    this->rows = other.rows;
    this->cols = other.cols;
    init();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = other.matrix[i][j];
}

template <typename T>
Matrix<T>::~Matrix()
{
    freeMatrix();
}

template <typename T>
void Matrix<T>::init()
{
    matrix = new T* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new T[cols];
    }
    
}
template <typename T>
void Matrix<T>::freeMatrix() {
	for (int i = 0; i < rows; i++) 
		delete [] matrix[i];
	delete [] matrix;
}
template <typename T>
void Matrix<T>::rand_matrix()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
}
template <typename T>
void Matrix<T>::print_matrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
             cout << matrix[i][j] << " ";
        }
        cout << endl;
           
    }
    cout << endl;     
}
template <typename T>
T Matrix<T>::Get_matrix(int i, int j)
{
    if (i < rows || j < cols || i < 0 || j < 0)
        return matrix[i][j];
    else
        return -1;
}
template <typename T>
void Matrix<T>::Set_matrix(int i, int j, T val)
{
    if (i < rows || j < cols || i < 0 || j < 0)
        matrix[i][j] = val;
    else
        return ;
}


int main()
{
    // Вариант 1
    cout << "\tВариант 1" << endl;
    Matrix<int> a(3, 4);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            a.Set_matrix(i, j, i + j);

    cout << "a:" << endl;
    a.print_matrix();

    Matrix<int> b(a); // вызов конструктора копирования
    cout << "b:" << endl;
    b.print_matrix();

    Matrix<int> c;
    c.operator=(a);  // вызов оператора копирования
    //c = a;
    cout << "c:" << endl;
    c.print_matrix();

    Matrix<int> d;
    d = c = b = a; // вызов оператора копирования в виде "цепочки"
    cout << "d:" << endl;
    d.print_matrix();




        // Вариант 2
    cout << endl <<"____________"<< endl << "\tВариант 2" << endl;

    Matrix<double> a1(3, 4);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            a1.Set_matrix(i, j, (i + j)*0.5);

    cout << "a1:" << endl;
    a1.print_matrix();

    Matrix<double> b1(a1); // вызов конструктора копирования
    cout << "b1:" << endl;
    b1.print_matrix();

    Matrix<double> c1;
    c1.operator=(a1);  // вызов оператора копирования
    //c = a;
    cout << "c1:" << endl;
    c1.print_matrix();

    Matrix<double> d1;
    d1 = c1 = b1 = a1; // вызов оператора копирования в виде "цепочки"
    cout << "d1:" << endl;
    d1.print_matrix();
    return 0;
}