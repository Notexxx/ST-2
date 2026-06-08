// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

const double EPS = 1e-6;
const double PI = 3.14159265358979323846;

// --- Конструктор ---

TEST(CircleTest, ConstructorSetsRadius) {
  Circle c(5.0);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(CircleTest, ConstructorCalculatesFerence) {
  Circle c(5.0);
  EXPECT_NEAR(2.0 * PI * 5.0, c.getFerence(), EPS);
}

TEST(CircleTest, ConstructorCalculatesArea) {
  Circle c(5.0);
  EXPECT_NEAR(PI * 25.0, c.getArea(), EPS);
}

TEST(CircleTest, ConstructorZeroRadius) {
  Circle c(0.0);
  EXPECT_NEAR(0.0, c.getRadius(), EPS);
  EXPECT_NEAR(0.0, c.getFerence(), EPS);
  EXPECT_NEAR(0.0, c.getArea(), EPS);
}

// --- setRadius ---

TEST(CircleTest, SetRadiusUpdatesFerence) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_NEAR(2.0 * PI * 10.0, c.getFerence(), EPS);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_NEAR(PI * 100.0, c.getArea(), EPS);
}

TEST(CircleTest, SetRadiusKeepsRadius) {
  Circle c(1.0);
  c.setRadius(7.0);
  EXPECT_NEAR(7.0, c.getRadius(), EPS);
}

// --- setFerence ---

TEST(CircleTest, SetFerenceUpdatesRadius) {
  Circle c(1.0);
  double f = 2.0 * PI * 5.0;
  c.setFerence(f);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
  Circle c(1.0);
  double f = 2.0 * PI * 3.0;
  c.setFerence(f);
  EXPECT_NEAR(PI * 9.0, c.getArea(), EPS);
}

TEST(CircleTest, SetFerenceKeepsFerence) {
  Circle c(1.0);
  double f = 2.0 * PI * 4.0;
  c.setFerence(f);
  EXPECT_NEAR(f, c.getFerence(), EPS);
}

// --- setArea ---

TEST(CircleTest, SetAreaUpdatesRadius) {
  Circle c(1.0);
  c.setArea(PI * 25.0);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
  Circle c(1.0);
  c.setArea(PI * 9.0);
  EXPECT_NEAR(2.0 * PI * 3.0, c.getFerence(), EPS);
}

TEST(CircleTest, SetAreaKeepsArea) {
  Circle c(1.0);
  double a = PI * 16.0;
  c.setArea(a);
  EXPECT_NEAR(a, c.getArea(), EPS);
}

// --- Взаимосвязь ---

TEST(CircleTest, SetRadiusThenGetConsistent) {
  Circle c(2.0);
  c.setRadius(6.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * PI * c.getRadius(), EPS);
  EXPECT_NEAR(c.getArea(), PI * c.getRadius() * c.getRadius(), EPS);
}

TEST(CircleTest, SetFerenceThenGetConsistent) {
  Circle c(1.0);
  c.setFerence(20.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * PI * c.getRadius(), EPS);
}

TEST(CircleTest, SetAreaThenGetConsistent) {
  Circle c(1.0);
  c.setArea(50.0);
  EXPECT_NEAR(c.getArea(), PI * c.getRadius() * c.getRadius(), EPS);
}

// --- Задача "Земля и верёвка" ---

TEST(TasksTest, RopeGapIsPositive) {
  EXPECT_GT(ropeGap(), 0.0);
}

TEST(TasksTest, RopeGapIsAbout16cm) {
  // 1 / (2 * PI) ≈ 0.159 м
  EXPECT_NEAR(1.0 / (2.0 * PI), ropeGap(), EPS);
}

TEST(TasksTest, RopeGapIndependentOfRadius) {
  // Зазор не зависит от радиуса Земли
  EXPECT_NEAR(0.1591549, ropeGap(), 1e-5);
}

// --- Задача "Бассейн" ---

TEST(TasksTest, PoolFenceCostPositive) {
  EXPECT_GT(poolFenceCost(3.0, 1.0, 1000.0, 2000.0), 0.0);
}

TEST(TasksTest, PoolFenceCostCorrect) {
  // Внешний радиус = 3 + 1 = 4, периметр = 2*PI*4, цена = 2000
  double expected = 2.0 * PI * 4.0 * 2000.0;
  EXPECT_NEAR(expected, poolFenceCost(3.0, 1.0, 1000.0, 2000.0), EPS);
}

TEST(TasksTest, PoolConcreteCostPositive) {
  EXPECT_GT(poolConcreteCost(3.0, 1.0, 1000.0), 0.0);
}

TEST(TasksTest, PoolConcreteCostCorrect) {
  // Площадь кольца = PI*(4^2 - 3^2) = PI*7, цена = 1000
  double expected = PI * (16.0 - 9.0) * 1000.0;
  EXPECT_NEAR(expected, poolConcreteCost(3.0, 1.0, 1000.0), EPS);
}

TEST(TasksTest, PoolFenceBiggerPath) {
  double fence1 = poolFenceCost(3.0, 1.0, 1000.0, 2000.0);
  double fence2 = poolFenceCost(3.0, 2.0, 1000.0, 2000.0);
  EXPECT_GT(fence2, fence1);
}

TEST(TasksTest, PoolConcreteWidePath) {
  double cost1 = poolConcreteCost(3.0, 1.0, 1000.0);
  double cost2 = poolConcreteCost(3.0, 2.0, 1000.0);
  EXPECT_GT(cost2, cost1);
}
