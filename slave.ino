//Slave & Master
#define _slave  0x8
#define _master 0x9
//FOR MASTER
const char _me = _slave;
const char _you= _master;

#include <U8glib.h>       // LCD
#include <Wire.h>         // RTC
U8GLIB_ST7920_128X64 u8g(3, 5, 6, U8G_PIN_NONE); 
//U8GLIB_ST7920_128X64_1X u8g(8, 9, 10, 11, 4, 5, 6, 7, 3, A3, A2);   // 8Bit Com: D0..D7: 8,9,10,11,4,5,6,7 en=18, di=17,rw=16

/* ------------------------------------- BITMAP ------------------------------------- */
const uint8_t _ShipLeft[] U8G_PROGMEM = {
    0x00,0x00,0x00,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x7F,0xFF,0xFC,
    0x4F,0xFF,0xFC,
    0x7F,0xFF,0xFC,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C,
    0x01,0xC0,0x1C
};
const uint8_t _ShipRight[] U8G_PROGMEM = {
    0x00,0x00,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x7F,0xFF,0xFC,
    0x7F,0xFF,0xE4,
    0x7F,0xFF,0xFC,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00,
    0x70,0x07,0x00
};
const uint8_t _ShipUp[] U8G_PROGMEM = {
    0x00,0x00,
    0x01,0xC0,
    0x01,0x40,
    0x01,0x40,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x7F,0xFF,
    0x7F,0xFF,
    0x7F,0xFF,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x7F,0xFF,
    0x7F,0xFF,
    0x7F,0xFF
};
const uint8_t _ShipDown[] U8G_PROGMEM = {
    0x00,0x00,
    0x7F,0xFF,
    0x7F,0xFF,
    0x7F,0xFF,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x7F,0xFF,
    0x7F,0xFF,
    0x7F,0xFF,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0xC0,
    0x01,0x40,
    0x01,0x40,
    0x01,0xC0
};
const uint8_t _FieldBitmap[] U8G_PROGMEM = {
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x82,0x08,0x20,0x82,0x08,0x20,0x82,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8
};
const uint8_t _MissMark[] U8G_PROGMEM = {
  0x00,
  0x14,
  0x08,
  0x14,
  0x00
};
const uint8_t _BodyMark[] U8G_PROGMEM = {
  0x3E,
  0x22,
  0x22,
  0x22,
  0x3E
};
const uint8_t _HeadMark[] U8G_PROGMEM = {
  0x3E,
  0x36,
  0x22,
  0x36,
  0x3E
};
const uint8_t _MyMark[] U8G_PROGMEM = {
  0x00,
  0x00,
  0x14,
  0x08,
  0x14,
  0x00,
  0x00
};
const uint8_t _MyCursor[] U8G_PROGMEM = {
  0x00,
  0x02,
  0x07,
  0x02
};
const uint8_t _YourCursor[] U8G_PROGMEM = {
  0x1C,
  0x00,
  0x41,
  0x41,
  0x41,
  0x00,
  0x1C  
};

/* ------------------------------------- CLASS -------------------------------------- */
//Status
const byte _Down = 0,_Up = 1, _Right = 2, _Left = 3;
class Ship{
  private:
    byte type;
    byte pos_x, draw_x;
    byte pos_y, draw_y;
    byte sta= true;    //1: Alive, 0: Destroyed
  public:
    Ship(byte t = _Up){
      resetShip(t);
    }
    Ship(byte t, byte x, byte y){
      sta = true;
      type = t;
      pos_x = x; draw_x = x * 6 + 1;
      pos_y = y; draw_y = y * 6 + 1;
    }
    void resetShip(byte t = _Up){
      sta = true;
      type = _Up;
      pos_x = 0; draw_x = 1;
      pos_y = 0; draw_y = 1;
    }
    void setPos(byte x = 0, byte y = 0){
      pos_x = x; draw_x = x * 6 + 1;
      pos_y = y; draw_y = y * 6 + 1;
    }
    void setShip(byte x = 0, byte y = 0, byte t = _ShipUp){
      pos_x = x; draw_x = x * 6 + 1;
      pos_y = y; draw_y = y * 6 + 1;
      type = t;
    }
    void setType(byte t){ type = t; }
    byte getX(){ return pos_x; }
    byte getY(){ return pos_y; }
    byte getType(){ return type; }
    void beFired(){ sta = false; }
    bool getStatus(){ return sta; }
    void draw(){
      switch(type){
        case _Up:     u8g.drawBitmapP(draw_x, draw_y, 2, 22, _ShipUp);    return;
        case _Right:  u8g.drawBitmapP(draw_x, draw_y, 3, 16, _ShipRight); return;
        case _Left:   u8g.drawBitmapP(draw_x, draw_y, 3, 16, _ShipLeft);  return;
        case _Down:   u8g.drawBitmapP(draw_x, draw_y, 2, 22, _ShipDown);
        default:;
      }
    }
};



/* ------------------------------------ CONSTANT ------------------------------------ */
//Button
const int _button1 = 7, _button2 = 9;
byte _buttonState1 = 0, _buttonState2 = 0;
byte _stateJoy = 0;

//RTC
const byte DS1307 = 0x68;
const byte _NumberOfFields = 7;
byte _second, _minute, _hour, _day, _wday, _month; 
int _year;

//Map
bool _clearShip= true;

//Receive info
bool _synchYet= false;

//Sending info
byte _myX = 0, _myY = 0, _yourX = 0, _yourY = 0, _synchX, _synchY;
byte _synch = 0;

//Ship
Ship _A[5];
Ship _O[5];
byte M[10][10];

//Gameplay
byte const _ready= -1, _place= 0, _wait= 1, _battle= 2, _fire= 3, _done= 4;
byte const _pause= 7, _resume= 8, _end= 9, _noTurn= 0;
byte _phase= _ready, _turn= _ready, _lastPhase;
bool _pausing= false, _AI= false;

//Time
int _countdown= 0, _placeTime= 60, _fireTime= 15, _relaxTime= 5, _sleepTime= 5;

//Place
byte _conflictShip= 0;

//Fire
byte F[10][10];
byte const _empty = 0, _miss = 1, _body = 2, _head = 3;
byte _result= 0;
const byte _mod= 5;
char _resultS[11];

void resetMap(){
  for(byte i= 0; i < 10; i++)
    for(byte j= 0; j < 10; j++)
      M[i][j] = F[i][j]= 0;
}

/* ------------------------------------- SETUP -------------------------------------- */
void setup(void) {

/* ----------------- HARDWARE ---------------------*/
  //Slave & Master
  Wire.begin(_me);
  Wire.onReceive(receiveEvent);
  
  setTime(12, 30, 45, 1, 8, 2, 15); // 12:30:45 CN 08-02-2015

  randomSeed(analogRead(0));

  //Joystick
  pinMode( A0, INPUT);
  pinMode( A1, INPUT);

  //LCD
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  pinMode(8, OUTPUT);

  //Button
  pinMode(_button1, INPUT);
  pinMode(_button2, INPUT);

  //Debug
  Serial.begin(9600);
  Serial.println("success");  
  
/* ----------------- SOFTWARE -------------------- */
  resetMap();
}

const byte _maxShip = 4;
byte _numMyShip= 0, _numYourShip= _maxShip;
/* --------------------------------------- RTC --------------------------------------- */
void readDS1307(){
        Wire.beginTransmission(DS1307);
        Wire.write((byte)0x00);
        Wire.endTransmission();
        Wire.requestFrom(DS1307, _NumberOfFields);
        
        _second = bcd2dec(Wire.read() & 0x7f);
        _minute = bcd2dec(Wire.read() );
        _hour   = bcd2dec(Wire.read() & 0x3f); // 24h mode
        _wday   = bcd2dec(Wire.read() );
        _day    = bcd2dec(Wire.read() );
        _month  = bcd2dec(Wire.read() );
        _year   = bcd2dec(Wire.read() );
        _year += 2000;    
}
/* BCD (Binary-Coded Decimal) to Decimal */
byte bcd2dec(byte num){ return ((num/16 * 10) + (num % 16));   }
/* Decimal to BCD */
byte dec2bcd(byte num){  return ((num/10 * 16) + (num % 10));  }

void digitalClockDisplay(){
    // digital clock display of the time
    Serial.print(_hour);
    printDigits(_minute);
    printDigits(_second);
    Serial.print(" ");
    Serial.print(_day);
    Serial.print(" ");
    Serial.print(_month);
    Serial.print(" ");
    Serial.print(_year); 
    Serial.println(); 
}

void printDigits(int digits){
    Serial.print(":");
        
    if(digits < 10) Serial.print('0');
    Serial.print(digits);
}
 
