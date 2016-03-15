# MatrizaRulit
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
class Matrix
{
private:
	int lines;
	int columns;
	int **mas;
public:
	Matrix();
	Matrix(Matrix &a);
	~Matrix();
	Matrix(int Lines, int Columns);
	void read_matrix(std::string s);
	void print_matrix();
	Matrix operator + (Matrix array);
	Matrix operator * (Matrix array);
	int*  operator [](int i);
	Matrix operator =(Matrix &a);
	int get_coutColumns();
	int get_coutLines();
	void reset();

};
Matrix::Matrix()
{
	lines = 0;
	columns = 0;
	mas = new int*[0];
	mas[0] = new int[0];

};
Matrix::Matrix(Matrix &a)
{
	lines = a.lines;
	columns = a.columns;
	mas = new int*[lines];
	for (int i = 0;i < lines;i++)
	{
		mas[i] = new int[columns];
	}
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < columns;j++)
			mas[i][j] = a.mas[i][j];

}
Matrix::~Matrix()
{
	for (int i = 0;i < lines;i++)

		delete[] mas[i];
	delete[] mas;

}

Matrix::Matrix(int Lines, int Columns)
{
	lines = Lines;
	columns = Columns;
	mas = new int*[lines];
	for (int i = 0;i < lines;i++)
	{
		mas[i] = new int[columns];
	}

}

void Matrix::read_matrix(std::string s)
{
	ifstream fin(s);
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < columns;j++)
			fin >> mas[i][j];
	fin.close();

}
void Matrix::print_matrix()
{
	for (int i = 0;i < lines;i++) {

		for (int j = 0;j < columns;j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}
Matrix Matrix::operator =(Matrix &a)
{
	for (int i = 0;i < lines;i++)

		delete[] mas[i];
	delete[] mas;
	lines = a.lines;
	columns = a.columns;
	mas = new int*[lines];
	for (int i = 0;i < lines;i++)
	{
		mas[i] = new int[columns];
	}
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < columns;j++)
			mas[i][j] = a.mas[i][j];

	return *this;
}


Matrix Matrix::operator + (Matrix array)
{

	Matrix result(*this);
	for (int i = 0;i < result.lines;i++)
		for (int j = 0;j < result.columns;j++)
			result.mas[i][j] += array.mas[i][j];
	return(result);
}

Matrix Matrix::operator * (Matrix array)
{

	Matrix result(lines, array.get_coutColumns());
	result.reset();
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < array.get_coutLines();j++)
			for (int t = 0;t < columns;t++)
				result.mas[i][j] += mas[i][t] * array.mas[t][j];
	return result;
}

int* Matrix::operator [] (int i)
{
	if ((i - 1)<0) exit(0);
	int *temp = new int[columns];
	for (int j = 0;j < columns; j++)
		temp[j] = mas[i - 1][j];
	return(temp);

}
int Matrix::get_coutColumns()
{
	return(columns);


}

int Matrix::get_coutLines()
{
	return(lines);
}
void Matrix::reset()
{
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < columns;j++)
			mas[i][j] = 0;
}
int main(void)
{
	Matrix matrix(5, 5);
	Matrix matrix1(5, 5);
	cout << "Enter path to '*.txt' " << endl;
	std::string s;
	std::getline(std::cin, s);
	matrix.read_matrix(s);
	matrix.print_matrix();
	int *line_matrix;
	line_matrix = matrix[2];
	cout << "second line of matrix:" << endl;
	for (int i = 0;i < matrix.get_coutColumns();i++)
		cout << line_matrix[i] << " ";

	cout << endl;
	matrix1 = matrix*matrix;
	cout << "New matrix after '*' :" << endl;
	matrix1.print_matrix();

	system("pause");


}
