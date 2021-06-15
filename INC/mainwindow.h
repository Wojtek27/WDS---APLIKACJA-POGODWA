#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 /*!
  *\file
  *\brief Defincja klasy mainwindow
  *
  * Plik zawiera definicję klasy mainwindow,
  * która odpowiada za główne okno aplikacji
  */

#include <QGraphicsPixmapItem>
#include <QtGui>
#include <QtCore>
#include <QComboBox>
#include <QWidget>
#include <QDateTime>
#include <QMainWindow>
#include <QTimer>
#include "scena.h"
#include "drugieokno.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief bialystok
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString bialystok = "http://api.openweathermap.org/data/2.5/weather?q=Białystok&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief bydgoszcz
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString bydgoszcz = "http://api.openweathermap.org/data/2.5/weather?q=Bydgoszcz&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief gdansk
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString gdansk = "http://api.openweathermap.org/data/2.5/weather?q=Gdańsk&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief gorzowWielkopolski
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString gorzowWielkopolski = "http://api.openweathermap.org/data/2.5/weather?q=gorzów%20wielkopolski&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief katowice
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString katowice = "http://api.openweathermap.org/data/2.5/weather?q=Katowice&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief kielce
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     */
    QString kielce = "http://api.openweathermap.org/data/2.5/weather?q=Kielce&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief krakow
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString krakow = "http://api.openweathermap.org/data/2.5/weather?q=Kraków&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief lublin
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString lublin = "http://api.openweathermap.org/data/2.5/weather?q=Lublin&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief lodz
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString lodz = "http://api.openweathermap.org/data/2.5/weather?q=Lodz&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief olsztyn
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString olsztyn = "http://api.openweathermap.org/data/2.5/weather?q=Olsztyn&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief opole
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString opole = "http://api.openweathermap.org/data/2.5/weather?q=Opole&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief poznan
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString poznan = "http://api.openweathermap.org/data/2.5/weather?q=Poznań&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief rzeszow
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString rzeszow = "http://api.openweathermap.org/data/2.5/weather?q=Rzeszów&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief szczecin
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString szczecin = "http://api.openweathermap.org/data/2.5/weather?q=Szczecin&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief torun
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString torun = "http://api.openweathermap.org/data/2.5/weather?q=Toruń&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief warszawa
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString warszawa = "http://api.openweathermap.org/data/2.5/weather?q=Warszawa&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief wroclaw
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString wroclaw = "http://api.openweathermap.org/data/2.5/weather?q=Wrocław&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief zielonaGora
     *
     * Zmienna przechowująca adres storny www, z których program odczytuje dane pogodowe
     *
     */
    QString zielonaGora = "http://api.openweathermap.org/data/2.5/weather?q=zielona%20gora&appid=9659f8c012bb4d8a7dc526993aedf14d";

    /*!
     * \brief odswiez
     *
     * Metoda odpowiedzialna za odswiezanie
     */
    void odswiez();

