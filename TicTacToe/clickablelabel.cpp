#include "clickablelabel.h"

// Constructor
ClickableLabel::ClickableLabel(const QString& text, QWidget* parent, int h, int w)
    : QLabel(parent), h(h), w(w)
{
    setText(text);
}

// Destructor
ClickableLabel::~ClickableLabel()
{
}

// setval(char ch, int h, int w)
// public slot: Controller::notify(char ch, int h, int w)
// Only set the text to ch if the notify is calling the correct slot
void ClickableLabel::setval(const QString& ch, int h, int w)
{
    if(this->h == h && this->w == w) {
        setText(ch);
    }

}

// mousePressEvent(QMouseEvent* event)
// emits the clicked signal with the correct coordinates for the button
void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked(1, h, w);
}
