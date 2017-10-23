double const THRESHOLD(20.0);//Spike threshold
double const TAU(20.0) ;//constant of time
double const C(1);
double const RESISTANCE= TAU/C;// Resistance membranaire
double const TREFRACTORY=(2.0);//Time refractory
double const h(0.1);// pas
long const REF_STEPS = TREFRACTORY/h; 
int const D(15);//Delay in steps
double const VRESET(0.0);//Membrane potential after refactory time
long const NE(10000);
long const NI(2500);
double const JE(0.1);// constante d'intensité
double const JI(-0.5);// constante d'intensité
double const g(2);
double const NU_thr(1/100);//stimulus par ms
double const NU_ext(g*NU_thr);
long const CE(NE*(1/100));
long const CI(NI*(1/100));
long const C_EXT(CE);
