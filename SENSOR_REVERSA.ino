int TrigDer = 9;
int EchoDer = 6;
int TrigIzq = 10;
int EchoIzq = 7;
int TrigAtras = 11; 
int EchoAtras = 8;

void setup() {
  Serial.begin(9600);
  
  pinMode(TrigDer, OUTPUT);
  pinMode(TrigIzq, OUTPUT);
  pinMode(TrigAtras, OUTPUT);
  pinMode(EchoDer, INPUT);
  pinMode(EchoIzq, INPUT);
  pinMode(EchoAtras, INPUT);
 }

 void loop() {
  GetSensorData();
}

void GetSensorData() {
  float SensorDer   = DistanceSensor(TrigDer, EchoDer) / 1000;
  Serial.print("Derecha: ");
  Serial.print(SensorDer);
  Serial.println(" cm");
  float SensorIzq   = DistanceSensor(TrigIzq, EchoIzq) / 1000;
  Serial.print("Izquierda: ");
  Serial.print(SensorIzq);
  Serial.println(" cm");
  float SensorAtras = DistanceSensor(TrigAtras, EchoAtras) / 1000;
  Serial.print("Atras: ");
  Serial.print(SensorAtras);
  Serial.println(" cm");
}

float DistanceSensor(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}
