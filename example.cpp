#include <stdlib.h>
#include <stdio.h>

#include <chrono>

#include "PolynomialSolver.h"

int main()
{
    // Input Motor PWM
    std::vector<double> m1_x = { 10, 15, 20, 25, 30, 40, 50 };

    // Measured Motor RPM
    std::vector<double> m1_y = { 121.3, 211.4, 272.6, 316.5, 352.8, 403.3, 444.5 };

    // Here we're doing the opposite way, input the RPM and predict PWM
    PolynomialSolver::PolynomialSolver m1SpeedPredictor(m1_y, m1_x, 3);

    // Store the predicted results
    std::vector<double> res;

    auto st = std::chrono::steady_clock::now();
    for (int i = 0; i < 500; i++)
        res.emplace_back(m1SpeedPredictor.predict(i));
    auto spendTime = std::chrono::steady_clock::now() - st;

    printf("Predict result: \n");
    for (auto& i : res)
        printf("%f ", i);
    printf("\nSpend time: %f msec.\n", std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(spendTime).count());

    return EXIT_SUCCESS;
}