double const THRESHOLD(20.0);//Spike threshold
double const TAU(20.0) ;//constant of time
double const C(1);
double const RESISTANCE= TAU/C;// Membrane Resistance
double const TREFRACTORY=(2.0);//Time refractory
double const h(0.1);// pas
long const REF_STEPS = TREFRACTORY/h; 
int const DELAY(15);//Delay in steps
double const VRESET(0.0);//value of Membrane potential after refactory time
long const NE(10000); // number of connection of excitaroy neurone
long const NI(2500); //number of connection of inhibitory neurone
double const JE(0.1);// constante of weight of connection of an excitatory neurone
double const JI(-0.5);// constant of weight of connection of an inhibitory neurone
double const g(5);
long const CE(NE*0.1);//connections from the excitatory neurons in the network
long const CI(NI*0.1);//connections from the inhibitory neurons in the network
long const C_EXT(CE);// number of connections from outside the network
long const eta(2); //
double const NU_thr(0.01);//stimulus par ms THRESHOLD/ (CE*J*TAU)
double const NU_ext(eta*CE*NU_thr);//additional random input from the rest of the brain.
