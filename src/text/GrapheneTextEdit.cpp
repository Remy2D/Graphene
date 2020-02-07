#include <QApplication>
#include <QMouseEvent>
#include <QTextDocumentFragment>
#include <QtWidgets/QWidget>

#include "GrapheneTextEdit.h"
#include "common/Logger.h"

GrapheneTextEdit::GrapheneTextEdit(QWidget *parent) : QTextEdit(parent) {
    setMouseTracking(true);
}

void GrapheneTextEdit::mousePressEvent(QMouseEvent *event) {
    QTextCursor tc = cursorForPosition(event->pos());
    tc.select(QTextCursor::WordUnderCursor);
    QString strWord = tc.selection().toHtml();


    auto obj = findSpecialObjects(strWord);

    if (obj) {
        obj->onMousePressed(tc);
    } else {
        QTextEdit::mousePressEvent(event);
    }

}

void GrapheneTextEdit::mouseMoveEvent(QMouseEvent *event) {
    QTextCursor tc = cursorForPosition(event->pos());
    tc.select(QTextCursor::WordUnderCursor);
    QString strWord = tc.selection().toHtml();

    auto obj = findSpecialObjects(strWord);

    if (obj) {
        obj->onMouseMoved(tc);
    } else {
        QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
    }

    QTextEdit::mouseMoveEvent(event);
    QWidget::repaint();
}

std::unique_ptr<SpecialObject> GrapheneTextEdit::findSpecialObjects(QString &strWord) {
    if (hackishAsFuckHtmlFormatter.containsUncheckedListNode(strWord)) {
        return std::make_unique<CheckedListNode>(CheckedListNode(false, hackishAsFuckHtmlFormatter));
    } else if (hackishAsFuckHtmlFormatter.containsCheckedListNode(strWord)) {
        return std::make_unique<CheckedListNode>(CheckedListNode(true, hackishAsFuckHtmlFormatter));
    }

    return nullptr;
}

void GrapheneTextEdit::insertCheckedListNode() {
    insertHtml(hackishAsFuckHtmlFormatter.getSpacer());
    insertHtml(hackishAsFuckHtmlFormatter.getCheckedListImage(false).append(" "));
    setFocus();
}

void CheckedListNode::onMouseMoved(QTextCursor &tc) {
    LOG_DEBUG("Hoovering over item: " << itemName());
    QApplication::setOverrideCursor(QCursor(Qt::PointingHandCursor));
}

void CheckedListNode::onMousePressed(QTextCursor &tc) {
    LOG_DEBUG("CheckedList node changed");
    tc.removeSelectedText();
    tc.insertHtml(hackishAsFuckHtmlFormatter.getCheckedListImage(!checked));
}

CheckedListNode::CheckedListNode(bool checked, text::HackishAsFuckHtmlFormatter &hackishAsFuckHtmlFormatter) :
        checked(checked),
        hackishAsFuckHtmlFormatter(hackishAsFuckHtmlFormatter) {
}

std::string CheckedListNode::itemName() {
    return "CheckedListNode";
}
