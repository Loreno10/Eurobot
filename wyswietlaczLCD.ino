int i;

void wyswietlaczLCD_inicjalizacja (){
  lcd.begin();   // Inicjalizacja LCD 2x16
  lcd.backlight(); // zalaczenie podwietlenia 
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
  lcd.print("     Husarz II");
  lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("X=");
  lcd.setCursor(7,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("Y=");
  lcd.setCursor(14,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("T=");
  lcd.setCursor(0,2); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("s=");
  lcd.setCursor(9,2); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("nz=");
  lcd.setCursor(0,3); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("kierunek=");
  lcd.setCursor(14,3); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("stan=");
 

}


void wyswietlaczLCD_nadawanie (){
  if (digitalRead(przelacznik_off_wyswietlacz) == 1) {
    if ( i > 50){
      lcd.setCursor(2,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
      lcd.print(int(X_o));
      if ( X_o < 10){
        lcd.setCursor(3,1); 
        lcd.print("  ");
      }
      if ( X_o < 100){
        lcd.setCursor(4,1); 
        lcd.print(" ");
      }
      if ( X_o < 1000){
        lcd.setCursor(5,1); 
        lcd.print(" ");
      }
      lcd.setCursor(9,1); 
      lcd.print(int(Y_o));
      if ( Y_o < 10){
        lcd.setCursor(10,1); 
        lcd.print("  ");
      }
      if ( Y_o < 100){
        lcd.setCursor(11,1); 
        lcd.print(" ");
      }
      if ( Y_o < 1000){
        lcd.setCursor(12,1); 
        lcd.print(" ");
      }
      lcd.setCursor(16,1); 
      lcd.print("    ");
      if ( Theta_o > 1){
        lcd.setCursor(16,1); 
        lcd.print(int(Theta_o*1000));
      }
      else if (Theta_o > 0.1){
        lcd.setCursor(17,1); 
        lcd.print(int(Theta_o*1000));
      }
      else if ( Theta_o > 0.01){
        lcd.setCursor(18,1); 
        lcd.print(int(Theta_o*1000));
      } 
      else if ( Theta_o > 0.001){
        lcd.setCursor(19,1); 
        lcd.print (int(Theta_o*1000));
      }
      
      lcd.setCursor(2,2); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
      lcd.print(dSm_calkowite);
      
      lcd.setCursor(12,2); 
      lcd.print(nr_zadania);
      
      lcd.setCursor(10,3); 
      lcd.print(dSm_calkowite);
      
      lcd.setCursor(19,3); 
      lcd.print(stan);
      i = 0;
    }
    i++;
  }


}

