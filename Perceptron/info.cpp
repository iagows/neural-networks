#include "info.h"

Info::Info()
{

}

QList<double> Info::getInput() const
{
    return input;
}

QList<double> Info::getOutput() const
{
    return output;
}

void Info::setInput(QList<double> i)
{
    input = i;
}

void Info::setOutput(QList<double> o)
{
    output = o;
}
