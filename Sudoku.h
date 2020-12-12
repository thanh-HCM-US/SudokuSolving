#ifndef SUDOKU_H
#define SUDOKU_H

#include <QTextEdit>
#include <QObject>

class Mediator;

class Sudoku : public QTextEdit
{
public:
    explicit Sudoku();
    virtual ~Sudoku();

    unsigned int getMainValue();

    void showMainValue();

    void showSubValue();

    void updateMainValue( unsigned int value_Bin);             //it will be called whenever there only one value in m_subValue

    void updateSubValueAdd(unsigned int);//add one more value into m_subValue

    void updateSubValueRemove(unsigned int value_Dec);//remove one more value into m_subValue

    void updateSubValueRemove_Bin(unsigned int value_Bin);

    unsigned int getSubValue() {return m_subValue_Bin;}

    bool isHasMainValue();

    void setFinishedInput(bool);

    void addMediator(Mediator*);

    void setMainValue(int);

    int getNumSubValue() {return static_cast<int>(m_numSubValue_Dec);}

    void allotherSudokuUpdateRemove();

    void allotherSudokuUpdateAdd();

private:
    //this is a final resul or input value
    unsigned int m_mainValue_Dec;

    //m_subValue is present all values which m_mainValue can set
    //ex: m_subValue = 0x000110011 => m_mainvalue can receive 1, 2, 5, 6
    //ex: m_subValue = 0x100000001 => m_mainValue can receive 1, 9
    unsigned int m_subValue_Bin;
    QString m_subValueByText = "";

    unsigned int m_numSubValue_Dec;

    bool m_hasMainValue;
    bool m_finishedInput;

    QVector<Mediator*> m_vectorMediator;

public slots:
    void setMainValueFromKey();    //set m_mainValue from key board
};

#endif // SUDOKU_H
