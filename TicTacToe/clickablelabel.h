#ifndef CLICKABLELABEL
#define CLICKABLELABEL

#include <QLabel>
#include <QObject>

class Controller;

class ClickableLabel : public QLabel
{
Q_OBJECT

    int h;
    int w;

public:
    explicit ClickableLabel( const QString& text="", QWidget* parent=0, int h = 4, int w = 4);
    ~ClickableLabel();

signals:
    void clicked(int type,int h, int w);

public slots:
    void setval(const QString& ch, int h, int w);

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL

