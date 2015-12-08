/*===== Include this in .h file=== */





/*====================================================*/
/* Include the following in .c file */


/* This is initalize the external reference clock */
void initialize_external_clock(void){

		/*===== Enable External clock and PLL =========*/
		/* Enable external reference clock */
			OSC0.CR = 0x80;  /* Set bit 7 high */
		
		/* Select the source for the external reference clock */
			MCG.C2 &= 0xFB;   /* Clear bit 2 */
		
		/* Set PLL Engaged External Mode, aka PEE mode , as clock source for MCGOUTCLK*/
			MCG.C1 &= 0x3F;  /* Clear bits 6 and 7 */
		
		/* Select Reference clock source to external */
			MCG.C1 &= 0xF8;  /* Clear bit 2 */
		
		/* Enable PLL as an output */
			MCG_C6 |= 0x40;	/*Set bit 6 */
		
		/*====== Supply Entral clock to the core ==============*/
			SIM.CLKDIV1 &= 0x0FFFFFFF  /* Divide External clock by 1 */
}
 
int main(void) {
initialize_external_clock();
}