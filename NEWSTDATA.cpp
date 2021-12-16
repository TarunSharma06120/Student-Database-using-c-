#include<iostream>
#include<string>
using namespace std;

struct student_data
{
 private:
  string  roll_no;
  string clas;
  char section;
 string name;
  string subject[3];
   string  marks[3];
   float percentage;
   float total;
    char a[100];
    public:
 
  //variables to modify records 
  
    string c_roll;
    string c_name;
    string c_clas;
    char c_section;
    string c_subject[3];
    string c_marks[3];
     
	int verify(char a)
	{
        int count=0; 
       int j=0;
       j=a;    
       if(j<48 || j>57)
       {
           count++;
       }
		return count; 

    } 
	
	 
    

    void getdata(int z)
    {
        int count=0;
          static int n=0; 
          static string i[100];
          	char c;	
			
            if(z==0)
			{
          
                          again: 
						
            cout<<endl<<"ENTER DATA OF STUDENT "<<endl;   
              			
               cout<<"enter your roll number here  ";
               cin>>roll_no;
			   c_roll=roll_no;
			     cin.ignore(1);

                int j=0;
				  float sum=0;
			   
			  for(int p=0;p<=0;p++)
			  {
				   
				  for(int k=0;k<roll_no.length();k++)
				  {
					  c=roll_no[k];
					
         					count=verify(c);
		                   
                	   if(count>0)
				       { 
				          	cout<<"invalid roll number ";
			        		 goto again;
				       }	
                       else
                       {
						     
							 j=c-48;
							sum=sum*10+j;
						   
						   
					   }						   
				  }
				   
			  
	          }       
            //TO VALIDATE ROLL NUMBERES 
			    
				 // cout<<endl<<"j=  "<<j<<"  c=  "<<c<<"  sum=  "<<sum;
				  if(sum<1 || sum>100)
				  {
					  cout<<endl<<"only numbers between 1 to 100 are allowed ";
					  goto again;
					  
				  }		
                  else
                  {
					  for(int p=0;p<100;p++)
					  {
						  if(i[p]==roll_no)
						  {
							  cout<<endl<<"THIS ROLL NUMBER IS ALREADY TAKEN TRY AGAIN "<<endl;
							  goto again;
						  }
						
					  }
					  i[n++]=roll_no;
				  }					 
                 
               				  

					   
             cout<<"enter your name here ";
              getline(cin,name);
                c_name=name;
				 
                      
            cout<<"enter your class here ";
             getline(cin,clas);
            			 
              
			  
			c_clas=clas;
			
                 j=0;
		    string a;
				 jj:
		  
            cout<<"ENTER  SECTION HERE ";
			
            getline(cin,a);
				
			
              
			if(a.length()>1)
			{
				cout<<"j="<<j;
				cout<<endl<<"INVALID SECTION ONLY SINGLE CHARRATERS ARE ALLOWED FROM A TO Z"<<endl;
				
				goto jj;
			}
			    c=verify_sub(a);
			     if(c=='t')
				 {
				   c_section=a[0];
        		  section=c_section;
				 }
				 else
				 {
					  cout<<endl<<"invalid only characters  A TO Z ARE ALLOWED "<<endl;
					 goto jj;
				 }
			
            for(int i=0;i<3;i++)
            {
                 jjj:
                cout<<"enter subject name here ";
                
                cin>>subject[i];
                 
				 
		         c=verify_sub(subject[i]);
				 if(c=='t')
				 {
				   c_subject[i]=subject[i];
				 }
				 else
				 {
					 cout<<endl<<"INVALID SUBJECT NAME IT CANNOT CONTAIN ANY NUMBER ONLY ALPHABETS ARE ALLOWED "<<endl;
					 goto jjj;
				 }
				 
                marks:
                cout<<"enter marks of "<<subject[i]<<" here ";
                
				cin>>marks[i];
                				
				c_marks[i]=marks[i];
				
				 int count=0;
				  int sum=0;
				       int j=0;
				       
				        for(int k=0;k<marks[i].length();k++)
				        {
					         c=marks[i][k];
					
         					 count=verify(c);
		                    
                	        if(count>0)
				            { 
				          	  cout<<"invalid marks only numbers are allowed  ";
			        		  goto marks;
				            }	
                            else
                            {
						     
							  j=c-48;
				
							  sum=sum*10+j;
						     
						    }
		        		}						   
				      
				  
				  if(sum<1 || sum>100)
				  {
					  cout<<endl<<"only numbers between 1 to 100 are allowed ";
					  goto marks;
					  
				  }
				  else
				  {
					  
					  total=total+sum;
				  }
								  
				  
               
             }     
             
              percentage=(total*100)/300;
			}
			if(z==1)
		    {
					  verify(i,n);
	    	}
		               
            if(z==2)
		    {
			   for(int jj=0;jj<100;jj++)
			   {
				   if(i[jj]==c_roll)
				   {
					   i[jj]='0';
				   }
			   }
	    	}
	     cin.ignore(1);	              					   
    }
  
      
       void showdata()
       {                    
               
                cout<<endl<<roll_no<<"|              |";
             cout<<name<<"|       |";
             cout<<clas<<"|         |";
           cout<<"|     "<<section<<"         |";
      
              for(int i=0;i<3;i++)
              {
                    cout<<"|   "<<marks[i]<<"   |";
 
              }        

               for(int i=0;i<3;i++)
               {
                     cout<<"|    "<<subject[i]<<"     |";
 
                }                       
              cout<<"|       "<<percentage<<"  |";  
              cout<<endl;   
               
        } 
		

