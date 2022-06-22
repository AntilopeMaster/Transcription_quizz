#include "include/GraphicalModule.h"

GraphicalModule::GraphicalModule ( std::string filepath, std::string moduleName, QObject* parent ) : QObject ( parent ), Module ( filepath, moduleName )
{

}

GraphicalModule::GraphicalModule ( const GraphicalModule& orig ) : QObject ( orig.parent() ), Module ( orig.filePath(),  orig.moduleName().toStdString() )
{
}

QString GraphicalModule::moduleName() const
{
    return QString::fromStdString ( m_moduleName );
}

QStringList GraphicalModule::keys()
{
    QStringList listQstring;

    std::for_each ( m_translations_map.cbegin(), m_translations_map.cend(), [&listQstring] ( const std::pair<std::string, std::string> map_element )
    {
        listQstring.push_back ( QString::fromStdString ( map_element.first ) );
    } );
    return listQstring;
}

QStringList GraphicalModule::values()
{
    QStringList listQstring;
    std::list<std::string> list;

    std::for_each ( m_translations_map.cbegin(), m_translations_map.cend(), [&listQstring] ( const std::pair<std::string, std::string> map_element )
    {
        listQstring.push_back ( QString::fromStdString ( map_element.second ) );
    } );
    return listQstring;
}
