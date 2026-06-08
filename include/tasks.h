// Copyright 2025 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double ropeGap();
double poolFenceCost(double poolRadius, double pathWidth,
                     double concreteCost, double fenceCost);
double poolConcreteCost(double poolRadius, double pathWidth,
                        double concreteCost);

#endif  // INCLUDE_TASKS_H_
