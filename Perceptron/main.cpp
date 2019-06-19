#include <QCoreApplication>

#include <QFile>
#include <iostream>
#include <QRandomGenerator64>
#include "dataloader.h"
#include "neurone.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName;

    if (argc == 1) {
        fileName = "input.csv";

    } else {
        fileName = argv[1];
    }

    DataLoader dataLoader;
    dataLoader.load(fileName);

    QList<Info> lines = dataLoader.getData();

    QList<Neurone> brain;

    int inLen = lines.at(0).getInput().size();
    int outLen = lines.at(0).getOutput().size();


    for (int i = 0; i < inLen; ++i) {
        Neurone n;
        QList<double> w;

        for (int o = 0; o < outLen; ++o) {
            qint64 rand = QRandomGenerator64::global()->generate() & std::numeric_limits<qint64>::max();
            w.append(rand);
        }

        n.setWeights(w);
        brain.append(n);
    }

    //neuronio de limiar
    {
        Neurone x0;
        x0.setValue(1);
        QList<double> w;

        for (int i = 0; i < outLen; ++i) {
            w.append(0);
        }

        x0.setWeights(w);
        brain.append(x0);
    }

    bool done = false;

    while (!done) {
        for (int i = 0, size = lines.size(); i < size; ++i) {
            Info line = lines.at(i);
            QList<double> input = line.getInput();
            QList<double> output = line.getOutput();

            for (int out = 0; out < output.size(); ++out) {
                for (int in = 0; in < input.size(); ++in) {
                    Neurone n = brain.at(in);
                    n.setValue(input.at(i));
                }

                //calcular e comparar com output.at(out)
                double net = 0;

                for (Neurone n : brain) {

                }
            }

        }

        break;
    }

    return a.exec();
}
