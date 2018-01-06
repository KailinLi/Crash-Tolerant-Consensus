#ifndef COLORITEM_H
#define COLORITEM_H

#include <QGraphicsItem>

//! [0]
class ColorItem : public QObject, public QGraphicsItem
{
public:
    ColorItem();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    void setColor(QColor c);
    void setText(QString s);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QColor color;
    QString text;
};
//! [0]

#endif
