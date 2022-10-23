const int PWM_PIN_LED = 12 ;
const int BUTTON_PIN = 33 ;

const int PWM_CHANNEL    = 0 ;
const int PWM_FREQ       =10000 ; // [Hz]
const int PWM_RESOLUTION =8 ;

int waveform = 0 ;
float t ;
float dutyCycle = 0 ;

void setup() {
  
  Serial.begin(115200);  
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  // Inicializando PWM
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(PWM_PIN_LED, PWM_CHANNEL);

}

void loop() {

  // Polling button
  if(digitalRead(BUTTON_PIN)){
    waveform++ ;
    if(waveform > 7){
      waveform = 0 ;
    }
    Serial.println(waveform);
    delay(500);
  }

  // Tiempo
  t++ ;
  if(t > 256){
      t = 0 ;
    }

  // Menú
  switch(waveform){
    
    case 0:
       dutyCycle = 0 ;
    break;
       
    case 1:
       dutyCycle = 0.3 ;
    break;
       
    case 2:
       dutyCycle = 0.5 ;
    break;

    case 3:
       dutyCycle = 0.8 ;
    break;

    case 4:
       dutyCycle = 1.0 ;
    break;


    case 5:
       dutyCycle = (t+0.1)/256 ;
       delay(2.5);
    break;

    case 6:
       dutyCycle = 0.5*sin(2*PI*t/256) + 0,5  ;
       delay(0.5);
    break;

    case 7:
       dutyCycle = pow(2.71828, ((t/255)-1)*2) ;
       delay(4);
    break;
    
  }

  Serial.println(dutyCycle*100);

  ledcWrite(PWM_CHANNEL, dutyCycle*255);
  
}
