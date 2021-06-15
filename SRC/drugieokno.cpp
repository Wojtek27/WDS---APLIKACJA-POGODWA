#include "drugieokno.h"
#include "ui_drugieokno.h"


drugieOkno::drugieOkno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drugieOkno)
{
    ui->setupUi(this);
    zegar = new QTimer(this);
    connect(zegar,SIGNAL(timeout()),this,SLOT(godzina()));
    zegar->start(1000);


    scenaTemp = new Scena(this);
    QGraphicsPixmapItem *picTemp = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/temperature.png"));
    scenaTemp->addItem(picTemp);
    ui->graphicsViewTemp->setScene(scenaTemp);

    scenaCis = new Scena(this);
    QGraphicsPixmapItem *picCis = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/pressure.png"));
    scenaCis->addItem(picCis);
    ui->graphicsViewCis->setScene(scenaCis);

    scenaWilg = new Scena(this);
    QGraphicsPixmapItem *picWilg = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/humidity.png"));
    scenaWilg->addItem(picWilg);
    ui->graphicsViewWilg->setScene(scenaWilg);

    scenaPrwr = new Scena(this);
    QGraphicsPixmapItem *picPrWr = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/wind_speed.png"));
    scenaPrwr->addItem(picPrWr);
    ui->graphicsViewPrW->setScene(scenaPrwr);

    scenaOpad = new Scena(this);
    QGraphicsPixmapItem *picOpad = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/ilosc_opadow.png"));
    scenaOpad->addItem(picOpad);
    ui->graphicsViewOpad->setScene(scenaOpad);
}


drugieOkno::~drugieOkno()
{
    delete ui;
}

void drugieOkno::wyluskajJsona(QString zawartosc)
{
    QJsonParseError bladJson;
    QJsonDocument dok = QJsonDocument::fromJson(zawartosc.toUtf8(),&bladJson);

    if(bladJson.error != QJsonParseError::NoError)
        qDebug() << bladJson.errorString();

    QJsonObject obiektJson = dok.object();
    QJsonObject mejn = obiektJson["main"].toObject();
    QJsonObject wind = obiektJson["wind"].toObject();
    QJsonObject rain = obiektJson["rain"].toObject();
    QJsonArray weather = obiektJson["weather"].toArray();
    QJsonObject firstEl = weather.at(0).toObject();
    double temperatura = mejn["temp"].toDouble();
    int wilgotnosc = mejn["humidity"].toInt();
    int cisnienie = mejn["pressure"].toInt();
    double predkoscWiatru = wind["speed"].toDouble();
    int kierunekWiatru = wind["deg"].toInt();
    double iloscOpadow = rain["1h"].toDouble();
    QString pogoda = firstEl["description"].toString();
    int kodPogody = firstEl["id"].toInt();
    QString nazwaMiasta = obiektJson["name"].toString();
    emit potrzebneParametry(temperatura, cisnienie, wilgotnosc, predkoscWiatru, iloscOpadow, pogoda, kierunekWiatru, nazwaMiasta, kodPogody);

}

