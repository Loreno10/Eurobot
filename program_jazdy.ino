/*
  funkcja_manipulatory('podstawa_dol');  1
 funkcja_manipulatory('podstawa_gora');   2
 funkcja_manipulatory('spych_podnies');  3 
 funkcja_manipulatory('spych_wsun');     4
 funkcja_manipulatory('wedka_opusc');   5 
 funkcja_manipulatory('wedka_podnies');  6
 funkcja_manipulatory('wedka_otworz');  7
 funkcja_manipulatory('wedka_zamkni');  8
 
 
 funkcja_manipulatory(5);  // opuszczenie calkowite wedki
 delay(1000);
 funkcja_manipulatory(6);  // 
 funkcja_manipulatory(9);  //   podniesienie wedki od polowy
 delay(1000);
 funkcja_manipulatory(7);   // zwolnienie rybek
 delay(200);
 funkcja_manipulatory(8);   // 
 funkcja_manipulatory(6);   // podniesienie wedki 
 delay(10000);
 
 
 */
int licz_zadan = 1;
int zadanie_dalej = 1;
double tablica[3][5][3];  //wynikowa tablica ruchów  ( [numer_trajektorii][numer_ruchu][dane_ruchu] )
void droga_planer(int nr1);
void droga_do_celu(double x_robota, double y_robota, double t_robota, double x_celu, double y_celu, double t_celu);
void  program_jazda_sztywno()
{
   if (digitalRead(przelacznik_koloru)  == 0 )  //FIOLET
   {      
     switch(nr_zadania)
     {
       case 1:
      sztywno( 1 , 270  , 2);
      break;

    case 3:
      sztywno( 4 , pi*1.5  , 1.5);  //prawo
      break;
      
    case 5:
      if ( Theta_o < pi*1.5 )       sztywno( 3 , pi*1.5   , 1);
      else                          sztywno( 4 , pi*1.5   , 1);
      break;

    case 7:
      sztywno( 1 , 50   , 2);
      break;

    case 9:
      sztywno( 3 ,0  , 1.5);
      break;
      
    case 11:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
      else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3, 0  , 1);
      break;


    case 13:
      sztywno( 11 ,655   ,2.5);
      break;
      
    case 15:
      sztywno( 22 ,100   ,2.5);
      break;         
      
    case 17:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
      else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3,  0  , 1);
      break;
      
    case 19:
      nr_zadania = 21;

      break;
      ///////kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk DO RYBEK
    case 21:
      sztywno( 22 ,475   ,2.5);
      break;

    case 23:
      sztywno( 4 ,pi*1.5   ,2);    //Obrót w stronę akwarium
      break;

    case 25:
      if ( Theta_o < pi*1.5 )       sztywno( 3 , pi*1.5   , 1);
      else                          sztywno( 4 , pi*1.5   , 1);
      break;  

    case 27:
      sztywno( 1 ,765  ,2);
      break;  //dojechaliśmy do akwarium

    case 29:
      sztywno( 4 ,pi  ,2);    //ustawienie się wedką w strone rybek
      break;

    case 31:
      if      ( Theta_o > pi    && Theta_o < 2*pi)     sztywno( 4 , pi   , 1);
      else if ( Theta_o < pi && Theta_o > 0)           sztywno( 3, pi  , 1);
      break;

    
    case 33:
      sztywno( 2 ,170   ,1);
      break; 





//ROBOT MUSI TERAZ JEŹDZIĆ TYŁEM PO RYBKI
    case 35:
      funkcja_manipulatory(5);  // opuszczenie calkowite wedki
      delay(1000);
      nr_zadania = 37;
      break;

    case 37:
      sztywno( 2 ,340   ,1);
      break;

    case 39:
      funkcja_manipulatory(9);  //   podniesienie wedki od polowy
      delay(1000);
      nr_zadania = 41;
      break;

    case 41:
      sztywno( 2 , 350  ,2);
      break;

    case 43:
      funkcja_manipulatory(7);   // zwolnienie rybek
      delay(200);        
      funkcja_manipulatory(10);  
      delay(10);
      funkcja_manipulatory(6);   
      delay(10);
      funkcja_manipulatory(11);   
      delay(500);
      funkcja_manipulatory(6);   
      delay(10);
      nr_zadania = 45;
      break;

    case 45:
      sztywno( 1 ,690   ,2);   //cofamy się, aby jeszcze raz podjechać po rybki
      break;    

    case 47:
      funkcja_manipulatory(5);  // opuszczenie calkowite wedki
      delay(1000);
      nr_zadania = 49;
      break;

    case 49:
      sztywno( 2 ,340   ,1);
      break;

    case 51:
      funkcja_manipulatory(9);  //   podniesienie wedki do polowy
      delay(1000);
      nr_zadania = 53;
      break;

    case 53:
      sztywno( 2 , 350   ,2);
      break;

    case 55:
      funkcja_manipulatory(7);   // zwolnienie rybek
      delay(200);
      nr_zadania = 57;
      break;
      
     case 57:
       funkcja_manipulatory(8);   // 
       funkcja_manipulatory(6);   // podniesienie wedki 
       delay(400);
       nr_zadania = 59;
        break;



     //ZAMYKANIE DRZWICZEK
     
     case 59:
      sztywno( 1 ,685  ,2);
      break;
      
     case 61:
       sztywno( 4 , pi*0.5  , 1.5);  //prawo
       break;
      
     case 63:
       if ( Theta_o < pi*0.5 )       sztywno( 3 , pi*0.5   , 1);
       else                          sztywno( 4 , pi*0.5   , 1);
       break;

   // case 61:
    //  sztywno( 11 ,2000   ,3.5);
    //  break;
      
      case 65:
        sztywno(11, 2100, 4);
        break;
 
     case 67:
      sztywno( 22 ,150 ,1);
      break;      
      
     case 69:
      sztywno( 3 ,pi ,2);
      break;

    case 71:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 3 , pi   , 1);
      else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 4 , pi  , 1);
      break;
  
    case 73:
      sztywno( 11 ,250   ,2);
      break; 
   
    case 75:
      sztywno( 4 ,pi*0.5   ,2);
      break;

    case 77:
      if ( Theta_o < pi*0.5 )       sztywno( 3 , pi*0.5   , 1);
      else                          sztywno( 4 , pi*0.5   , 1);
      break;
      
    case 79:
      sztywno( 11 ,300   ,2);
      break;  

    case 81:
      sztywno( 22 ,100  ,2);
      break;
     }
   }
   
   
   
   
   
    //ZIELONY
   else 
   {
     switch (nr_zadania)
     {
       case 1:
         sztywno( 1 , 270  , 2);  //335
         break;

    case 3:
      sztywno( 3 , pi*0.5  , 1.5);  //lewo
      break;
      
    case 5:
      if ( Theta_o < pi*0.5 )       sztywno( 3 , pi*0.5   , 1);
      else                          sztywno( 4 , pi*0.5   , 1);
      break;

    case 7:
      sztywno( 1 , 50   , 2);
      break;

    case 9:
      sztywno( 4 ,0  , 1.5);
      break;
      
    case 11:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
      else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3, 0  , 1);
      break;


    case 13:
      sztywno( 11 ,583   ,2.5);  //710
      break;

    case 15:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
      else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3,  0  , 1);
      break;
      
    case 17:
      nr_zadania = 19;
      break;
              
       case 19:
         sztywno(2, 495, 2);  //wróć
         break;
       
       case 21:
         sztywno(4, 1.5*pi, 2);  //obrót w prawo
         break;
       
       case 23:
         if ( Theta_o < pi*1.5 )       sztywno( 3 , pi*1.5   , 1);
         else                          sztywno( 4 , pi*1.5   , 1);
         break;
       
       case 25:
         sztywno(11, 870, 2);  //droga do drzwi UWZGLEDNIA POCZĄTKOWE PRZESUNIĘCIE DO KLOCKÓW (50)
         break;
