#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cal.h"

int main()
{
	char cal[20];
	char arrayb[20];
	char hexa[20];
	char ch;
	float a=0, b=0;
	int hex1, hex2;
	int dec1, dec2;
	char op1;
	char op2[3];
	int i=0, j=0, h=0, k1=0, k2=0, flag_op=0, x=0;
	char n[20];
	int index=0;
	int p=0;
	int d=0;
	char modenum[3];
	float out1=0;
	int out2=0;

	while(1)
	{	
		printf("1: standard, 2: oct, 3: dec, q: exit >> ");
		fgets(modenum,sizeof(modenum),stdin);

		
		if(modenum[0] == 'q')
		{
                    printf("program exit\n");
                    break;
                }
                else if(modenum[0] != 'q' && modenum[0] != '1' && modenum[0] != '2' && modenum[0] != '3')
                {
                    printf("try again1\n");
                    continue;
                }


		switch(modenum[0])
		{
		    case '1':{
			while(1){
			       
			    flag_op=0;		
			    n[0]='\0';
			    modenum[0]='\0';
			    printf("calculate formula: ");

			    fgets(cal,sizeof(cal),stdin);

			    if(cal[1] == '\n' && cal[0] == 'q')
			    {	
				printf("program exit\n");
				break;
			    }
			    else if(cal[1] == '\n' && cal[0] != 'q')
			    {
				printf("%c %c\n",cal[0],cal[1]);
				printf("try again1\n");
				continue;
			    }
			    
			    for(i = 0; i < 20; i++)
			    {
			    	if(cal[i] == ' ' && index == 0)
			    	{	
			    		index++;
			    		a=atof(cal);
			    		op1 = cal[i+1];
	
			    		if(cal[i+2] != ' ')
			    		{		
			    		    printf("try again2\n");
			    		    flag_op=1;
			    		}
			    	
			    	}    
			        else if(cal[i] == ' ' && index == 1)
			    	{
			    	    for(h = i + 1; h <= 20; h++)
			            {
			        	if(cal[h] == '\0')
			    		    break;
	
	                                    arrayb[p] = cal[h];
	                                    p++;
			    	    }
	
			    	    b=atof(arrayb);
			    	    p=0;
			    	    arrayb[0]='\0';
			    	    index=0;
			    	    break;
			    	}
			          
			    }
			    
		    	    
			    if(isNum(a) == 0)
	    		    {
			        printf("try again 5\n");
			        continue;
	    		    }
	
			    if(isNum(b) == 0)
			    {
			        printf("try agian 6\n");
			        continue;
			    }
	
			    if(flag_op == 1)
			    {
			        printf("op error\n");
			        continue;
			    }
	
			    if(((a < -100000) || (a > 100000)) && ((b < -100000) || (b > 100000)))
	      		    {
			        printf("try again 4\n\n");
			        continue;
		            }
	
			    printf("output: ");
			    if(op1 == '+')
			    {	
			    	out1=add(a,b);
	
			    	if(isInt(out1) != 1)
			    	{
			    	    printf("%.0f\n\n",out1);
			    	    continue;		
		       	            }
	
			    	printf("%.3f\n",out1);
			    }
			    else if(op1 == '-')
			    {
			    	out1=sub(a,b);
			    	
	                            if(isInt(out1) != 1)
	                            {
	                                printf("%.0f\n\n",out1);
	                                continue;
	                            }             
	
			    	printf("%.3f\n",out1);
	                    }
			    else if(op1 == '*')
			    {
	                            out1=mul(a,b);
	
	                            if(isInt(out1) != 1)
	                            {
	                                printf("%.0f\n\n",out1);
	                                continue;
	                            }
		
	
	                            printf("%.3f\n",out1);
			    }
			    else if(op1 == '/')
			    {
	                            out1=divs(a,b);
	
	                            if(isInt(out1) != 1)
	                            {
	                                printf("%.0f\n\n",out1);
	                                continue;
	                            }
	                            printf("%.3f\n",out1);
	                    }
			    else 
			            printf("try again3\n");
			    
			    cal[0]='\0';
			    printf("\n");
			}
			        
			break;
			   }
		
		    case '2':{
			    
			while(1)
			{
			    flag_op=0;	
			    modenum[0]='\0';
			    cal[0]='\0';
			    index=0;
		    
                            printf("calculate formula: ");

                            fgets(cal,sizeof(cal),stdin);

			    for(i =0; i < strlen(cal); i++)
			    {
				printf("%c",cal[i]);
			    }
	    
			    if(cal[1] == '\n' && cal[0] == 'q')
                            {
                                printf("program exit\n");
                                break;
                            }
                            else if(cal[1] == '\n' && cal[0] != 'q')
                            {
                                printf("try again1\n");
                                continue;
                            }
			    
			    for(i = 0; i < 20; i++)
			    {
				if(cal[i] == ' ' && index == 0)
				{   	
					    index++;
					    printf("index: %d\n",index);
					
					    for(j = 0; j < i; j++)
					    {
						hexa[j] = cal[j];
						if(hexa[j] != '<' && hexa[j] != '>' && hexa[j] != '0' && hexa[j] != '1' && hexa[j] != '2' && hexa[j] != '3' && hexa[j] != '4' && hexa[j] != '5' && hexa[j] != '6' && hexa[j] != '7' && hexa[j] != '8' && hexa[j] != '9' && hexa[j] != 'A' && hexa[j] != 'B' && hexa[j] != 'C' && hexa[j] != 'D' && hexa[j] != 'E' && hexa[j] != 'F')
						k1++;	
					    }    
					printf("hexa: ");			
					for(int t=0; t<strlen(hexa);t++)
					    printf("%c", hexa[t]);
					printf("\n");
					hex1=strtol(hexa,NULL,16);
					if((cal[i+1] == '<' && cal[i+2] == '<') || (cal[i+1] == '<' && cal[i+2] == '<'))
					{
					    op2[0]=cal[i+1];
					    op2[1]=cal[i+2];

					    if(cal[i+3] != ' ')
					    {		
						printf("try again2\n");
						flag_op=1;
					    }				
					}
					else				    
					    op2[0] = cal[i+1];
	
				}    
			    	else if(cal[i] == ' ' && index == 1)
				{
				    for(h = i + 1; h <= 20; h++)
			      	    {
			    		if(cal[h] == '\0')
					    break;
	
	                                arrayb[p] = cal[h];
	                                
					if(arrayb[p] != '<' && arrayb[p] != '>' && arrayb[p] != '0' && arrayb[p] != '1' && arrayb[p] != '2' && arrayb[p] != '3' && arrayb[p] != '4' && arrayb[p] != '5' && arrayb[p] != '6' && arrayb[p] != '7' && arrayb[p] != '8' && arrayb[p] != '9' && arrayb[p] != 'A' && arrayb[p] != 'B' && arrayb[p] != 'C' && arrayb[p] != 'D' && arrayb[p] != 'E' && arrayb[p] != 'F')
                                                k2++;

					p++;
				    }
                                                
				}

				    hex2=strtol(arrayb,NULL,16);
				    p=0;
				    arrayb[0]='\0';
				    index=0;
				    break;
			      
						
			}
		/*	 if(isIntHex(hex1) == 0 || isIntHex(hex2) == 0)
                         {
                             printf("try again 5\n");
                             continue;
			 } 
*/
			printf("%d %d\n",hex1,hex2); 

			    
			 if(k1 > 0 || k2 > 0)
			 {
			     printf("try again 7\n");
			     k1=0;
			     k2=0;
			     continue;
			 }
 
                         if(flag_op==1)
                         {
                             printf("op error\n");
                             continue;
                         }
 
                         if(((hex1 < -100000) || (hex1 > 100000)) || ((hex2 < -100000) || (hex2 > 100000)))
                         {
                             printf("try again 4\n\n");
                             continue;
                         }
 
                         printf("output: ");
			 if(strlen(op2)==1)
			 {
			    if(op2[0] == '+')
                            {
                                    out2=addHexDec(hex1,hex2);
                                     printf("%x\n",out2);
                            }
                            else if(op2[0] == '-')
                            {
                                    out2=subHexDec(hex1,hex2);
                                    printf("%x\n",out2);
                            }
                            else if(op2[0] == '*')
                            {
                                    out2=mulHexDec(hex1,hex2);
                                    printf("%x\n",out2);
                            }
                            else if(op2[0] == '/')
                            {
                                    out2=divsHexDec(hex1,hex2);
                                    printf("%x\n",out2);
                            }
                            else
                                  printf("try again3\n");
			 }
			 else if(strlen(op2) == 2)
			 {
			     if(op2[0] == '<')
			     {
				    out2=shftLeft(hex1,hex2);
				    printf("%x\n",out2);
			     }
			     else if(op2[0] == '>')
			     {
				    out2=shftRight(hex1,hex2);
				    printf("%x\n",out2);
			     }

			 }

                         cal[0]='\0';
			 hexa[0]='\0';
			 op2[0]='\0';
                         printf("\n");
			}
 
                         break;		  
			   }	 

		    case '3':{
			    
			while(1)
			{			
			    flag_op=0;	
			    modenum[0]='\0';	    
                            printf("calculate formula: ");

                            fgets(cal,sizeof(cal),stdin);
			    if(cal[1] == '\n' && cal[0] == 'q')
                            {
                                printf("program exit\n");
                                break;
                            }
                            else if(cal[1] == '\n' && cal[0] != 'q')
                            {
                                printf("try again1\n");
                                continue;
                            }


			    for(i = 0; i < 20; i++)
			    {
				    if(cal[i] == ' ' && index == 0)
				    {	
					    index++;
					    dec1=atoi(cal);

					    for(j = 0; j < i; j++)
					    {
						hexa[j] = cal[j];
					    
					    }    
					    
					    if((cal[i+1] == '<' && cal[i+2] == '<') || (cal[i+1] == '>' && cal[i+2] == '>'))
					    {
						op2[0]=cal[i+1];
						op2[1]=cal[i+2];

						if(cal[i+3] != ' ')
						{		
						    flag_op=1;
						}				
					    }
					    else				    
						op2[0] = cal[i+1];
	
				    }    
				   else if(cal[i] == ' ' && index == 1)
				   {
					for(h = i + 1; h <= 20; h++)
					{
					  if(cal[h] == '\0')
						break;
	
					    arrayb[p] = cal[h];
					    p++;
					}
	
	    			    dec2=atoi(arrayb);
	    			    p=0;
	    			    arrayb[0]='\0';
	    			    index=0;
	    			    break;
	    			  }       
	    					
			  }
			  if(isIntDec(dec1) == 0 || isIntDec(dec2) == 0)
                          {
                                 printf("try again 5\n");
                                 continue;
			  } 
 
                          if(flag_op == 1)
                          {
                                 printf("op error\n");
                                 continue;
			  }
 
                          if(((dec1 < -100000) || (dec1 > 100000)) || ((dec2 < -100000) || (dec2 > 100000)))
                          {
                                 printf("try again 4\n\n");
                                 continue;
                          }
 
                          printf("output: ");
			  if(strlen(op2) == 1)
			  {
				if(op2[0] == '+')
				{
                                        out2=addHexDec(dec1,dec2);
                                        printf("%d\n",out2);
				}
                                else if(op2[0] == '-')
                                {
                                        out2=subHexDec(dec1,dec2);
                                        printf("%d\n",out2);
                                }
                                else if(op2[0] == '*')
                                {
                                        out2=mulHexDec(dec1,dec2);
                                        printf("%d\n",out2);
                                }
                                else if(op2[0] == '/')
                                {
                                        out2=divsHexDec(dec1,dec2);
                                        printf("%d\n",out2);
                                }
                                else
                                      printf("try again3\n");
			  }
			  else if(strlen(op2) == 2)
			  {
	    		     if(op2[0] == '<')
	    		     {
	    			    out2=shftLeft(dec1,dec2);
	    			    printf("%d\n",out2);
	    		     }
	    		     else if(op2[0] == '>')
	    		     {
	    			    out2=shftRight(dec1,dec2);
	    			    printf("%d\n",out2);
	    		     }

	    		  }

			 cal[0]='\0';
	    		 hexa[0]='\0';
	    		 op2[0]='\0';
			 printf("\n");
			}
 
                         break;
			   	     
		    }	
		}

	}	
    	return 0;
}

