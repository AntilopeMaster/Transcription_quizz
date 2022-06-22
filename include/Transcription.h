#ifndef TRANSCRIPTION_H
#define TRANSCRIPTION_H

#include <QObject>
#include <QQmlContext>
#include <QQmlListProperty>
#include <QSharedPointer>

#include "include/GraphicalModule.h"

class Transcription : public QObject
{
    Q_OBJECT

    Q_PROPERTY ( QQmlListProperty<GraphicalModule> modules READ modules NOTIFY modulesChanged )
    Q_PROPERTY ( QStringList modulesName READ modulesName NOTIFY modulesChanged )
public:
    explicit Transcription ( QObject* parent = nullptr );

    void initialize ( QQmlContext& qmlContext );

    QQmlListProperty<GraphicalModule> modules();

    Q_INVOKABLE void addModules ( const QString& filePath, const QString& moduleName = "" );

    QStringList modulesName();

signals:
    void modulesChanged();

private:
    static int modulesCount ( QQmlListProperty<GraphicalModule>* list ) ;
    static GraphicalModule* modulesAt ( QQmlListProperty<GraphicalModule>* list, int index ) ;

    QList<QSharedPointer<GraphicalModule>> m_modules;
    QStringList m_modulesName;
};

#endif // TRANSCRIPTION_H
