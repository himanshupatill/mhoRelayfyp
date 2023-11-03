void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

  float volSample[3];
  float curSample[3];
 
  int R = 1;
  int Z = 3;
  int tau = 72;
  int count = 0;
  int threshold = 2;

// the loop function runs over and over again forever

void loop() {
  for(int i=0; i<3; i++){
    double volSource = analogRead(A0);
    volSource = volSource/204.6;
    volSample[i] = volSource;
    Serial.print("volSample[");
    Serial.print(i);
    Serial.print("] : ");
    Serial.print(volSample[i]);
    Serial.println(" ");
    
    double curSource = analogRead(A1);
    curSource = curSource/204.6;
    curSource = curSource/R;
    curSample[i] = curSource;
    
    Serial.print("curSample[");
    Serial.print(i);
    Serial.print("] : ");
    Serial.print(curSample[i]);
    Serial.println(" ");
    delay(1000);
  }

  double I=sqrt(pow(curSample[1], 2)+pow((curSample[2]-curSample[0])/2*(2*3.14*50*0.001)*1, 2)); 
  Serial.print("I : ");
  Serial.print(I);
  Serial.println(" ");
  double V=sqrt(pow(volSample[1], 2)+pow((volSample[2]-volSample[0])/2*(2*3.14*50*0.001)*1, 2));
  Serial.print("V : ");
  Serial.println(V);
  Serial.println(" ");
  //int phi= atan(((2*3.14*50*0.001)*curSample[1]*(2*1))/(curSample[2]-curSample[0]));
  double phi =72;
//  Serial.print("phi : ");
//  Serial.print(phi);


  if(V<I*Z*cos(phi-tau)){ 
    count++;
  }
  else{
    count = 0;
  }
  Serial.print("count : ");
  Serial.print(count);
  Serial.println(" ");
   digitalWrite(12, HIGH);
  if(count == threshold){
    digitalWrite(12, HIGH);
    //delay(1000);
    digitalWrite(12, LOW);
  }

  delay(1000);
  
  //int v2 = analogRead(A2);

  
  
//  if(volSource > 204 && volSource < 614){
//    digitalWrite(13, HIGH);
//  }
//  else{
//    digitalWrite(13, LOW); 
//  }
//  
//  if(curSource > 204 && curSource < 410){
//    digitalWrite(12, HIGH);
//  }
//  else{
//    digitalWrite(12, LOW);
//  }

  
  
}
