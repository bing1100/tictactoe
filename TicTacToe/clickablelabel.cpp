#include "clickablelabel.h"
#include "controller.h"
#include <QFont>

// Constructor
ClickableLabel::ClickableLabel(const QString& text, QWidget* parent, int h, int w, Controller * contr)
    : QLabel(parent), h(h), w(w)
{
    // Setup formatting for label text
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    this->setAlignment(Qt::AlignCenter);
    this->setFont(font);
    setText(text);

    // Setup the signals with slots
    QObject::connect(contr    , SIGNAL(notify(const QString&, int, int))
                    ,this, SLOT(setval(const QString&, int, int)));
    QObject::connect(this, SIGNAL(clicked(int, int, int))
                    ,contr    , SLOT(catchclick(int, int, int)));
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
