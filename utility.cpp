#include "utility.h"

QString convertItoString(unsigned int i)
{
    QString strConverted;
    switch (i) {
    case 1:
        strConverted = "1";
        break;
    case 2:
        strConverted = "2";
        break;
    case 3:
        strConverted = "3";
        break;
    case 4:
        strConverted = "4";
        break;
    case 5:
        strConverted = "5";
        break;
    case 6:
        strConverted = "6";
        break;
    case 7:
        strConverted = "7";
        break;
    case 8:
        strConverted = "8";
        break;
    case 9:
        strConverted = "9";
        break;
    default:
        break;
    }
    return strConverted;
}

int convertSubValueToInt(unsigned int subValue)
{
    int result = 0;
    while (subValue != 0)
    {
        ++result;
        subValue = subValue >> 1;
    }
    return result;
}

QString convertSubValueIntToText(int subValue)
{
    QString strSubValue;
    for (unsigned int i = 1; i < 10; ++i)
    {
        if ((subValue & (1 << (i-1))) != 0)
        {
            strSubValue += convertItoString(i);
        }
        else
        {
            strSubValue += "  ";
        }

        if ((i == 3) || (i == 6))
        {
            strSubValue += "\n";
        }
        else if (i == 9)
        {/*nothing todo*/}
        else
        {
            strSubValue += " ";
        }
    }
    return strSubValue;
}

unsigned int checkNumSubValue(unsigned int value)
{
    unsigned int count = 0;
    unsigned int tmp = 1;
    for(int i=0; i<9; ++i)
    {
        if ((value & tmp) != 0)
        {
            ++count;
        }
        tmp = tmp << 1;
    }
    return count;
}

bool findOnlyOneMatch(Mediator* mediator)
{
    bool result = false;
    std::map<Sudoku*, unsigned int> mapFindOnlyOneMatch;
    unsigned int total = 0;
    for (int i=0; i<9; ++i)
    {
        Sudoku* sudokuI = mediator->getVectorSudoku().at(i);
        if (! sudokuI->isHasMainValue())
        {
            unsigned int totalSaved = total;
            total = total | sudokuI->getSubValue();
            for (std::map<Sudoku*, unsigned int>::iterator it = mapFindOnlyOneMatch.begin();
                 it != mapFindOnlyOneMatch.end();
                 ++it)
            {
                it->second |= sudokuI->getSubValue();
            }
            mapFindOnlyOneMatch.insert(std::make_pair(sudokuI, totalSaved));
        }
    }

    for (std::map<Sudoku*, unsigned int>::iterator it = mapFindOnlyOneMatch.begin();
         it != mapFindOnlyOneMatch.end();
         ++it)
    {
        unsigned int xorValue_Bin = it->second ^ total;
        if (checkNumSubValue(xorValue_Bin) == 1)
        {
            it->first->setMainValue(convertSubValueToInt(xorValue_Bin));
            result = true;
        }
        else if (checkNumSubValue(xorValue_Bin) > 1)
        {
            //TODO moi o chi nhan 1 gia tri duy nhat , neu co 2 gia tri duy nhat la sai.
        }
    }
    return result;
}

bool findDuplicate(Mediator* mediator)
{
    bool result =false;
    QVector<Sudoku*> sudokuHas2subValue;
    //find all sudo has 2 subValue, and add all of them into one list
    for (int i = 0; i<9; ++i)
    {
        Sudoku* sudokuI = mediator->getVectorSudoku().at(i);
        if (checkNumSubValue(sudokuI->getSubValue()) == 2)
        {
            sudokuHas2subValue.append(sudokuI);
        }
    }

    while (sudokuHas2subValue.size() > 1)
    {
        bool resultOfForLoop = false;
        for (int i = 1; i < sudokuHas2subValue.size(); ++i)
        {
            if (sudokuHas2subValue[0]->getSubValue() == sudokuHas2subValue[i]->getSubValue())
            {
                mediator->allotherSudokuUpdateRemove(sudokuHas2subValue[0],
                                                     sudokuHas2subValue[i],
                                                     sudokuHas2subValue[0]->getSubValue());
                sudokuHas2subValue.erase(&sudokuHas2subValue[i]);
                sudokuHas2subValue.erase(&sudokuHas2subValue[0]);
                result = true;
                resultOfForLoop = true;
                break;
            }
        }
        if (resultOfForLoop == false)
        {
            sudokuHas2subValue.erase(&sudokuHas2subValue[0]);
        }
    }
    return result;
}

bool findTriplicate(Mediator* mediator)
{
    bool result = false;
    QVector<Sudoku*> sudokuHas2or3subValue;
    //find all sudo has 2 or 3 subValue, and add all of them into one list
    for (int i = 0; i<9; ++i)
    {
        Sudoku* sudokuI = mediator->getVectorSudoku().at(i);
        if ((checkNumSubValue(sudokuI->getSubValue()) == 2)
             || (checkNumSubValue(sudokuI->getSubValue()) == 3))
        {
            sudokuHas2or3subValue.append(sudokuI);
        }
    }

    while (sudokuHas2or3subValue.size() > 2)
    {
        bool resultOfForLoop = false;
        for (int i = 1; i < (sudokuHas2or3subValue.size() -1); ++i)
        {
            for (int z = i+1; z < sudokuHas2or3subValue.size(); ++z)
            {
                unsigned int tmp =
                        sudokuHas2or3subValue[0]->getSubValue()
                        | sudokuHas2or3subValue[i]->getSubValue()
                        | sudokuHas2or3subValue[z]->getSubValue();
                if (checkNumSubValue(tmp) == 3)
                {
                    mediator->allotherSudokuUpdateRemove(sudokuHas2or3subValue[0],
                                                         sudokuHas2or3subValue[i],
                                                         sudokuHas2or3subValue[z],
                                                         sudokuHas2or3subValue[0]->getSubValue());
                    sudokuHas2or3subValue.erase(&sudokuHas2or3subValue[z]);
                    sudokuHas2or3subValue.erase(&sudokuHas2or3subValue[i]);
                    sudokuHas2or3subValue.erase(&sudokuHas2or3subValue[0]);
                    result = true;
                    resultOfForLoop = true;
                    break;
                }
                else if (checkNumSubValue(tmp) <3)
                {
                    //TODO 3 o ma chi co 2 gia tri thoa dk la sai.
                }
            }
            if (resultOfForLoop == true)
                break;
        }
        if (resultOfForLoop == false)
        {
            sudokuHas2or3subValue.erase(&sudokuHas2or3subValue[0]);
        }
    }
    return result;
}
