#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    scena = new Scena(this);
    scena->setSceneRect(-250,-300,500,600);
    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/mapa.png"));
    scena->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) -QPointF(pixItem->boundingRect().width()/2,
                                          pixItem->boundingRect().height()/2));

    ui->Mapa_2->setScene(scena);

    QComboBox* comboBox = new QComboBox;
    ui->comboBox->addItem("Białystok");
    ui->comboBox->addItem("Bydgoszcz");
    ui->comboBox->addItem("Gdańsk");
    ui->comboBox->addItem("Gorzów Wielkopolski");
    ui->comboBox->addItem("Katowice");
    ui->comboBox->addItem("Kielce");
    ui->comboBox->addItem("Kraków");
    ui->comboBox->addItem("Lublin");
    ui->comboBox->addItem("Łódź");
    ui->comboBox->addItem("Olsztyn");
    ui->comboBox->addItem("Opole");
    ui->comboBox->addItem("Poznań");
    ui->comboBox->addItem("Rzeszów");
    ui->comboBox->addItem("Szczecin");
    ui->comboBox->addItem("Toruń");
    ui->comboBox->addItem("Warszawa");
    ui->comboBox->addItem("Wrocław");
    ui->comboBox->addItem("Zielona Góra");


    connect(comboBox, QOverload<int>::of(&QComboBox::activated),
           [=](int index) { on_comboBox_activated(index); });

    zegar = new QTimer(this);
    connect(zegar,SIGNAL(timeout()),this,SLOT(godzina()));
    zegar->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::odswiez()
{
    QTime czas = QTime::currentTime().addSecs(1);
    while(QTime::currentTime() < czas)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}


/***************************************************************************************************************/

void MainWindow::on_actionBia_ystok_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(bialystok);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionBydgoszcz_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(bydgoszcz);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionGda_sk_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(gdansk);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionGorz_w_Wielkopolski_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(gorzowWielkopolski);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionKatowice_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(katowice);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionKielce_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(kielce);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionKrak_w_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(krakow);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionLublin_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(lublin);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_action_d_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(lodz);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionOlsztyn_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(olsztyn);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionOpole_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(opole);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionPozna_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(poznan);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}
void MainWindow::on_actionRzesz_w_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(rzeszow);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionSzczecin_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(szczecin);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionToru_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(torun);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionWarszawa_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(warszawa);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionWroc_aw_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(wroclaw);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_actionZielona_G_ra_triggered()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(zielonaGora);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

/*********************************************************************************************************/

void MainWindow::on_comboBox_activated(int index)
{
    switch(index){

    case 0:
        drugieokno = new drugieOkno;
        drugieokno->wez(bialystok);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 1:
        drugieokno = new drugieOkno;
        drugieokno->wez(bydgoszcz);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 2:
        drugieokno = new drugieOkno;
        drugieokno->wez(gdansk);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 3:
        drugieokno = new drugieOkno;
        drugieokno->wez(gorzowWielkopolski);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 4:
        drugieokno = new drugieOkno;
        drugieokno->wez(katowice);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 5:
        drugieokno = new drugieOkno;
        drugieokno->wez(kielce);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 6:
        drugieokno = new drugieOkno;
        drugieokno->wez(krakow);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 7:
        drugieokno = new drugieOkno;
        drugieokno->wez(lublin);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 8:
        drugieokno = new drugieOkno;
        drugieokno->wez(lodz);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 9:
        drugieokno = new drugieOkno;
        drugieokno->wez(olsztyn);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 10:
        drugieokno = new drugieOkno;
        drugieokno->wez(opole);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 11:
        drugieokno = new drugieOkno;
        drugieokno->wez(poznan);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 12:
        drugieokno = new drugieOkno;
        drugieokno->wez(rzeszow);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 13:
        drugieokno = new drugieOkno;
        drugieokno->wez(szczecin);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 14:
        drugieokno = new drugieOkno;
        drugieokno->wez(torun);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 15:
        drugieokno = new drugieOkno;
        drugieokno->wez(warszawa);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 16:
        drugieokno = new drugieOkno;
        drugieokno->wez(wroclaw);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    case 17:
        drugieokno = new drugieOkno;
        drugieokno->wez(zielonaGora);
        connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
        drugieokno->show();
        break;
    }

}
void MainWindow::godzina()
{
    QDateTime czas = QDateTime::currentDateTime();
    QString czas_tekst = czas.toString("dd-MM-yyyy hh:mm:ss");
    ui->label_czas->setText(czas_tekst);
}

void MainWindow::on_Odswiez_clicked()
{
    odswiez();
}
/*************************************************************************************************************/

void MainWindow::on_Gdansk_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(gdansk);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}
void MainWindow::on_Szczecin_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(szczecin);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Olsztyn_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(olsztyn);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Bydgoszcz_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(bydgoszcz);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Bialystok_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(bialystok);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Torun_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(torun);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Gorzow_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(gorzowWielkopolski);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Poznan_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(poznan);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Zielona_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(zielonaGora);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Wroclaw_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(wroclaw);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Opole_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(opole);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Lodz_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(lodz);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Kielce_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(kielce);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Katowice_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(katowice);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Krakow_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(krakow);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Rzeszow_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(rzeszow);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Lublin_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(lublin);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_Warszawa_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(warszawa);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

/****************************************************************************************************/

void MainWindow::on_pushButtonBia_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(bialystok);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonBYD_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(bydgoszcz);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonGDA_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(gdansk);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonGOR_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(gorzowWielkopolski);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonKAT_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(katowice);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonKIE_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(kielce);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonKRA_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(krakow);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonLUB_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(lublin);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonLOD_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(lodz);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonOLS_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(olsztyn);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonOPO_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(opole);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtoPOZ_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(poznan);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonRZE_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(rzeszow);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonsSZC_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(szczecin);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonTOR_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(torun);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonWAR_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(warszawa);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonWRO_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(wroclaw);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}

void MainWindow::on_pushButtonZIE_clicked()
{
    drugieokno = new drugieOkno;
    drugieokno->wez(zielonaGora);
    connect(drugieokno, &drugieOkno::potrzebneParametry, drugieokno, &drugieOkno::ustawParametry);
    drugieokno->show();
}




