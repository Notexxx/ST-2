// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"

// Задача "Земля и верёвка"
// Радиус Земли 6378.1 км = 6378100 м
// Добавляем 1 метр к длине окружности, находим разницу радиусов
double ropeGap() {
  double earthRadius = 6378100.0;
  Circle earth(earthRadius);
  double originalFerence = earth.getFerence();
  earth.setFerence(originalFerence + 1.0);
  return earth.getRadius() - earthRadius;
}

// Задача "Бассейн"
// Стоимость ограды (погонные метры внешней окружности)
double poolFenceCost(double poolRadius, double pathWidth,
                     double concreteCost, double fenceCost) {
  Circle outer(poolRadius + pathWidth);
  return outer.getFerence() * fenceCost;
}

// Стоимость бетонной дорожки (площадь кольца)
double poolConcreteCost(double poolRadius, double pathWidth,
                        double concreteCost) {
  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);
  double ringArea = outer.getArea() - pool.getArea();
  return ringArea * concreteCost;
}
