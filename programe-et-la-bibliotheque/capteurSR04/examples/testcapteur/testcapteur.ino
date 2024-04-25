#include "capteurSR04.hpp"
/* 
 * Code d'exemple pour un capteur à ultrasons HC-SR04.
 */

/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const byte buz= 6;
long measure;
int distance_mm;

/** Fonction setup() */
void setup() {
   
  /* Initialise le port série */
  Serial.begin(115200);
  init2(TRIGGER_PIN,ECHO_PIN);
}
 
/** Fonction loop() */
void loop() {

  declencheImpulsion(TRIGGER_PIN);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
   measure = mesureTemps (ECHO_PIN);
  /* 3. Calcul la distance à partir du temps mesuré */
    distance_mm =calculDist (measure);
  /* Affiche les résultats en mm, cm et m */
   afficher (distance_mm);

   noTone(buz);
   if (distance_mm < 200) {
    tone(buz, 880);
  } else if (distance_mm >= 200 && distance_mm <= 1000) {
    tone(buz, 440); 
  } else {
    noTone(buz); 
  }
  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(500);
}
