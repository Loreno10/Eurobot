// odpalenie komunikacji
//                rosrun rosserial_python serial_node.py /dev/ttyACM1 _baud:=115200 __name:=node_2
// nasłuch ---    rostopic echo czujnik_odleglosci_przod_lewy
// nasłuch ---    rostopic echo czujnik_odleglosci_przod_lewy
// nasłuch ---    rostopic echo czujnik_odleglosci_przod_prawy
// nasłuch ---    rostopic echo czujnik_odleglosci_tyl_lewy
// nasłuch ---    rostopic echo czujnik_odleglosci_tyl_prawy
// nasłuch ---    rostopic echo potwierdzenie_manipulatory_D
// nadawanie --   rostopic pub odbior_serwo_D std_msgs/UInt16  <angle>
//                rostopic pub -1 odbior_serwo_D std_msgs/Int16  12

#include <MegaServo.h>
#include "Ultrasonic.h"
#define zatrzymanie_robota           A0
#define kierunek_robota_1            A1
#define kierunek_robota_2            A2
#define zwolnienie_predkosci_robota  A3


#define rozkaz_serwo_platforma         A8
#define rozkaz_serwo_spych             A9
#define rozkaz_serwo_wedka             A10
#define rozkaz_serwo_wedka_zwolnienie  A11
#define rozkaz_serwo_wedka_polowa      A12



MegaServo serwo_podstawa_klocki_1;
MegaServo serwo_podstawa_klocki_2;
MegaServo serwo_spych;
MegaServo serwo_wedka;
MegaServo serwo_wedka_otwarcie;



Ultrasonic ultrasonic_przod_lewy       (22, 24);    // (echo pierwsza wartosc , triger druga)
//Ultrasonic ultrasonic_przpd_srodek   (26, 28);
Ultrasonic  ultrasonic_przod_prawy     (30, 32);
Ultrasonic ultrasonic_tyl_lewy         (23, 25);
//Ultrasonic ultrasonic_tyl_srodek     (27, 29);
Ultrasonic  ultrasonic_tyl_prawy       (31, 33);

int odleglosc_minimalna_przod_lewy   = 22;
int odleglosc_minimalna_przod_prawy  = 22;
int odleglosc_minimalna_przod_srodek = 22;
int odleglosc_minimalna_tyl_lewy     = 18;
int odleglosc_minimalna_tyl_prawy    = 18;
int odleglosc_minimalna_tyl_srodek   = 18;

int odleglosc_zwolnienia_przod_lewy   = 40;
int odleglosc_zwolnienia_przod_prawy  = 40;
int odleglosc_zwolnienia_przod_srodek = 40;
int odleglosc_zwolnienia_tyl_lewy     = 40;
int odleglosc_zwolnienia_tyl_prawy    = 40;
int odleglosc_zwolnienia_tyl_srodek   = 40;


int kierunek;




void setup() {

  pinMode(zatrzymanie_robota,           OUTPUT);
  pinMode(zwolnienie_predkosci_robota,  OUTPUT);

  pinMode(kierunek_robota_2,             INPUT);
  pinMode(kierunek_robota_2,             INPUT);
  pinMode(rozkaz_serwo_platforma,        INPUT);
  pinMode(rozkaz_serwo_spych,            INPUT);
  pinMode(rozkaz_serwo_wedka,            INPUT);
  pinMode(rozkaz_serwo_wedka_zwolnienie, INPUT);
  pinMode(rozkaz_serwo_wedka_polowa,     INPUT);


  serwo_podstawa_klocki_1.attach(11);
  serwo_podstawa_klocki_2.attach(10);
  serwo_spych.attach(3);
  serwo_wedka.attach(1);
  serwo_wedka_otwarcie.attach(2);
serwo_wedka_otwarcie.write(108);
   //serwo_podstawa_klocki_1.detach();
  //serwo_podstawa_klocki_2.detach();

  //serwo_spych.detach();

  serwo_spych.write(50);
  //delay(500);

  //serwo_wedka_otwarcie.write(104);
  // delay(500);
  serwo_wedka.write(56);
  delay(500);

}

void loop() {

  funkcja_komunikacja () ;
  czujniki_odleglosci () ;
  delay(10);
}















