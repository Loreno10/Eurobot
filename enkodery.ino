void initEncoders() {
  pinMode(slaveSelectEnc1, OUTPUT);
  pinMode(slaveSelectEnc2, OUTPUT);
  digitalWrite(slaveSelectEnc1, HIGH);
  digitalWrite(slaveSelectEnc2, HIGH);
  SPI.begin();
  digitalWrite(slaveSelectEnc1, LOW);
  SPI.transfer(0x88);
  SPI.transfer(0x03);
  digitalWrite(slaveSelectEnc1, HIGH);
  digitalWrite(slaveSelectEnc2, LOW);
  SPI.transfer(0x88);
  SPI.transfer(0x03);
  digitalWrite(slaveSelectEnc2, HIGH);
}
long readEncoder(int encoder) {
  unsigned int count_1, count_2, count_3, count_4;
  long count_value;
  if (encoder == 1) {
    digitalWrite(slaveSelectEnc1, LOW);
    SPI.transfer(0x60);
    count_1 = SPI.transfer(0x00);
    count_2 = SPI.transfer(0x00);
    count_3 = SPI.transfer(0x00);
    count_4 = SPI.transfer(0x00);
    digitalWrite(slaveSelectEnc1, HIGH);
  }
  else if (encoder == 2) {
    digitalWrite(slaveSelectEnc2, LOW);
    SPI.transfer(0x60);
    count_1 = SPI.transfer(0x00);
    count_2 = SPI.transfer(0x00);
    count_3 = SPI.transfer(0x00);
    count_4 = SPI.transfer(0x00);
    digitalWrite(slaveSelectEnc2, HIGH);
  }
  count_value = (count_1 << 8) + count_2;
  count_value = (count_value << 8) + count_3;
  count_value = (count_value << 8) + count_4;
  return count_value;
}
void clearEncoderCount() {
  digitalWrite(slaveSelectEnc1, LOW);
  SPI.transfer(0x98);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  digitalWrite(slaveSelectEnc1, HIGH);
  delayMicroseconds(100);
  digitalWrite(slaveSelectEnc1, LOW);
  SPI.transfer(0xE0);
  digitalWrite(slaveSelectEnc1, HIGH);
  digitalWrite(slaveSelectEnc2, LOW);
  SPI.transfer(0x98);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  SPI.transfer(0x00);
  digitalWrite(slaveSelectEnc2, HIGH);
  delayMicroseconds(100);
  digitalWrite(slaveSelectEnc2, LOW);
  SPI.transfer(0xE0);
  digitalWrite(slaveSelectEnc2, HIGH);
}

double ustawienie_kata ( double kat)
{
  if ( kat >= pi * 2) {
    kat = kat - pi * 2;
  }
  if ( kat <= -pi * 2) {
    kat = kat + pi * 2;
  }
  if ( kat < 0 ) {
    kat = pi * 2 + kat;
  }
  else {
    kat = kat;
  }
  return kat;
}
