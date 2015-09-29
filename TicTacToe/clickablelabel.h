#ifndef CLICKABLELABEL
#define CLICKABLELABEL

#include <QLabel>
#include <QObject>

class Controller;

class ClickableLabel : public QLabel
{
Q_OBJECT

    // Location the of button
    int h;
    int w;

public:

    // Constructor/destructor
    explicit ClickableLabel( const QString& text="", QWidget* parent=0, int h = 4, int w = 4, Controller * contr = 0);
    ~ClickableLabel();

signals:

    // Signals controller that this square has been clicked on
    void clicked(int type,int h, int w);

public slots:

    // Catches signals from controller(notify) to change the text of the label
    void setval(const QString& ch, int h, int w);

protected:

    // If the mouse is clicked, emit the clicked signal
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL

