// on définit les variables et on importe les bibliotheque ici 
// int nomvariable valuer 
// #define nom valeur 
int c1 = 52;
int c2 = 50;
int c3 = 48;
int c4 = 46;
int c5 = 44;
int c6 = 42;
int c7 = 38;
int c8 = 36;
int c9 = 34;
int c10 = 32;

int ena = 10;
int enb = 11;

int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;

float bms = 90;
float rms;
float lms;

float kp =0.65;
float kd = 5;

int maxrms = 160;
int maxlms = 160;
int ms;

int lasterror = 0;


//////////////////////////////
void setup() {
  //pinMode(pin,OUTPUT ou INPUT)
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  pinMode(c5,INPUT);
  pinMode(c6,INPUT);
  pinMode(c7,INPUT);
  pinMode(c8,INPUT);
  pinMode(c9,INPUT);
  pinMode(c10,INPUT);
  
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT); 
  Serial.begin(9600);

}

void loop() {
   int capt1 = digitalRead(c1);
 int capt2 = digitalRead(c2);
 int capt3 = digitalRead(c3);
 int capt4 = digitalRead(c4);
 int capt5 = digitalRead(c5);
 int capt6 = digitalRead(c6);
 int capt7 = digitalRead(c7);
 int capt8 = digitalRead(c8);
 int capt9 = digitalRead(c9);
 int capt10 = digitalRead(c10);
  if (!capt1&&!capt2&&!capt3&&!capt4&&!capt5&&!capt6&&!capt7) {
    back();
    delay(40);
  }
  else if (capt1&&capt2&&capt3) {
    left();
    delay(80);
  }
  else if (capt8&&capt9&&capt10) {
    right();
    delay(80);
  }
  else if (capt1||capt2||capt3) {
    left();
    delay(50);
  }
  else if (capt8||capt9||capt10) {
    right();
    delay(50);
  }
  else {
    PID();
  }
  }

void PID() { 
 int capt1= digitalRead(c1);
 int capt2 = digitalRead(c2);
 int capt3 = digitalRead(c3);
 int capt4 = digitalRead(c4);
 int capt5 = digitalRead(c5);
 int capt6 = digitalRead(c6);
 int capt7 = digitalRead(c7);
 int capt8 = digitalRead(c8);
 int capt9 = digitalRead(c9);
 int capt10 = digitalRead(c10);
 

 
 int error=0; //kznzt 75
 
 ms = kp*error +kd*(error-lasterror);
 lasterror = error;
 if(lms > maxlms){
  lms = maxlms;
 }if(lms < 0){
  lms = 0;
 }if(rms < 0){
  rms = 0;
 }if(rms > maxrms){
  rms = maxrms;
 }
 
  analogWrite(enb,lms);
  analogWrite(ena,rms);
   if (capt2 ||capt1) {
  left();
   }
  else if  (capt3||capt4 || capt5 || capt6 || capt7 || capt8 ) {
  forward();
 }
   else if (   capt9|| capt10  ) {
  right();
   }

 }
//création des fonctions 
// type de rretour ( bool int char) nomfonction(parametre1,parametre2.....) {   }
void forward(){
  //digitalWrite(pin,HIGH)==digitalWrite(pin,1)
  //digitalWrite(pin,0)==digitalWrite(pin,0)
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right(){
  //digitalWrite(pin,HIGH)==digitalWrite(pin,1)
  //digitalWrite(pin,0)==digitalWrite(pin,0)
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void left(){
  //digitalWrite(pin,HIGH)==digitalWrite(pin,1)
  //digitalWrite(pin,0)==digitalWrite(pin,0)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void back() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
