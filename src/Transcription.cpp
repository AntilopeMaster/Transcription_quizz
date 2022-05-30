#include "include/Transcription.h"
#include <QtQml>

Transcription::Transcription ( QObject* parent ) : QObject ( parent )
{
    addModules ( "/home/pellencst/eee/Transcription_quizz/modules/hiragana/tab.txt" );
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

void Transcription::addModules ( const std::string& filePath )
{
    QSharedPointer<GraphicalModule> module ( new GraphicalModule ( filePath ) );
    m_modules.push_back ( module );

    emit modulesChanged();
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
