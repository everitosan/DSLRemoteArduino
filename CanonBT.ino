#define focus 7
#define trigger 6

int state = 0;

void setup() {
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);

  pinMode(focus, OUTPUT);
  digitalWrite(focus, LOW);
  
  Serial1.begin(9600);
  Serial.begin(9600);
  delay(1000);
  
}

void loop() {
  if(Serial1.available() > 0) {
    state = Serial1.read();
    }
    
   if(state == '0') { // focus and trigger off
      digitalWrite(trigger, LOW);
      digitalWrite(focus, LOW);
      
      state = 0;
    } else if (state =='1') { // Focus on
      digitalWrite(focus, HIGH);
      digitalWrite(trigger, LOW);

      state = 0;
    } else if (state =='2') { // Trigger on
      digitalWrite(trigger, HIGH);
      digitalWrite(focus, LOW);

      state = 0;
    }
}
