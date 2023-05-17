# PolynomialSolver_Eigen3
By given the input data set and observed data set, the PolynomialSolver is able to find n-degrees polynomial coefficients to approach the data distribution. The implementation is based on Eigen3.

## Usage
The usage of PolynomialSolver is similar to **numpy.polyfit**, passing two sets of data and degree number while constructing. For dealing with the polynomial, call `predict()` function.

## Example
Build the example file:
```
g++ example.cpp -o out
```
and run:
```
./out
```
The expected output could be (result may be variant):
```
Predict result:
2.049804 2.13993 ... 66.923566 67.282465
Spend time: 0.411153 msec.
```
