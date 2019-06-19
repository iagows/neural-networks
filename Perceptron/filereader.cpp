#include "filereader.h"

#include <QFile>
#include <QIODevice>

FileReader::FileReader()
{

}

QList<Example> FileReader::getExamples(QString path)
{
    QList<Example> result;
    QFile file(path);

    if (file.open(QIODevice::ReadOnly)) {
        QString all = file.readAll();
        QStringList lines = all.split('\n');

        for (QString line : lines) {
            QStringList sideAB = line.split('#');

            if (sideAB.size() != 2) {
                throw "Error: line without IO";
            }

            Example e;
            e.setInputs(stringlistToDouble(sideAB[0]));
            e.setOutputs(stringlistToDouble(sideAB[1]));

            result.append(e);
        }
    }

    return result;
}

QList<double> FileReader::stringlistToDouble(QString s)
{
    QList<double> list;

    QStringList data = s.split(',');

    for (QString str : data) {
        list.append(str.toDouble());
    }

    return list;
}
