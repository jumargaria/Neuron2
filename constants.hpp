double const THRESHOLD(20.0);//!Spike threshold
double const TAU(20.0) ;//!constant of time
double const C(1);//!
double const RESISTANCE= TAU/C;//! Membrane Resistance
double const TREFRACTORY=(2.0);//! refractory Time in ms
double const h(0.1);//! step
unsigned long const REF_STEPS = TREFRACTORY/h; //!refractory time in step
unsigned int const DELAY(15);//! Delay in steps
double const VRESET(0.0);//! Membrane value potential after refactory time
unsigned long const NE(10000); //! number of connection of excitaroy neurone
unsigned long const NI(2500); //!number of connection of inhibitory neurone
double const g(5);//! JI/JE
double const JE(0.1);//! constante of weight of connection of an excitatory neurone
double const JI(-g*JE);//! constant of weight of connection of an inhibitory neurone
unsigned long const eta(2); //!
double const NU_thr(0.01);//!stimulus par ms THRESHOLD/ (CE*J*TAU)
double const NU_ext(eta*NU_thr);//!additional random input from the rest of the brain.
//*CE comment faire ?