/* Set time for DS1307 */
void setTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, int yr){
        Wire.beginTransmission(DS1307);
        Wire.write(byte(0x00)); // Ä‘áº·t láº¡i pointer
        Wire.write(dec2bcd(sec));
        Wire.write(dec2bcd(min));
        Wire.write(dec2bcd(hr));
        Wire.write(dec2bcd(wd)); // day of week: Sunday = 1, Saturday = 7
        Wire.write(dec2bcd(d)); 
        Wire.write(dec2bcd(mth));
        Wire.write(dec2bcd(yr));
        Wire.endTransmission();
}





/* ---------------------------------------- JoyStick ------------------------------------ */
byte _joyX = 0, _joyY = 0;
byte _delayJoy = 4, _delayButton = 0;
bool checkMap( const byte &x, const byte &y, const byte &type){
  if( ( x < 7 && x >= 0 ) && ( y < 7 && y >= 0 ) )
    return true;
  else if( ( x == 7 && type/2 == 0 ) && ( y >= 0 && y < 7 ) )
    return true;
  else if( ( y == 7 && type/2 == 1 ) && ( x >= 0 && x < 7 ) )
    return true;
  else
    return false;
}

void readJoy(){
  _joyX = analogRead( A0)/450;
  _joyY = analogRead( A1)/450;
}
void nextPoint( byte &x, byte &y){
  readJoy();
  _stateJoy = _joyX + 3*_joyY;
  switch( _stateJoy ){
    case 1:   y--;  return;
    case 7:   y++;  return;
    case 5:   x--;  return;
    case 3:   x++;  return;
  }
}
void getJoySetShip( Ship &A){
  byte x= A.getX(), y= A.getY();

  nextPoint(x, y);
  if( checkMap( x, y, A.getType()) )
    A.setPos( x, y ), _delayJoy = 0;
  _myX = x;
  _myY = y;
}
void getJoySetCursor(){
  byte x= _myX, y= _myY;
  nextPoint(x, y);
  if( !( x < 0 || x >= 10 || y < 0 || y >= 10 ) )
    _myX= x, _myY= y;
}


void printMap(){
  Serial.println("+----------+");
  for(byte i= 0; i < 10; i++){
    Serial.print("|");   
    for(byte j=0; j < 10; j++)
      if( M[i][j] )
        Serial.print("X");
      else
        Serial.print(" ");
    Serial.println("|");
  }
}
bool checkConflictShip( const Ship &A){
  byte x= A.getX(), y= A.getY(), type= A.getType();
  switch( type ){
    case _Up:
      if( M[y+1][x]||M[y+1][x+2]||M[y][x+1]||M[y+2][x+1]||M[y+3][x]||M[y+3][x+1]||M[y+3][x+2] )
        {   _conflictShip= 80;   return false;}
      break;
    case _Left:
      if( M[y+1][x]||M[y+1][x+2]||M[y][x+1]||M[y+2][x+1]||M[y][x+3]||M[y+1][x+3]||M[y+2][x+3] )
        {   _conflictShip= 80;   return false;}
      break ;
    case _Down:
      if( M[y][x]||M[y+2][x]||M[y][x+2]||M[y+2][x+2]||M[y][x+1]||M[y+2][x+1]||M[y+3][x+1] )
        {   _conflictShip= 80;   return false;}
      break;
    case _Right:
      if( M[y][x]||M[y+2][x]||M[y][x+2]||M[y+2][x+2]||M[y+1][x]||M[y+1][x+2]||M[y+1][x+3] )
        {   _conflictShip= 80;   return false;}
    default:;
  }
  return true;
}
bool checkConflictFire(){
  return ( F[_myX][_myY] == _empty );
}

