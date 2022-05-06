#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "include/utils.hpp"

#include "include/Module.h"

int main ( int argc, char* argv[] )
{
    QCoreApplication::setAttribute ( Qt::AA_EnableHighDpiScaling );

    std::list<int> a = {4, 3, 2, 1};

    std::vector<int> b = {4, 3, 2, 1};

    std::map<std::string, int> c = {{"a", 4}, {"b", 3}, {"c", 2}, {"d", 1}};

    Module moduleA ( "/home/pellencst/eee/Transcription_quizz/modules/hiragana/tab.txt" );

    Module moduleB ( "/home/pellencst/eee/Transcription_quizz/modules/katakana/tab.txt" );


//    std::cout << a << std::endl;
//    std::cout << b << std::endl;
//    std::cout << c << std::endl;

    QGuiApplication app ( argc, argv );

    QQmlApplicationEngine engine;
    engine.load ( QUrl ( QStringLiteral ( "qrc:/qml/main.qml" ) ) );

    if ( engine.rootObjects().isEmpty() )
    {
        return -1;
    }

    return app.exec();
}
