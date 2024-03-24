#include<iostream>
#include<vector>
#include<cmath>
// y = w*x

std::vector<double> forward(std::vector<double> x, double w) {
    for (int i=0; i<x.size(); i++) {
        x[i] = w*x[i];
    }
    return x;
}

double loss(std::vector<double> y_predicted, std::vector<double> y) {
    std::vector<double> loss_vector;
    for (int i=0; i<y.size(); i++) {
        loss_vector.push_back(sqrt((y_predicted[i] - y[i])*(y_predicted[i] - y[i])));
    }
    double mean_loss=0;
    for (int i=0; i<loss_vector.size(); i++) {
        mean_loss = mean_loss + loss_vector[i];
    }
    return mean_loss/loss_vector.size();
}

double gradient_descent(std::vector<double> y_predicted, std::vector<double> y, std::vector<double> x) {
    
}

int main() {
    std::vector<double>     x_train{1, 5, 4, 8, 2}, y_train{2, 10, 8, 16, 4};
    double                  weight = 0, learning_rate = 0.01;
    int                     iters = 10;

    for (int i=0; i<iters; i++) {

    }

}