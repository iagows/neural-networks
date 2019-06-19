#ifndef NEURONE_H
#define NEURONE_H

#include <QList>

class Neurone
{
public:
    Neurone();

    double &getValue();
    void setValue(const double v);

    QList<double> &getWeights();
    void setWeights(QList<double> w);
private:
    double value;
    QList<double> weights;
};

#endif // NEURONE_H
