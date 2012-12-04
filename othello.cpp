#include "othello.h"
#include "ui_othello.h"

Othello::Othello(QWidget *parent, short gameSize) :
    QMainWindow(parent), gameSize(gameSize),
    ui(new Ui::Othello)
{
    ui->setupUi(this);

    this->setFixedSize(2*PADDING + gameSize*CELLSIZE,2*PADDING + gameSize*CELLSIZE+44);
    this->setWindowTitle("Othello");

    board = new QBoard(this, gameSize, &list);
    board->setGeometry(0, 22, 2*PADDING + gameSize*CELLSIZE,
                       2*PADDING + gameSize*CELLSIZE);

    game = new Game(gameSize, &list);

    statusLabel= new QLabel(ui->statusBar);
    ui->statusBar->addWidget(statusLabel);
    game->update();
    updateStatus();

    connect(board, SIGNAL(click(short, short)), this, SLOT(click(short, short)));

    /* Set up the signal from GUI */
    connect(ui->actionNew_Game, SIGNAL(triggered()), this, SLOT(newGame()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionHow_to_play, SIGNAL(triggered()), this, SLOT(help()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    board->paintPieces();
}

Othello::~Othello()
{
    delete game;
    delete board;
    delete ui;
    delete statusLabel;
}

void Othello::click(short xpos, short ypos)
{
    if(game->put(xpos, ypos, game->turn()))
       board->paintPieces();
    updateStatus();
    if(game->ended()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Win");
        if(game->greenCount > game->redCount)
            msgBox.setInformativeText("Green have won the game!");
        else if(game->greenCount < game->redCount)
            msgBox.setInformativeText("Red have won the game!");
        else
            msgBox.setInformativeText("Draw");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void Othello::updateStatus()
{
    QString status = "Red: " +
            QString::number(game->redCount) +
            "\tGreen: " +
            QString::number(game->greenCount) +
            "\tCurrent: " +
            (game->turn() == player1 ? "Green" : "Red");
    statusLabel->setText(status);
}

void Othello::newGame()
{
    game->reset();
    board->paintPieces();
    updateStatus();
}

void Othello::help()
{
    QDesktopServices::openUrl(QUrl("http://en.wikipedia.org/wiki/Othello_(game)#Rules"));
}

void Othello::about()
{
    QMessageBox msgBox;
    msgBox.setWindowOpacity(0.9);
    msgBox.setWindowTitle("About");
    msgBox.setInformativeText("<b>Othello</b><br>Based on Qt " QT_VERSION_STR "<p>By Yi Kong(yk1211@imperial.ac.uk)<p>Built on " __DATE__ " at " __TIME__);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
