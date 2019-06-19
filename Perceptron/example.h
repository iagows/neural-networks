#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QList>

class Example
{
public:
    Example();

    QList<double>& getInputs();
    QList<double>& getOutputs();

    void setInputs(QList<double> in);
    void setOutputs(QList<double> out);

    QString toString() const;
    std::string toStdString() const;
private:
    QList<double> inputs;
    QList<double> outputs;
};

#endif // EXAMPLE_H
