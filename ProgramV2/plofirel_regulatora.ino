double r_hamowania;
double DT_p, DT_p2;

double translacja_enkoder         = 0;
double rotacja_enkoder            = 0;
double uchyb_rotacji              = 0;
double uchyb_translacji_lewy      = 0;
double uchyb_translacji_prawy     = 0;
double uchyb_translacji           = 0;

double profil_translacji          = 0;
double uchyb_poprzedni_translacji = 0;
double uchyb_poprzedni_rotacji    = 0;
int    predkosc_translacji        = 0;
int    predkosc_rotacji           = 0;

void profiler() {

  if (abs(s_zadane + tolerancja_translacji) >= abs(dSm_calkowite) && abs(s_zadane - tolerancja_translacji) <= abs(dSm_calkowite) && stan == 1) {
    stan = 0;
  }

  s_hamowania = ((V_bierzaca - 0) * (V_bierzaca + 0) / (3 * przyspieszenie_zadane_translacji));
  if (stan == 1) {                                       //   c1 - jedzie prosto
    stan_robota_D = 33 ;
    if (kierunek == 1 || kierunek == 11 ) {
      if (abs(dSm_calkowite) > (s_zadane - s_hamowania)) {
        V_ustalona = V_hamoania;                                   // zwolni do zera
      }
    }
    if (kierunek == 2 || kierunek == 22) {
      if ((dSm_calkowite)   > (s_zadane - s_hamowania)) {
        V_ustalona = V_hamoania;   // zwolni do zera
      }
    }
  }
  if ( V_bierzaca < V_ustalona) {
    V_bierzaca += przyspieszenie_zadane_translacji;
    if ( V_bierzaca > V_ustalona) {
      V_bierzaca = V_ustalona;
    }
  }

  if ( V_bierzaca > V_ustalona) {
    V_bierzaca -= przyspieszenie_zadane_translacji;
    if ( V_bierzaca < V_ustalona) {
      V_bierzaca = V_ustalona;
    }
  }
 
  //////////////////////////////////////////////////////////////////////////// SKRET
  if ( stan == 3){
    stan_robota_D = 33;
    if ( kierunek == 3 ) {
      if (  Theta_o > r_zadane ) {
        DT = (2*pi-  Theta_o ) + r_zadane ;
      }
      else {
        DT =   r_zadane - Theta_o  ;
      }
    }

    if ( kierunek == 4 ) {
      if (  Theta_o < r_zadane ) {
        DT = (2*pi -  r_zadane ) + Theta_o ;
      }
      else {
        DT =    Theta_o - r_zadane   ;
      }
    }

    if (((DT) < tolerancja_rotacji) && stan == 3) {
      stan = 0;
    }

    if (  DT > DT_p && DT > DT_p2  && DT != DT_p && DT != DT_p2 && DT > 6.27){
      stan = 0;
      stan_potwierdzenie = stan_potwierdzenie | ( 1 << 5);
    }  
    DT_p = DT;
    DT_p2 = DT_p;

    r_hamowania = ((R_bierzaca ) * (R_bierzaca ) / (300 ));

    if ( abs(DT) <  r_hamowania ) {
      R_ustalona = R_hamoania;
    }
  }

  if ( R_bierzaca < R_ustalona) {
    R_bierzaca += przyspieszenie_zadane_rotacji;
    if ( R_bierzaca > R_ustalona) {
      R_bierzaca = R_ustalona;
    }
  }
  if ( R_bierzaca > R_ustalona) {
    R_bierzaca -= przyspieszenie_zadane_rotacji;
    if ( R_bierzaca < R_ustalona) {
      R_bierzaca = R_ustalona;
    }
  }

  if (stan == 0) {      // 0 - nie robi nic stoi;
    s_zadane   = 0;
    r_zadane   = 0;
    R_bierzaca = 0;
    V_bierzaca = 0;
    R_bierzaca = 0;
    V_bierzaca = 0;
  }

  profil_translacji = V_bierzaca;
  profil_rotacji    = R_bierzaca;
}



