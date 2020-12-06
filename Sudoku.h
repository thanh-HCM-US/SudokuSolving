#ifndef SUDOKU_H
#define SUDOKU_H

#include <QTextEdit>
#include <QObject>

class Sudoku : public QTextEdit
{
public:
    explicit Sudoku();
    virtual ~Sudoku();

    void setMainValue(unsigned int);    //set m_mainValue from key board
    unsigned int getMainValue();
    void updateMainValue();             //it will be called whenever there only one value in m_subValue

    void updateSubValueAdd(unsigned int);//add one more value into m_subValue
    void updateSubValueRemove(unsigned int);//remove one more value into m_subValue
private:
    void showMainValue();
    void showSubValue();

    //this is a final resul or input value
    unsigned int m_mainValue;
    //m_subValue is present all values which m_mainValue can set
    //ex: m_subValue = 0x000110011 => m_mainvalue can receive 1, 2, 5, 6
    //ex: m_subValue = 0x100000001 => m_mainValue can receive 1, 9
    unsigned int m_subValue;
};

#endif // SUDOKU_H
