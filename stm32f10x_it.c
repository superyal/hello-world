void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_FLAG_RXNE)!=RESET)
	{
		static unsigned char k=0;
		USART_ClearFlag(USART1,USART_FLAG_RXNE);
		k++;
		if(k%3==1) hour=USART_ReceiveData(USART1);
		else if(k%3==2) minute=USART_ReceiveData(USART1);
		else second=USART_ReceiveData(USART1);
		USART_SendData(USART1,k);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	}
}

	