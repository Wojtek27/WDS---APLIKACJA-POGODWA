#ifndef DRUGIEOKNO_H
#define DRUGIEOKNO_H

 /*!
  *\file
  *
  *\brief Defincja klasy drugieokno
  *
  * Plik zawiera definicję klasy drugieokno,
  * która odpowiada za drugie okno aplikacji oraz pobieranie danych ze strony www
  */
#include <QtWidgets>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QLineEdit>
#include <QGraphicsPixmapItem>
#include "scena.h"

namespace Ui {
class drugieOkno;
}

class drugieOkno : public QDialog
{
    Q_OBJECT

public:
    explicit drugieOkno(QWidget *parent = nullptr);
    ~drugieOkno();

    /*!
     * \brief wyluskajJsona
     *
     * Metoda odpowiadająca za wyłuskanie jsona ze strony www
     *
     * \param[in] zawartosc - ciąg danych JSON
     */
    void wyluskajJsona(QString zawartosc);


public slots:
    /*!
     * \brief ustawParametry
     *
     * Metoda, która wypisuje potrzebne parametry ze storny internetowej
     * w drugim oknie aplikacji
     *
     * \param[in] temp - paramter przechowujący wartość temperatury
     * \param[in] cis - paramter przechowujący wartość cisnienia
     * \param[in] wilg - paramter przechowujący wartość wilgotności
     * \param[in] prwr - paramter przechowujący wartość prędkości wiatru
     * \param[in] ilo - paramter przechowujący wartość ilości opadów w ciągu ostatniej godziny
     * \param[in] pog - paramter przechowujący opis pogody
     * \param[in] krw - paramter przechowujący wartość kierunku wiatru
     * \param[in] miasto - paramter przechowujący nazwę miasta
     * \param[in] kPog - paramter przechowujący wartość kodu pogody
     */
    void ustawParametry(double &temp, int &cis, int &wilg, double &prwr, double &ilo, QString &pog, int &krw, QString &miasto, int &kPog);
    /*!
     * \brief wez
     *
     * Metoda, która odpowiada za komunikacje ze strona www
     *
     * \param[in] zawartosc - zmienna, która przekazuje adres strony www
     */
    void wez(QString zawartosc);

private slots:
    /*!
     * \brief godzina
     *
     * Metoda, która odpowiada za wyświetlenie aktualnej godziny w drugim oknie
     *
     */
    void godzina();
    /*!
     * \brief odczytaj
     *
     * Metoda odpowiadająca za odczytanie zawartosci ze strony www
     */
    void odczytaj();

signals:
    /*!
     * \brief potrzebneParametry
     *
     * Slot, potrzebny do metody wyluskajJsona
     *
     * \param[in] temp - paramter przechowujący wartość temperatury
     * \param[in] cis - paramter przechowujący wartość cisnienia
     * \param[in] wilg - paramter przechowujący wartość wilgotności
     * \param[in] prwr - paramter przechowujący wartość prędkości wiatru
     * \param[in] ilo - paramter przechowujący wartość ilości opadów w ciągu ostatniej godziny
     * \param[in] pog - paramter przechowujący opis pogody
     * \param[in] krw - paramter przechowujący wartość kierunku wiatru
     * \param[in] miasto - paramter przechowujący nazwę miasta
     * \param[in] kPog - paramter przechowujący wartość kodu pogody
     *
     */
    void potrzebneParametry(double &temp, int &cis, int &wilg, double &prwr, double &ilo, QString &pog, int &krw, QString &miasto, int &kPog);
private:
    Ui::drugieOkno *ui;
    //drugieOkno *parametryPogodowe;
    QNetworkAccessManager manager;
    QString kierWiatru = "";
    QString miastoPl = "";
    QString pogoda = "";
    QTimer *zegar;
    Scena * scenaTemp;
    Scena * scenaCis;
    Scena * scenaWilg;
    Scena * scenaPrwr;
    Scena * scenaOpad;
    Scena * scenakierWrN;
    Scena * scenakierWrNE;
    Scena * scenakierWrE;
    Scena * scenakierWrSE;
    Scena * scenakierWrS;
    Scena * scenakierWrSW;
    Scena * scenakierWrW;
    Scena * scenakierWrNW;
    Scena * slonce;
    Scena * lekkieZach;
    Scena * zachmurzenie;
    Scena * mocneZach;
    Scena * lekkiDeszcz;
    Scena * deszcz;
    Scena * burza;
};

#endif // DRUGIEOKNO_H
