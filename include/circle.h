// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius;   // радиус
    double ference;  // длина окружности
    double area;     // площадь

    // Вспомогательные приватные методы для пересчёта
    void updateFromRadius();
    void updateFromFerence();
    void updateFromArea();

 public:
    // Конструктор
    explicit Circle(double r);

    // Сеттеры
    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    // Геттеры
    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
