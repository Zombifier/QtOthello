#ifndef QBOARD_H
#define QBOARD_H

#include <vector>
#include <QColor>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QWidget>

#include "piece.h"
#include "player.h"

#define PADDING 2
#define CELLSIZE 42
#define CELLWIDTH 41

class QPiece : public QPushButton, public Piece
{
    Q_OBJECT
public:
    QPiece(QWidget * parent = 0, short x = 0, short y = 0);
    /*
     *  Owner is either 0 - Not owned, ie No piece placed
     *  Or 1,2
     */
protected:
    void paint(QPaintEvent* event);
};

class QBoard : public QWidget
{
    Q_OBJECT
    const short gameSize;
public:
    explicit QBoard(QWidget *parent = 0, short gameSize = 8,
                    std::vector<QPiece*>* list = NULL);
    void paintPieces();
private:
    std::vector<QPiece*>* list;
private slots:
    void relay();
signals:
    void click(short x, short y);
};

#endif // QBOARD_H