//RYBKI         
       case 27:
         sztywno(2, 1677, 2);  //droga do akwarium
         break;
       
       case 29:
         sztywno(3, 0, 2);   //obrót w celu ustawienia wedki nad akwarium
         break;

       case 31:
         if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
         else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3, 0  , 1);
         break;
       
       case 33:
         sztywno(1, 160, 2);  //dojazd nad akwarium
         break;       

       case 35:
         funkcja_manipulatory(5);  // opuszczenie calkowite wedki
         delay(1000);
         nr_zadania = 37;
         break;
       
       case 37:
         sztywno(1, 303, 2);   //łapanie rybek
         break;
       
       case 39:
         funkcja_manipulatory(9);  //   podniesienie wedki do polowy
         delay(1000);
         nr_zadania = 41;
         break;
       
       case 41:
         sztywno(1, 318, 2);   //dojazd do siatki
         break;
       
       case 43:
          funkcja_manipulatory(7);   // zwolnienie rybek
          delay(200);        
          funkcja_manipulatory(10);  
          delay(10);
          funkcja_manipulatory(6);   
          delay(10);
          funkcja_manipulatory(11);   
          delay(500);
          funkcja_manipulatory(6);   
          delay(10);
          nr_zadania = 45;
          break;
        
       case 45:
         sztywno(2, 621, 2);   //powrót do akwarium
         break;
        
       case 47:
         funkcja_manipulatory(5);  // opuszczenie calkowite wedki
         delay(1000);
         nr_zadania = 49;
         break;
       
       case 49:
         sztywno(1, 303, 2);   //łapanie rybek
         break;
       
       case 51:
         funkcja_manipulatory(9);  //   podniesienie wedki do polowy
         delay(1000);
         nr_zadania = 53;
         break;
       
       case 53:
         sztywno(1, 318, 2);   //dojazd do siatki
         break;
       
       case 55:
          funkcja_manipulatory(7);   // zwolnienie rybek
          delay(200);        
          funkcja_manipulatory(10);  
          delay(10);
          funkcja_manipulatory(6);   
          delay(10);
          funkcja_manipulatory(11);   
          delay(500);
          funkcja_manipulatory(6);   
          delay(10);
          nr_zadania = 57;
          break;
        
       case 57:
         sztywno(2, 621, 2);   //powrót do akwarium
         break; 
       
       case 59:
         funkcja_manipulatory(5);  // opuszczenie calkowite wedki
         delay(1000);
         nr_zadania = 61;
         break;
       
       case 61:
         sztywno(1, 303, 2);   //łapanie rybek
         break;
       
       case 63:
         funkcja_manipulatory(9);  //   podniesienie wedki do polowy
         delay(1000);
         nr_zadania = 65;
         break;
       
       case 65:
         sztywno(1, 318, 2);   //dojazd do siatki
         break;
       
       case 67:
          funkcja_manipulatory(7);   // zwolnienie rybek
          delay(200);        
          funkcja_manipulatory(10);  
          delay(10);
          funkcja_manipulatory(6);   
          delay(10);
          funkcja_manipulatory(11);   
          delay(500);
          funkcja_manipulatory(6);   
          delay(10);
          nr_zadania = 69;
          break;
        
       case 69:
         sztywno(2, 621, 2);   //powrót do akwarium
         break;
         
       case 71:
         funkcja_manipulatory(5);  // opuszczenie calkowite wedki
         delay(1000);
         nr_zadania = 73;
         break;
       
       case 73:
         sztywno(1, 303, 2);   //łapanie rybek
         break;
       
       case 75:
         funkcja_manipulatory(9);  //   podniesienie wedki do polowy
         delay(1000);
         nr_zadania = 77;
         break;
       
       case 77:
         sztywno(1, 318, 2);   //dojazd do siatki
         break;
       
       case 79:
          funkcja_manipulatory(7);   // zwolnienie rybek
          delay(200);        
          funkcja_manipulatory(10);  
          delay(10);
          funkcja_manipulatory(6);   
          delay(10);
          funkcja_manipulatory(11);   
          delay(500);
          funkcja_manipulatory(6);   
          delay(10);
          nr_zadania = 81;
          break;
          
        case 81:
           sztywno(2, 621, 2);   //powrót do akwarium
           break;


     }     
   }
 }

 

