//
//  main.c
//  EulerMethod
//
//  Created by Hiroki Kayanuma on 2018/06/21.
//  Copyright © 2018 Hiroki Kayanuma. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void euler(double, double, double, int);
double func(double, double);
void adjustment_euler1(double x0, double y0, double xx, int num);
void adjustment_euler2(double x0, double y0, double xx, int num);
void runge_kutta_method(double x0, double y0, double xx, int num);

int main(int argc, const char * argv[]) {
    printf("### Euler method\n");
    euler(1.0, 1.0, 2.0, 10);
    return 0;
}

double func(double x, double y) {
    return (y/(2.0 * x));
}

void euler(double x0, double y0, double xx, int num) {
    int i;
    double h = (xx - x0) / (double)num;
    printf("i   x       y        true      error\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < num; i++) {
        y0 += h * func(x0, y0);
        x0 += h;
        printf("%2d %4.1lf %9.6lf %9.6lf %9.6lf\n", i+1, x0, y0, sqrt(x0), fabs(y0 - sqrt(x0)));
    }
}

void adjustment_euler1(double x0, double y0, double xx, int num) {
    int i;
    double k1, k2;
    double h = (xx - x0) / (double)num;
    printf("i   x       y        true      error\n");
    printf("-----------------------------------------------\n");
    for (i = 0; i < num; i++) {
        y0 += h * func(x0, y0);
        x0 += h;
        printf("%2d %4.1lf %9.6lf %9.6lf %9.6lf\n", i+1, x0, y0, sqrt(x0), fabs(y0 - sqrt(x0)));
    }
}