void saveFire(){
  if( _result % _mod == _head && F[_myX][_myY] == _empty )
    _numYourShip--;
  F[_myX][_myY] = _result % _mod;
}
void saveShip( const Ship &A){
  _clearShip= false;
  byte x= A.getX(), y= A.getY(), type= A.getType();
  M[y+1][x+1]= true;
  switch( type ){
    case _Up:
      M[y+1][x]= M[y+1][x+2]= M[y+2][x+1]= true;
      M[y+3][x]= M[y+3][x+1]= M[y+3][x+2]= true;
      M[y][x+1]= _head - 1 + _mod * _numMyShip;
      break;
    case _Left:
      M[y][x+1]= M[y+1][x+2]= M[y+2][x+1]= true;
      M[y][x+3]= M[y+1][x+3]= M[y+2][x+3]= true;
      M[y+1][x]= _head - 1 + _mod * _numMyShip;
      break;
    case _Down:
      M[y  ][x]= M[y  ][x+1]= M[y  ][x+2]= true;
      M[y+2][x]= M[y+2][x+1]= M[y+2][x+2]= true;
      M[y+3][x+1]= _head - 1 + _mod * _numMyShip;
      break;
    case _Right:
      M[y][x  ]= M[y+1][x  ]= M[y+2][x  ]= true;
      M[y][x+2]= M[y+1][x+2]= M[y+2][x+2]= true;
      M[y+1][x+3]= _head - 1 + _mod * _numMyShip;
    default:;
  }
  printMap();
}
void clearShip(){
  _clearShip= true;
  for(byte i= 0; i < 10; i++)
    for(byte j= 0; j < 10; j++)
      M[i][j] = 0;
}
void readButtn(){
  _buttonState1 = digitalRead(_button1);
  _buttonState2 = digitalRead(_button2);
  for(byte i=0; i < 19; i++){
    delay(1);
    _buttonState1 += digitalRead(_button1);
    _buttonState2 += digitalRead(_button2);
  }
}

void resetGame(){
  clearShip();
  _turn= -1;
  _phase= _ready;
  _numMyShip= 0;
  _numYourShip= _maxShip;
  resetMap();
  for(int i= 0; i < _maxShip; i++)
    _A[i].resetShip();
}
void getButtonReady(){
  if( _buttonState1 == 20 )   _turn= -1 - _turn;
}
void getButtonAI(){
  if( _buttonState2 == 20 ){
    _AI= !_AI;
    if( _AI ){
      _placeTime= 15;
      _fireTime= 5;
    }
    else{
      _placeTime= 60;
      _fireTime= 15;
    }
  }
}
void getButtonSaveShip( Ship &s){
  if( _buttonState2 == 20 ){
    byte x= s.getX();
    byte y= s.getY();
    if ( ( x < 7 && y < 7) || checkMap( x, y, (s.getType()+1)%4 ) ){
      s.setType( (s.getType()+1)%4 );
      _delayButton = 0;
    }
  }
  if( _buttonState1 == 20 && checkConflictShip( s ) ){
    saveShip(_A[_numMyShip]);
    _numMyShip++;
//    _A[_numMyShip].createShip();
    _delayButton = -2;
  }
}
void getButtonPause(){
  if( _buttonState1 == 20 ){
    _lastPhase= _phase;
    _phase= _pause;
    _pausing= true;
  }
}
void getButtonResume(){
  if( _buttonState1 == 20 )
    _phase= _resume;
}
void getButtonFire(){
  if( _buttonState2 == 20 && checkConflictFire() )
    _phase= _fire;
}
void getButtonPlayAgain(){
  if( _buttonState1 == 20 || _buttonState2 == 20 ){
    resetGame();
  }
}




