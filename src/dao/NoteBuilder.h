#ifndef GRAPHENE_NOTE_FACTORY_H
#define GRAPHENE_NOTE_FACTORY_H

#include <model/Note.h>

class QVariant;

class NoteBuilder {
public:
    Note build();

    NoteBuilder& id(const QVariant& id);
    NoteBuilder& creationDate(const QVariant& creationDate);
    NoteBuilder& lastModifiedDate(const QVariant& lastModifiedDate);
    NoteBuilder& content(const QVariant& content);
    NoteBuilder& digest(const QVariant& digest);

private:
    Note note;
};
#endif  // GRAPHENE_NOTE_FACTORY_H