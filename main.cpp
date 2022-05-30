#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "include/utils.hpp"

#include "include/Module.h"

#include "include/Transcription.h"

int main ( int argc, char* argv[] )
{
    QCoreApplication::setAttribute ( Qt::AA_EnableHighDpiScaling );

//    Module moduleA ( "/home/pellencst/eee/Transcription_quizz/modules/hiragana/tab.txt" );

//    Module moduleB ( "/home/pellencst/eee/Transcription_quizz/modules/katakana/tab.txt" );

    Transcription transcription;


    QGuiApplication app ( argc, argv );

    QQmlApplicationEngine engine;
    transcription.initialize ( *engine.rootContext() );

    engine.rootContext()->setContextProperty ( "transcription", &transcription );

    engine.load ( QUrl ( QStringLiteral ( "qrc:/qml/main.qml" ) ) );


    if ( engine.rootObjects().isEmpty() )
    {
        return -1;
    }

    return app.exec();
}
