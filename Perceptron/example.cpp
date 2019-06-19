#include "example.h"

#include <QStringBuilder>
Example::Example()
{

}

QList<double> &Example::getInputs()
{
    return inputs;
}

QList<double> &Example::getOutputs()
{
    return outputs;
}

void Example::setInputs(QList<double> in)
{
    inputs = in;
}

void Example::setOutputs(QList<double> out)
{
    outputs = out;
}

QString Example::toString() const
{
    QString s = "[Example] Inputs: ";

    for (double i : inputs) {
        s = s % QString::number(i) % " ";
    }

    s = s.trimmed();

    s = s % "\t\t Outputs: ";

    for (double o : outputs) {
        s = s % QString::number(o) % " ";
    }

    s = s.trimmed();
    return s;
}

std::string Example::toStdString() const
{
    return toString().toStdString();
}
