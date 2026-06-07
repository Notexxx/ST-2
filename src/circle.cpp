// Copyright 2025 UNN-CS
#include "circle.h"
#include <cmath>  // для M_PI

// Вспомогательные методы
void Circle::updateFromRadius() {
    ference = 2 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::updateFromFerence() {
    radius = ference / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::updateFromArea() {
    radius = std::sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
}

// Конструктор
Circle::Circle(double r) : radius(r) {
    updateFromRadius();
}

// Сеттеры
void Circle::setRadius(double r) {
    radius = r;
    updateFromRadius();
}

void Circle::setFerence(double f) {
    ference = f;
    updateFromFerence();
}

void Circle::setArea(double a) {
    area = a;
    updateFromArea();
}

// Геттеры
double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