void drugieOkno::ustawParametry(double &temp, int &cis, int &wilg, double &prwr, double &ilo, QString &pog, int &krw, QString &miasto, int &kPog)
{
    int T = temp;
    ui->lineEditTemperaruta->setText(QString::number(T-273));
    ui->lineEditCisnienie->setText(QString::number(cis));
    ui->lineEditWilgotnosc->setText(QString::number(wilg));
    int v = prwr;
    ui->linePredkoscWiatru->setText(QString::number(v*3.6));
    ui->lineEditIloscOpadow->setText(QString::number(ilo));

    if(pog == "clear sky"){
        pogoda = "Bezchmurnie";
    }else if(pog == "few clouds"){
        pogoda = "Lekkie zachmurzenie";
    }else if(pog == "scattered clouds"){
        pogoda = "Zachmurzenie";
    }else if(pog == "broken clouds"){
        pogoda = "Całkowite zachmurzenie";
    }else if(pog == "overcast clouds"){
        pogoda = "Całkowite zachmurzenie";
    }else if (pog == "shower rain"){
        pogoda = "Lekki deszcz";
    }else if(pog == "light rain"){
        pogoda = "Lekki deszcz";
    }else if(pog == "rain"){
        pogoda = "Deszcz";
    }else if(pog == "moderate rain"){
        pogoda = "Deszcz";
    }else if (pog == "heavy intensity rain"){
        pogoda = "Ulewny deszcz";
    }else if (pog == "very heavy rain"){
        pogoda = "Ulewny deszcz";
    }else if (pog == "extreme rain"){
        pogoda = "Ekstremalni ulewny deszcz";
    }else if(pog == "thunderstorm"){
        pogoda = "Burza";
    }else if (pog == "heavy thunderstorm"){
        pogoda = "Silna burza";
    }else if (pog == "	light thunderstorm"){
        pogoda = "Lekka burza";
    }else if (pog == "thunderstorm with heavy rain"){
        pogoda = "Burza z ulewnym deszczem";
    }else if (pog == "thunderstorm with rain"){
        pogoda = "Burza z deszczem";
    }else
        pogoda = pog;
    ui->lineEditPogoda->setText(pogoda);

    if((krw >= 0 && krw <= 22 )|| (krw >= 338 && krw <=360)){
        kierWiatru = "N";
        scenakierWrN = new Scena(this);
        QGraphicsPixmapItem *pickierWiaN = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_s.png"));
        scenakierWrN->addItem(pickierWiaN);
        ui->graphicsViewKier->setScene(scenakierWrN);
    }
    if(krw >= 23 && krw <= 67){
        kierWiatru = "NE";
        scenakierWrNE = new Scena(this);
        QGraphicsPixmapItem *pickierWiaNE = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_SW.png"));
        scenakierWrNE->addItem(pickierWiaNE);
        ui->graphicsViewKier->setScene(scenakierWrNE);
    }
    if(krw >= 68 && krw <= 112){
        kierWiatru = "E";
        scenakierWrE = new Scena(this);
        QGraphicsPixmapItem *pickierWiaE = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_W.png"));
        scenakierWrE->addItem(pickierWiaE);
        ui->graphicsViewKier->setScene(scenakierWrE);
    }
    if(krw >= 113 && krw <= 157){
        kierWiatru = "SE";
        scenakierWrSE = new Scena(this);
        QGraphicsPixmapItem *pickierWiaSE = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_NW.png"));
        scenakierWrSE->addItem(pickierWiaSE);
        ui->graphicsViewKier->setScene(scenakierWrSE);
    }
    if(krw >= 158 && krw <= 202){
        kierWiatru = "S";
        scenakierWrS = new Scena(this);
        QGraphicsPixmapItem *pickierWiaS = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_N.png"));
        scenakierWrS->addItem(pickierWiaS);
        ui->graphicsViewKier->setScene(scenakierWrS);
    }
    if(krw >= 203 && krw <= 247){
        kierWiatru = "SW";
        scenakierWrSW = new Scena(this);
        QGraphicsPixmapItem *pickierWiaSW = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_NE.png"));
        scenakierWrSW->addItem(pickierWiaSW);
        ui->graphicsViewKier->setScene(scenakierWrSW);
    }
    if(krw >= 248 && krw <= 292){
        kierWiatru = "W";
        scenakierWrW = new Scena(this);
        QGraphicsPixmapItem *pickierWiaW = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_e.png"));
        scenakierWrW->addItem(pickierWiaW);
        ui->graphicsViewKier->setScene(scenakierWrW);
    }
    if(krw >= 293 && krw <= 337){
        kierWiatru = "NW";
        scenakierWrNW = new Scena(this);
        QGraphicsPixmapItem *pickierWiaNW = new QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/direction_SE.png"));
        scenakierWrNW->addItem(pickierWiaNW);
        ui->graphicsViewKier->setScene(scenakierWrNW);
    }

    ui->lineEditKierunekWiatru->setText(kierWiatru);

    if(miasto == "Warsaw"){
        miastoPl = "Warszawa";
    }
    else if(miasto == "Krakow"){
        miastoPl = "Kraków";
    }
    else if(miasto == "Opole Voivodeship"){
        miastoPl = "Opole";
    }
    else if(miasto == "Lublin Voivodeship"){
        miastoPl = "Lublin";
    }else
        miastoPl = miasto;
    ui->lineEditMiasto->setText(miastoPl);

    if(kPog == 200 || kPog == 201 || kPog == 202 || kPog == 210 || kPog == 211 || kPog == 212 || kPog == 221 || kPog == 230 || kPog == 231 || kPog == 232){
        burza = new Scena(this);
        QGraphicsPixmapItem *picBurza = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/th.png"));
        burza->addItem(picBurza);
        ui->graphicsViewPogoda->setScene(burza);
    }
    if(kPog == 300 || kPog == 301 || kPog == 302 || kPog == 310 || kPog == 311 || kPog == 312 || kPog == 312 || kPog == 313 || kPog == 314 || kPog == 321){
        lekkiDeszcz = new Scena(this);
        QGraphicsPixmapItem *picLDeszcz = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/l.png"));
        lekkiDeszcz->addItem(picLDeszcz);
        ui->graphicsViewPogoda->setScene(lekkiDeszcz);
    }
    if(kPog == 500 || kPog == 501 || kPog == 502 || kPog == 503 || kPog == 504 || kPog == 511 || kPog == 520 || kPog == 521 || kPog == 522 || kPog == 531){
        deszcz = new Scena(this);
        QGraphicsPixmapItem *picDeszcz = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/rain.png"));
        deszcz->addItem(picDeszcz);
        ui->graphicsViewPogoda->setScene(deszcz);
    }
    if(kPog == 800){
        slonce = new Scena(this);
        QGraphicsPixmapItem *picSlonce = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/slonce.png"));
        slonce->addItem(picSlonce);
        ui->graphicsViewPogoda->setScene(slonce);
    }
    if(kPog == 801){
        lekkieZach = new Scena(this);
        QGraphicsPixmapItem *piclekkiezach = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/fewclouds.png"));
        lekkieZach->addItem(piclekkiezach);
        ui->graphicsViewPogoda->setScene(lekkieZach);
    }
    if(kPog == 802){
        zachmurzenie = new Scena(this);
        QGraphicsPixmapItem *piczachmurzenie = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/clouds.png"));
        zachmurzenie->addItem(piczachmurzenie);
        ui->graphicsViewPogoda->setScene(zachmurzenie);
    }
    if(kPog == 803 || kPog == 804){
        mocneZach = new Scena(this);
        QGraphicsPixmapItem *picmocneZach = new  QGraphicsPixmapItem(QPixmap(":/pliki/zdjecia/darkcloud.png"));
        mocneZach->addItem(picmocneZach);
        ui->graphicsViewPogoda->setScene(mocneZach);
    }
}

void drugieOkno::wez(QString zawartosc)
{
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(zawartosc)));
    connect(reply, &QNetworkReply::readyRead, this,&drugieOkno::odczytaj);

}

void drugieOkno::godzina()
{
    QDateTime czas = QDateTime::currentDateTime();
    QString czas_tekst = czas.toString("dd-MM-yyyy hh:mm:ss");
    ui->label_czas->setText(czas_tekst);
}

void drugieOkno::odczytaj()
{
    QString strReply;
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply){
        strReply = reply->readAll();
    }
    wyluskajJsona(strReply);
}





