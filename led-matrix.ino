/*
Pin 11 - Middle level leds
Pin 12 - Bottom level leds
Pin 13 - Top level leds
Pin 2->10 - Single leds


   Physical Pins                  Declared as
|       |[ 8][5][2]          |       |[6][3][0]
|Arduino|[ 9][6][3]    New   |Arduino|[7][4][1]
|       |[10][7][4]          |       |[8][5][2]

Physical pin connection as shown above.

Defined by arrays:
Bottom level row_led[0]
Middel level row_led[1]
Top level    row_led[2]


*/

int single_led[] =  {2, 3, 4, 5, 6, 7, 8, 9, 10};
int row_led[] = {12, 11, 13};
int booted = 0;
// the setup function runs once when you press reset or power the board
void setup() {


  for(int i = 0; i < 9; i++){
    pinMode(single_led[i], OUTPUT);
  }
  for(int i = 0; i < 3; i++){
    pinMode(row_led[i], OUTPUT);
  }
}


void loop() {
  if(booted == 0){
    fancy_blink(25,10);
    booted = 1;
  }
  big_blink(1000, 10);
  fancy_blink(200, 10);

} 
    
  //------------------------------------//
 //---------Defined functions----------//
//------------------------------------//

//-----------------
//Clean-up function
//-----------------
void reset_pins(){
  for(int i = 0; i < 9; i++){
    digitalWrite(single_led[i], LOW);
  }
  for(int i = 0; i < 3; i++){
    digitalWrite(row_led[i], LOW);
  }
}

//--------------------------------------------------------
//Blinks all LEDs (speed defined by the function argument)
//--------------------------------------------------------
void big_blink(int blink_time, int big_blinks_max){
  int big_blinks = 0;
  
  while(big_blinks < big_blinks_max){
    digitalWrite(row_led[0], HIGH);
    digitalWrite(row_led[1], HIGH);
    digitalWrite(row_led[2], HIGH);
    
    for(int i = 0; i < 9; i++){
      digitalWrite(single_led[i], HIGH);
    }
    delay(blink_time);
    reset_pins();
    delay(blink_time);
    
    big_blinks++;
  }
  reset_pins();
  return;  
}

//--------------
//Rotating Sides
//--------------

//-----------
//Fancy Blink
//-----------
void fancy_blink(int fancy_time, int fancy_blink_max){
  int fancy_blinks = 0;
  int fancy_layer = 2;
  
  while(fancy_blinks < fancy_blink_max){
    fancy_layer = 2;
    
    while(fancy_layer != -1){
      for(int i = 0; i < 9; i++)
        digitalWrite(single_led[i], HIGH);
      
      digitalWrite(row_led[fancy_layer], HIGH);
      
      delay(fancy_time);
      reset_pins();
      delay(fancy_time);
      fancy_layer--;
      fancy_blinks++;
    }
  }
}
//--------------------
//A "Loading" Sequence
//--------------------
void loading_seq(){
  int top_seq[] = {0, 1, 2, 5, 8, 7, 6, 3};
  int loops = 0;
  while(loops < 12){
    if(loops == 0)
    digitalWrite(row_led[2], HIGH);
    if(loops == 3)
    digitalWrite(row_led[1], HIGH);
    if(loops == 9)
    digitalWrite(row_led[0], HIGH);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(single_led[top_seq[i]], HIGH);
      delay(100);
    }
    digitalWrite(single_led[4], HIGH);
    for(int i = 0; i < 8; i++){
      digitalWrite(single_led[top_seq[i]], LOW);
      delay(100);
    }
    loops++;  
  }
  reset_pins();
  return;
}