void sztywno(int kierunek_sztywno , double odleglosc_sztywno, float predkosc_sztywno) {
  kierunek = kierunek_sztywno;
  if ( kierunek == 1 || kierunek == 2 || kierunek == 11 || kierunek == 22) {
    R_ustalona = 0;
    r_zadane   = 0;
    V_ustalona = predkosc_sztywno;
    stan       = 1;
    s_zadane   = odleglosc_sztywno;
    s_zadane   = s_zadane + dSm_calkowite;
  }
  if ( kierunek == 3 || kierunek == 4 ) {
    Theta_startu = Theta_o;
    R_ustalona   = predkosc_sztywno;
    V_ustalona   = 0;
    stan         = 3;
    r_zadane     = odleglosc_sztywno;
  }
  nr_zadania ++;
}



void funkcja_manipulatory(int rozkaz_manipulator) {
  switch (rozkaz_manipulator) {

  case 1:
    digitalWrite(rozkaz_serwo_platforma, HIGH);
    break;
  case 2:
    digitalWrite(rozkaz_serwo_platforma, LOW);
    break;
  case 3:
    digitalWrite(rozkaz_serwo_spych, HIGH);
    break;
  case 4:
    digitalWrite(rozkaz_serwo_spych, LOW);
    break;
  case 5:
    digitalWrite(rozkaz_serwo_wedka, HIGH);
    break;
  case 6:
    digitalWrite(rozkaz_serwo_wedka, LOW);
    break;
  case 7:
    digitalWrite(rozkaz_serwo_wedka_zwolnienie, HIGH);
    break;
  case 8:
    digitalWrite(rozkaz_serwo_wedka_zwolnienie, LOW);
    break;
  case 9:
    digitalWrite(rozkaz_serwo_wedka_polowa, HIGH);
    break;
  case 10:
    digitalWrite(rozkaz_serwo_wedka_polowa, LOW);
    break;
  case 11:
    digitalWrite(rozkaz_serwo_platforma, LOW);
    digitalWrite(rozkaz_serwo_spych, LOW);
    digitalWrite(rozkaz_serwo_wedka, LOW);
    digitalWrite(rozkaz_serwo_wedka_zwolnienie, LOW);
    digitalWrite(rozkaz_serwo_wedka_polowa, LOW);
    break;
  }
}

