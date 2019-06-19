#include "dataloader.h"

#include <QFile>
#include <QIODevice>

DataLoader::DataLoader()
{

}

bool DataLoader::load(QString path, QChar separator, QChar needleIO)
{
    QFile file(path);

    this->data.clear();

    if (file.open(QIODevice::ReadOnly)) {
        QString contents = file.readAll();
        QStringList lines = contents.split('\n');

        for (QString line : lines) {
            QStringList io = line.split(needleIO);

            if (io.size() == 2) {
                QStringList in = io.at(0).split(separator);
                QStringList out = io.at(1).split(separator);

                Info info;

                if (in.size() > 0 && out.size() > 0) {
                    QList<double> input;
                    QList<double> output;

                    for (QString i : in) {
                        input.append(i.toDouble());
                    }

                    for (QString o : out) {
                        output.append(o.toDouble());
                    }

                    info.setInput(input);
                    info.setOutput(output);
                }

                this->data.append(info);
            }
        }

        return true;
    }

    return false;
}

QList<Info> &DataLoader::getData()
{
    return data;
}
