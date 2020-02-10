#include "Bind.h"
#include <boost/algorithm/string.hpp>

void bind(QString &string, const QString &param) {
    string = string.arg(QString::fromStdString(boost::replace_all_copy(param.toStdString(), "\'", "\'\'")));
}

void bind(QString &string, const QDateTime &time) {
    string = string.arg(time.toSecsSinceEpoch());
}
