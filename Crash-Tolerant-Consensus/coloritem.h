#ifndef COLORITEM_H
#define COLORITEM_H

#include <QGraphicsItem>
#include <QParallelAnimationGroup>

//! [0]
class ColorItem : public QGraphicsObject//QGraphicsItem
{
public:
    ColorItem();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    void setColor(QColor c);
    void setText(QString s);
    void stopAnimation();
    QParallelAnimationGroup *animation;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) Q_DECL_OVERRIDE;

private:
    QColor color;
    QString text;
};
//! [0]

#endif
