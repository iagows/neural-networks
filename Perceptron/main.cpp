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

    QList<Info> inputs = dataLoader.getData();

    QList<Neurone> brain;

    for (Info info : inputs) {
        QList<double> in = info.getInput();
        QList<double> out = info.getOutput();

        for (double d : in) {
            Neurone neurone;
            neurone.setValue(d);
            QList<double> w;

            for (double dd : out) {
                qint64 rand = QRandomGenerator64::global()->generate() & std::numeric_limits<qint64>::max();

                w.append(rand);
            }

            neurone.setWeights(w);
        }
    }

    return a.exec();
}
