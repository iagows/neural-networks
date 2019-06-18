#ifndef DATALOADER_H
#define DATALOADER_H

#include <QString>
#include <QList>

#include "info.h"

class DataLoader
{
public:
    DataLoader();
    bool load(QString path, QChar separator = ',', QChar needleIO = '#');

    QList<Info> getData();
private:
    QList<Info> data;
};

#endif // DATALOADER_H
