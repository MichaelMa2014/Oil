//
//  Cylinder.hpp
//  Oil
//
//  Created by 马琛骁 on 16/3/27.
//  Copyright © 2016年 Michael Ma. All rights reserved.
//

#ifndef Cylinder_hpp
#define Cylinder_hpp

#include <stdio.h>
#define PI 3.1415926
#define CUBIC 0.005 // 每个立方体的边长
#define DEGREE 4.1
#define ANGLE DEGREE*PI/180 // 倾斜角的角度
#define A 0.89 // 椭圆的长半径
#define B 0.6 // 椭圆的短半径
#define H 2.45 // 椭圆柱体的高度
#define H_PRECISION 1

#include <stdio.h>
#include <math.h>

double R_x(double x);
double R_y(double y);
double R_z(double z);
bool Oval(double x, double z);
bool Inside(double x, double y, double z);
int Layer(double z);
double Calculate(double height);
void Rotate_x_Cylinder();

#endif /* Cylinder_hpp */
