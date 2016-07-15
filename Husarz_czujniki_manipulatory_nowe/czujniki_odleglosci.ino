int wykryto_przeszkode_przod_winda  = 0 ;
int wykryto_przeszkode_przod_lewy   = 0 ;
int wykryto_przeszkode_przod_prawy  = 0 ;
int wykryto_przeszkode_przod_srodek = 0 ;
int wykryto_przeszkode_tyl_lewy     = 0 ;
int wykryto_przeszkode_tyl_prawy    = 0 ;
int wykryto_przeszkode_tyl_srodek   = 0 ;
int czujnik_przod_lewy;
int czujnik_przod_prawy;
int czujnik_przod_srodek;
int czujnik_tyl_lewy;
int czujnik_tyl_prawy;
int czujnik_tyl_srodek;
int odleglosc_tabela_1[4], odleglosc_tabela_2[4],odleglosc_tabela_3[4],odleglosc_tabela_4[4],odleglosc_tabela_5[4],odleglosc_tabela_6[4];




void czujniki_odleglosci () {
  
  
  if ( kierunek == 1){
    czujnik_przod_lewy   =  ultrasonic_przod_lewy.Ranging(CM);
    czujnik_przod_prawy  =  ultrasonic_przod_prawy.Ranging(CM);
    //czujnik_przod_srodek =  ultrasonic_przpd_srodek.Ranging(CM);
    czujnik_przod_srodek =  50;
    if ( czujnik_przod_lewy   > 200 ) czujnik_przod_lewy   = 200;
    if ( czujnik_przod_prawy  > 200 ) czujnik_przod_prawy  = 200;
    if ( czujnik_przod_srodek > 200 ) czujnik_przod_srodek = 200;

    odleglosc_tabela_1[0] = odleglosc_tabela_1[1];
    odleglosc_tabela_1[1] = odleglosc_tabela_1[2];
    odleglosc_tabela_1[2] = czujnik_przod_lewy;

    odleglosc_tabela_2[0] = odleglosc_tabela_2[1];
    odleglosc_tabela_2[1] = odleglosc_tabela_2[2];
    odleglosc_tabela_2[2] = czujnik_przod_prawy;

    odleglosc_tabela_3[0] = odleglosc_tabela_3[1];
    odleglosc_tabela_3[1] = odleglosc_tabela_3[2];
    odleglosc_tabela_3[2] = czujnik_przod_srodek;

    if (( odleglosc_tabela_1[0]< odleglosc_minimalna_przod_lewy) && ( odleglosc_tabela_1[1]< odleglosc_minimalna_przod_lewy) && ( odleglosc_tabela_1[2]< odleglosc_minimalna_przod_lewy))
      wykryto_przeszkode_przod_lewy = 1;
    else if (( odleglosc_tabela_1[0]> odleglosc_minimalna_przod_lewy) && ( odleglosc_tabela_1[1]> odleglosc_minimalna_przod_lewy) && ( odleglosc_tabela_1[2]> odleglosc_minimalna_przod_lewy))
      wykryto_przeszkode_przod_lewy = 0;
    if (( odleglosc_tabela_2[0]< odleglosc_minimalna_przod_prawy) && ( odleglosc_tabela_2[1] < odleglosc_minimalna_przod_prawy) && ( odleglosc_tabela_2[2] < odleglosc_minimalna_przod_prawy))
      wykryto_przeszkode_przod_prawy  = 1 ;
    else if (( odleglosc_tabela_2[0]> odleglosc_minimalna_przod_prawy) && ( odleglosc_tabela_2[1] > odleglosc_minimalna_przod_prawy) && ( odleglosc_tabela_2[2] > odleglosc_minimalna_przod_prawy))
      wykryto_przeszkode_przod_prawy  = 0 ;

    if (( odleglosc_tabela_3[0]< odleglosc_minimalna_przod_srodek) && ( odleglosc_tabela_3[1]< odleglosc_minimalna_przod_srodek) && ( odleglosc_tabela_3[2]< odleglosc_minimalna_przod_srodek))
      wykryto_przeszkode_przod_srodek = 1;
    else if (( odleglosc_tabela_3[0]> odleglosc_minimalna_przod_srodek) && ( odleglosc_tabela_3[1]> odleglosc_minimalna_przod_srodek) && ( odleglosc_tabela_3[2]> odleglosc_minimalna_przod_srodek))
      wykryto_przeszkode_przod_srodek = 0;

    if (( wykryto_przeszkode_przod_lewy  == 1 ) || (wykryto_przeszkode_przod_prawy  == 1 ) || (wykryto_przeszkode_przod_srodek  == 1 ))
      digitalWrite(zatrzymanie_robota, HIGH); 
    else
      digitalWrite(zatrzymanie_robota, LOW); 
      
      
         if (( odleglosc_tabela_1[0]< odleglosc_zwolnienia_przod_lewy) && ( odleglosc_tabela_1[1]< odleglosc_zwolnienia_przod_lewy) && ( odleglosc_tabela_1[2]< odleglosc_zwolnienia_przod_lewy))
      wykryto_przeszkode_przod_lewy = 1;
    else if (( odleglosc_tabela_1[0]> odleglosc_zwolnienia_przod_lewy) && ( odleglosc_tabela_1[1]> odleglosc_zwolnienia_przod_lewy) && ( odleglosc_tabela_1[2]> odleglosc_zwolnienia_przod_lewy))
      wykryto_przeszkode_przod_lewy = 0;
    if (( odleglosc_tabela_2[0]< odleglosc_zwolnienia_przod_prawy) && ( odleglosc_tabela_2[1] < odleglosc_zwolnienia_przod_prawy) && ( odleglosc_tabela_2[2] < odleglosc_zwolnienia_przod_prawy))
      wykryto_przeszkode_przod_prawy  = 1 ;
    else if (( odleglosc_tabela_2[0]> odleglosc_zwolnienia_przod_prawy) && ( odleglosc_tabela_2[1] > odleglosc_zwolnienia_przod_prawy) && ( odleglosc_tabela_2[2] > odleglosc_zwolnienia_przod_prawy))
      wykryto_przeszkode_przod_prawy  = 0 ;

    if (( odleglosc_tabela_3[0]< odleglosc_zwolnienia_przod_srodek) && ( odleglosc_tabela_3[1]< odleglosc_zwolnienia_przod_srodek) && ( odleglosc_tabela_3[2]< odleglosc_zwolnienia_przod_srodek))
      wykryto_przeszkode_przod_srodek = 1;
    else if (( odleglosc_tabela_3[0]> odleglosc_zwolnienia_przod_srodek) && ( odleglosc_tabela_3[1]> odleglosc_zwolnienia_przod_srodek) && ( odleglosc_tabela_3[2]> odleglosc_zwolnienia_przod_srodek))
      wykryto_przeszkode_przod_srodek = 0;

    if (( wykryto_przeszkode_przod_lewy  == 1 ) || (wykryto_przeszkode_przod_prawy  == 1 ) || (wykryto_przeszkode_przod_srodek  == 1 ))
      digitalWrite(zwolnienie_predkosci_robota, HIGH); 
    else
      digitalWrite(zwolnienie_predkosci_robota, LOW);
      
  }
  if ( kierunek == 2){
    czujnik_tyl_lewy  =  ultrasonic_tyl_lewy.Ranging(CM);
    czujnik_tyl_prawy =  ultrasonic_tyl_prawy.Ranging(CM);
    //czujnik_tyl_srodek =  ultrasonic_tyl_srodek.Ranging(CM);
    czujnik_tyl_srodek =  50;
    if ( czujnik_tyl_lewy   > 200 ) czujnik_tyl_lewy   = 200;
    if ( czujnik_tyl_prawy  > 200 ) czujnik_tyl_prawy  = 200;
    if ( czujnik_tyl_srodek > 200 ) czujnik_tyl_srodek = 200;

    odleglosc_tabela_4[0] = odleglosc_tabela_4[1];
    odleglosc_tabela_4[1] = odleglosc_tabela_4[2];
    odleglosc_tabela_4[2] = czujnik_tyl_lewy;

    odleglosc_tabela_5[0] = odleglosc_tabela_5[1];
    odleglosc_tabela_5[1] = odleglosc_tabela_5[2];
    odleglosc_tabela_5[2] = czujnik_tyl_prawy;

    odleglosc_tabela_6[0] = odleglosc_tabela_6[1];
    odleglosc_tabela_6[1] = odleglosc_tabela_6[2];
    odleglosc_tabela_6[2] = czujnik_tyl_srodek;

    if (( odleglosc_tabela_4[0]< odleglosc_minimalna_tyl_lewy) && ( odleglosc_tabela_4[1]< odleglosc_minimalna_tyl_lewy) && ( odleglosc_tabela_4[2]< odleglosc_minimalna_tyl_lewy))
      wykryto_przeszkode_tyl_lewy = 1;
    else if (( odleglosc_tabela_4[0]> odleglosc_minimalna_tyl_lewy) && ( odleglosc_tabela_4[1]> odleglosc_minimalna_tyl_lewy) && ( odleglosc_tabela_4[2]> odleglosc_minimalna_tyl_lewy))
      wykryto_przeszkode_tyl_lewy = 0;
    if (( odleglosc_tabela_5[0]< odleglosc_minimalna_tyl_prawy) && ( odleglosc_tabela_5[1] < odleglosc_minimalna_tyl_prawy) && ( odleglosc_tabela_5[2] < odleglosc_minimalna_tyl_prawy))
      wykryto_przeszkode_tyl_prawy  = 1 ;
    else  if (( odleglosc_tabela_5[0]> odleglosc_minimalna_tyl_prawy) && ( odleglosc_tabela_5[1] > odleglosc_minimalna_tyl_prawy) && ( odleglosc_tabela_5[2] > odleglosc_minimalna_tyl_prawy))
      wykryto_przeszkode_tyl_prawy  = 0 ;  
    if (( odleglosc_tabela_6[0]< odleglosc_minimalna_tyl_srodek) && ( odleglosc_tabela_6[1] < odleglosc_minimalna_tyl_srodek) && ( odleglosc_tabela_6[2] < odleglosc_minimalna_tyl_srodek))
      wykryto_przeszkode_tyl_srodek  = 1 ;
    else  if (( odleglosc_tabela_6[0]> odleglosc_minimalna_tyl_srodek) && ( odleglosc_tabela_6[1] > odleglosc_minimalna_tyl_srodek) && ( odleglosc_tabela_6[2] > odleglosc_minimalna_tyl_srodek))
      wykryto_przeszkode_tyl_srodek  = 0 ;

    if (( wykryto_przeszkode_tyl_lewy  == 1 ) || (wykryto_przeszkode_tyl_prawy  == 1 ) || (wykryto_przeszkode_tyl_srodek  == 1 ))
      digitalWrite(zatrzymanie_robota, HIGH); 
    else
      digitalWrite(zatrzymanie_robota, LOW); 
      
      
        if (( odleglosc_tabela_4[0]< odleglosc_zwolnienia_tyl_lewy) && ( odleglosc_tabela_4[1]< odleglosc_zwolnienia_tyl_lewy) && ( odleglosc_tabela_4[2]< odleglosc_zwolnienia_tyl_lewy))
      wykryto_przeszkode_tyl_lewy = 1;
    else if (( odleglosc_tabela_4[0]> odleglosc_zwolnienia_tyl_lewy) && ( odleglosc_tabela_4[1]> odleglosc_zwolnienia_tyl_lewy) && ( odleglosc_tabela_4[2]> odleglosc_zwolnienia_tyl_lewy))
      wykryto_przeszkode_tyl_lewy = 0;
    if (( odleglosc_tabela_5[0]< odleglosc_zwolnienia_tyl_prawy) && ( odleglosc_tabela_5[1] < odleglosc_zwolnienia_tyl_prawy) && ( odleglosc_tabela_5[2] < odleglosc_zwolnienia_tyl_prawy))
      wykryto_przeszkode_tyl_prawy  = 1 ;
    else  if (( odleglosc_tabela_5[0]> odleglosc_zwolnienia_tyl_prawy) && ( odleglosc_tabela_5[1] > odleglosc_zwolnienia_tyl_prawy) && ( odleglosc_tabela_5[2] > odleglosc_zwolnienia_tyl_prawy))
      wykryto_przeszkode_tyl_prawy  = 0 ;  
    if (( odleglosc_tabela_6[0]< odleglosc_zwolnienia_tyl_srodek) && ( odleglosc_tabela_6[1] < odleglosc_zwolnienia_tyl_srodek) && ( odleglosc_tabela_6[2] < odleglosc_zwolnienia_tyl_srodek))
      wykryto_przeszkode_tyl_srodek  = 1 ;
    else  if (( odleglosc_tabela_6[0]> odleglosc_zwolnienia_tyl_srodek) && ( odleglosc_tabela_6[1] > odleglosc_zwolnienia_tyl_srodek) && ( odleglosc_tabela_6[2] > odleglosc_zwolnienia_tyl_srodek))
      wykryto_przeszkode_tyl_srodek  = 0 ;

    if (( wykryto_przeszkode_tyl_lewy  == 1 ) || (wykryto_przeszkode_tyl_prawy  == 1 ) || (wykryto_przeszkode_tyl_srodek  == 1 ))
      digitalWrite(zwolnienie_predkosci_robota, HIGH); 
    else
      digitalWrite(zwolnienie_predkosci_robota, LOW); 
  } 
}