/* ---------------------------------------- Receive Event ------------------------------------ */
const byte _evConnect= -1, _evPlace= 0, _evWait= 1, _evMyTurn= 2, _evYourTurn= 3;
const byte _evBeFired= 4, _evResult= 5, _evDone= 6, _evRelax= 7, _evPause= 8, _evResume= 9, _evEnd= 10;
bool synch(){
  _synchYet = ( Wire.available() > 0 );
  return _synchYet;
}
void eventConnect(){
  if( _turn == _noTurn ){
    _phase= _place;
    _countdown= _placeTime;
  }
  if( _phase != _ready && _turn != _noTurn && _phase != _end ){
    resetGame();
  }
}
void eventPlace(){
  if( _phase == _ready && _turn == _noTurn ){
    _phase= _place;
    _countdown= _placeTime;
  }
}
void eventWait(){
  _turn= Wire.read();
  if( _phase == _wait && _turn != _noTurn )
    _phase= _battle;
}
void eventMyTurn(){
  _synchX= Wire.read();
  _synchY= Wire.read();
  if( _phase == _wait )
    _phase= _battle;
  if( _turn == _noTurn && _me == _master )
    _turn= _me;
//  Serial.print("My turn :");
//  Serial.println( _turn );
}
void eventYourTurn(){
  _yourX= Wire.read();
  _yourY= Wire.read();
  _result= M[_yourX][_yourY] + 1;
  if( _phase == _done ){
    _phase= _battle;
    _countdown= _fireTime;
    _turn= _you;
  }
}
void eventBeFire(){
  _yourX= Wire.read();
  _yourY= Wire.read();
  _result= M[_yourX][_yourY] + 1;
  _phase= _fire;
}
void eventResult(){
  _synchX= Wire.read();
  _synchY= Wire.read();
  _result= Wire.read();
  Serial.print("\tsX = ");Serial.print(_synchX);
  Serial.print("\tsY = ");Serial.print(_synchY);
  if( _synchX == _myX && _synchY == _myY ){
    saveFire();
    _phase= _done;
    _countdown= _relaxTime;
  }
}
void eventDone(){
  if( _phase == _fire ){
    _phase= _done;
    _countdown= _relaxTime;
    if( _result % _mod == _head && _A[ _result / _mod ].getStatus() ){
      _numMyShip--;
      _A[ _result / _mod ].beFired();
    }
  }
  if( _numMyShip == 0 || _numYourShip == 0 )
    _phase= _end;
}
void eventPause(){
  if( !_pausing ){
    _lastPhase= _phase;
    _phase= _pause;
    _pausing= true;
  }
}
void eventResume(){
  _phase= _lastPhase;
}
void eventEndGame(){
  if( _turn == _me || _turn == _you )
    _phase= _end;
}
void receiveEvent(int address){
  if ( synch() ){
    switch( _phase ){
//      case _ready:  eventReady();     break;
//      case _place:  eventPlace();     break;
//      case _wait:   eventWait();      break;
//      case _battle: eventBattle();    break;
//      case _fire:   eventFire();
    }
    _synch= Wire.read();
    Serial.print("Synch = ");Serial.print(_synch);
    if( _pausing ){
      if( _synch != _evPause ){
        _phase= _lastPhase;
        _pausing= false;
      }
    } else
    switch( _synch ){
      case _evConnect:    eventConnect();     break;
      case _evPlace:      eventPlace();       break;
      case _evWait:       eventWait();        break;
      case _evMyTurn:     eventMyTurn();      break;
      case _evYourTurn:   eventYourTurn();    break;
      case _evBeFired:    eventBeFire();      break;
      case _evResult:     eventResult();      break;
      case _evDone:       eventDone();        break;
      case _evPause:      eventPause();       break;
      case _evResume:     eventResume();      break;
      case _evEnd:        eventEndGame();     break;
    }
  }
  Serial.print("\tPhase = ");Serial.print(_phase);
  Serial.print("\t");Serial.print(_turn);
  if( _phase > _wait && _phase < 10 ){
    if( _turn == _me ){
      Serial.print("\tMy");
      if( _phase >= _battle ){
        Serial.print("\tX = ");Serial.print(_myX);
        Serial.print("\tY = ");Serial.print(_myY);
      }
    }
    else if( _turn == _you ){
      Serial.print("\tYour");
      if( _phase >= _battle ){
        Serial.print("\tX = ");Serial.print(_yourX);
        Serial.print("\tY = ");Serial.print(_yourY);
      }
    }
    else
      Serial.print("\tOh no!");      
  }
  if( _phase >= _fire ){
    Serial.print("\tResult = ");Serial.print(_result);
    delay(5000);
//    _phase= _battle;
//    _turn= _you;
  }

  Serial.println();
}




/* ---------------------------------------- Control ------------------------------------ */
void readyGame(){
  getButtonReady();
  getButtonAI();
}
void placeShip(){
  if( _numMyShip < _maxShip ){
    if( _delayJoy > 1 )
      getJoySetShip(_A[_numMyShip]);
    else
      _delayJoy++;

    if( _delayButton > 3 )
      getButtonSaveShip(_A[_numMyShip]);
    else
      _delayButton++;
  } 
  else{
//    if( !_clearShip )
//      clearShip();
    if( _turn == _you ){
      _phase= _battle;
      _countdown= _fireTime;
    }
    else
      _phase= _wait;
  }
}
void waitPlayer(){
  Serial.println("Wait you!");
  if( _turn == 0 )
    _turn = _me;
}
void battleMe(){
  getJoySetCursor();
  getButtonFire();
}
void battleYou(){
//  _myX = _yourX;
//  _myY = _yourY;
}
void battle(){
  switch( _turn ){
    case _me:   battleMe();   break;
    case _you:  battleYou();  break;
  }
}
void fire(){
//  if( _synch = 5 ){
//    saveFire();
//    _phase = _battle;
//    _turn = _you;
//    _countdown= _fireTime;
//  }
}
void done(){
}
void pause(){
//  Serial.println("Pause");
  getButtonPause();
}
void resum(){
//  Serial.println("Resume");
  getButtonResume();
  getButtonAI();
}
void endGame(){
  getButtonPlayAgain();
}
void control(){
  readButtn();
  switch( _phase ){
    case _ready:  readyGame();      break;
    case _place:  placeShip();      break;
    case _wait:   waitPlayer();     break;
    case _battle: battle();         
    case _done:   done();
    case _fire:   pause();          break;
    case _pause:  resum();          break;
    case _end:    endGame();        break;
  }
}





