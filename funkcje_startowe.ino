byte potwierdzenie_wyslania_koloru;
int wartosc_przelacznik_taktyka;

void funkcja_zworki_start (){

  if (digitalRead(zworka_start_robata)  == 0 && potwierdzenie_wyslania_koloru == 0) {
    if (digitalRead(przelacznik_taktyka_1) == 1)
      wartosc_przelacznik_taktyka = 1;
    if (digitalRead(przelacznik_taktyka_2) == 1)
      wartosc_przelacznik_taktyka = 2;
    if (digitalRead(przelacznik_taktyka_3) == 1)
      wartosc_przelacznik_taktyka = 3;
    if (digitalRead(przelacznik_taktyka_4) == 1)
      wartosc_przelacznik_taktyka = 4;
    if (digitalRead(przelacznik_taktyka_5) == 1)
      wartosc_przelacznik_taktyka = 5;

    switch (wartosc_przelacznik_taktyka) {
    case 1 :
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 2);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 3);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 4);
      break;
    case 2 :
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 2);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 3);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 4);
      break;
    case 3 :
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 2);
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 3);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 4);
      break;
    case 4 :
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 2);
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 3);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 4);
      break;
    case 5 :
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 2);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 3);
      stan_potwierdzenie = stan_potwierdzenie & ~( 1 << 4);
      break;
    }
    if (digitalRead(przelacznik_koloru) == 1) {
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 5);
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 6);
    }
    else {
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 5);
    }
    potwierdzenie_wyslania_koloru = 1;
    moment_rozpoczecia_meczu = millis();
    start_meczu = 1;
  }
}

void funkcja_kierunek_sleep (){

  switch  (kierunek) {
  case 1 :
    digitalWrite(dir_silnik_pin_1, LOW);
    digitalWrite(dir_silnik_pin_2, HIGH);
    break;
  case 2:
    digitalWrite(dir_silnik_pin_1, HIGH);
    digitalWrite(dir_silnik_pin_2, LOW);
    break;
  case 3 :
    digitalWrite(dir_silnik_pin_1, HIGH);
    digitalWrite(dir_silnik_pin_2, HIGH);
    break;
  case 4:
    digitalWrite(dir_silnik_pin_1, LOW);
    digitalWrite(dir_silnik_pin_2, LOW);
break;
 case 11 :
    digitalWrite(dir_silnik_pin_1, LOW);
    digitalWrite(dir_silnik_pin_2, HIGH);
    break;
  case 22:
    digitalWrite(dir_silnik_pin_1, HIGH);
    digitalWrite(dir_silnik_pin_2, LOW);
    break;
    break;
  }
  if (stan == 1 || stan == 3) {
    if (predkosc_lewy != 0) {
      digitalWrite(sleep_silnik_pin_2, HIGH);
    }
    else {
      digitalWrite(sleep_silnik_pin_2, LOW);
    }
    if (predkosc_prawy != 0) {
      digitalWrite(sleep_silnik_pin_1, HIGH);
    }
    else {
      digitalWrite(sleep_silnik_pin_1, LOW);
    }
  }
  else {
    digitalWrite(sleep_silnik_pin_1, LOW);
    digitalWrite(sleep_silnik_pin_2, LOW);
  }
}



