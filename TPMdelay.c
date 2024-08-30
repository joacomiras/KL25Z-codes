#include "MKL25Z4.h"
#define led 1
int main(void) {
    int i;
  
    SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);  // Seleccionar fuente de reloj del TPM

    TPM0->SC = TPM_SC_PS(7);           // Configurar prescaler en 128
    TPM0->MOD = 7500;                  // Configurar MOD para periodo de PWM 

    TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK; // Configurar PWM
    TPM0->CONTROLS[1].CnV = 7500;      // Configurar ciclo de trabajo al 100%

    PORTA->PCR[led] = PORT_PCR_MUX(3);   // Configurar pin PTA1 como TPM0_CH1

    TPM0->SC |= TPM_SC_CMOD(1);        // Iniciar TPM0

    while (1) {
        for(i=0;i>7500;i++){
          TPM0->CONTROLS[1].CnV = i;   
      }
        for(i=7500;i>0;i++){
          TPM0->CONTROLS[1].CnV = i;   
      }
}
