#include <iostream>
#include <vector>

class Matrix
{
private:
  // --std=c++11 flag can be used to remove the space between below consecutive right angle brackets
  std::vector<std::vector<int> > matrix;

public:
  Matrix(int noRows, int noCols) : matrix(noRows, std::vector<int>(noCols, 0)) {}

  void userInput()
  {
    std::cout << "Enter matrix elements:" << std::endl;

    for (int i = 0; i < matrix.size(); ++i)
    {
      for (int j = 0; j < matrix[0].size(); ++j)
      {
        std::cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
        std::cin >> matrix[i][j];
      }
    }
  }

  void setElement(int i, int j, int value)
  {
    matrix[i][j] = value;
  }

  friend std::ostream &operator<<(std::ostream &out, const Matrix &obj)
  {
    out << "Matrix:" << std::endl;

    for (int i = 0; i < obj.matrix.size(); ++i)
    {
      for (int j = 0; j < obj.matrix[0].size(); ++j)
      {
        std::cout << obj.matrix[i][j] << " ";
      }
      std::cout << std::endl;
    }

    return out;
  }

  Matrix operator+(const Matrix &obj)
  {
    int noRows = matrix.size();
    int noCols = matrix[0].size();
    Matrix result(noRows, noCols);

    for (int i = 0; i < noRows; ++i)
    {
      for (int j = 0; j < noCols; ++j)
      {
        result.setElement(i, j, matrix[i][j] + obj.matrix[i][j]);
      }
    }

    return result;
  }
};

int main()
{
  int rows, cols;

  std::cout << "Enter the number of rows and columns for the matrices: ";
  std::cin >> rows >> cols;

  Matrix m1(rows, cols);
  m1.userInput();
  Matrix m2(rows, cols);
  m2.userInput();

  std::cout << "\nMatrix 1:" << std::endl;
  std::cout << m1;

  std::cout << "\nMatrix 2:" << std::endl;
  std::cout << m2;

  std::cout << "\nSum of the matrices:" << std::endl;
  std::cout << m1 + m2;
}
