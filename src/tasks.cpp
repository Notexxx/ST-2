// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

double earthRopeGap() {
    // Радиус Земли в метрах (6378.1 км = 6 378 100 м)
    const double EARTH_RADIUS_M = 6378100.0;

    Circle earth(EARTH_RADIUS_M);      // Земля
    double initialFerence = earth.getFerence();  // Исходная длина верёвки
    earth.setFerence(initialFerence + 1.0);      // Добавляем 1 метр

    // Зазор = новый радиус - старый радиус
    return earth.getRadius() - EARTH_RADIUS_M;
}

double poolCost() {
    // Радиусы в метрах
    const double POOL_RADIUS = 3.0;      // Бассейн
    const double PATH_WIDTH = 1.0;       // Дорожка
    const double OUTER_RADIUS = POOL_RADIUS + PATH_WIDTH;  // Внешний круг

    const double CONCRETE_PRICE = 1000.0; // руб/м²
    const double FENCE_PRICE = 2000.0;    // руб/м

    Circle pool(POOL_RADIUS);
    Circle withPath(OUTER_RADIUS);

    double pathArea = withPath.getArea() - pool.getArea();  // Площадь дорожки
    double fenceLength = withPath.getFerence();            // Длина ограды

    // Общая стоимость
    return (pathArea * CONCRETE_PRICE) + (fenceLength * FENCE_PRICE);
}