#define PIN_A               13
#define PIN_WHITE           12
#define PIN_BLACK           8
#define PINO_BOTAO_BLACK    2
#define PINO_BOTAO_WHITE    3


volatile bool blackBtnUpper = false;
volatile bool whiteBtnUpper = false;
volatile bool fistClick 	= true;
volatile bool started = false;
volatile bool timeBurst = false;
volatile unsigned long int timeWhite = 180000;
volatile unsigned long int timeBlack = 180000;
volatile unsigned long int baseLine = 0;
volatile unsigned long int nextPrint = 0;
volatile unsigned long int timemReference = 0;



void setup() {
  Serial.begin(9600);
  pinMode(PIN_WHITE, OUTPUT);
  pinMode(PIN_BLACK, OUTPUT);
  pinMode(PINO_BOTAO_BLACK, INPUT_PULLUP);
  pinMode(PINO_BOTAO_WHITE, INPUT_PULLUP);

  digitalWrite(PIN_WHITE, LOW);
  digitalWrite(PIN_BLACK, LOW);

  attachInterrupt(digitalPinToInterrupt(PINO_BOTAO_BLACK), btnWhitePlayer, FALLING);
  attachInterrupt(digitalPinToInterrupt(PINO_BOTAO_WHITE), btnBlackPlayer, RISING);
}

void loop() {
  
  // Se o tempo estiver estourado não faz nada.
  if(timeBurst){
  	return;
  }
  
  // Se o negocio dos tiver levantado, significa que o branco está jogando
  if (blackBtnUpper) {
    
    // Se ainda não tiver começado, comece
    if (!started) {
      started = true;
      nextPrint = baseLine;
    }
    
    // Reduz 1 segundo
    if(millis() >= timemReference ){
    	timemReference += 1000;
      	timeWhite -= 1000;
    }
    
    if(timeWhite <= 0){
    	Serial.println("O tempo das Brancas acabou. As Pretas ganharam!");
      	timeBurst = true;
        digitalWrite(PIN_WHITE, LOW);
    	digitalWrite(PIN_BLACK, LOW);
    }else{
    	digitalWrite(PIN_WHITE, HIGH);
    	digitalWrite(PIN_BLACK, LOW);
    }

   
  }

  if (started && whiteBtnUpper) {
    
    if(millis() >= timemReference ){
    	timemReference += 1000;
      	timeBlack -= 1000;
    }
    
    if(timeBlack <= 0){
    	Serial.println("O tempo das Pretas acabou. As Brancas ganharam!");
      	timeBurst = true;
        digitalWrite(PIN_WHITE, LOW);
    	digitalWrite(PIN_BLACK, LOW);
    }else{
    	digitalWrite(PIN_WHITE, LOW);
    	digitalWrite(PIN_BLACK, HIGH);
    }
    
  
  }

  if (started && millis() >= nextPrint) {
    printTimeOfThePlayer();
    nextPrint += 1000;
  }
}

void printTime(unsigned long int time) {
  unsigned long seconds = time / 1000;
  unsigned long minutes = seconds / 60;
  seconds %= 60;

  if (minutes < 10) {
    Serial.print("0");
  }
  Serial.print(minutes);
  Serial.print(":");
  if (seconds < 10) {
    Serial.print("0");
  }
  Serial.print(seconds);
}

void printTimeOfThePlayer() {
  Serial.print("Brancas ");
  printTime(timeWhite);
  Serial.print(" VS ");
  printTime(timeBlack);
  Serial.println(" Pretas");
}

void btnWhitePlayer() {
  if(!fistClick && !blackBtnUpper && whiteBtnUpper){
  	timeBlack += 3000;
  }
  fistClick = false;
  baseLine = millis();
  timemReference = baseLine;
  blackBtnUpper = true;
  whiteBtnUpper = false;
}

void btnBlackPlayer() {
  
  baseLine = millis();
  timemReference = baseLine;
  
  if(blackBtnUpper && !whiteBtnUpper){
  	timeWhite += 3000;
  }
  
  
  blackBtnUpper = false;
  whiteBtnUpper = true;
}