private slots:

    /*!
     * \brief on_actionBia_ystok_triggered
     *
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionBia_ystok_triggered();

    /*!
     * \brief on_actionBydgoszcz_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionBydgoszcz_triggered();

    /*!
     * \brief on_actionGda_sk_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionGda_sk_triggered();

    /*!
     * \brief on_actionGorz_w_Wielkopolski_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionGorz_w_Wielkopolski_triggered();

    /*!
     * \brief on_actionKatowice_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionKatowice_triggered();

    /*!
     * \brief on_actionKielce_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionKielce_triggered();

    /*!
     * \brief on_actionKrak_w_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionKrak_w_triggered();

    /*!
     * \brief on_actionLublin_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionLublin_triggered();

    /*!
     * \brief on_action_d_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_action_d_triggered();

    /*!
     * \brief on_actionOlsztyn_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionOlsztyn_triggered();

    /*!
     * \brief on_actionOpole_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionOpole_triggered();

    /*!
     * \brief on_actionPozna_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionPozna_triggered();

    /*!
     * \brief on_actionRzesz_w_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionRzesz_w_triggered();

    /*!
     * \brief on_actionSzczecin_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionSzczecin_triggered();

    /*!
     * \brief on_actionToru_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionToru_triggered();

    /*!
     * \brief on_actionWarszawa_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionWarszawa_triggered();

    /*!
     * \brief on_actionWroc_aw_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionWroc_aw_triggered();

    /*!
     * \brief on_actionZielona_G_ra_triggered
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji z menuBar
     */
    void on_actionZielona_G_ra_triggered();


    /*!
     * \brief on_comboBox_activated
     *
     *
     * Metoda odpowiadająca za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy wybierzemy jedną z osiemnastu opcji rozwijanych z
     * przycisku comboBox
     *
     *
     * \param index
     */
    void on_comboBox_activated(int index);


    /*!
     * \brief godzina
     *
     * Metoda odpowidająca za wyświetlenie aktualnej daty oraz godziny
     */
    void godzina();

    /*!
     * \brief on_Odswiez_clicked
     *
     *
     *
     * Slot odpowiadający za odświeżanie
     */
    void on_Odswiez_clicked();


    /*!
     * \brief on_Gdansk_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Gdansk_clicked();

    /*!
     * \brief on_Szczecin_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Szczecin_clicked();

    /*!
     * \brief on_Olsztyn_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Olsztyn_clicked();

    /*!
     * \brief on_Bydgoszcz_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Bydgoszcz_clicked();

    /*!
     * \brief on_Bialystok_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Bialystok_clicked();

    /*!
     * \brief on_Torun_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Torun_clicked();

    /*!
     * \brief on_Gorzow_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Gorzow_clicked();

    /*!
     * \brief on_Poznan_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Poznan_clicked();

    /*!
     * \brief on_Zielona_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Zielona_clicked();

    /*!
     * \brief on_Wroclaw_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Wroclaw_clicked();

    /*!
     * \brief on_Opole_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Opole_clicked();

    /*!
     * \brief on_Lodz_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Lodz_clicked();

    /*!
     * \brief on_Kielce_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Kielce_clicked();

    /*!
     * \brief on_Katowice_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Katowice_clicked();

    /*!
     * \brief on_Krakow_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Krakow_clicked();

    /*!
     * \brief on_Rzeszow_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Rzeszow_clicked();

    /*!
     * \brief on_Lublin_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Lublin_clicked();

    /*!
     * \brief on_Warszawa_clicked
     *
     * Slot odpowiadający za wyświetlenie drugiego okna gdy klikniemy na nazwę miasta na mapie
     */
    void on_Warszawa_clicked();

    /*!
     * \brief on_pushButtonBia_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonBia_clicked();

    /*!
     * \brief on_pushButtonBYD_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonBYD_clicked();

    /*!
     * \brief on_pushButtonGDA_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonGDA_clicked();

    /*!
     * \brief on_pushButtonGOR_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonGOR_clicked();

    /*!
     * \brief on_pushButtonKAT_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonKAT_clicked();

    /*!
     * \brief on_pushButtonKIE_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonKIE_clicked();

    /*!
     * \brief on_pushButtonKRA_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonKRA_clicked();

    /*!
     * \brief on_pushButtonLUB_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonLUB_clicked();

    /*!
     * \brief on_pushButtonLOD_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonLOD_clicked();

    /*!
     * \brief on_pushButtonOLS_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonOLS_clicked();

    /*!
     * \brief on_pushButtonOPO_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonOPO_clicked();

    /*!
     * \brief on_pushButtoPOZ_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtoPOZ_clicked();

    /*!
     * \brief on_pushButtonRZE_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonRZE_clicked();

    /*!
     * \brief on_pushButtonsSZC_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonsSZC_clicked();

    /*!
     * \brief on_pushButtonTOR_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonTOR_clicked();

    /*!
     * \brief on_pushButtonWAR_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonWAR_clicked();

    /*!
     * \brief on_pushButtonWRO_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonWRO_clicked();

    /*!
     * \brief on_pushButtonZIE_clicked
     * Slot odpowiadający za wyświetlenie nowego okna,
     * w którym wyświetli się nam pogoda dla wybranego miasta,
     * gdy klikniemy na jeden z osiemnastu przycisków
     *
     */
    void on_pushButtonZIE_clicked();





private:
    Ui::MainWindow *ui;
    drugieOkno *drugieokno;
    Scena * scena;
    QTimer *zegar;

};
#endif // MAINWINDOW_H
