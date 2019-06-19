#include "info.h"

Info::Info()
{

}

QList<double> &Info::getInput()
{
    return input;
}

QList<double> &Info::getOutput()
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
