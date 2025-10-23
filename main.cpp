int motorPinL = 3;
int motorPinR = 5;
int sensors[5]={A1,A2,A3,A4,A5};
int weights[5]={-2,-1,0,1,2};
float lastError = 0;
int speed = 210;

float readLine(){
  int sum=0, count=0;
  for (int i=0;i<5;i++){
    int val = !digitalRead(sensors[i]); // Inverting so black(on line) = 1 
    count += val; // counts over how many sensors is the line distributed
    sum += val * weights[i];
  }
  if (count == 0){float error = lastError; return error;}
  float error = sum/count;
  lastError = error;
  return error;
}

float PIDcontrol(int error){
  //Derivative and Integral do not seem necessary at this point to me
  int kp = 20;
  float correction = error*kp; 
  analogWrite(motorPinL,speed+correction);
  analogWrite(motorPinR,speed-correction);
}
  

void setup()
{
  pinMode(motorPinL, OUTPUT);
  pinMode(motorPinR, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  analogWrite(motorPinL,speed);
  analogWrite(motorPinR,speed);
}

void loop()
{
  PIDcontrol(readLine());
}
