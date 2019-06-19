#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>
#include "example.h"

class FileReader
{
public:
    FileReader();

    static QList<Example> getExamples(QString path);

private:
    static QList<double> stringlistToDouble(QString s);
};

#endif // FILEREADER_H