/* ---------------------------------------- Send Event ------------------------------------ */
//_evConnect= -1, _evPlace= 0, _evWait= 1, _evMyTurn= 2, _evYourTurn= 3;
//_evBeFired= 4, _evResult= 5, _evPause= 6;
const byte _seYourTurn= _evMyTurn, _seMyTurn= _evYourTurn, _seFire= _evBeFired;
void sendReady(){
  if( _turn == _noTurn )
    Wire.write( _evConnect );
}
void sendPlace(){
  Wire.write( _evPlace );
}
void sendWait(){
  Wire.write( _evWait );
  Wire.write( _turn );
}
void sendBattle(){
  if( _turn == _me ){
    Wire.write( _seMyTurn );
    Wire.write(_myX);
    Wire.write(_myY);
  }
  else{
    Wire.write( _seYourTurn );
    Wire.write(_yourX);
    Wire.write(_yourY);
  }
}
void sendFire(){
  if( _turn == _me ){
    Wire.write( _seFire );
    Wire.write(_myX);
    Wire.write(_myY);
  }
  else {
    Wire.write( _evResult );
    Wire.write(_yourX);
    Wire.write(_yourY);    
    Wire.write(_result);
  }
}
void sendDone(){
  Wire.write( _evDone );
}
void sendPause(){
  Wire.write( _evPause );
}
void sendResume(){
  Wire.write( _evResume );
}
void sendEndGame(){
  Wire.write( _evEnd );
}
void sendEvent(){
  Wire.beginTransmission(_you);
  switch( _phase ){
    case _ready:  sendReady();    break;
    case _place:  sendPlace();    break;
    case _wait:   sendWait();     break;
    case _battle: sendBattle();   break;
    case _fire:   sendFire();     break;
    case _done:   sendDone();     break;
    case _pause:  sendPause();    break;
    case _resume: sendResume();   break;
    case _end:    sendEndGame();  break;
  }
  
//  Wire.write(_synch);
//  Wire.write(_myX);
//  Wire.write(_myY);
  Wire.endTransmission();
}




