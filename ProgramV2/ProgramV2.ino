
// odpalenie komunikacji rosrun rosserial_python serial_node.py /dev/ttyACM0 _baud:=115200 __name:=node_1
// nasłuch ---rostopic echo <zmienna>
// nadawanie --rostopic pub servo std_msgs/UInt16  <angle>

//  rostopic echo kierunek_zadany_D
//  rostopic echo odometria_X_D
//  rostopic echo odometria_Y_D
//  rostopic echo odometria_T_D
//  rostopic echo stan_robota_D
//  rostopic echo potwierdzenie_odbioru_D


//  rostopic pub -1 kierunek_zadany_D std_msgs/Int16  1
//  rostopic pub -1 odleglosc_zadana_D std_msgs/Int16  100

//  rostopic pub -1 odbior_stan_D std_msgs/Int16  100
//  rostopic pub -1 odbior_theta_D std_msgs/Int16  100

/*
  kierunek:     1 - przód
  2 - tył
  3 - lewo
  4 - prawo
*/

#include <SPI.h>
#include <Tone.h>
#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD


#define przelacznik_koloru             22
#define przelacznik_off_wyswietlacz    23
#define zworka_start_robata            26
#define zatrzymanie_robota             14
#define kierunek_robota_2              15
#define kierunek_robota_1              16
#define zwolnienie_predkosci_robota    17

#define przelacznik_taktyka_5          A0
#define przelacznik_taktyka_4          A1
#define przelacznik_taktyka_3          A2
#define przelacznik_taktyka_2          A3
#define przelacznik_taktyka_1          A4

#define rozkaz_serwo_platforma         A8
#define rozkaz_serwo_spych             A9
#define rozkaz_serwo_wedka             A10
#define rozkaz_serwo_wedka_zwolnienie  A11
#define rozkaz_serwo_wedka_polowa      A12


#define  sleep_silnik_pin_2          5          // sterowanie silnikami - uspienie ( HIGH - jazda lub uspienie, LOW - silniki wylaczone)
#define  step_silnik_pin_2           10          // kroki podawane do sterownika
#define  dir_silnik_pin_2            4          // kierunek obrotu silnika

#define  sleep_silnik_pin_1          7         // sterowanie silnikami - uspienie ( HIGH - jazda lub uspienie, LOW - silniki wylaczone)
#define  step_silnik_pin_1           8        // kroki podawane do sterownika
#define   dir_silnik_pin_1           6         // kierunek obrotu silnika

#define slaveSelectEnc1              49     //enkoder
#define slaveSelectEnc2              53      //enkoder

double X_o                           = 1200;
double Y_o                           = 110;
double Theta_o                       = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Ustawienie adresu ukladu na 0x27
Tone silnik_prawy;
Tone silnik_lewy;
double profil_rotacji             = 0;
//unsigned int czas_trwania_meczu = 90 ;
unsigned int czas_trwania_meczu      = 85 ;
// PARAMETRY ROBOTA !!
double   rozstaw_kol_pomiarowych     = 101.8;               // obwód kol pomiarowych [było 101.5]
double   obwod_kol_pomiarowych_prawy = 232;        // rozstaw kol pomiarowych podany w mm (222)   srednica 74 mm
double   obwod_kol_pomiarowych_lewy  = 232.5;        // rozstaw kol pomiarowych podany w mm

double   rozstaw_kol_napedowych      = 260;               // odległość pomiędzy środkami kol  napędowych
double   obwod_kol_napedowych        = 276;               // obwód kol napędowych
double   liczba_impulsow_obrot       = 10000;          // liczba impulsów odpowiadających jednemu obrotowi enkodera (360 stopni)

double Kp                               = 3000;   //wzmocnienie
double Kd                               = 150;
double przyspieszenie_zadane_translacji = 0.01;
double przyspieszenie_zadane_rotacji    = 0.025;
double R_hamoania                       = 0.2;
double V_hamoania                       = 0.4;
int    tolerancja_translacji            = 4;
double tolerancja_rotacji               = 0.005;
int   predkosc_lewy          = 0;
int   predkosc_prawy         = 0;

