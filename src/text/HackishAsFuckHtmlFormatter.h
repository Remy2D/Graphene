#ifndef GRAPHENE_HTML_FORMATTER_H
#define GRAPHENE_HTML_FORMATTER_H

#include <string>
#include <QtCore/QString>

namespace text {

class HackishAsFuckHtmlFormatter {
public:
    QString getCheckedListImage(bool checked);

    QString getSpacer();

    bool containsCheckedListNode(QString &);

    bool containsUncheckedListNode(QString &);

private:
    std::string getCheckedListImageFileName(bool checked);

    const QString checkedListNodeFile = "checked.png";
    const QString uncheckedListNodeFile = "unchecked.png";
    const std::string htmlImageTemplate = "<img src='resources/images/FILENAME' height='FONTSIZE' width='FONTSIZE'/>";
    const QString spacer = "<br/>";
};

}  // namespace text

#endif  // GRAPHENE_HTML_FORMATTER_H