      void dell(string r)
	  {
		  getdata(2);
		  
	  }

  void verify()
  {
	  getdata(1);
	  
  }
  
  void verify(string a[],int k)
  {
	  char c;
	  int count=0;
	  taken:
	    cin.sync();
	  cout<<endl<<"ENTER NEW ROLL NUMBER HERE "<<endl;
	     
	   getline(cin,c_roll);
	    		 
	   for(int p=0;p<=0;p++)
	   {
		   for(int j=0;j<c_roll.length();j++)
		   {
			   c=c_roll[j];
	      		  count=verify(c);
               if(count>0)
               {
				   cout<<endl<<"ONLY NUMBERS ARE ALLOWED "<<endl;
				   count=0;
				   goto taken;
			   }				   
		   }
	   }
	  
 
	   for(int p=0;p<=k;p++)
	   {
		   if(a[p]==c_roll)
		   {
			   cout<<endl<<"THIS ROLL NUMBER IS ALREADY TAKEN ";
			   
			   goto taken;
		   }
	   }
	  roll_no=c_roll;
	  a[k++]=roll_no;
	  
  }

      void change_name()
       {
		   cin.sync();
           cout<<"enter the new name here ";
           cin.ignore();
           getline(cin,c_name); 
             name=c_name;              
           
       } 
	  
	  void change_class()
       {
		    cin.sync();
                cout<<"ENTER NEW CLASS HERE ";
               cin>>c_clas;
              clas=c_clas;
        
       }
  
     void change_section()
     {
	    
		  int j=0;
		    string a;
				 jj:
				 cin.sync();
            cout<<endl<<"ENTER NEW SECTION HERE ";
            getline(cin,a);
		
              
			if(a.length()>1)
			{
				cout<<endl<<"INVALID SECTION ONLY SINGLE CHARRATERS ARE ALLOWED FROM A TO Z"<<endl;
				goto jj;
			}
			
             j=a[0];
			 
         cout<<endl<<"j="<<j;
     
            
         if(j>=65 && j<=122)
         {
               if(j>=65 || j<=90)
			   {
				    c_section=a[0];
        		  section=c_section;
				   
			   }
			   else if(j>=97 || j<=122)
			   {
				    c_section=a[0];
        		  section=c_section;
			   }
			   else
			   {
				   cout<<endl<<"invalid only characters  A TO Z ARE ALLOWED ";
				   
                   cout<<endl<<"j="<<j;
                  j=0;
                  goto jj;
			   }
              
		 }
		 else
		 {
			  cout<<endl<<"invaliddddd only characters  A TO Z ARE ALLOWED ";
			   
         cout<<endl<<"j="<<j;
                  j=0;
                  goto jj;
		 }
   }
  
 
      void change_subject(int  index,string q)
      {
          c_subject[index]=q;
          subject[index]=c_subject[index];
       
      }
  
     
          void change_marks(string mm,int index)
          {
              c_marks[index]=mm;
              marks[index]=c_marks[index];    
                                  
          }

