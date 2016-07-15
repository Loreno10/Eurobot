/*        jazda do zamku , zabranie klockow , odstawienie klockow
  void  program_jazda_sztywno() {
  switch (nr_zadania) {
    case 1:
      sztywno( 1 , 200   , 2);
      break;
    case 3:
      sztywno( 4 , 5.8  , 1.5);
      break;
    case 5:
      if ( Theta_o < 5.8 )       sztywno( 3 , 5.8   , 1);
      else                          sztywno( 4 , 5.8   , 1);
      break;
    case 7:
      sztywno( 1 , 960   , 2);
      break;

    case 9:
      sztywno( 3 , 0  , 1.5);
      break;
    case 11:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi * 2   , 1);
      else if ( Theta_o < pi * 2 && Theta_o > pi)     sztywno( 3, 0  , 1);
      break;


    case 13:
      sztywno( 1 , 700   , 2);
      break;
    case 15:
      sztywno( 4 , 5.8  , 1.5);
      break;
    case 17:
      if ( Theta_o < 5.8 )       sztywno( 3 , 5.8   , 1);
      else                          sztywno( 4 , 5.8   , 1);
      break;

    case 19:
      sztywno( 2 , 380   , 2);
      break;
    case 21:
      sztywno( 4 , pi * 1.5  , 1.5);
      break;
    case 23:
      if ( Theta_o < pi * 1.5 )       sztywno( 3 , pi * 1.5   , 1);
      else                          sztywno( 4 , pi * 1.5   , 1);
      break;
    case 25:
      funkcja_manipulatory(1);
      //delay(1000);
      nr_zadania = 27;
      break;
    case 27:
      przyspieszenie_zadane_translacji = 0.1;
      sztywno( 11 , 600   , 14);
      break;
    case 29:
      przyspieszenie_zadane_translacji = 0.03;
      sztywno( 2 , 300   , 2);
      break;

    case 31:
      sztywno( 4 , pi  , 1.5);
      break;
    case 33:
      if ( Theta_o < pi )           sztywno( 3 , pi  , 1);
      else                          sztywno( 4 , pi  , 1);
      break;
    case 35:
      sztywno( 11 , 800   , 1.5);
      break;
    case 37:
      sztywno( 4 , pi / 2  , 1.5);
      break;
    case 39:
      if ( Theta_o < pi / 2 )           sztywno( 3 , pi / 2  , 1);
      else                          sztywno( 4 , pi / 2  , 1);
      break;
    case 41:
      sztywno( 11 , 500   , 1.5);
      break;

    case 43:
      sztywno( 3 , 0  , 1.5);
      break;
    case 45:
      if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi * 2   , 1);
      else if ( Theta_o < pi * 2 && Theta_o > pi)     sztywno( 3, 0  , 1);
      break;
    case 47:
      sztywno( 11 , 600  , 1.5);
      break;
    case 49:
      funkcja_manipulatory(3);
      nr_zadania = 49;
      break;
    case 51:
      sztywno( 2 , 600  , 4);
      break;
    case 53:
      funkcja_manipulatory(2);
      funkcja_manipulatory(4);
      delay(1000);
      nr_zadania = 55;
      break;
  }
  }
*/







//////////////////////////////////////////////////
/*   wsuniecie klockow do pola (homologacja
 case 1:
    sztywno( 1 , 200   , 2);
    break;

    case 3:
    sztywno( 4 , pi*1.5  , 1.5);
    break;
    case 5:
    if ( Theta_o < pi*1.5 )       sztywno( 3 , pi*1.5   , 1);
    else                          sztywno( 4 , pi*1.5   , 1);
    break;

    case 7:
    sztywno( 1 , 15   , 2);
    break;

    case 9:
    sztywno( 3 ,0  , 1.5);
    break;
    case 11:
    if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
    else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3, 0  , 1);
    break;


    case 13:
    sztywno( 1 ,950   ,2);
    break;

    case 15:
    if      ( Theta_o > 0    && Theta_o < pi)     sztywno( 4 , pi*2   , 1);
    else if ( Theta_o < pi*2 && Theta_o > pi)     sztywno( 3, 0  , 1);
    break;
    case 17:
    nr_zadania = 19;

    break;

    case 19:
    sztywno( 2 ,700   ,2);
    break;

    case 21:
    sztywno( 4 , pi*1.5  , 1.5);
    break;
    case 23:
    if ( Theta_o > pi*1.5 )       sztywno( 4 , pi*1.5   , 1);
    else                          sztywno( 3 , pi*1.5   , 1);
    break;

    case 25:
    sztywno( 1 ,400   ,3);
    break;
    case 27:
    sztywno( 3 ,0  , 1.5);
    break;
    case 29:
    if ( Theta_o > pi*2 )       sztywno( 3 , pi*2   , 1);
    else if ( Theta_o < pi*2 )    sztywno( 4 , pi*2   , 1);
    break;
    case 31:
    sztywno( 1 ,1000   ,3);
    break;

    case 33:
    sztywno( 4 , pi*1.5  , 1.5);
    break;
    case 35:
    if ( Theta_o > pi*1.5 )       sztywno( 4 , pi*1.5   , 1);
    else                          sztywno( 3 , pi*1.5   , 1);
    break;

    case 37:
    funkcja_manipulatory(1);
    break;
    case 39:
    sztywno( 1 ,600   ,8);
    break;
    case 41:
    sztywno( 2 ,200   ,2);
    break;
  */



  /*/*  cos
  case 1:
  sztywno( 1 ,200   ,2);
  break;
  case 3:
  sztywno( 4 ,4.71  ,1.5);
  break;
  case 5:
  sztywno( 1 ,20   ,2);
  break;
  case 7:
  sztywno( 3 ,0   ,1.5);
  break;
  case 9:
  sztywno( 1 ,850   ,2);
  break;
  case 11:
  sztywno( 2 ,800   ,2);
  break;
  case 13:
  sztywno( 4 ,4.71   ,1.5);
  break;
  case 15:
  sztywno( 1 ,600   ,3);
  break;
  case 17:
  sztywno( 3 ,0   ,2);
  break;
  case 19:
  sztywno( 1 ,400   ,3);
  break;
*/