/* --------------------------------------- LCD --------------------------------------- */
int _timeSec = 0, _counter = 0;
long _counterFrame = 0l;
char tmp_string[11];
int c = 0, last = 0;
void makeString(char s[11]){
  for(int i= 0; i < 11; i++){
    tmp_string[i] = s[i];
  }
}
uint8_t *past( byte x ){
  switch( x ){
    case _head:         return _HeadMark;
    case _body:         return _BodyMark;
    case _miss:         return _MissMark;
  }
}
void printCheckJoy(){
  itoa(_stateJoy, tmp_string, 10);
  u8g.drawStr( 65, 50, tmp_string);
  if( _stateJoy != 4 ){
    switch( _stateJoy ){
      case 1:
        u8g.drawStr( 65, 60, "Up");
        break;
      case 7:
        u8g.drawStr( 65, 60, "Down");
        break;
      case 5:
        u8g.drawStr( 65, 60, "Left");
        break;
      case 3:
        u8g.drawStr( 65, 60, "Right");
        break;
      default:
        u8g.drawStr( 65, 60, "NO!!!");
    }
  }
}
void printCheckFrame(){
  itoa(_timeSec, tmp_string, 10);
  u8g.drawStr( 65, 30, tmp_string);
  itoa(_counterFrame, tmp_string, 10);
  u8g.drawStr( 65, 40, tmp_string);
}
void printCoundown(){
  makeString("End in:  s");
  tmp_string[7]= _countdown / 10 + '0';
  tmp_string[8]= _countdown % 10 + '0';
  u8g.drawStr( 65, 20, tmp_string);
}
void printCheckSynchronize(){
  u8g.drawStr( 65, 20, "Time: ");
  itoa(_synch, tmp_string, 10);
  u8g.drawStr( 95, 20, tmp_string);
  itoa(_yourX, tmp_string, 10);
  u8g.drawStr( 95, 30, tmp_string);
  itoa(_yourY, tmp_string, 10);
  u8g.drawStr( 95, 40, tmp_string);
}
void printPlace(){
  for(byte i= 0; i <= min( _numMyShip, _maxShip-1); i++)
    _A[i].draw();
}
void printShip(){
  for(byte i= 0; i <= _maxShip-1; i++)
    if( _A[i].getStatus() )
      _A[i].draw();
}
void printShot(){
  for(int i= 0; i < 10; i++)
    for(int j= 0; j < 10; j++)
      if( M[i][j] > 0 )
        u8g.drawBitmapP(i * 6 - 1, j * 6, 1, 7, _MyMark );
}
void printPast(){
  for(int i= 0; i < 10; i++)
    for(int j= 0; j < 10; j++)
      if( F[i][j] > 0 )
        u8g.drawBitmapP(i * 6 - 1, j * 6 + 1, 1, 5, past( F[i][j] ) );
}
void printMyCursor(){
  u8g.drawBitmapP(_myX * 6 - 3, _myY * 6 + 1, 1, 4, _MyCursor);  
}
void printYourCursor(){
  u8g.drawBitmapP(_yourY * 6 - 1, _yourX * 6, 1, 7, _YourCursor);  
}
void printField(){
  u8g.drawBitmapP(0, 0, 8, 61, _FieldBitmap);
//  u8g.setColorIndex(1);
//  u8g.drawBox(0, 0, 61, 61);
//  u8g.setColorIndex(0);
//  u8g.drawBox(1, 1, 59, 59);
//  u8g.setColorIndex(1);
//  int x = 6, y = 6;
//  for(int i = 0; i < 9; i++){
//    for(int j = 0; j < 9; j++){
//      u8g.drawPixel(x, y);
//      y += 6;
//    }
//    x += 6;
//    y = 6;
//  }
}
void printPhase(char s[12]){
  u8g.setFont(u8g_font_profont12);
  u8g.drawStr( 65, 10, s);
}
void printButton(char s1[7], char s2[7]){
//  u8g.setFont(u8g_font_profont10);
  u8g.drawStr( 65, 62, s1);
  u8g.drawStr( 100, 62, s2);
}
void printNumMyShip(){
  makeString( "Ship:  / " );
  tmp_string[6] = _numMyShip + '0';
  tmp_string[8] = _maxShip + '0';
  u8g.drawStr( 64, 30, tmp_string);
}
void printNumYourShip(){
  makeString( "Ship:  / " );
  tmp_string[6] = _numYourShip + '0';
  tmp_string[8] = _maxShip + '0';
  u8g.drawStr( 64, 30, tmp_string);
}

