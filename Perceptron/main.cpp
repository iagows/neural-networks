#include <QCoreApplication>

#include <QFile>
#include <iostream>
#include <QRandomGenerator64>

#include "filereader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName;

    if (argc == 1) {
        fileName = "input.csv";

    } else {
        fileName = argv[1];
    }

    QList<Example> examples = FileReader::getExamples(fileName);

    for (Example e : examples) {
        std::cout << e.toStdString() << std::endl;
    }

    return 0;
}
