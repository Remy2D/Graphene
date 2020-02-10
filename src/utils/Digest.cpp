#include "Digest.h"

QString Digest::digest(QString text) {
    text = text.simplified();
    text.truncate(20);

    return text;
}
