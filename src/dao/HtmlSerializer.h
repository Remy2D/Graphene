#ifndef GRAPHENE_HTML_SERIALIZER_H
#define GRAPHENE_HTML_SERIALIZER_H

#include <QtCore/QString>

class HtmlSerializer {
public:
    static QString serialize(const QString &rawHtml);

    static QString deserialize(const QString &serializedHtml);
};

#endif  // GRAPHENE_HTML_SERIALIZER_H
