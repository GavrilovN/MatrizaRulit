#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
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
	Matrix(const Matrix &a);
	~Matrix();
	Matrix(int _lines, int _columns);
	void read_matrix(std::string s);
	void print_matrix();
	Matrix operator + (const Matrix &array);
	Matrix operator * (const Matrix &array);
	int*  operator [](int i) const;
	Matrix operator =(Matrix &a);
	int get_cout_columns() const;
	int get_cout_lines() const;
	void reset();

};
Matrix::Matrix() : lines(0), columns(0), mas(nullptr)
{};

Matrix::Matrix(const Matrix &a): lines(a.lines), columns(a.columns)
{
	
	mas = new int*[lines];

	for (int i = 0;i < lines;i++)
	{
		mas[i] = new int[columns];
		for (int j = 0;j < columns;j++)
			mas[i][j] = a.mas[i][j];
	}

}
Matrix::~Matrix()
{
	for (int i = 0;i < lines;i++)

		delete[] mas[i];
	delete[] mas;

}

Matrix::Matrix(int _lines, int _columns) : lines(_lines), columns(_columns)
{
	mas = new int*[lines];
	for (int i = 0;i < lines;i++)
	{
		mas[i] = new int[columns];
	}

}

void Matrix::read_matrix(const std::string s)
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
		for (int j = 0;j < columns;j++)
			mas[i][j] = a.mas[i][j];
	}
	return *this;
}


Matrix Matrix::operator + (const Matrix &array)
{

	Matrix result(this-> lines,this->columns);
	for (int i = 0;i < result.lines;i++)
		for (int j = 0;j < result.columns;j++)
			result.mas[i][j] = array.mas[i][j]+this->mas[i][j];
	return result;
}   

Matrix Matrix::operator * (const Matrix &array)
{

	Matrix result(lines, array.columns);
	result.reset();
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < array.columns; j++)
			for (int t = 0;t < columns;t++)
				result.mas[i][j] += mas[i][t] * array.mas[t][j];
	return result;
}

int* Matrix::operator [] (int i) const
{
	if ((i - 1) < 0) exit();
	int *temp = new int[columns];
	for (int j = 0;j < columns; j++)
		temp[j] = mas[i - 1][j];
	return temp;

}
int Matrix::get_cout_columns() const
{
	return columns;


}

int Matrix::get_cout_lines() const
{
	return lines;
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
	cout << "Write way of file '*.txt' " << endl;
	std::string s;
	std::getline(std::cin, s);
	cout << "You wrote " << s << endl;
	matrix.read_matrix(s);
	matrix.print_matrix();
	int *line_matrix;
	line_matrix = matrix[2];
	cout << "secontd line of matrix:" << endl;
	for (int i = 0;i < matrix.get_cout_columns();i++)
		cout << line_matrix[i] << " ";

	cout << endl;
	matrix1 = matrix*matrix;
	cout << "New matrix after '*' :" << endl;
	matrix1.print_matrix();

	system("pause");


}
