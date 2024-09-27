#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <vector>
class Matrix {
    private:
        int m;
        int n;

        std::vector<double> matrix;

    public:

        Matrix(int n, int m);
        Matrix(Matrix const &copy);

        Matrix &operator=(Matrix const &copy);
        Matrix &operator+(Matrix const &add);
        Matrix &operator-(Matrix const &sub);
        Matrix &operator[](int i);

        Matrix dot(Matrix const &mat);
        Matrix scale(double scalar);


};

#endif
