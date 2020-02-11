#include "Bind.h"
#include "HtmlSerializer.h"

void bind(QString &string, const QString &param) {
    string = string.arg(HtmlSerializer::serialize(param));
}

void bind(QString &string, const QUuid &param) {
    string = string.arg(param.toString(QUuid::StringFormat::WithBraces));
}

void bind(QString &string, const QDateTime &time) {
    string = string.arg(time.toSecsSinceEpoch());
}
