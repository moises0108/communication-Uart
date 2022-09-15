//Includes
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <IRremote.hpp>
//Set pins and default msg
LiquidCrystal lcd (3, 4, 5, 6, 7, 8);
byte IR_RECEIVE_PIN = 2;
String messages = "";
byte contador = 0;
byte PINBUZ = 9;
char msg[16] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  lcd.begin(16, 2);
  printEpr();

}

void loop() {
  messageReceived();
  sendMessage();
  clear_row(0);
  lcd.setCursor(0, 0);
}
//receive a message send by uart and save in epprom
void messageReceived() {
  String messageReceive = "";
  byte conteprom = 0;
  char letter = ' ';
  if (Serial.available()) {
    lcd.setCursor(0, 1);
    clear_row(1);
    pinMode(PINBUZ, HIGH);
    while (Serial.available()) {
      letter = Serial.read();
      messageReceive += ((char)letter);
      EEPROM.write(conteprom, letter);
      conteprom += 1;
    }
    if (conteprom<17){
      for(byte i=0;i<17-conteprom;i++){
        EEPROM.write(conteprom+i, 32);
      }
    }
    lcd.print(messageReceive);
    pinMode(PINBUZ, LOW);
  }
}
//Send the message and activate the buzzer
void sendMessage() {
  makeMessage();
  pinMode(PINBUZ, HIGH);
  Serial.write(msg, 16);
}
//make a message to send for Uart
void makeMessage() {

  for (byte i = 0; i < 16; i++) {
    msg[i] = ' ';
  }
  char letter = 123;
  while (true) {
    messageReceived();
    if (IrReceiver.decode()) {

      IrReceiver.resume();

      if (IrReceiver.decodedIRData.command == 0x43) {
        contador = 0;
        break;
      }
      else if (IrReceiver.decodedIRData.command == 0x44) {
        if (contador != 0) {
          contador = contador - 1;
          lcd.setCursor(contador, 0);
          lcd.print(" ");
          msg[contador] = ' ';
          lcd.setCursor(contador, 0);
        }
      }
      else {
        letter = (options(IrReceiver.decodedIRData.command));
        if (letter != 123) {
          lcd.setCursor(contador, 0);
          lcd.print(letter);
          msg[contador] = letter;
          contador += 1;
        }
      }
    }
    if (contador > 17) {
      contador = contador - 1;
    }

  }

}
//Select a buttom of the controller and pass a array to suboption()
char options(int signalIr) {
  char option = 123;
  if (signalIr == 0x16) {
    char zero[] = {'0', 'A', 'B', 'C', '@'};
    option = sub_option(zero, 0x16, sizeof(zero));
  }
  else if (signalIr == 0xC) {
    char one[] = {'1', 'D', 'E', 'F', '?'};
    option = sub_option(one, 0xC, sizeof(one));
  }
  else if (signalIr == 0x18) {
    char two[] = {'2', 'G', 'H', 'I', '<'};
    option = sub_option(two, 0x18, sizeof(two));
  }
  else if (signalIr == 0x5E) {
    char three[] = {'3', 'J', 'K', 'L', '='};
    option = sub_option(three, 0x5E, sizeof(three));
  }
  else if (signalIr == 0x8) {
    char four[] = {'4', 'M', 'N', 'O', '>'};
    option = sub_option(four, 0x8, sizeof(four));
  }
  else if (signalIr == 0x1C) {
    char five[] = {'5', 'P', 'Q', 'R', ';'};
    option = sub_option(five, 0x1C, sizeof(five));
  }
  else if (signalIr == 0x5A) {
    char six[] = {'6', 'S', 'T', 'U', ':'};
    option = sub_option(six, 0x5A, sizeof(six));
  }
  else if (signalIr == 0x42) {
    char seven[] = {'7', 'V', 'W', 'X', '!'};
    option = sub_option(seven, 0x42, sizeof(seven));
  }
  else if (signalIr == 0x52) {
    char eigth[] = {'8', 'Y', 'Z', ' ', '#'};
    option = sub_option(eigth, 0x52, sizeof(eigth));
  }
  else if (signalIr == 0x4A) {
    char nine[] = {'9', '$', '%', '&', 39};
    option = sub_option(nine, 0x4A, sizeof(nine));
  }
  return option;
}
//sub option move between the array and select a option
char sub_option(char letters[], int signalIr, byte sizeletters) {
  byte cont = 0;
  bool in = true;
  while (in) {
    messageReceived();
    if (IrReceiver.decode()) {

      IrReceiver.resume();
      if (IrReceiver.decodedIRData.command == signalIr) {
        cont += 1;
        if (sizeletters <= cont) {
          cont = 0;
        }
        lcd.print(letters[cont]);
        lcd.setCursor(contador, 0);
      }
      else if (IrReceiver.decodedIRData.command == 0x40) {
        in = false;
      }
    }
  }

  return letters[cont];


}
//Save data in epprom
void printEpr() {
  lcd.setCursor(0, 1);
  for (byte i = 0; i < 16; i++) {
    lcd.print((char)EEPROM.read(i));
  }
}
//Clear a row in the lcd
void clear_row(byte row) {
  String clearRow = "                ";
  lcd.setCursor(0, row);
  lcd.print(clearRow);
  lcd.setCursor(0, row);
}
