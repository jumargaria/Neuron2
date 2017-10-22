double const THRESHOLD(20.0);//Spike threshold
double const TAU(20.0) ;//constant of time
double const C(1);
double const RESISTANCE= TAU/C;// Resistance membranaire
double const TREFRACTORY=(2.0);//Time refractory
double const h(0.1);// pas
long const REF_STEPS = TREFRACTORY/h; // constant of time below which the Membrane potential is refractory
double const J(0.1);// constante d'intensité
int const D(4);//Delay in steps
double const VRESET(0.0);//Membrane potential after refactory time
