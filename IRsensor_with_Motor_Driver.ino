int IR1 = 4;
int IR2 = 5;
int IR3 = 6;
int IR4 = 7;
int IR5 = 8;
int IR6 = 9;
int Leftmotor1 = 23;
int Leftmotor2 = 24;
int Rightmotor1 = 29;
int Rightmotor2 = 30;
void setup() {
  // put your setup code here, to run once:
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
pinMode(IR3, INPUT);
pinMode(IR4, INPUT);
pinMode(IR5, INPUT);
pinMode(IR6, INPUT);

pinMode(Leftmotor1, OUTPUT);
pinMode(Leftmotor2, OUTPUT);
pinMode(Rightmotor1, OUTPUT);
pinMode(Rightmotor2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int s1 = digitalRead(IR1);
int s2 = digitalRead(IR2);
int s3 = digitalRead(IR3);
int s4 = digitalRead(IR4);
int s5 = digitalRead(IR5);
int s6 = digitalRead(IR6);

//Serial.print(s1);
//Serial.print(s2);
//Serial.print(s3);
//Serial.print(s4);
//Serial.print(s5);
//Serial.println(s6);

if ((s1==1)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==1)){
  forward();
  Serial.println("Moving Forward");
}

if ((s1==1)&&(s2==0)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)){
  forward();
  Serial.println("Moving Forward");
}

if ((s1==1)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==1)){
  forward();
  Serial.println("Moving Forward");
}

if ((s1==0)&&(s2==1)&&(s3==1)){
  backward();
  delay(300);
  right();
  Serial.println("Moving Right");
}

if ((s1==1)&&(s2==1)&&(s3==0)){
  backward();
  delay(300);
  left();
  Serial.println("Moving Left");
}

if ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)){
  Stop();
  Serial.println("Robot Stopped");
}
}

void forward(){
  digitalWrite(Leftmotor1, HIGH);
  digitalWrite(Leftmotor2, LOW);
  digitalWrite(Rightmotor1, HIGH);
  digitalWrite(Rightmotor2, LOW);
}

void backward(){
  digitalWrite(Leftmotor1, LOW);
  digitalWrite(Leftmotor2, HIGH);
  digitalWrite(Rightmotor1, LOW);
  digitalWrite(Rightmotor2, HIGH);
}

void right(){
  digitalWrite(Leftmotor1, HIGH);
  digitalWrite(Leftmotor2, LOW);
  digitalWrite(Rightmotor1, LOW);
  digitalWrite(Rightmotor2, HIGH);
}

void left(){
  digitalWrite(Leftmotor1, LOW);
  digitalWrite(Leftmotor2, HIGH);
  digitalWrite(Rightmotor1, LOW);
  digitalWrite(Rightmotor2, HIGH);
}

void Stop(){
  digitalWrite(Leftmotor1, HIGH);
  digitalWrite(Leftmotor2, HIGH);
  digitalWrite(Rightmotor1, HIGH);
  digitalWrite(Rightmotor2, HIGH);
}
