
//traffic light
//this one is not complete 

#define carred 13
#define caryel 12
#define cargre 11

#define pasred 10
#define pasgre 9


void setup()
{
  pinMode(carred, OUTPUT); 
  pinMode(caryel, OUTPUT); 
  pinMode(cargre, OUTPUT); 
  pinMode(pasred, OUTPUT); 
  pinMode(pasgre, OUTPUT); 
  
}

void loop()
{
  
  digitalWrite(carred, HIGH);
  delay(7000); 
  digitalWrite(caryel, HIGH);
  delay (4000);
  digitalWrite(cargre, LOW);
  delay(11000);

do{
    digitalWrite (pasred,HIGH);
  }while(carred == 1);

do{
    digitalWrite (pasred,HIGH);
  }while(caryel == 1);

do{
    digitalWrite (pasgre,HIGH);
  }while(cargre == 1);

}

//traffic light
//not complete

#define CarGre 4
#define CarYel 3
#define CarRed 2

#define PawnGre 12
#define PawnRed 13

void CarGo() {
  
  digitalWrite(CarGre, HIGH);
  delay(13000);
  digitalWrite(CarGre, LOW);
  digitalWrite(CarYel, HIGH);
  delay(4000);
  digitalWrite(CarYel, LOW);

}

void CarStop() {
  
  digitalWrite(CarRed, HIGH);
  delay(9000);
  digitalWrite(CarRed, LOW);

}

void PawnGo() {
  
  digitalWrite(PawnGre, HIGH);

}
  
void PawnStop() {
  
  digitalWrite(PawnRed, HIGH);

}

void setup()
{
  pinMode(CarGre, OUTPUT);
  pinMode(CarYel, OUTPUT);
  pinMode(CarRed, OUTPUT);
}

void loop()
{
  int a=1;
  switch (a) {
  
  case 1:
    if (a=1) {
      while (a=1) {
        CarGo;
        while (CarGo == 1) {
          PawnStop;
        }
      }

        if (CarGo == 0) {

            a-1;
        }
      
    }
  
  case 2:
    if (a=0) {
      while (a=0) {
          CarStop;
          while (CarStop == 1) {
            PawnGo;
          }
      }

      if (CarStop == 1) {

          a=1;
      }
    }
  }
