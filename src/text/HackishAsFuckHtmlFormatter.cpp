#include "common/Configuration.h"
#include "HackishAsFuckHtmlFormatter.h"

#include <boost/algorithm/string.hpp>

QString text::HackishAsFuckHtmlFormatter::getCheckedListImage(bool checked) {
    auto fontSize = getConfiguration().getString(config::PropertyKey::UI_FONT_SIZE);
    auto imageFileName = getCheckedListImageFileName(checked);

    return QString::fromStdString(
        boost::replace_all_copy(
        boost::replace_all_copy(htmlImageTemplate, "FILENAME", imageFileName),
        "FONTSIZE",
        fontSize
        )
    );
}

std::string text::HackishAsFuckHtmlFormatter::getCheckedListImageFileName(bool checked) {
    if (checked) {
        return checkedListNodeFile.toStdString();
    } else {
        return uncheckedListNodeFile.toStdString();
    }
}

bool text::HackishAsFuckHtmlFormatter::containsCheckedListNode(QString& html) {
    return html.contains(checkedListNodeFile);
}

bool text::HackishAsFuckHtmlFormatter::containsUncheckedListNode(QString& html) {
    return html.contains(uncheckedListNodeFile);
}

QString text::HackishAsFuckHtmlFormatter::getSpacer() {
    return spacer;
}
