// Copyright 2025 UNN-CS
#include "circle.h"
#include "tasks.h"
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <cmath>

// ==================================================
// ТЕСТЫ ДЛЯ КОНСТРУКТОРА И ГЕТТЕРОВ (5 тестов)
// ==================================================

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SmallRadius) {
    Circle c(0.001);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.001);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 0.001);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 0.000001);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e12);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * (-5.0));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

// ==================================================
// ТЕСТЫ ДЛЯ setRadius (4 теста)
// ==================================================

TEST(CircleTest, SetRadiusUpdatesFerenceAndArea) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 4.0);
}

TEST(CircleTest, SetRadiusToZero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusToNegative) {
    Circle c(5.0);
    c.setRadius(-3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * (-3.0));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 9.0);
}

TEST(CircleTest, SetRadiusMultipleTimes) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    c.setRadius(4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
}

// ==================================================
// ТЕСТЫ ДЛЯ setFerence (4 теста)
// ==================================================

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
    Circle c(1.0);
    double newFerence = 2 * M_PI * 3.0;
    c.setFerence(newFerence);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), newFerence);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 9.0);
}

TEST(CircleTest, SetFerenceToZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceToNegative) {
    Circle c(5.0);
    c.setFerence(-2 * M_PI * 2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 4.0);
}

TEST(CircleTest, SetFerenceChainTest) {
    Circle c(1.0);
    c.setFerence(2 * M_PI * 2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    c.setFerence(2 * M_PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
}

// ==================================================
// ТЕСТЫ ДЛЯ setArea (4 теста)
// ==================================================

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
    Circle c(1.0);
    double newArea = M_PI * 4.0;
    c.setArea(newArea);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), newArea);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 2.0);
}

TEST(CircleTest, SetAreaToZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaToNegative) {
    Circle c(5.0);
    c.setArea(-M_PI * 9.0);
    EXPECT_TRUE(std::isnan(c.getRadius()) || c.getRadius() < 0);
}

TEST(CircleTest, SetAreaChainTest) {
    Circle c(1.0);
    c.setArea(M_PI * 4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    c.setArea(M_PI * 9.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
}

// ==================================================
// ТЕСТЫ ДЛЯ ЗАДАЧИ "ЗЕМЛЯ И ВЕРЁВКА" (3 теста)
// ==================================================

TEST(TasksTest, EarthRopeGapValue) {
    double gap = earthRopeGap();
    EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(TasksTest, EarthRopeGapPositive) {
    double gap = earthRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(TasksTest, EarthRopeGapNotNegative) {
    double gap = earthRopeGap();
    EXPECT_GE(gap, 0.0);
}

// ==================================================
// ТЕСТЫ ДЛЯ ЗАДАЧИ "БАССЕЙН" (4 теста)
// ==================================================

TEST(TasksTest, PoolCostPositive) {
    double cost = poolCost();
    EXPECT_GT(cost, 0.0);
}

TEST(TasksTest, PoolCostCalculation) {
    double expectedCost = (M_PI * 7.0) * 1000.0 + (2 * M_PI * 4.0) * 2000.0;
    EXPECT_NEAR(poolCost(), expectedCost, 0.1);
}

TEST(TasksTest, PoolCostReasonable) {
    double cost = poolCost();
    EXPECT_GT(cost, 70000.0);
    EXPECT_LT(cost, 75000.0);
}

TEST(TasksTest, PoolCostNotZero) {
    double cost = poolCost();
    EXPECT_NE(cost, 0.0);
}

// ==================================================
// КОМБИНИРОВАННЫЕ ТЕСТЫ (2 теста)
// ==================================================

TEST(CircleTest, SetRadiusThenSetFerenceThenSetArea) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    c.setFerence(2 * M_PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    c.setArea(M_PI * 16.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
}

TEST(CircleTest, GettersAfterMultipleSets) {
    Circle c(1.0);
    c.setRadius(2.0);
    double r1 = c.getRadius();
    double f1 = c.getFerence();
    double a1 = c.getArea();

    c.setFerence(2 * M_PI * 3.0);
    double r2 = c.getRadius();
    double f2 = c.getFerence();
    double a2 = c.getArea();

    EXPECT_DOUBLE_EQ(r1, 2.0);
    EXPECT_DOUBLE_EQ(r2, 3.0);
}
