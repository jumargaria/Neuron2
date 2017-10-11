double const THRESHOLD(20.0);//Spike threshold
double const TAU(20.0) ;//constant of time
double const C(1);
double const RESISTANCE= TAU/C;// Resistance membranaire
double const TREFRACTORY=(2.0);//Time refractory
double const h(0.1);// pas
long const REF_STEPS = TREFRACTORY/h; 
double const J(2);// constante d'intensité
int const D(4);//Delay in steps