void droga_do_celu(double x_robota, double y_robota, double t_robota, double x_celu, double y_celu, double t_celu)
{
  bool rodzaj_ruchu = 1; //1 - obrót, 0 - ruch prostoliniowy
  int nr_ruchu = 1;    //służy do numerowania ruchów w tablicaelach (2 wymiar tablicaeli tablica)
  int nr_trajektorii = 1; //trzeci wymiar tablicaeli tablica
  double t_temp;  //przechowuje kąt o jaki powinien obrócić się robot w danym ruchu
  double przekatna_kat = atan2((y_celu - y_robota), (x_celu - x_robota));  //kąt nachylenia przekątnej
  double przekatna_dlugosc = sqrt(pow((x_celu - x_robota), 2) + pow((y_celu - y_robota), 2));  //długość przekątnej
  double thety[3][4] = { 
    { 
      przekatna_kat , t_celu , 5, 5                                                         } 
    , { 
      0 , pi / 2 , t_celu, 5                                                         } 
    , { 
      pi / 2 , 0, t_celu, 5                                                         } 
  }; //kolejne kąty w każdej z trajektorii (5 oznacza, że nastąpił koniec trajektorii)

  //Modyfikacja tablicaeli thety w przypadku różnych ustawień celu względem robota
  if (x_robota > x_celu)
  {
    thety[1][0] = pi;
    thety[2][1] = pi;
  }
  if (y_robota > y_celu)
  {
    thety[1][1] = 3 * pi / 2;
    thety[2][0] = 3 * pi / 2;
  }

  double drogi[3][2] = { 
    { 
      przekatna_dlugosc                                                         } 
    , { 
      x_celu - x_robota , y_celu - y_robota                                                         } 
    , { 
      y_celu - y_robota , x_celu - x_robota                                                         } 
  }; //kolejne długości do przejechania
  int licznik_thet = 1;  //służy do wskazywania pozycji w tablicaeli thety
  int licznik_drog = 1;  //służy do wskazywania pozycji w tablicaeli drogi

  bool robot_przodem; //TRUE - robot ustawiony przodem do wektora jego ruchu, FALSE - robot porusza się w danej chwili tyłem
  double t_robota_updated = t_robota;  //pozycja kątowa robota w aktualnie obliczanym punkcie trajektorii

  while (1)
  {
    if (rodzaj_ruchu == 1)  //obrót
    {
      t_temp = thety[nr_trajektorii - 1][licznik_thet - 1] - t_robota_updated;

      if ((t_temp == (2 * pi)) || (t_temp == (-2 * pi)))   //zamiana 360 stopni na 0 stopni
          t_temp = 0;

      if (t_temp)  //jeśli różne od zera
      {
        //konwersja kąta do zakresu <0, 2pi>
        if (t_temp > pi)
          t_temp -= (2 * pi);
        if (t_temp < (-pi))
          t_temp += (2 * pi);

        //sprawdzenie, czy przypadkiem ustawienie się robota tyłem, nie da mniejszego kąta obrotu (chyba, że musimy już sutawić się na pozycji końcowej - wtedy trzeba to zrobić przodem)
        if ((t_temp > pi / 2) && (thety[nr_trajektorii - 1][licznik_thet] != 5))
        {
          t_temp -= pi;
          robot_przodem = 0;   //ustawi się tyłem do wektora wymaganego, bo tak będzie szybciej
        }
        else if (t_temp < (-(pi / 2)) && (thety[nr_trajektorii - 1][licznik_thet] != 5))
        {
          t_temp += pi;
          robot_przodem = 0;   //ustawi się tyłem do wektora wymaganego, bo tak będzie szybciej
        }
        else
          robot_przodem = 1;   //ustawi się przodem do wektora wymaganego, bo tak będzie szybciej (lub tak musi, żeby osiągnąć t_celu)

        //Zapis danych do tablicy
        if (t_temp)   //na wypadek gdyby modyfikacje kąta theta doprowadziły do wyzerowania tego kąta
        {
          tablica[nr_trajektorii - 1][nr_ruchu - 1][0] = nr_ruchu;
          if (t_temp > 0)
          {
            tablica[nr_trajektorii - 1][nr_ruchu - 1][1] = 4;  //obrót w lewo
            tablica[nr_trajektorii - 1][nr_ruchu - 1][2] = t_temp;   //wartość kąta do obrotu
          }
          else
          {
            tablica[nr_trajektorii - 1][nr_ruchu - 1][1] = 3;  //obrót w prawo
            tablica[nr_trajektorii - 1][nr_ruchu - 1][2] = -t_temp;   //wartość kąta do obrotu
          }

          t_robota_updated += t_temp;    //pozycja robota po zmianie

          nr_ruchu++;
        }

      }

      rodzaj_ruchu = 0;  //nastepny ruch będzie prostoliniowy

      licznik_thet++;
      //SPRAWDZAMY CZY NOWA TRAJEKTORIA
      if (thety[nr_trajektorii - 1][licznik_thet - 1] == 5)   //skończyliśmy obroty w danej trajektorii
      {
        nr_trajektorii++;
        if (nr_trajektorii == 4)  //koniec obliczeń
          break;
        nr_ruchu = 1;
        licznik_thet = 1;  //indeks thet znów od początku (bo nowa trajektoria)
        licznik_drog = 1;  //indeks dróg znów od początku (bo nowa trajektoria)
        rodzaj_ruchu = 1;  //skoro skonczylismy trajektorie, to nowa trajektoria zawsze zaczyna sie od obrotu
        t_robota_updated = t_robota;  //przywracam początkową wartość kąta robota, aby zrobić obliczenia dla nowe trajektorii
      }
    }

    else          //ruch prostoliniowy
    {
      double droga_temp = drogi[nr_trajektorii - 1][licznik_drog - 1];
      if (droga_temp)   //jeśli droga niezerowa
      {
        tablica[nr_trajektorii - 1][nr_ruchu - 1][0] = nr_ruchu;
        if (droga_temp > 0)
        {
          if (robot_przodem)
            tablica[nr_trajektorii - 1][nr_ruchu - 1][1] = 1;  //jazda do przodu
          else
            tablica[nr_trajektorii - 1][nr_ruchu - 1][1] = 2;  //jazda do tyłu
          tablica[nr_trajektorii - 1][nr_ruchu - 1][2] = droga_temp;  //długość drogi
        }
        else
        {
          if (robot_przodem)
            tablica[nr_trajektorii - 1][nr_ruchu - 1][1] = 1;  //jazda do przodu
          else
            tablica[nr_trajektorii - 1][nr_ruchu - 1][1] = 2;  //jazda do tyłu
          tablica[nr_trajektorii - 1][nr_ruchu - 1][2] = -droga_temp;  //długość drogi
        }

        nr_ruchu++;
      }

      licznik_drog++;

      rodzaj_ruchu = 1;  //nastepny ruch będzie obrotowy
    }
  }
}
int znacznik_nr = 0;
int nr;
void droga_planer(int nr1) {
  if (znacznik_nr == 0){
    nr = nr1;
    znacznik_nr = 1 ;
  }
  if ( tablica[0][0][0] != 0) {
    if ( tablica[0][0][1] == 3) {
      tablica[0][0][2] = tablica[0][0][2] + Theta_o;
      if ( tablica[0][0][2] > pi * 2) tablica[0][0][2] = tablica[0][0][2] - 2 * pi;
    }
    if ( tablica[0][0][1] == 4) {
      tablica[0][0][2] =  Theta_o - tablica[0][0][2];
      if ( tablica[0][0][2] < 0) tablica[0][0][2] =  pi * 2 + tablica[0][0][2] ;
    }
    sztywno( tablica[0][0][1] , tablica[0][0][2]   , 1);
    tablica[0][0][0] = 0;
    nr ++;
  }
  if ( tablica[0][0][1] != 0 && tablica[0][0][0] == 0 && (nr_zadania) == nr ) {
    if ( (tablica[0][0][1] == 3 || tablica[0][0][1] == 4 ) && tablica[0][0][2] == 0) {
      if ( Theta_o > 0    && Theta_o < pi)     {
        sztywno( 4 , pi * 2   , 1);
        nr ++;
      }
      else if  ( Theta_o < pi * 2 && Theta_o > pi){
        sztywno( 3, 0  , 1);
        nr ++;
      }
    }
    else if ( (tablica[0][0][1] == 3 || tablica[0][0][1] == 4 ) &&  tablica[0][0][2] != Theta_o&& (nr_zadania) == nr ) {
      if ( Theta_o < tablica[0][0][2] )    {
        sztywno( 3 , tablica[0][0][2]   , 1);
        nr ++;
      }
      else {
        sztywno( 4 , tablica[0][0][2]   , 1);
        nr ++;
      }
    }
    tablica[0][0][1] = 0;
  }

  if ( tablica[0][1][0] != 0 && tablica[0][0][0] == 0 && (nr_zadania) == nr ) {
    if ( tablica[0][1][1] == 3) {
      tablica[0][1][2] = tablica[0][1][2] + Theta_o;
      if ( tablica[0][1][2] > pi * 2) tablica[0][0][2] = tablica[0][1][2] - 2 * pi;
    }
    if ( tablica[0][1][1] == 4) {
      tablica[0][1][2] =  Theta_o - tablica[0][10][2];
      if ( tablica[0][1][2] < 0) tablica[0][1][2] =  pi * 2 + tablica[0][1][2] ;
    }
    sztywno( tablica[0][1][1] , tablica[0][1][2]   , 1);
    tablica[0][1][0] = 0;
    nr ++;
  }
  if ( tablica[0][1][1] != 0 && tablica[0][1][0] == 0 && tablica[0][0][0] == 0 && (nr_zadania) == nr ) {
    if ( (tablica[0][1][1] == 3 || tablica[0][1][1] == 4 ) && tablica[0][1][2] == 0) {
      if     ( Theta_o > 0    && Theta_o < pi) {
        sztywno( 4 , pi * 2   , 1);
        nr ++;
      }
      else if ( Theta_o < pi * 2 && Theta_o > pi){
        sztywno( 3, 0  , 1);
        nr ++;
      }
    }
    else if ( (tablica[0][1][1] == 3 || tablica[0][0][1] == 4 ) &&  tablica[0][1][2] != Theta_o && (nr_zadania) == nr ) {
      if ( Theta_o < tablica[0][1][2] ) {
        sztywno( 3 , tablica[0][1][2]   , 1);
        nr ++;
      }
      else           {
        sztywno( 4 , tablica[0][1][2]   , 1);
        nr ++;
      }
    }
    tablica[0][1][1] = 0;
  }


  if ( tablica[0][2][0] != 0 && tablica[0][0][0] == 0 && (nr_zadania) == nr ) {
    if ( tablica[0][2][1] == 3) {
      tablica[0][2][2] = tablica[0][2][2] + Theta_o;
      if ( tablica[0][2][2] > pi * 2) tablica[0][0][2] = tablica[0][2][2] - 2 * pi;
    }
    if ( tablica[0][2][1] == 4) {
      tablica[0][2][2] =  Theta_o - tablica[0][10][2];
      if ( tablica[0][2][2] < 0) tablica[0][2][2] =  pi * 2 + tablica[0][2][2] ;
    }
    sztywno( tablica[0][2][1] , tablica[0][2][2]   , 1);
    tablica[0][2][0] = 0;
    nr ++;
  }
  if ( tablica[0][2][1] != 0 && tablica[0][2][0] == 0 && tablica[0][0][0] == 0) {
    if ( (tablica[0][2][1] == 3 || tablica[0][2][1] == 4 ) && tablica[0][2][2] == 0 && (nr_zadania) == nr ) {
      if   ( Theta_o > 0    && Theta_o < pi)  {
        sztywno( 4 , pi * 2   , 1);
        nr ++;
      }
      else if ( Theta_o < pi * 2 && Theta_o > pi) {
        sztywno( 3, 0  , 1);
        nr ++;
      }
    }
    else if ( (tablica[0][2][1] == 3 || tablica[0][0][1] == 4 ) &&  tablica[0][2][2] != Theta_o && (nr_zadania) == nr ) {
      if ( Theta_o < tablica[0][2][2] ) {
        sztywno( 3 , tablica[0][2][2]   , 1);
        nr ++;
      }
      else           {
        sztywno( 4 , tablica[0][2][2]   , 1);
        nr ++;
      }
    }
    tablica[0][2][1] = 0;
  }
  if (  tablica[0][0][0] == 0 &&  tablica[0][1][0] == 0 &&  tablica[0][2][0] == 0 ) {
    zadanie_dalej ++;
    znacznik_nr = 0;
  }
}