     char verify_sub(string sub)
	 {
		  int j=0;
		  int count=0;
		  
		 for(int i=0;i<=0;i++)
		 {
			 for(int p=0;p<sub.length();p++)
			 {
				  j=sub[p];
     
            
                if(j>=65 && j<=122)
				{
					if(j>=65 || j<=90)
					{
						count++;
				   
					}
					else if(j>=97 || j<=122)
					{
						count++;
					}
					else
					{
						count=0;
					}
              
				}
				else
				{
						count=0;
				}
				
			     
			 }
			 
		 }
		 
		  if(count==sub.length())
		  {
			  return 't';
		  }
		  if(count==0)
		  {
			 
			return 'f';
		  }
		 return 'k';
	 }

};

    int verify(char a)
	{
        int count=0; 
       int j=0;
       j=a;    
       if(j<48 || j>57)
       {
           count++;
       }
		return count; 

    } 

int main()  
{
  student_data s1[100];      

  
 int n;   
  int i=0;
   string c;
    int count=0;

 
   perform: 
     
 cout<<endl<<"1.CREATE A NEW RECORD"<<endl<<"2.MODIFY EXISTING RECORD"<<endl<<"3.DELETE A RECORD"<<endl<<"4.DELETE ALL RECORDS"<<endl<<"5.SHOW A RECORD"<<endl<<"6.SHOW ALL RECORDS";
  
   cout<<endl<<"DO YOU WANT TO PERFORM ANY FUNCTION GIVEN ABOVE IF YES THEN ENTER Y IF NO THEN ENTER N"<<endl;
    
   getline(cin,c);
    cin.sync();
  
   if(c=="yes" || c=="YES" || c=="Y" || c=="y") 
   {
      string r;
	  char c;
	  string gj;
		ff:
	   cout<<"enter the serial number of the function you want to perform "<<endl;
       getline(cin,gj);
	   
	    if(gj.length()>1)
		{
			cout<<endl<<"YOU MUST ENTER VALUES BETWEEN 1 TO 6 "<<endl;
			  goto ff;
		}
        
		 c=gj[0];
           if(c<49 || c>54)
		   {
			  cout<<endl<<"YOU MUST ENTER VALUES BETWEEN 1 TO 6 "<<endl;
			  goto ff;
		   }
	      
          
        switch(c)
        {
               case 49:				
		        int k;		  
                 n=0;
		       ok1:
               cout<<"how many students data you will enter? ";
                cin>>n;
				if(n!=1 || n!=100)
			   	{
					 cin.clear();
					while (cin.get() != '\n')
					{
						 cout<<"YOU MUST ENTER ONLY NUMBERS ";
                      goto ok1;
                    }
					
				}			
				
                count=count+n;                   
                 while(i<count)
                 {
      
                      s1[i++].getdata(0);
                 }
				   
                      break;
                
				 case 50:
                        int c2;      
                        int num;
                                              
                           int sum;
                          int j;						  
                          char c;   
                      
                         cout<<endl<<"WHICH RECORD YOU WANT TO MODIFY"<<endl;
                        goto MODIFYY;	
                        
						r22:
						
                        cout<<endl<<"ENTER THE ROLL NUMBER OF THAT RECORD WHICH YOU WANT TO MODIFY ";
						
                        getline(cin,r);
						 
						
						  for(int p=0;p<=0;p++)
						  {	  
						  
							  for(int u=0;u<r.length();u++)
							  {
								  c=r[u];
                                  num=s1[count].verify(c);								 
								  
							  }
							  if(num>0)
							  {
								  cout<<endl<<"INVALID ROLL NUMBER ONLY NUMBERS ARE ALLOWED BETWEEN 1 TO 100 "<<endl;
								  goto r22;
								 
							  }
							  else
							  {
								  j=c-48;
				
							    sum=sum*10+j;
						     
							  }
						  }
					  
       					  if(sum<1 || sum>100)
						   {
							   cout<<endl<<"ONLY NUMBERS BETWEEN 1 TO 100 ARE ALLOWED ";
							   goto r22;
							   
						   }
						
						
                           for(int j=0;j<count;j++)
                           {    
                                       if(s1[j].c_roll==r)
                                       {
                                               k=j;
                                              int t;
                                                cout<<endl<<"WHAT YOU WANT TO CHANGE IN THIS RECORD "<<endl;
                          cout<<"1.ROLL NUMBER "<<endl<<"2. NAME"<<endl<<"3.CLASS"<<endl<<"4.SECTION"<<endl<<"5.TO CHANGE ANY SUBJECT 1,2 OR 3    "<<endl<<"6.TO CHANGE ANY MARKS OF  SUBJECT 1,2 OR 3 "<<endl;
                                                      
                                           
                                                   s1[j].showdata();
                                              
                                              aggg:
                                          cout<<endl<<"NOW ENTER THE SERIAL NUMBER OF THE OPTION GIVEN ABOVE THE RECORD YOU WANT TO CHANGE    ";
                                          cin>>t;
                                              
                                                  if(t==1)
                                                  {
                                                         s1[k].verify();
                                                       cout<<endl<<"after modifying the record "<<endl;
													    cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASSE   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
                                              
                                                       s1[k].showdata();
                                                                  
                                                  }
             					                  else if(t==2)
                                                  {
                                                          s1[k].change_name();
                                                          cout<<endl<<"after modifying the record "<<endl;
														  cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASSE   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               
                                                       s1[k].showdata();
                                                                  
                                                  }
                                                   else if(t==3)
                                                  {
                                                         s1[k].change_class();
                                                           cout<<endl<<"after modifying the record "<<endl;
														    cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASSE   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               
                                                       s1[k].showdata();
                                                                  
                                                  }
                                                  else if(t==4)
                                                  {
                                                       s1[k].change_section();
                                                         cout<<endl<<"after modifying the record "<<endl;
														 cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASSE   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               
                                                       s1[k].showdata();
                                                                  
                                                  }       
                                                  else if(t==5)
                                                  {
                                                         int z=0;
                                                            string sub;
                                                           string c_sub;
                                                           char y;
                                                                   wrong_subject:
                                                                 cout<<endl<<"ENTER THE NAME OF SUBJECT YOU WANT TO CHANGE HERE  ";
                                                                  cin.sync();
                                                                getline(cin,sub);
                   
                                                                        for(int w=0;w<3;w++)
                                                                        {
                                                                              if(s1[k].c_subject[w]==sub)
                                                                              {
                                                                                        z++;
                                                                                           cout<<endl<<" SUBJECT "<<w+1 <<" FOUND AS  "<<sub<<"DO YOU WANT TO CHANGE THIS ONLY? ";
                                                                                            cin>>y;     
                                                                                      if(y=='y' || y=='Y')
                                                                                       {
                                                                                                cout<<endl<<"NOW ENTER THE NEW  NAME OF SUBJECT HERE "<<endl;
                                                                                                cin.ignore(1);
                                                                                                getline(cin,c_sub);
                                                                                               s1[k].c_subject[w]=c_sub;
                                                                                               s1[k].change_subject(w,c_sub);   
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                           cout<<endl<<"OK"<<endl;
                                                                                      
                                                                                        }
                                                                                                               
                                                                                }
                                                                              
                                                                                      
                                                                        }
                                                              
                                                                     if(z==0)
                                                                     {
                                                                                        cout<<"THE SUBJECT YOU ENTERED IS NOT AVAILABLE ";
                                                                                        cout<<endl<<"TRY AGAIN  ";
                                                                                        goto wrong_subject;
                                                                                
                                                                     } 
                                                                    else
                                                                    {
                                                                        cout<<endl<<"AFTER CHANGING SUBJECT NAME "<<endl;
																		cout<<"ROLL NUMBERS      |"<<"|  NAME       |"<<"|  CLASSE   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               
                                                                         s1[k].showdata();
                                                                     }
 
                                                          
                                                  }
                                                  else if(t==6)
                                                 {
                                                              string marks;
                                                         int q=0,z=0;
                                                         string sub;
                                                            char y;
															int tot=0;
															int sum=0;
															int j=0;
															char cc;
                                                                   wrong_sub:
                                                                   
                                                                 cout<<endl<<"enter the name of subject of which you want to change the marks "<<endl;
                                                                cin.ignore(1);
                                                                getline(cin,sub);
                                                                
                                                                   
                                                                        for(int w=0;w<3;w++)
                                                                        {
                                                                              if(s1[k].c_subject[w]==sub)
                                                                              {
                                                                                        z++;
                                                                                           cout<<endl<<" SUBJECT "<<w+1 <<" FOUND AS  "<<sub<<"DO YOU WANT TO CHANGE THIS ONLY? "<<endl;
                                                                                           cin>>y;     
                                                                                       if(y=='y' || y=='Y')
                                                                                       {
																						       haha:
																							   sum=0;
                                                                                                cout<<endl<<"ENTER NEW MARKS HERE "<<endl;
                                                                                                 rm:
																								 cin.ignore(1);
                                                                                                  getline(cin,marks);
																								  cin.ignore(1);
																									
																									for(int kk=0;kk<marks.length();kk++)
																									{
																										cc=marks[kk];
					
																										tot=s1[k].verify(cc);
																										cout<<endl<<"tot after verify "<<tot;
																										if(tot>0)
																										{ 
																												cout<<"invalid marks only numbers are allowed  ";
																												tot=0;
																												cin.ignore(1);
																												goto haha;
																										}	
																										else
																										{
						     
																											j=cc-48;
				
																											sum=sum*10+j;
						     
																										}
																									}						   
				                                                                                
																										cout<<endl<<"j=  "<<j<<"  c=  "<<c<<"  sum=  "<<sum;
																										if(sum<1 || sum>100)
																										{
				
																								          cout<<endl<<"only numbers between 1 to 100 are allowed sum>1 || sum<100";
																												goto haha;
					  
																										}
				                                                                                        else
																						                {
																												s1[k].change_marks(marks,w);
																												cout<<endl<<"after modifying the record "<<endl;
																												cout<<"ROLL NUMBERS      |"<<"|  NAMES      |"<<"|  CLASSE   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               
																												s1[k].showdata();
																										} 
 
                                                                                          }
                                                                                         else
                                                                                         {
                                                                                             cout<<endl<<"OK"<<endl;
                                                                                         }
                                                                                                               
                                                                                }
                                                                                
                                                                        }
                                                              if(z==0)
                                                              { 
                                                                  cout<<endl<<"THE NAME OF SUBJECT YOU ENTERED IS WRONG OR NOT AVAILABLE PLEASE TRY AGAIN "<<endl;
                                                                  goto wrong_sub;
                                                              }   
                          
 
                                                   
                                                  }
												  else
												  {
													  cout<<endl<<"ONLY VALUES BETWEEN 1 TO 6 ARE ALLOWED "<<endl;
													  goto aggg;
													  
												  }
                                       }
                                       else
                                       {
                                           cout<<"NO RECORD FOUND YOU MAY ENTERED WRONG ROLL NUMBER "<<endl;
                                       }
                               												  
                                                  
									    
						      }										
				       
                 break;
				    case 51:
                             
                             int c3;
							 int tot;
							 char cc;
							 c3=22;
						
                               								 
                               cout<<endl<<"WHICH RECORD YOU WANT TO DELETE "<<endl;
                                
                               goto DELETE;
                                 ok3: 
                                 sum=0;							
                                 
                                 								  
                               cout<<endl<<"ENTER THE ROLL NUMBER OF THAT RECORD WHICH YOU WANT TO DELETE  "<<endl; 
                                     cin.sync();          
             					   getline(cin,r);
								
								for(int p=0;p<=0;p++)
								{
									for(int g=0;g<r.length();g++)
									{
										cc=r[g];
										tot=verify(cc);
										if(tot>0)
										{
											cout<<endl<<"ONLY NUMBERS BETWEEN 1 TO 100 ARE ALLOWED ";
											goto ok3;
										}
										else
										{
		                                    j=cc-48;
							                 sum=sum*10+j;								
       									
										}
									}
								}
								
								 
							if(sum<1 || sum>100)
						    {
								cout<<"INVALID ROLL NUMBER! ONLY VALUES BETWEEN 1 TO 100 ARE ALLOWED";
	     						 goto ok3;
							}
							else
                            {								
							
                              for(int p=0;p<count;p++)
                              {
								        
                                    if(s1[p].c_roll==r)
                                    {
										 s1[p].dell(r);
                                        s1[p]=s1[p+1];
                                        count--;
                                        i--;
                                    }
                                      
                              
                              }
							 
                            }							 
                           cout<<endl<<"CHECK TAHT RECORD HAS BEEN DELETED "<<endl;
                              for(int p=0;p<count;p++)
                              {
                                    s1[p].showdata();                   
                              
                              }
                                  
                   
                     break;
					 
					 case 52:
                        
						 if(count==0)
						 {
							 cout<<endl<<"NO DATA AVAILABLE TO DELETE ALL RECORDS"<<endl;
						 }
                   if(count>0)
                   { 						
                    for(int p=0;p<=count;p++)
                    {
                        count--;                  
                    }
					 
                    
					cout<<endl<<"ALL RECORD HAS BEEN DELETED "<<endl;
                   }
                    break;
					
					case 53:
                     
                      an_name:	
                      j=0;					  
                      int g;
					  sum=0;
                 
                 if(count>0)
			     {					 
                      cout<<endl<<"ENTER YOUR ROLL_NO HERE   ";
					
                       getline(cin,r);
					   
                      
					            for(int p=0;p<=0;p++)
								{
									for(g=0;g<r.length();g++)
									{
										cc=r[g];
										tot=verify(cc);
										if(tot>0)
										{
											cout<<endl<<"ONLY NUMBERS BETWEEN 1 TO 100 ARE ALLOWED  TRY AGAIN";
											goto an_name;
										}
										else
										{
		                                    j=cc-48;
							                 sum=sum*10+j;								
       									
										}
									}
								}
								
								// cout<<endl<<"sum== "<<sum;
							if(sum<1 || sum>100)
						    {
								cout<<"INVALID ROLL NUMBER! ONLY VALUES BETWEEN 1 TO 100 ARE ALLOWED";
	     						 goto an_name;
							}

                 	 
                       g=0;
                      for(int p=0;p<count;p++)
                      {
                          if(s1[p].c_roll==r)
                          { 
                              g++;
							   cout<<"ROLL NUMBER   |"<<"|  NAME     |"<<"| CLASS   |"<<"|  SECTION   |"<<"|   M1  |" <<"|  M2  |"<<"|   M3  |"<<"|  SUBJECT 1 |"<<"|  SUBJECT 2  |"<<"|  SUBJECT 3   |"<<"|PERCENTAGE  |";                
               
                              s1[p].showdata();   
                          }
                      } 
                     if(g==0)
                     {
                            cout<<"THE ROLL NUMBER YOU ENTERED IS MAY BE INCORRECT OR NOT AVAILABLE IN THIS DATABASE "<<endl;
                            cout<<"TRY TO FIND YOUR  NAME BELOW AND ENTER THE ROLL NUMBER AGAIN "<<endl; 
                              for(int p=0;p<count;p++)
                              {
                                 s1[p].showdata();
                              }
                            cout<<"TRY AGAIN "<<endl;
                           goto an_name;
                       
                     }
                 }
				 else
				 {
					 cout<<endl<<"NO DATA AVAILABLE ATLEAST CREATE ONE RECORD "<<endl;
				 }
					 
					 
					 break;
                 case 54:
                     k=0;
                   c2=1;
               cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASS   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               
			     
                      for(int j=0;j<count;j++)
                      {    
                 
                         s1[j].showdata();
                          k++;
              
                      }
					  if(k==0)
					  {
						   cout<<endl<<"NO DATA AVAILABLE PLEASE CREATE ATLEAST ONE RECORD "<<endl;
					  }
                 
                 if(c2>1)
                 {
					  MODIFYY:
					  k=0;
					   cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASS   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
                   
					  for(int j=0;j<count;j++)
                      {    
                 
                         s1[j].showdata();
						 k++;
					  }
					  if(k==0)
                      {  

                        cout<<endl<<"NO DATA AVAILABLE PLEASE CREATE ATLEAST ONE RECORD "<<endl;
                      
                       }  
                       else
                       {
						  goto r22;   
					   }						   
                       
				 }					 
                 
                 if(c3==3)
				 {
					 DELETE:
					 k=0;
				       cout<<"ROLL NUMBERS      |"<<"|  NAME        |"<<"|  CLASS   |"<<"|     SECTION   |"<<"|     M1  |" <<"|    M2  |"<<"|    M3  |"<<"|   SUBJECT 1 |"<<"|   SUBJECT 2  |"<<"|   SUBJECT 3   |"<<"|PERCENTAGE   |";                
               	        
					 for(int j=0;j<count;j++)
                      {    
                 
                         s1[j].showdata();
						 k++;
					  }
					  if(k==0)
                      {  

                        cout<<endl<<"NO DATA AVAILABLE PLEASE CREATE ATLEAST ONE RECORD "<<endl;
                      
                      }             
                      else
					  {
						  goto ok3;
					  }
					 
				 }					 
                       
             
                 break;
        }  
		 
         goto perform; 
     }
     else
     {
          cout<<"THANKS FOR COMING";
     }
 
}