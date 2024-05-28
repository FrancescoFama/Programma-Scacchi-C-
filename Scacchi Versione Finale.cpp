/* Inclusione delle librerie necessarie per il corretto funzionamento del programma*/

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <cmath>


using namespace std;
int main()
{
/* Dichiarazione delle variabili*/
int const DIMR=8,DIMC=8,DIMVET=4;
int Matrice[DIMR][DIMC],vetN[DIMVET],vetB[DIMVET];
int r,c,rIN,cIN,rFI,cFI,ERRORE,i,SOSTITUZIONE,somma,EN_PASSANT,ARROCCO_NO;
char mossa;
bool re,EFFETTUATA;
cout<<endl<<"          Il gioco degli Scacchi!"<<endl<<endl;

/*Inizio del codice */
for(r=0;r<=DIMR-1;r++)
   {
   	cout<<"   "<<r<<" ";
   }
cout<<endl;

for (r=0;r<=DIMR-1;r++)
 {
 for (c=0;c<=DIMC-1;c++)
	 {
	 if(c==0)
	   {
	   cout<<r<<"  ";
	   }
	 if(r==0&&c==0||r==0&&c==7)
	   {
	   Matrice[r][c]=3;
	   cout<<"TN | ";
	   }
	 if(r==7&&c==0||r==7&&c==7)
	   {
	   Matrice[r][c]=9;
	   cout<<"TB | ";
	   }
	 if(r==0&&c==1||r==0&&c==6)
	   {
	   Matrice[r][c]=2;
	   cout<<"CN | ";
	   }
	 if(r==7&&c==1||r==7&&c==6)
	   {
	   Matrice[r][c]=8;
	   cout<<"CB | ";
	   }
	 if(r==0&&c==2||r==0&&c==5)
	   {
	   Matrice[r][c]=6;
	   cout<<"AN | ";
	   }
	 if(r==7&&c==2||r==7&&c==5)
	   {
	   Matrice[r][c]=12;
	   cout<<"AB | ";
	   }
	 if(r==1)
	   {
	   Matrice[r][c]=1;
	   cout<<"PN | ";
	   }
	 if(r==6)
	   {
	   Matrice[r][c]=7;
	   cout<<"PB | ";
	   }
	 if(r==0&&c==4)
	   {
	   Matrice[r][c]=4;
	   cout<<"RN | ";
	   }
	 if(r==7&&c==4)
	   {
	   Matrice[r][c]=10;
	   cout<<"RB | ";
	   }
	 if(r==0&&c==3)
	   {
	   Matrice[r][c]=5;
	   cout<<"rN | ";
	   }
	 if(r==7&&c==3)
	   {
	   Matrice[r][c]=11;
	   cout<<"rB | ";
	   }
	 if(r==2||r==3||r==4||r==5)
	   {
	   Matrice[r][c]=0;
	   cout<<"   | ";
	   }
	 }
	    
 cout<<endl;
	
 }

re=true;
/*re=true significa che il Re è vivo*/
mossa='B';
while(re==true)
     {
     ARROCCO_NO=0;
     ERRORE=0;
     EFFETTUATA=false;
     cout<<endl;
     
     if(mossa=='N')
       {
       	cout<<"TURNO DEI NERI"<<endl;
	   }
     else
	   {
	   cout<<"TURNO DEI BIANCHI"<<endl;
	   }
	   
     cout<<endl;
     cout<<"Inserire le cordinate iniziali e finali per fare la mossa"<<endl;
     
	 cout<<"Iniziali:  "<<endl;
	 cin>>rIN;
	 cin>>cIN;
	 cout<<endl;
	 
	 if(Matrice[rIN][cIN]==0)
	   {
	   cout<<"La casella selezionata risulta vuota"<<endl;
	   ERRORE++;
	   }
	 else
	   {
	   if(mossa=='B'&&Matrice[rIN][cIN]<7||mossa=='N'&&Matrice[rIN][cIN]>6)
	   {
	   cout<<"NON E' IL TUO TURNO"<<endl;
	   ERRORE++;
	   }
	 else
	   {
	   cout<<endl;
	   cout<<"Finali:  "<<endl;
	   cin>>rFI;
	   cin>>cFI;
	   cout<<endl; 
	   
     if(rIN==rFI&&cIN==cFI)
	   {
	   ERRORE++;
	   }
	 else
	   {
	     /*Verifico che le celle inserite nella mossa esistano nella scacchiera*/
		 if(rIN>=0&&rIN<=7&&cIN>=0&&cIN<=7&&rFI>=0&&rFI<=7&&cFI>=0&&cFI<=7)
		   {
             /*Se c'è un ARROCCO fatto da pedine NERE*/
             if(Matrice[rIN][cIN]==3&&Matrice[rFI][cFI]==4||Matrice[rIN][cIN]==4&&Matrice[rFI][cFI]==3)
               {
               if(rIN==0&&cIN==0&&rFI==0&&cFI==4||rIN==0&&cIN==7&&rFI==0&&cFI==4||rFI==0&&cFI==0&&rIN==0&&cIN==4||rFI==0&&cFI==7&&rIN==0&&cIN==4)
			     {
			     if(cIN<cFI)
			       {
			       for(c=cIN+1;c<cFI;c++)
			          {
			          if(Matrice[rIN][c]!=0)
			            {
			            ARROCCO_NO=1;
						}
					  }
					if(ARROCCO_NO==0&&(Matrice[rIN][cIN]==3||Matrice[rFI][cFI]==3))
					  {
					  if(cIN==0)
					    {
					    Matrice[rIN][cIN+3]=3;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cFI-2]=4;
					    Matrice[rFI][cFI]=0;
						}
					  else
					    {
					    Matrice[rIN][cFI-2]=3;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cIN+2]=4;
					    Matrice[rFI][cFI]=0;
						}
					  }
				   }
				   
			     if(cIN>cFI)
			       {
			       for(c=cIN-1;c>cFI;c--)
			          {
			          if(Matrice[rIN][c]!=0)
			            {
			            ARROCCO_NO=1;
						}
					  }
					if(ARROCCO_NO==0&&(Matrice[rIN][cIN]==3||Matrice[rFI][cFI]==3))
					  {
					  if(cIN==0)
					    {
					    Matrice[rIN][cIN+3]=3;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cFI-2]=4;
					    Matrice[rFI][cFI]=0;
						}
					  else
					    {
					    Matrice[rIN][cFI-2]=3;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cIN+2]=4;
					    Matrice[rFI][cFI]=0;
						}
					  }
				   }
				 }
			   }
		   	
		   	/*Se c'è un ARROCCO fatto da pedine BIANCHE*/
             if(Matrice[rIN][cIN]==9&&Matrice[rFI][cFI]==10||Matrice[rIN][cIN]==10&&Matrice[rFI][cFI]==9)
               {
               if(rIN==7&&cIN==0&&rFI==7&&cFI==4||rIN==7&&cIN==7&&rFI==7&&cFI==4||rFI==7&&cFI==0&&rIN==7&&cIN==4||rFI==7&&cFI==7&&rIN==7&&cIN==4)
			     {
			     if(cIN<cFI)
			       {
			       for(c=cIN+1;c<cFI;c++)
			          {
			          if(Matrice[rIN][c]!=0)
			            {
			            ARROCCO_NO=1;
						}
					  }
					if(ARROCCO_NO==0&&(Matrice[rIN][cIN]==9||Matrice[rFI][cFI]==9))
					  {
					  if(cIN==0)
					    {
					    Matrice[rIN][cIN+3]=9;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cFI-2]=10;
					    Matrice[rFI][cFI]=0;
						}
					  else
					    {
					    Matrice[rIN][cFI-2]=9;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cIN+2]=10;
					    Matrice[rFI][cFI]=0;
						}
					  }
				   }
				   
			     if(cIN>cFI)
			       {
			       for(c=cIN-1;c>cFI;c--)
			          {
			          if(Matrice[rIN][c]!=0)
			            {
			            ARROCCO_NO=1;
						}
					  }
					if(ARROCCO_NO==0&&(Matrice[rIN][cIN]==9||Matrice[rFI][cFI]==9))
					  {
					  if(cIN==0)
					    {
					    Matrice[rIN][cIN+3]=9;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cFI-2]=10;
					    Matrice[rFI][cFI]=0;
						}
					  else
					    {
					    Matrice[rIN][cFI-2]=9;
					    Matrice[rIN][cIN]=0;
					    Matrice[rIN][cIN+2]=10;
					    Matrice[rFI][cFI]=0;
						}
					  }
				   }
			     } 
		       }  
		   	
		     /*Se si considera un pedone NERO*/
		     if(Matrice[rIN][cIN]==1)
			   {
			   if(EN_PASSANT==1)
			     {
			     if(rFI==rIN+1&&cFI==cIN+1&&Matrice[rFI-1][cFI]==7||rFI==rIN+1&&cFI==cIN-1&&Matrice[rFI-1][cFI]==7)
			       {
			       Matrice[rFI][cFI]=1;
			       Matrice[rIN][cIN]=0;
			       Matrice[rFI-1][cFI]=0;
			       }
			     }
			     
			   if(cIN+1==cFI&&rIN+1==rFI||cIN-1==cFI&&rIN+1==rFI)
			     {
			     if(Matrice[rFI][cFI]!=0)
			       {
			       Matrice[rFI][cFI]=1;
				   Matrice[rIN][cIN]=0;
				   EN_PASSANT=0;
				   }
				 }
				else
				 {
				 /*Se si parte dalla riga uno*/	 
				   if(rIN==1)
				     {
				     if(rFI==rIN+1&&cFI==cIN)
				 	   {
					   Matrice[rFI][cFI]=1;
					   Matrice[rIN][cIN]=0;
					   EN_PASSANT=0;
					   }
					 else
				 	   {
				 	   	if(rFI==rIN+2&&cFI==cIN)
						   {
						   Matrice[rFI][cFI]=1;
						   Matrice[rIN][cIN]=0;
						   EN_PASSANT=1;
						   }
						else
						   {
						   ERRORE++;
						   EN_PASSANT=0;
						   }
				 	   }
				     }
				   else
				     {
				     if(rFI==rIN+1&&cFI==cIN)
					   {
					   Matrice[rFI][cFI]=1;
					   Matrice[rIN][cIN]=0;
					   EN_PASSANT=0;
					   }   
					 else	 
					   {
					   ERRORE++;
					   }  
				     }  
				 }
			      
			   }
			   
		   /*Se si considera un pedone BIANCO*/
		     if(Matrice[rIN][cIN]==7)
			   {
			   if(EN_PASSANT==1)
			     {
			     if(rFI==rIN-1&&cFI==cIN-1&&Matrice[rFI+1][cFI]==1||rFI==rIN-1&&cFI==cIN+1&&Matrice[rFI+1][cFI]==1)
			       {
			       Matrice[rFI][cFI]=7;
			       Matrice[rIN][cIN]=0;
			       Matrice[rFI+1][cFI]=0;
			       }
			     }
			     
			   if(cIN+1==cFI&&rIN-1==rFI||cIN-1==cFI&&rIN-1==rFI)
			     {
			     if(Matrice[rFI][cFI]!=0)
			       {
			       Matrice[rFI][cFI]=7;
				   Matrice[rIN][cIN]=0;
				   EN_PASSANT=0;
				   }
				 }
				else
				 {
				 /*Se si parte dalla riga uno*/
				   if(rIN==6)
				     {
				     if(rFI==rIN-1&&cFI==cIN)
				 	   {
					   Matrice[rFI][cFI]=7;
					   Matrice[rIN][cIN]=0;
					   EN_PASSANT=0;
					   }
					 else
				 	   {
				 	   	if(rFI==rIN-2&&cFI==cIN)
						   {
						   Matrice[rFI][cFI]=7;
						   Matrice[rIN][cIN]=0;
						   EN_PASSANT=1;
						   }
						else
						   {
						   ERRORE++;
						   EN_PASSANT=0;
						   }
				 	   }
				     }
				   else
				     {
				     if(rFI==rIN-1&&cFI==cIN)
					   {
					   Matrice[rFI][cFI]=7;
					   Matrice[rIN][cIN]=0;
					   EN_PASSANT=0;
					   }   
					 else	 
					   {
					   ERRORE++;
					   }  
				     }  
				 }  
			   }
			   
		   /*Se si considera una torre NERA*/	   
		     if(Matrice[rIN][cIN]==3)
			   {
			   EN_PASSANT=0;
			   /*PER LE RIGHE*/
			   if(rIN==rFI)
			     {
			     if(cIN+1<cFI)
			       {
				   for(c=cIN+1;c<cFI;c++)
				      {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI-1)
						  {
						  Matrice[rFI][cFI]=3;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN+1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=3;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(cIN-1>cFI)
			       {
				   for(c=cIN-1;c>cFI;c--)
			          {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI+1)
						  {
						  Matrice[rFI][cFI]=3;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN-1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=3;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			     }
			     
			   /*PER LE COLONNE*/
			   
			   if(cIN==cFI)
				 {
				 if(rIN+1<rFI)
			       {
				   for(r=rIN+1;r<rFI;r++)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI-1)
						  {
						  Matrice[rFI][cFI]=3;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(rIN+1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=3;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(rIN-1>rFI)
			       {
				   for(r=rIN-1;r>rFI;r--)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI+1)
			              {
			              Matrice[rFI][cFI]=3;
			              Matrice[rIN][cIN]=0;
			              }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
				   else
			       {
			       	if(rIN-1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=3;
					  Matrice[rIN][cIN]=0;
				      }
				   }     
				     
				 }
		       }
		    
		    /*Se si considera una torre BIANCA*/	   
		     if(Matrice[rIN][cIN]==9)
			   {
			   EN_PASSANT=0;
			   /*PER LE RIGHE*/
			   if(rIN==rFI)
			     {
			     if(cIN+1<cFI)
			       {
				   for(c=cIN+1;c<cFI;c++)
				      {
			          if(Matrice[rIN][c]==0)
			            {
			            
			            if(c==cFI-1)
						  {
						  Matrice[rFI][cFI]=9;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN+1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=9;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(cIN-1>cFI)
			       {
				   for(c=cIN-1;c>cFI;c--)
			          {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI+1)
						  {
						  Matrice[rFI][cFI]=9;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN-1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=9;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			     }
			     
			   /*PER LE COLONNE*/
			   
			   if(cIN==cFI)
				 {
				 if(rIN+1<rFI)
			       {
				   for(r=rIN+1;r<rFI;r++)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI-1)
						  {
						  Matrice[rFI][cFI]=9;
						  Matrice[rIN][cIN]=0;
						  }
						
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(rIN+1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=9;
					  Matrice[rIN][cIN]=0;
				      }
				   }
				   
			     if(rIN-1>rFI)
			       {
				   for(r=rIN-1;r>rFI;r--)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI+1)
			              {
			              Matrice[rFI][cFI]=9;
			              Matrice[rIN][cIN]=0;
			              }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
				   else
			       {
			       	if(rIN-1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=9;
					  Matrice[rIN][cIN]=0;
				      }
				   }     
				     
				 }
		       }
		       
		    /*Se si considera un alfiere NERO*/
			if(Matrice[rIN][cIN]==6)
			  {
			  EN_PASSANT=0;
			  if(rIN-rFI>1&&cIN-cFI>1)
			    {
			    r=rIN-1;
				c=cIN-1;
			    /*DIREZIONE R- C-*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI+1)
			             {
			             Matrice[rFI][cFI]=6;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r--;
					     c--;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }	       	 
			    }
			    else
				{
				if(rIN-1==rFI&&cIN-1==cFI)
				  {
				  Matrice[rFI][cFI]=6;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
			    
			    
			    
			    if(rIN-rFI>1&&cIN-cFI<-1)
			    {
			    r=rIN-1;
			    c=cIN+1;
				/*DIREZIONE R- C+*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI+1)
			             {
			             Matrice[rFI][cFI]=6;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r--;
					     c++;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }
				}
				else
				{
				if(rIN-1==rFI&&cIN+1==cFI)
				  {
				  Matrice[rFI][cFI]=6;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
				
				
				
				if(rIN-rFI<-1&&cIN-cFI<-1)
			    {
			    r=rIN+1;
			    c=cIN+1;
			    /*DIREZIONE R+ C+*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI-1)
			             {
			             Matrice[rFI][cFI]=6;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r++;
					     c++;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }
				}
				else
				{
				if(rIN+1==rFI&&cIN+1==cFI)
				  {
				  Matrice[rFI][cFI]=6;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
				
				
				if(rIN-rFI<-1&&cIN-cFI>1)
			    {
			    r=rIN+1;
			    c=cIN-1;
			    /*DIREZIONE R+ C-*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI-1)
			             {
			             Matrice[rFI][cFI]=6;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r++;
					     c--;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }
			    
				}
				else
				{
				if(rIN+1==rFI&&cIN-1==cFI)
				  {
				  Matrice[rFI][cFI]=6;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
				if(Matrice[rIN][cIN]==6)
				  {
				  ERRORE++;
				  }
			  }
		         
				
			       
			/*Se si considera un alfiere BIANCO*/
			if(Matrice[rIN][cIN]==12)
			  {
			  EN_PASSANT=0;
			  if(rIN-rFI>1&&cIN-cFI>1)
			    {
			    r=rIN-1;
				c=cIN-1;
			    /*DIREZIONE R- C-*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI+1)
			             {
			             Matrice[rFI][cFI]=12;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r--;
					     c--;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }	       	 
			    }
			    else
				{
				if(rIN-1==rFI&&cIN-1==cFI)
				  {
				  Matrice[rFI][cFI]=12;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
			    
			    
			    
			    if(rIN-rFI>1&&cIN-cFI<-1)
			    {
			    r=rIN-1;
			    c=cIN+1;
				/*DIREZIONE R- C+*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI+1)
			             {
			             Matrice[rFI][cFI]=12;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r--;
					     c++;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }
				}
				else
				{
				if(rIN-1==rFI&&cIN+1==cFI)
				  {
				  Matrice[rFI][cFI]=12;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
				
				
				
				if(rIN-rFI<-1&&cIN-cFI<-1)
			    {
			    r=rIN+1;
			    c=cIN+1;
			    /*DIREZIONE R+ C+*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI-1)
			             {
			             Matrice[rFI][cFI]=12;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r++;
					     c++;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }
				}
				else
				{
				if(rIN+1==rFI&&cIN+1==cFI)
				  {
				  Matrice[rFI][cFI]=12;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
				
				
				if(rIN-rFI<-1&&cIN-cFI>1)
			    {
			    r=rIN+1;
			    c=cIN-1;
			    /*DIREZIONE R+ C-*/
			    while(EFFETTUATA==false&&ERRORE==0)
			         {
			         if(Matrice[r][c]==0)
			           {
			           if(r==rFI-1)
			             {
			             Matrice[rFI][cFI]=12;
			             Matrice[rIN][cIN]=0;
			             EFFETTUATA=true;
						 }
					   else
					     {
					     r++;
					     c--;
						 }
					   }
					 else
					   {
					   ERRORE++;
					   }
					 }
			    
				}
				else
				{
				if(rIN+1==rFI&&cIN-1==cFI)
				  {
				  Matrice[rFI][cFI]=12;
			      Matrice[rIN][cIN]=0;
			      EFFETTUATA=true;
				  }	
				}
			if(Matrice[rIN][cIN]==12)
				  {
				  ERRORE++;
				  }
			  }
		       
			
			/*Se si considera un cavallo NERO*/
			if(Matrice[rIN][cIN]==2)
			  {
			  EN_PASSANT=0;
			  if((rFI-rIN==2&&cFI-cIN==1)||(rFI-rIN==2&&cFI-cIN==-1)||(rFI-rIN==-2&&cFI-cIN==1)||(rFI-rIN==-2&&cFI-cIN==-1)||(rFI-rIN==1&&cFI-cIN==2)||(rFI-rIN==1&&cFI-cIN==-2)||(rFI-rIN==-1&&cFI-cIN==2)||(rFI-rIN==-1&&cFI-cIN==-2))
			    {
			    Matrice[rFI][cFI]=2;
			    Matrice[rIN][cIN]=0;
				}
			  else
			    {
			    ERRORE++;
			    }
			  }
			
			/*Se si considera un cavallo BIANCO*/
			if(Matrice[rIN][cIN]==8)
			  {
			  EN_PASSANT=0;
			  if((rFI-rIN==2&&cFI-cIN==1)||(rFI-rIN==2&&cFI-cIN==-1)||(rFI-rIN==-2&&cFI-cIN==1)||(rFI-rIN==-2&&cFI-cIN==-1)||(rFI-rIN==1&&cFI-cIN==2)||(rFI-rIN==1&&cFI-cIN==-2)||(rFI-rIN==-1&&cFI-cIN==2)||(rFI-rIN==-1&&cFI-cIN==-2)) 
			    {
				Matrice[rFI][cFI]=8;
			    Matrice[rIN][cIN]=0;
				}
			  else
			    {
			    ERRORE++;
			    }
			  }	
			  
			/*Se si considera un re NERO*/
			if(Matrice[rIN][cIN]==4)
			  {
			  EN_PASSANT=0;
			  if((rFI-rIN==1&&cFI-cIN==1)||(rFI-rIN==1&&cFI-cIN==-1)||(rFI-rIN==-1&&cFI-cIN==1)||(rFI-rIN==-1&&cFI-cIN==-1)||(rFI==rIN&&cFI-cIN==1)||(rFI==rIN&&cFI-cIN==-1)||(rFI-rIN==1&&cFI==cIN)||(rFI-rIN==-1&&cFI==cIN))
			    {
			    Matrice[rFI][cFI]=4;
			    Matrice[rIN][cIN]=0;
				}
			  }
			
			/*Se si considera un re BIANCO*/
			if(Matrice[rIN][cIN]==10)
			  {
			  EN_PASSANT=0;
			  if((rFI-rIN==1&&cFI-cIN==1)||(rFI-rIN==1&&cFI-cIN==-1)||(rFI-rIN==-1&&cFI-cIN==1)||(rFI-rIN==-1&&cFI-cIN==-1)||(rFI==rIN&&cFI-cIN==1)||(rFI==rIN&&cFI-cIN==-1)||(rFI-rIN==1&&cFI==cIN)||(rFI-rIN==-1&&cFI==cIN))
			    {
				Matrice[rFI][cFI]=10;
			    Matrice[rIN][cIN]=0;
				}
			  }	
			  
			/*Se si considera una regina NERA*/	   
		     if(Matrice[rIN][cIN]==5)
			   {
			   EN_PASSANT=0;
			   /*PER LE RIGHE*/
			   if(rIN==rFI)
			     {
			     if(cIN+1<cFI)
			       {
				   for(c=cIN+1;c<cFI;c++)
				      {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI-1)
						  {
						  Matrice[rFI][cFI]=5;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN+1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=5;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(cIN-1>cFI)
			       {
				   for(c=cIN-1;c>cFI;c--)
			          {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI+1)
						  {
						  Matrice[rFI][cFI]=5;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN-1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=5;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			     }
			     
			   /*PER LE COLONNE*/
			   
			   if(cIN==cFI)
				 {
				 if(rIN+1<rFI)
			       {
				   for(r=rIN+1;r<rFI;r++)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI-1)
						  {
						  Matrice[rFI][cFI]=5;
						  Matrice[rIN][cIN]=0;
						  }
						
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(rIN+1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=5;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(rIN-1>rFI)
			       {
				   for(r=rIN-1;r>rFI;r--)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI+1)
			              {
			              Matrice[rFI][cFI]=5;
			              Matrice[rIN][cIN]=0;
			              }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
				   else
			       {
			       	if(rIN-1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=5;
					  Matrice[rIN][cIN]=0;
				      }
				   }     
				     
				 }
				/*In obliquo*/ 
				 if(Matrice[rIN][cIN]==5)
				  {
				  if(rIN-rFI>1&&cIN-cFI>1)
				    {
				    r=rIN-1;
					c=cIN-1;
				    /*DIREZIONE R- C-*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI+1)
				             {
				             Matrice[rFI][cFI]=5;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r--;
						     c--;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }	       	 
				    }
				    else
					{
					if(rIN-1==rFI&&cIN-1==cFI)
					  {
					  Matrice[rFI][cFI]=5;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
				    
				    
				    
				    if(rIN-rFI>1&&cIN-cFI<-1)
				    {
				    r=rIN-1;
				    c=cIN+1;
					/*DIREZIONE R- C+*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI+1)
				             {
				             Matrice[rFI][cFI]=5;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r--;
						     c++;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }
					}
					else
					{
					if(rIN-1==rFI&&cIN+1==cFI)
					  {
					  Matrice[rFI][cFI]=5;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
					
					
					
					if(rIN-rFI<-1&&cIN-cFI<-1)
				    {
				    r=rIN+1;
				    c=cIN+1;
				    /*DIREZIONE R+ C+*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI-1)
				             {
				             Matrice[rFI][cFI]=5;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r++;
						     c++;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }
					}
					else
					{
					if(rIN+1==rFI&&cIN+1==cFI)
					  {
					  Matrice[rFI][cFI]=5;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
					
					
					if(rIN-rFI<-1&&cIN-cFI>1)
				    {
				    r=rIN+1;
				    c=cIN-1;
				    /*DIREZIONE R+ C-*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI-1)
				             {
				             Matrice[rFI][cFI]=5;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r++;
						     c--;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }
				    
					}
					else
					{
					if(rIN+1==rFI&&cIN-1==cFI)
					  {
					  Matrice[rFI][cFI]=5;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
				  }
				if(Matrice[rIN][cIN]==5)
				  {
				  ERRORE++;
				  }
		       }  
			
			/*Se si considera una regina BIANCA*/	   
		     if(Matrice[rIN][cIN]==11)
			   {
			   EN_PASSANT=0;
			   /*PER LE RIGHE*/
			   if(rIN==rFI)
			     {
			     if(cIN+1<cFI)
			       {
				   for(c=cIN+1;c<cFI;c++)
				      {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI-1)
						  {
						  Matrice[rFI][cFI]=11;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN+1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=11;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(cIN-1>cFI)
			       {
				   for(c=cIN-1;c>cFI;c--)
			          {
			          if(Matrice[rIN][c]==0)
			            {
			            if(c==cFI+1)
						  {
						  Matrice[rFI][cFI]=11;
						  Matrice[rIN][cIN]=0;
						  }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(cIN-1==cFI)
			       	  {
			       	  Matrice[rFI][cFI]=11;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			     }
			     
			   /*PER LE COLONNE*/
			   
			   if(cIN==cFI)
				 {
				 if(rIN+1<rFI)
			       {
				   for(r=rIN+1;r<rFI;r++)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI-1)
						  {
						  Matrice[rFI][cFI]=11;
						  Matrice[rIN][cIN]=0;
						  }
						
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
			       else
			       {
			       	if(rIN+1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=11;
					  Matrice[rIN][cIN]=0;
				      }
				   }
			       
			     if(rIN-1>rFI)
			       {
				   for(r=rIN-1;r>rFI;r--)
			          {
			          if(Matrice[r][cIN]==0)
			            {
			            if(r==rFI+1)
			              {
			              Matrice[rFI][cFI]=11;
			              Matrice[rIN][cIN]=0;
			              }
			            }
			          else
			            {
			            ERRORE++;
			            }
			          }
			       }
				   else
			       {
			       	if(rIN-1==rFI)
			       	  {
			       	  Matrice[rFI][cFI]=11;
					  Matrice[rIN][cIN]=0;
				      }
				   }     
				     
				 }
				 /*In obliquo*/
				 if(Matrice[rIN][cIN]==11)
				  {
				  if(rIN-rFI>1&&cIN-cFI>1)
				    {
				    r=rIN-1;
					c=cIN-1;
				    /*DIREZIONE R- C-*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI+1)
				             {
				             Matrice[rFI][cFI]=11;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r--;
						     c--;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }	       	 
				    }
				    else
					{
					if(rIN-1==rFI&&cIN-1==cFI)
					  {
					  Matrice[rFI][cFI]=11;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
				    
				    
				    
				    if(rIN-rFI>1&&cIN-cFI<-1)
				    {
				    r=rIN-1;
				    c=cIN+1;
					/*DIREZIONE R- C+*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI+1)
				             {
				             Matrice[rFI][cFI]=11;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r--;
						     c++;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }
					}
					else
					{
					if(rIN-1==rFI&&cIN+1==cFI)
					  {
					  Matrice[rFI][cFI]=11;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
					
					
					
					if(rIN-rFI<-1&&cIN-cFI<-1)
				    {
				    r=rIN+1;
				    c=cIN+1;
				    /*DIREZIONE R+ C+*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI-1)
				             {
				             Matrice[rFI][cFI]=11;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r++;
						     c++;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }
					}
					else
					{
					if(rIN+1==rFI&&cIN+1==cFI)
					  {
					  Matrice[rFI][cFI]=11;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
					
					
					if(rIN-rFI<-1&&cIN-cFI>1)
				    {
				    r=rIN+1;
				    c=cIN-1;
				    /*DIREZIONE R+ C-*/
				    while(EFFETTUATA==false&&ERRORE==0)
				         {
				         if(Matrice[r][c]==0)
				           {
				           if(r==rFI-1)
				             {
				             Matrice[rFI][cFI]=11;
				             Matrice[rIN][cIN]=0;
				             EFFETTUATA=true;
							 }
						   else
						     {
						     r++;
						     c--;
							 }
						   }
						 else
						   {
						   ERRORE++;
						   }
						 }				    
					}
					else
					{
					if(rIN+1==rFI&&cIN-1==cFI)
					  {
					  Matrice[rFI][cFI]=11;
				      Matrice[rIN][cIN]=0;
				      EFFETTUATA=true;
					  }	
					}
				  }
				if(Matrice[rIN][cIN]==11)
				  {
				  ERRORE++;
				  }
		       }  		     
       }
      else
       {
       ERRORE++;
	   }
	 }
	}
	   
		for(i=0;i<=DIMVET-1;i++)
		   {
		   vetN[i]=0;
		   vetB[i]=0;
		   }
		
		 for (r=0;r<=DIMR-1;r++)
			 {
			 for (c=0;c<=DIMC-1;c++)
				 {
				    if(Matrice[r][c]<7)
					  {
					  if(Matrice[r][c]==2)
					  vetN[0]=vetN[0]+1;
					  if(Matrice[r][c]==3)
					  vetN[1]=vetN[1]+1;
					  if(Matrice[r][c]==6)
					  vetN[2]=vetN[2]+1;
					  if(Matrice[r][c]==5)
					  vetN[3]=vetN[3]+1;
					  }
					else
					  {
					  if(Matrice[r][c]==8)
					  vetB[0]=vetB[0]+1;
					  if(Matrice[r][c]==9)
					  vetB[1]=vetB[1]+1;
					  if(Matrice[r][c]==12)
					  vetB[2]=vetB[2]+1;
					  if(Matrice[r][c]==11)
					  vetB[3]=vetB[3]+1;
					  }
				 }
			 }
			 
		 if(mossa=='N')
		  {
		  if(rFI==7&&Matrice[rFI][cFI]==1)
		    {
			somma=7;
			
			for(i=0;i<=DIMVET-1;i++)
			   {
			   if(vetN[i]<2&&i==0)
			     {
			     cout<<" CAVALLO NERO (0) | ";
			     somma=somma-1;
				 }
			   if(vetN[i]<2&&i==1)
			     {
			     cout<<" TORRE NERA (1) | ";
			     somma=somma-1;
				 } 
			   if(vetN[i]<2&&i==2)
			     {
			     cout<<" ALFIERE NERO (2) | ";
			     somma=somma-1;
				 }
			   if(vetN[i]<1&&i==3)
			     {
			     cout<<" REGINA NERA (3)";
			     somma=somma-1;
				 }
			   }
			
			if(somma==7)
			  {
			  cout<<endl<<" NON SONO STATI MANGIATI PEZZI NERI";
			  Matrice[rFI][cFI]=5;
			  }
			  
		  cin>>SOSTITUZIONE;
		  
		  if(SOSTITUZIONE==0)
		    {
		    Matrice[rFI][cFI]=2;
			}
		  if(SOSTITUZIONE==1)
		    {
		    Matrice[rFI][cFI]=3;
			}
		  if(SOSTITUZIONE==2)
		    {
		    Matrice[rFI][cFI]=6;
			}
		  if(SOSTITUZIONE==3)
		    {
		    Matrice[rFI][cFI]=5;
			}
		  }  
		    }
		    
		  
		
		if(mossa=='B')
		  {
		  if(rFI==0&&Matrice[rFI][cFI]==7)
		    {
			somma=7;
		
			for(i=0;i<=DIMVET-1;i++)
			   {
			   if(vetB[i]<2&&i==0)
			     {
			     cout<<" CAVALLO BIANCO (0) | ";
			     somma=somma-1;
				 }
			   if(vetB[i]<2&&i==1)
			     {
			     cout<<" TORRE BIANCA (1) | ";
			     somma=somma-1;
				 }
			   if(vetB[i]<2&&i==2)
			     {
			     cout<<" ALFIERE BIANCO (2) | ";
			     somma=somma-1;
				 }
			   if(vetN[i]<1&&i==3)
			     {
			     cout<<" REGINA BIANCA (3)";
			     somma=somma-1;
				 }
			   }
			
			if(somma==7)
			  {
			  cout<<endl<<" NON SONO STATI MANGIATI PEZZI BIANCHI";
			  Matrice[rFI][cFI]=11;
			  }
			  
		  cin>>SOSTITUZIONE;
		   
		  if(SOSTITUZIONE==0)
		    {
		    Matrice[rFI][cFI]=8;
			}
		  if(SOSTITUZIONE==1)
		    {
		    Matrice[rFI][cFI]=9;
			}
		  if(SOSTITUZIONE==2)
		    {
		    Matrice[rFI][cFI]=12;
			}
		  if(SOSTITUZIONE==3)
		    {
		    Matrice[rFI][cFI]=11;
			} 
		   }
		 } 

	   if(ERRORE==0)
         {
         for(r=0;r<=DIMR-1;r++)
			{
			cout<<"   "<<r<<" ";
			}
            cout<<endl;
         
         for (r=0;r<=DIMR-1;r++)
		   {
		   for (c=0;c<=DIMC-1;c++)
		       {
		       if(c==0)
		         {
		         cout<<r<<"  ";
				 }
		       if(Matrice[r][c]==1)
		       cout<<"PN | ";
		       if(Matrice[r][c]==2)
		       cout<<"CN | ";
		       if(Matrice[r][c]==3)
		       cout<<"TN | ";
		       if(Matrice[r][c]==4)
		         {
		         cout<<"RN | ";
		         ERRORE++;
				 }
		       if(Matrice[r][c]==5)
		       cout<<"rN | ";
		       if(Matrice[r][c]==6)
		       cout<<"AN | ";
		       if(Matrice[r][c]==7)
		       cout<<"PB | ";
		       if(Matrice[r][c]==8)
		       cout<<"CB | ";
		       if(Matrice[r][c]==9)
		       cout<<"TB | ";
		       if(Matrice[r][c]==10)
		         {
		         cout<<"RB | ";
		         ERRORE++;
				 }
				 
		       if(Matrice[r][c]==11)
		       cout<<"rB | ";
		       if(Matrice[r][c]==12)
		       cout<<"AB | ";
			   if(Matrice[r][c]==0)
			   cout<<"   | ";
	           }
	           
           cout<<endl;
           }
           
           if(ERRORE<2)  
			  {
			  re=false;
			  } 
			  
        
          if(mossa=='B')
            {
            mossa='N';
			}
		  else
		    {
		    if(mossa=='N')
	          {
	          mossa='B';
			  }
			}
         }
        else
         {
         cout<<"Non e' stato possibile effettuare la mossa, riprova"<<endl;
		 }
        
	   }
    }
    
if(mossa=='N')
cout<<endl<<"VITTORIA PER I BIANCHI"<<endl;

if(mossa=='B')
cout<<endl<<"VITTORIA PER I NERI"<<endl;
	   
       

return 0;
}
