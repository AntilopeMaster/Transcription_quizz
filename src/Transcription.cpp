#include "include/Transcription.h"
#include <QtQml>

Transcription::Transcription ( QObject* parent ) : QObject ( parent )
{
//    addModules ( "/home/pellencst/eee/Transcription_quizz/modules/hiragana/tab.module" );
}

void Transcription::initialize ( QQmlContext& qmlContext )
{
    qmlRegisterType<GraphicalModule>();

//    qRegisterMetaType<GraphicalModule>();
}

QQmlListProperty<GraphicalModule> Transcription::modules()
{
    return QQmlListProperty<GraphicalModule> ( this, &m_modules, &Transcription::modulesCount, &Transcription::modulesAt );
}

void Transcription::addModules ( const QString& filePath,  const QString& moduleName )
{
    QSharedPointer<GraphicalModule> module ( new GraphicalModule ( filePath.toStdString(), moduleName.toStdString() ) );

    if ( module.isNull() )
    {
        return;
    }

    m_modules.push_back ( module );
    m_modulesName.push_back ( module->moduleName() );
    emit modulesChanged();
}

QStringList Transcription::modulesName()
{
    return m_modulesName;
}

int Transcription::modulesCount ( QQmlListProperty<GraphicalModule>* list )
{
    if ( list == nullptr )
    {
        return 0;
    }

    Transcription* model = qobject_cast< Transcription* > ( list->object ) ;

    if ( model == nullptr )
    {
        return 0;
    }

    return model->m_modules.count();
}

GraphicalModule* Transcription::modulesAt ( QQmlListProperty<GraphicalModule>* list, int index )
{
    if ( list == nullptr )
    {
        return nullptr ;
    }

    Transcription* model = qobject_cast< Transcription* > ( list->object ) ;

    if ( model == nullptr )
    {
        return nullptr ;
    }

    return model->m_modules.at ( index ).data();
}
