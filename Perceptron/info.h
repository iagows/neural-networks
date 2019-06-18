#ifndef INFO_H
#define INFO_H

#include <QList>

class Info
{
public:
    Info();

    QList<double> getInput() const;
    QList<double> getOutput() const;

    void setInput(QList<double> i);
    void setOutput(QList<double> o);
private:
    QList<double> input;
    QList<double> output;
};

#endif // INFO_H
