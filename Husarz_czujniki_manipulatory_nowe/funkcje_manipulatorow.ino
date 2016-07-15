boolean znacznik_serwo_platforma, znacznik_serwo_spych , znacznik_serwo_wedka, znacznik_serwo_wedka_zwolnienie, znacznik_serwo_wedka_polowa ;

void podstawa_gora_f() {
 serwo_podstawa_klocki_1.write(100);
  serwo_podstawa_klocki_2.write(87);
  delay(500);
}
void podstawa_dol_f() {
  serwo_podstawa_klocki_1.write(19);
  serwo_podstawa_klocki_2.write(165);
  delay(500);
}

void serwo_spych_wysun_f() {
  //serwo_spych.attach(2);
  serwo_spych.write(71); //26
  delay(3000);
  serwo_spych.write(50);  //4
  delay(3000);
  //serwo_spych.detach();
  serwo_spych.attach(3);
      digitalWrite(2, LOW);
}

void rozkaz_serwo_wedka_opusc_f() {
  serwo_wedka.write(155);
  delay(500);
}
void rozkaz_serwo_wedka_schowaj_f() {
  serwo_wedka.write(56);
  delay(500);
}
void rozkaz_serwo_wedka_zwolnienie_otworz_f() {
  serwo_wedka_otwarcie.write(70);
  delay(500);
  serwo_wedka_otwarcie.write(108);
   delay(500);
}
void rozkaz_serwo_wedka_zwolnienie_zamknij_f() {
  serwo_wedka_otwarcie.write(104);
  delay(500);
}

void rozkaz_serwo_wedka_polowa_otworz_f() {
  serwo_wedka.write(100);
  delay(500);
}




void funkcja_komunikacja () {
  if (digitalRead(kierunek_robota_1) == 1)                                                 kierunek = 1;
  else if (digitalRead(kierunek_robota_2) == 1)                                            kierunek = 2;
  else if ((digitalRead(kierunek_robota_1) == 0) && (digitalRead(kierunek_robota_2) == 0)) kierunek = 0;


  if (digitalRead(rozkaz_serwo_platforma) == 1  && znacznik_serwo_platforma == 0) {
    znacznik_serwo_platforma = 1;
    podstawa_dol_f();
  }
  else if (digitalRead(rozkaz_serwo_platforma) == 0 && znacznik_serwo_platforma == 1) {
    znacznik_serwo_platforma = 0;
    podstawa_gora_f();
  }

  if (digitalRead(rozkaz_serwo_spych) == 1 && znacznik_serwo_platforma == 1 && znacznik_serwo_spych == 0) {
    znacznik_serwo_spych = 1;
    serwo_spych_wysun_f();
  }
  else if (digitalRead(rozkaz_serwo_spych) == 0 && znacznik_serwo_spych == 1) {
    znacznik_serwo_spych = 0;
  }

  if (digitalRead(rozkaz_serwo_wedka) == 1 && znacznik_serwo_wedka == 0 ) {
    znacznik_serwo_wedka = 1;
    if (digitalRead(rozkaz_serwo_wedka_polowa) == 0)  rozkaz_serwo_wedka_opusc_f();
  }
  else if (digitalRead(rozkaz_serwo_wedka) == 0 && znacznik_serwo_wedka == 1) {
    znacznik_serwo_wedka = 0;
    rozkaz_serwo_wedka_schowaj_f();
  }

  if (digitalRead(rozkaz_serwo_wedka_zwolnienie) == 1 && znacznik_serwo_wedka_zwolnienie == 0) {
    znacznik_serwo_wedka_zwolnienie = 1;
    rozkaz_serwo_wedka_zwolnienie_otworz_f();
  }
  else if (digitalRead(rozkaz_serwo_wedka_zwolnienie) == 0 && znacznik_serwo_wedka_zwolnienie == 1) {
    znacznik_serwo_wedka_zwolnienie = 0;
    rozkaz_serwo_wedka_zwolnienie_zamknij_f();
  }

  if (digitalRead(rozkaz_serwo_wedka_polowa) == 1 && znacznik_serwo_wedka_polowa == 0) {
    znacznik_serwo_wedka_polowa = 1;
    rozkaz_serwo_wedka_polowa_otworz_f();
  }
  else if (digitalRead(rozkaz_serwo_wedka_polowa) == 0 && znacznik_serwo_wedka_polowa == 1) {
    znacznik_serwo_wedka_polowa = 0;
    rozkaz_serwo_wedka_schowaj_f() ;
  }
}



