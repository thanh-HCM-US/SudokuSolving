//#ifndef UTILITY_H
#define UTILITY_H

#include "Mediator.h"
#include "Sudoku.h"
#include <iostream>
#include <map>
#include <QVector>

QString convertItoString(unsigned int i);

int convertSubValueToInt(unsigned int subValue);

QString convertSubValueIntToText(int subValue);

unsigned int checkNumSubValue(unsigned int value);

bool findOnlyOneMatch(Mediator* mediator);

bool findDuplicate(Mediator* mediator);

bool findTriplicate(Mediator* mediator);
