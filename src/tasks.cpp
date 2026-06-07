// Copyright 2025 UNN-CS
#include "tasks.h"          // сначала свой заголовок
#define _USE_MATH_DEFINES   // затем define
#include <cmath>            // затем системные заголовки
#include "circle.h"         // затем другие свои заголовки

double earthRopeGap() {
    const double EARTH_RADIUS_M = 6378100.0;
    Circle earth(EARTH_RADIUS_M);
    double initialFerence = earth.getFerence();
    earth.setFerence(initialFerence + 1.0);
    return earth.getRadius() - EARTH_RADIUS_M;
}

double poolCost() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double OUTER_RADIUS = POOL_RADIUS + PATH_WIDTH;
    const double CONCRETE_PRICE = 1000.0;
    const double FENCE_PRICE = 2000.0;
    
    Circle pool(POOL_RADIUS);
    Circle withPath(OUTER_RADIUS);
    
    double pathArea = withPath.getArea() - pool.getArea();
    double fenceLength = withPath.getFerence();
    
    return (pathArea * CONCRETE_PRICE) + (fenceLength * FENCE_PRICE);
}
