//
//  Cylinder.cpp
//  Oil
//
//  Created by 马琛骁 on 16/3/27.
//  Copyright © 2016年 Michael Ma. All rights reserved.
//

#include "Cylinder.hpp"
//  绕 x 轴旋转

double R_x(double x) { // x to x'
    return x;
}
double R_y(double y) { // y to y'
    return cos(ANGLE) * y + sin(ANGLE) * y;
}
double R_z(double z) { // z to z'
    return -sin(ANGLE) * z + cos(ANGLE) * z;
}

bool Oval(double x, double z) {
    return pow(R_x(x), 2) / pow(R_x(A), 2) + pow(R_z(z), 2) / pow(R_z(B), 2) < 1;
}

bool Inside(double x, double y, double z) {
    return R_x(-A) < x && x < R_x(A) &&
    R_y(0) < y && y < R_y(H) &&
    R_z(-B) < z && z < R_z(B) &&
    Oval(x, z);
}

int Layer(double z) {
    int count = 0;
    for(double x = R_x(-A); x < R_x(A); x += CUBIC) {
        for(double y = R_y(0); y < R_y(H); y += CUBIC) {
            //          对角线的两个顶点都在规定区域内时，认为整个立方体在范围内
            if(Inside(x, y, z) && Inside(x + CUBIC, y + CUBIC, z + CUBIC)) count++;
        }
    }
    return count;
}

double Calculate(double height) {
    int result = 0;
    for(double z = R_z(-B); z < height; z += CUBIC) {
        result += Layer(z);
    }
//    printf("高度为 %f 时, 正方体个数为 %d, 总体积为 %f\n", height - R_z(-B), result, result * CUBIC * CUBIC * CUBIC);
    printf("%.3f %9.4f\n", height - R_z(-B), result * CUBIC * CUBIC * CUBIC);
    return result * CUBIC * CUBIC * CUBIC;
}

void Rotate_x_Cylinder() {
    printf("椭圆柱体，绕 x 轴旋转 %.2f 度\n", DEGREE);
    printf("  高度      体积\n");
    for (double height = R_z(-B); height < R_z(B); height += H_PRECISION) {
        Calculate(height);
    }
}