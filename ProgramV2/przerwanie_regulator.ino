
double Sl, Sr;
double dSr , dSl, dSd, dSm, OldSr , OldSl;
byte   zatrzymanie_robota_czujniki;
int V_poprzednia;
byte zwolnienie_predkosci_robota_znacznik;
int licznik_error;
double  uchyb_poprzedni_prawy , uchyb_poprzedni_lewy , uchyb_prawy, uchyb_lewy;
ISR(TIMER5_COMPA_vect)       // timer compare interrupt service routine
{
  funkcja_zworki_start ();
  funkcja_kierunek_sleep ();

  Sl =  readEncoder(2);        //enkoder
  Sr = -readEncoder(1);        //enkoder
  dSl = Sl - OldSl;
  dSl = ((dSl * obwod_kol_pomiarowych_lewy) / liczba_impulsow_obrot);
  dSr = Sr - OldSr;
  dSr = (( dSr * obwod_kol_pomiarowych_prawy) / liczba_impulsow_obrot);
  dSm = 0.5 * (dSl + dSr);
  translacja_enkoder = dSl + dSr;
  rotacja_enkoder    = dSl - dSr;
  dSd = (dSr - dSl) / rozstaw_kol_pomiarowych;
  X_o = X_o + dSm * sin(Theta_o);
  Y_o = Y_o - dSm * cos(Theta_o);
  Theta_o = Theta_o + dSd;
  Theta_o = ustawienie_kata (Theta_o);
  OldSl = Sl;
  OldSr = Sr;
  dSm_calkowite = dSm_calkowite + abs(dSm);

  prawy_predkosc_m_s = (dSr * 1000 / 5000 );
  lewy_predkosc_m_s  = (dSl * 1000 / 5000 );

  if ( kierunek == 1)    digitalWrite(kierunek_robota_1, HIGH);
  else                   digitalWrite(kierunek_robota_1, LOW);
  if ( kierunek == 2)    digitalWrite(kierunek_robota_2, HIGH);
  else                   digitalWrite(kierunek_robota_2, LOW);


  if ( start_meczu == 1 ) {
    odliczanie_czasu_meczu = millis();
    odliczanie_czasu_meczu = odliczanie_czasu_meczu - moment_rozpoczecia_meczu;
  }

  if ( odliczanie_czasu_meczu / 1000 <= czas_trwania_meczu) {
    if ( stan == 1 || stan == 3) {


      if (kierunek == 1 || kierunek == 2 ) {
        if (digitalRead(zatrzymanie_robota) == 0) {
          if (zatrzymanie_robota_czujniki == 1) {
            s_zadane   = s_stop;
            R_ustalona = 0;
            r_zadane   = 0;
            V_ustalona = V_poprzednia;
            stan       = 1;
            zatrzymanie_robota_czujniki = 0;
            stop_licznik                = 0;
          }
          if (digitalRead(zwolnienie_predkosci_robota) == 1 && zwolnienie_predkosci_robota_znacznik == 0 ) {
            V_poprzednia = V_ustalona;
            V_ustalona = 1;
            zwolnienie_predkosci_robota_znacznik = 1;
          }
          else if (digitalRead(zwolnienie_predkosci_robota) == 0 && zwolnienie_predkosci_robota_znacznik == 1 )
          {
            V_ustalona =  V_poprzednia ;
            zwolnienie_predkosci_robota_znacznik = 0;
          }

          if (( abs(dSr) < 0.2 &&  predkosc_prawy > 300 ) || (abs(dSl) < 0.2 && predkosc_lewy > 300 )) {    // ERROR      brak ruchu a predkosc wieksza niz wartosc minimalna          stan_potwierdzenie = stan_potwierdzenie | ( 1 << 2);
            licznik_error ++;
          }
          else {
            licznik_error = 0;
          }
          if (licznik_error > 300 ) {
            stan = 0 ;
            licznik_error = 0;
          }

          profiler();

          uchyb_prawy = (profil_translacji) - prawy_predkosc_m_s;
          uchyb_lewy  = (profil_translacji) - lewy_predkosc_m_s;
          predkosc_prawy = Kp * uchyb_prawy        +  Kd * ( uchyb_prawy -  uchyb_poprzedni_prawy);
          predkosc_lewy  = (Kp + 40) * uchyb_lewy  +  Kd * ( uchyb_lewy  -  uchyb_poprzedni_lewy );
          uchyb_poprzedni_prawy = uchyb_prawy;
          uchyb_poprzedni_lewy  = uchyb_lewy;


          if (predkosc_prawy > prdekosc_maksymalna)
            predkosc_prawy   = prdekosc_maksymalna;
          if (predkosc_lewy  > prdekosc_maksymalna)
            predkosc_lewy    = prdekosc_maksymalna;
          predkosc_prawy = abs(predkosc_prawy);
          predkosc_lewy  = abs(predkosc_lewy);
          silnik_prawy.play(predkosc_prawy);
          silnik_lewy.play(predkosc_lewy);
          /*
                predkosc_prawy = Kp * profil_translacji ;
            predkosc_lewy  = Kp * profil_translacji ;
                    if ((abs(prawy_predkosc_m_s) - abs(lewy_predkosc_m_s)) > 0.005) {
            predkosc_prawy = predkosc_prawy + (lewy_predkosc_m_s- prawy_predkosc_m_s)*Kp;
            }
            if ((abs(lewy_predkosc_m_s)- abs(prawy_predkosc_m_s)) > 0.005) {
            predkosc_lewy = predkosc_lewy + ( prawy_predkosc_m_s - lewy_predkosc_m_s)*Kp;
            }

            predkosc_prawy = Kp * profil_translacji ;
            predkosc_lewy  = Kp * profil_translacji ;

            if ((dSr - dSl) < 0.08) {
            predkosc_prawy = predkosc_prawy + (abs(dSl) - abs(dSr)) * Kp;
            }
            if ((dSr - dSl) > 0.08) {
            predkosc_lewy = predkosc_lewy + (abs(dSr) - abs(dSl)) * Kp ;
            }
            if (predkosc_prawy > prdekosc_maksymalna)
            predkosc_prawy   = prdekosc_maksymalna;
            if (predkosc_lewy  > prdekosc_maksymalna)
            predkosc_lewy    = prdekosc_maksymalna;
            predkosc_prawy = abs(predkosc_prawy);
            predkosc_lewy  = abs(predkosc_lewy);
            silnik_prawy.play(predkosc_prawy);
            silnik_lewy.play(predkosc_lewy);
          */
        }
        else if (digitalRead(zatrzymanie_robota) == 1) {
          if ( zatrzymanie_robota_czujniki == 0) {
            s_stop = s_zadane;
            V_bierzaca = 0;
            V_ustalona = 0;
            zatrzymanie_robota_czujniki = 1;
            s_zadane = 0;
          }
          if ( stop_licznik <= 40 ) {
            digitalWrite(sleep_silnik_pin_1, HIGH);
            digitalWrite(sleep_silnik_pin_2, HIGH);
            silnik_prawy.play(0);
            silnik_lewy.play(0);
            stop_licznik ++;
            predkosc_lewy  = 0;
            predkosc_prawy = 0;
          }
        }
      }

      else if ( kierunek == 11 || kierunek == 22) {
        if (( abs(dSr) < 0.2 &&  predkosc_prawy > 300 ) || (abs(dSl) < 0.2 && predkosc_lewy > 300 )) {    // ERROR      brak ruchu a predkosc wieksza niz wartosc minimalna          stan_potwierdzenie = stan_potwierdzenie | ( 1 << 2);
          licznik_error ++;
        }
        else {
          licznik_error = 0;
        }
        if (licznik_error > 300 ) {
          stan = 0 ;
          licznik_error = 0;
        }

        profiler();

       
          profiler();

          uchyb_prawy = (profil_translacji) - prawy_predkosc_m_s;
          uchyb_lewy  = (profil_translacji) - lewy_predkosc_m_s;
          predkosc_prawy = Kp * uchyb_prawy        +  Kd * ( uchyb_prawy -  uchyb_poprzedni_prawy);
          predkosc_lewy  = (Kp + 40) * uchyb_lewy  +  Kd * ( uchyb_lewy  -  uchyb_poprzedni_lewy );
          uchyb_poprzedni_prawy = uchyb_prawy;
          uchyb_poprzedni_lewy  = uchyb_lewy;


          if (predkosc_prawy > prdekosc_maksymalna)
            predkosc_prawy   = prdekosc_maksymalna;
          if (predkosc_lewy  > prdekosc_maksymalna)
            predkosc_lewy    = prdekosc_maksymalna;
          predkosc_prawy = abs(predkosc_prawy);
          predkosc_lewy  = abs(predkosc_lewy);
          silnik_prawy.play(predkosc_prawy);
          silnik_lewy.play(predkosc_lewy);
      }
      else if (kierunek == 3 || kierunek == 4) {
        profiler();


        predkosc_prawy =   Kp * profil_rotacji;
        predkosc_lewy  =   Kp * profil_rotacji;
        if (predkosc_prawy > prdekosc_maksymalna)
          predkosc_prawy = prdekosc_maksymalna;
        if (predkosc_lewy > prdekosc_maksymalna)
          predkosc_lewy = prdekosc_maksymalna;
        predkosc_prawy = abs(predkosc_prawy);
        predkosc_lewy  = abs(predkosc_lewy);
        silnik_prawy.play(predkosc_prawy);
        silnik_lewy.play(predkosc_lewy);
      }
    }
    else if ( stan == 0) {
      if ( stop_licznik <= 80 ) {
        s_zadane = 0;
        r_zadane = 0;
        digitalWrite(sleep_silnik_pin_1, HIGH);
        digitalWrite(sleep_silnik_pin_2, HIGH);
        silnik_prawy.play(0);
        silnik_lewy.play(0);
        stop_licznik ++;
        predkosc_lewy  = 0;
        predkosc_prawy = 0;

      }
      else {
        stan = 8;
        stop_licznik             = 0;
        nr_zadania ++;
        }
    }
  }
  else {
    
    
    funkcja_manipulatory(5);
    
    
    if ( stop_licznik <= 80 ) {
      s_zadane = 0;
      r_zadane = 0;
      digitalWrite(sleep_silnik_pin_1, HIGH);
      digitalWrite(sleep_silnik_pin_2, HIGH);
      silnik_prawy.play(0);
      silnik_lewy.play(0);
      stop_licznik ++;
      predkosc_lewy  = 0;
      predkosc_prawy = 0;
    }
    else {
      stan                 = 9;
      stop_licznik         = 0;
      if (start_meczu == 1)
        stan_robota_D      = 22;
    }
  }
}














