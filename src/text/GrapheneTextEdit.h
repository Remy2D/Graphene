#pragma once

#include <QtWidgets/QTextEdit>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <boost/optional.hpp>
#include <memory>
#include "HackishAsFuckHtmlFormatter.h"

//todo: separate file:
class SpecialObject {
public:
    virtual void onMouseMoved(QTextCursor &) = 0;

    virtual void onMousePressed(QTextCursor &) = 0;

    virtual std::string itemName() = 0;
};

class CheckedListNode : public SpecialObject {
public:
    explicit CheckedListNode(bool checked, text::HackishAsFuckHtmlFormatter &);

    void onMouseMoved(QTextCursor &) override;

    void onMousePressed(QTextCursor &) override;

    std::string itemName() override;

private:
    bool checked;
    text::HackishAsFuckHtmlFormatter &hackishAsFuckHtmlFormatter;
};

class GrapheneTextEdit : public QTextEdit {

public:
    explicit GrapheneTextEdit(QWidget *parent);

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *e) override;

    void insertCheckedListNode();

private:
    std::unique_ptr<SpecialObject> findSpecialObjects(QString &cursor);

    text::HackishAsFuckHtmlFormatter hackishAsFuckHtmlFormatter;
};