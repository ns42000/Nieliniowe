#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62


#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19


String msg;

int kierunek=0, kierunek_a=0, kierunek_b=0, kierunek_c=0, kroki=0;

int kroki_a=0, kroki_b=0, kroki_c=0;

int czy_mam_odp = 0;    // Zmienna sprawdzajaca czy był ruch



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, HIGH);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, HIGH);
  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, HIGH);
  pinMode(Z_STEP_PIN, OUTPUT);

  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);

  
  

}

void loop() {
  // put your main code here, to run repeatedly:


//laborki2 zawracanie itd ruch silnikow


//krancowki 
  if (((digitalRead(X_MAX_PIN)==0 && kierunek_a==0) || kierunek_a==1) && kroki_a > 0)
  {
  digitalWrite(X_STEP_PIN, LOW);
  kroki_a--;
  }
  if (((digitalRead(Y_MAX_PIN)==0 && kierunek_b==0) || kierunek_b==1) && kroki_b > 0)
  {
  digitalWrite(Y_STEP_PIN, LOW);
  kroki_b--;
  }
  if (((digitalRead(Z_MAX_PIN)==0 && kierunek_c==0) || kierunek_c==1) && kroki_c > 0)
  {
  digitalWrite(Z_STEP_PIN, LOW);
  kroki_c--;
  }
 
  delay(1);
  
  digitalWrite(X_STEP_PIN, HIGH);
  digitalWrite(Y_STEP_PIN, HIGH);
  digitalWrite(Z_STEP_PIN, HIGH);
  
  
  
  /*
  kroki++;
  if(kroki ==500) {
    kroki=0;
  kierunek=!kierunek;
  }
  
  
  digitalWrite(X_DIR_PIN, kierunek);
  digitalWrite(Y_DIR_PIN, kierunek);
  digitalWrite(Z_DIR_PIN, kierunek);


  Serial.println(digitalRead(X_MAX_PIN));
  Serial.println(digitalRead(Y_MAX_PIN));
  Serial.println(digitalRead(Z_MAX_PIN));
 
 */
 
  while (Serial.available() > 0)
  {
    
    msg = Serial.readStringUntil('\n');
    sscanf(msg.c_str(),"a %i b %i c %i",&kroki_a, &kroki_b, &kroki_c);
    //Serial.println(kroki_a);
    //Serial.println(kroki_b);
    //Serial.println(kroki_c);
    czy_mam_odp=1;
    if (kroki_a < 0) 
    {
      kroki_a = -kroki_a;
    kierunek_a=1;
    digitalWrite(X_DIR_PIN, kierunek_a);
    }
    else 
    {
      kierunek_a=0;
      digitalWrite(X_DIR_PIN, kierunek_a);
    }

    
    if (kroki_b < 0) 
    {
      kroki_b = -kroki_b;
    kierunek_b=1;
    digitalWrite(Y_DIR_PIN, kierunek_b);
    }
    else 
    {
      kierunek_b=0;
      digitalWrite(Y_DIR_PIN, kierunek_b);
    }

    
    if (kroki_c < 0) 
    {
      kroki_c = -kroki_c;
    kierunek_c=1; 
    digitalWrite(Z_DIR_PIN, kierunek_c);
    }
    else 
    {
      kierunek_c=0;
      digitalWrite(Z_DIR_PIN, kierunek_c);
    }  
  }
  if ((kroki_a==0)&&(kroki_b==0)&&(kroki_c==0)&&(czy_mam_odp==1))
      {
        Serial.println(" :) ");
        czy_mam_odp=0;
      }
  
  
  













}
