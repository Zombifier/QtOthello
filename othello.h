#ifndef OTHELLO_H
#define OTHELLO_H

#include <QDesktopServices>
#include <QLabel>
#include <QMessageBox>
#include <QtGui/QMainWindow>
#include <QUrl>
#include <vector>

#include "game.h"
#include "player.h"
#include "qboard.h"

namespace Ui {
    class Othello;
}

class Othello : public QMainWindow
{
    Q_OBJECT
public:
    explicit Othello(QWidget *parent = 0, short gameSize = 8);
    ~Othello();
    std::vector<QPiece*> list;
    short gameSize;
    Game* game;
private:
    QBoard* board;
    Ui::Othello *ui;
    QLabel* statusLabel;
    void init();
    void updateStatus();
private slots:
    void click(short xpos, short ypos);
    void newGame();
    void help();
    void about();
};

#endif // OTHELLO_H
