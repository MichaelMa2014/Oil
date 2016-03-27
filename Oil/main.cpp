//
//  main.cpp
//  Oil
//
//  Created by 马琛骁 on 16/3/27.
//  Copyright © 2016年 Michael Ma. All rights reserved.
//

//  以椭圆柱体某一底面中心为原点，底面短半径所在直线为 x 轴，水平面为 x-y 平面建系
//  旋转以原点为中心（旋转轴过原点？）
//  单位是 m

#include <stdio.h>
#include <math.h>
#include "Cylinder.hpp"

int main() {
    Rotate_x_Cylinder();
    return 0;
}