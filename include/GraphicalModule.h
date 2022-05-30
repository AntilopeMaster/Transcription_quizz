#ifndef GRAPHICALMODULE_H
#define GRAPHICALMODULE_H

#include <QObject>
#include <QHash>
#include <QList>
#include <QString>
#include <QStringList>
#include <algorithm>

#include "include/Module.h"

class GraphicalModule : public QObject, public Module
{
    Q_OBJECT

    Q_PROPERTY ( QString moduleName READ moduleName CONSTANT )
    Q_PROPERTY ( QStringList keys READ keys CONSTANT )
    Q_PROPERTY ( QStringList values READ values CONSTANT )

public:
    explicit GraphicalModule ( std::string filepath = "", QObject* parent = nullptr );

    GraphicalModule ( const GraphicalModule& orig );

    QString moduleName() const;
    QStringList keys();
    QStringList values();

signals:

};

Q_DECLARE_METATYPE ( GraphicalModule )

#endif // GRAPHICALMODULE_H
