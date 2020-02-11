#include "HtmlSerializer.h"

#include <boost/algorithm/string.hpp>

QString HtmlSerializer::serialize(const QString &rawHtml) {
    return QString::fromStdString(
            boost::replace_all_copy(
                    boost::replace_all_copy(rawHtml.toStdString(), "\'", "\'\'"),
                    "\n",
                    "\\n"
            ));
}

QString HtmlSerializer::deserialize(const QString &serializedHtml) {
    return QString::fromStdString(
            boost::replace_all_copy(
                    boost::replace_all_copy(serializedHtml.toStdString(), "\'\'", "\'"),
                    "\\n",
                    "\n"
            ));
}
