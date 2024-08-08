#include<iostream>
#include<vector>
#include<cmath>
#include <numeric> 
// y = w*x

std::vector<double> forward(std::vector<double> x, double w) {
    for (int i=0; i<x.size(); i++) {
        x[i] = w*x[i];
    }
    return x;
}

double forward(double x, double w) {
    return x*w;
}

double mean(const std::vector<double>& v) {
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    return sum / v.size();
}

double loss(std::vector<double> y_predicted, std::vector<double> y) {
    std::vector<double> loss_vector;
    for (int i=0; i<y.size(); i++) {
        loss_vector.push_back(sqrt((y_predicted[i] - y[i])*(y_predicted[i] - y[i])));
    }
    return mean(loss_vector);
}

double gradient_descent(std::vector<double> y_predicted, std::vector<double> y, std::vector<double> x) {
    std::vector<double> difference, x_doubled;
    for (int i=0; i<y.size(); i++) {
        difference.push_back((2*x[i])*(y[i] - y_predicted[i]));
    }
    return -1*mean(difference);
    
}

int main() {
    std::vector<double>     x_train{1, 5, 4, 8, 2}, y_train{2, 10, 8, 16, 4};
    double                  weight = 0, learning_rate = 0.01;
    int                     iters = 50;

    for (int epoch=0; epoch<iters; epoch++) {
        std::vector<double> y_predicted = forward(x_train, weight);
        double l = loss(y_predicted, y_train);
        double dw = gradient_descent(y_predicted, y_train, x_train);
        weight = weight - learning_rate*dw;
        if(epoch%10==0) {
            std::cout << "epoch " << epoch << ": w = " << weight << ", loss = " << l << std::endl; 
        }
    }
    std::cout << "prediction after training: f(9) = " << forward(9, weight) << std::endl;

}
