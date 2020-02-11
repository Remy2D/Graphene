#ifndef GRAPHENE_LIST_VIEW_H
#define GRAPHENE_LIST_VIEW_H

#include <QtWidgets/QListView>

class GrapheneListView : public QListView {
public:
    explicit GrapheneListView(QWidget *parent = nullptr);
};

#endif  // GRAPHENE_LIST_VIEW_H