void drawReady(){
/******** Left screen ********/
  printField();
  
/******* Right screen ******/
  u8g.setFont(u8g_font_profont17);
  u8g.drawStr( 65, 11, "B");
  u8g.drawStr( 76, 11, "A");
  u8g.drawStr( 87, 11, "T");
  u8g.drawStr( 98, 11, "T");
  u8g.drawStr( 109, 11, "L");
  u8g.drawStr( 120, 11, "E");
  u8g.drawStr( 71, 25, "SHIP");

  u8g.setFont(u8g_font_profont12);

  if( _turn ){
    if( _second % 2 > 0 )
      u8g.drawStr( 71, 40, "Ready!!!");
    if( _synchYet )
      u8g.drawStr( 63, 52, "Found enemy");
    u8g.drawStr( 65, 62, "Ready");
  }
  else{
    u8g.drawStr( 64, 40, "Waitting...");
    u8g.drawStr( 69, 50, "for enemy");
    u8g.drawStr( 65, 62, "Quit");
  }

  u8g.drawStr( 118, 62, "AI");
  if( _AI )
    u8g.drawStr( 105, 62, "No");
}
void drawPlacing(){
/******** Left screen ********/
  printField();
  printPlace();

/******* Right screen ******/
  printPhase("PLACING");
  printCoundown();
  printNumMyShip();

  if( _conflictShip && _conflictShip-- )
    u8g.drawStr( 64, 50, "Conflict!!!");
  
  printButton( "OK", "Spin" );
}
void drawWaitting(){
/******** Left screen ********/
  printField();
  printShip();

/******* Right screen ******/
  printPhase("YOU FIRST");
  printCoundown();
  printNumMyShip();

//  printCheckFrame();
//  printCheckSynchronize();
//  printCheckJoy();
}
void drawMyTurn(){
/******** Left screen ********/
  printPast();
  printMyCursor();

/******* Right screen ******/
  printPhase("YOUR TURN");

  printNumYourShip();
}
void drawYourTurn(){
/******** Left screen ********/
  printShip();
//  printShot();
  printYourCursor();

/******* Right screen ******/
  printPhase("ENEMY TURN");

  printNumMyShip();
}
void drawBattle(){
/******** Left screen ********/
  printField();

/******* Right screen ******/
  switch( _turn ){
    case _me :  drawMyTurn();     break;
    case _you:  drawYourTurn();   break;
  }

  printCoundown();

  u8g.drawStr( 65, 62, "Pause");
  if( _turn == _me && _phase == _battle )
    u8g.drawStr( 105, 62, "Fire");
}
void drawDone(){
  drawBattle();

  switch( _result % _mod ){
    case _head:
      u8g.drawStr( 64, 40, "Head Shot");      break;
    case _body:
      u8g.drawStr( 64, 40, "Body Shot");      break;
    case _miss:
      u8g.drawStr( 64, 40, "Miss Shot");      break;
  }
}
void drawPause(){
/******** Left screen ********/
  printField();
  printShip();

/******* Right screen ******/
  printPhase("PAUSING");
  printCoundown();
  printNumMyShip();

  u8g.drawStr( 65, 62, "Resume");

  u8g.drawStr( 118, 62, "AI");
  if( _AI )
    u8g.drawStr( 105, 62, "No");
}
void drawEndGame(){
/******** Left screen ********/
  printField();
  printPast();
  
/******* Right screen ******/
  u8g.setFont(u8g_font_profont17);
  if( _numYourShip == 0 )
    u8g.drawStr( 64, 11, "WIN");
  else
    u8g.drawStr( 64, 11, "LOSE");
  u8g.setFont(u8g_font_profont12);

  u8g.drawStr( 64, 62, "Play again!");  
}
void draw(){
  switch( _phase ){
    case _ready:  drawReady();        break;
    case _place:  drawPlacing();      break;
    case _wait:   drawWaitting();     break;
    case _battle: 
    case _fire:   drawBattle();       break;
    case _done:   drawDone();         break;
    case _pause:  drawPause();        break;
    case _end:    drawEndGame();      break;
  }
}





/* --------------------------------------- LCD --------------------------------------- */
void randomPlace(){
  while( _numMyShip < _maxShip ){
    _A[ _numMyShip ].setShip( random(7), random(7), random(4) );
    if( checkConflictShip( _A[ _numMyShip ] ) ){
      saveShip( _A[_numMyShip] );
      _numMyShip++;
    }
  }
}
void randomFire(){
  if( _turn == _me ){
    if( _AI ){
      while( !checkConflictFire() ){
        _myX= random(10);
        _myY= random(10);
      }
    }
    _phase= _fire;
  }
}
void nextTurn(){
  if( _turn == _you ){
    _turn= _me;
    _phase= _battle;
    _countdown= _fireTime;
  }
}
void overTime(){
  switch( _phase ){
    case _place:    randomPlace();    break;
    case _battle:   randomFire();     break;
    case _done:     nextTurn();       break;
  }
}




void loop(void) {
  readDS1307();

  if( _year == 2164 )
    Serial.println("****************************************************************");

  control();
  if( _countdown == 0 )
    overTime();

  sendEvent();
  
  u8g.firstPage();
  do{
    draw();
  } while(u8g.nextPage());






//  _counterFrame = _counterFrame + 1;
  if( !_pausing && _countdown && _counter != _second){
    _timeSec++;
    _counter = _second;
    _countdown--;
  }
//  delay(250);
//  Serial.print("button 1 = ");Serial.print(_buttonState1);
//  Serial.print("\tbutton 2 = ");Serial.println(_buttonState2);
//  Serial.print("joy X = ");Serial.print(_joyX);
//  Serial.print("\tjoy Y = ");Serial.println(_joyY);
//  Serial.println("--------------------");
}




