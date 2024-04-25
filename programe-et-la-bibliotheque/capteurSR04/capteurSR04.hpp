#ifndef capteurSR04_HPP_INCLUDED
#define capteurSR04_INCLUDED
int init2(int TRIGGER_PIN,int ECHO_PIN);
int mesureTemps (int ECHO_PIN);
int calculDist (long measure);
void afficher (int distance_mm);
int declencheImpulsion(int TRIGGER_PIN);
#endif // MATH_HPP_INCLUDED
