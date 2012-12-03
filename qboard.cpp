#include "qboard.h"

QPiece::QPiece(QWidget * parent, short xpos, short ypos) :
    QPushButton(parent), Piece(xpos, ypos) { }

void QPiece::paint(QPaintEvent* event)
{
    event->accept();
    QPainter p(this);
    p.drawRect(0,0,width(),height());
    if(owner){
        QColor fc;
        switch(owner){
            case(1):
                fc.setRgb(255,255,255);
                break;
            case(2):
                fc.setRgb(33,33,33);
                break;
        }
        p.setBrush(fc);
        p.drawEllipse(2,2,width()-4,height()-4);
    }
    p.end();
}

QBoard::QBoard(QWidget *parent, short gameSize, std::vector<QPiece*>* list) :
    QWidget(parent), gameSize(gameSize), list(list)
{
    for(short i = 0; i < gameSize * gameSize; i++){
        QPiece* p = new QPiece(this, (i%gameSize), (i/gameSize));
        list->push_back(p);
        // Place the piece on the canvas
        p->setGeometry(PADDING+(p->xpos)*CELLSIZE, PADDING+(p->ypos)*CELLSIZE, CELLWIDTH, CELLWIDTH);
        connect(p, SIGNAL(clicked()), this, SLOT(relay()));
    }
}

void QBoard::paintPieces()
{
    for(short pos = 0; pos < gameSize*gameSize; pos++)
        switch (list->at(pos)->owner) {
            case(player2):
                list->at(pos)->setStyleSheet("background-color: rgb(255, 51, 102)");
                break;
            case(player1):
                list->at(pos)->setStyleSheet("background-color: rgb(20, 255, 128)");
                break;
            case(empty):
                list->at(pos)->setStyleSheet("background-color: rgb(220, 220, 220)");
                break;
        }
}

void QBoard::relay()
{
    QPiece* sender = dynamic_cast<QPiece*>(QObject::sender());
    emit click(sender->xpos, sender->ypos);
}
