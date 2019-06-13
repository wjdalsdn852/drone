#include <Servo.h> //서보모터 라이브러리 사용

Servo myservo;  
  
char ch;

int distance = 0; //Cm로 계산된 거리값을 저장해두기위해 변수를 선언합니다.
int volt = 0;
void setup() {

  Serial.begin(115200); //거리값을 PC모니터로 쉽게 확인하기위해 시리얼통신을 선언해줍니다.
 myservo.attach(9);  


 
}

void loop() {

     myservo.write(180);    
      delay(600);

 volt = map(analogRead(A0), 0, 1023, 0, 5000); 
  distance = (27.61 / (volt - 0.1696)) * 1000; 

   Serial.print(distance);  //거리값을 시리얼모니터로 출력해줍니다.

  Serial.println(" cm");

  Serial.println(" ");
      
      myservo.write(0);
      delay(600);

 volt = map(analogRead(A0), 0, 1023, 0, 5000); 
  distance = (27.61 / (volt - 0.1696)) * 1000; 

if(distance <= 50) {
myservo.write(90);
      delay(3000);
}
   Serial.print(distance);  //거리값을 시리얼모니터로 출력해줍니다.

  Serial.println(" cm");

  Serial.println(" ");
  
}