//Odomeria
double pi                            = 3.14159265359;
double dSm_calkowite;
// Regulator
int prdekosc_maksymalna              = 15000;

double r_zadane;    // droga potrzebna na wychamowanie jazdy wprost
double s_zadane;
double V_ustalona;
double V_bierzaca;
double s_hamowania;   // droga potrzebna na wychamowanie skretu
double R_ustalona;
double R_bierzaca;

unsigned int stan_potwierdzenie          = 1;
//////////////////////////////////////////////////////////////////////////////////////////////////
int   stan        = 5;
int   kierunek    = 0;
double DT;
int   rotacja;
double uchyb_poprzedni_translacji_prawy;
double uchyb_poprzedni_translacji_lewy;
double potwierdzenie_odbioru_D         = 0;
int    stop_licznik                    = 0;
double stan_robota_D                   = 0;
//byte   zatrzymanie_robota_czujniki   = 0;
double s_stop;
//byte  potwierdzenie_wyslania_koloru    = 0;
unsigned long odliczanie_czasu_meczu   = 0;   // odliczanie czasu od rozpoczecia meczu ( wyciagniecia zworki)
unsigned long moment_rozpoczecia_meczu = 0;
byte start_meczu                       = 0;
double Theta_startu;
//int katowa_przelacznik_taktyka = 0;
double lewy_predkosc_m_s,  prawy_predkosc_m_s;
int nr_zadania = 1;
int v ;
/////////////////////////////////////////////////////////////////////////////////////////////////


//.............................................................................................................
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
void setup() {
Serial.begin(9600);
  stan_robota_D = 0;
  pinMode(sleep_silnik_pin_1,             OUTPUT);
  pinMode(sleep_silnik_pin_2,             OUTPUT);
  pinMode(step_silnik_pin_1,              OUTPUT);
  pinMode(step_silnik_pin_2,              OUTPUT);
  pinMode(dir_silnik_pin_1,               OUTPUT);
  pinMode(dir_silnik_pin_2,               OUTPUT);
  pinMode(kierunek_robota_1,              OUTPUT);
  pinMode(kierunek_robota_2,              OUTPUT);
  pinMode(rozkaz_serwo_platforma,         OUTPUT);
  pinMode(rozkaz_serwo_spych,             OUTPUT);
  pinMode(rozkaz_serwo_wedka,             OUTPUT);
  pinMode(rozkaz_serwo_wedka_zwolnienie,  OUTPUT);
  pinMode(rozkaz_serwo_wedka_polowa,      OUTPUT);

  pinMode(przelacznik_koloru,            INPUT);
  pinMode(przelacznik_off_wyswietlacz,   INPUT);
  pinMode(zworka_start_robata,           INPUT);
  pinMode(zatrzymanie_robota,            INPUT);
  pinMode(przelacznik_taktyka_1,         INPUT);
  pinMode(przelacznik_taktyka_2,         INPUT);
  pinMode(przelacznik_taktyka_3,         INPUT);
  pinMode(przelacznik_taktyka_4,         INPUT);
  pinMode(przelacznik_taktyka_5,         INPUT);
  pinMode(zwolnienie_predkosci_robota,   INPUT);

  initEncoders();                                       //enkoder
  clearEncoderCount();                                  //enkoder
  silnik_prawy.begin(step_silnik_pin_1);
  silnik_lewy.begin(step_silnik_pin_2);

  wyswietlaczLCD_inicjalizacja ();

 // funkcja_manipulatory(2);
 //  funkcja_manipulatory(4);
  // initialize timer1
  noInterrupts();           // disable all interrupts
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5  = 0;
  OCR5A = 310;            // compare match register 16MHz/256/2Hz   400 okolo 6.4ms  380-6.1ms 300-4.9ms
  TCCR5B |= (1 << WGM12);   // CTC mode
  TCCR5B |= (1 << CS12);    // 256 prescaler
  TIMSK5 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts
}




void loop() {
  if (( stan == 8 ||  stan == 5) &&  start_meczu == 1 ) {
    program_jazda_sztywno();
  }
  wyswietlaczLCD_nadawanie ();
   delay(15);
}


































































