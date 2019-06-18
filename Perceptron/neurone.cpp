#include "neurone.h"

Neurone::Neurone()
{

}

double Neurone::getValue()
{
    return value;
}

void Neurone::setValue(double v)
{
    value = v;
}

QList<double> Neurone::getWeights()
{
    return weights;
}

void Neurone::setWeights(QList<double> w)
{
    weights = w;
}
