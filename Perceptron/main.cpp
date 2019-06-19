#include <QCoreApplication>

#include <QFile>
#include <iostream>
#include <QRandomGenerator64>
#include "dataloader.h"
#include "neurone.h"

int main(int argc, char *argv[])
{
    const double initialNeuroneValue = 1;
    const double alpha = 1;

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

    Info thisLine = lines.at(0);
    int inLen = thisLine.getInput().size();
    int outLen = thisLine.getOutput().size();


    for (int i = 0; i < inLen; ++i) {
        Neurone n;
        QList<double> w;

        for (int o = 0; o < outLen; ++o) {
            //qint64 rand = QRandomGenerator64::global()->generate() & std::numeric_limits<qint64>::max();
            int rand = 1;
            w.append(rand);
        }

        n.setValue(initialNeuroneValue);
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

    int count = 0;

    while (!done) {
        int internalCounter = 0;
        std::cout << "------ " << count << " ------" << std::endl;

        for (int i = 0, size = lines.size(); i < size; ++i) {
            Info line = lines.at(i);
            QList<double> inputLine = line.getInput();
            QList<double> outputLine = line.getOutput();

            for (int out = 0; out < outputLine.size(); ++out) {
                for (int in = 0; in < inputLine.size(); ++in) {
                    Neurone n = brain.at(in);
                    n.setValue(inputLine.at(in));
                    brain.replace(in, n);
                }

                //calcular e comparar com output.at(out)
                double net = 0;

                for (Neurone n : brain) {
                    net += n.getValue() * n.getWeights().at(out);
                }

                //se deu diferente

                if (!qFuzzyCompare(net, outputLine.at(out))) {
                    for (int j = 0; j < brain.size(); ++j) {
                        Neurone n = brain.at(j);
                        double newW = n.getWeights().at(out) + (alpha * (outputLine.at(out) - net) * n.getValue());

                        n.getWeights()[out] = newW;
                        brain.replace(j, n);
                        std::cout << "Valor: " << newW << std::endl;
                    }

                    std::cout << "---------------" << std::endl;

                } else {
                    internalCounter++;

                    if (internalCounter >= size) {
                        std::cout << "Eita" << std::endl;
                        goto fim;
                    }
                }
            }
        }

        if (++count > 40) {
            break;
        }
    }

fim:

    return 0;
}
