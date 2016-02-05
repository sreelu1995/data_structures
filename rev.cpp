 #include<iostream>

using namespace std;

class stack{

  public:

  char str[20];
  string exp,res;
  int top;

   stack()
   {
       top=-1;
   }

   void push(char var)
   {
       str[++top]=var;

   }

   char pop()
   {
       return str[top--];
   }

   char ftop()
   {
       if(top!=-1)

           return str[top];
   }

void insert()
{
    cout<<"enter the infix expression:";
    cin>>exp;
}

void postconv()
{
   char s;
   int p,q,j;

   int l=exp.length();

  for(int i=0;i<l;i++)
  {

     if(exp[i]!='('&&exp[i]!=')'&&exp[i]!='^'&&exp[i]!='*'&&exp[i]!='/'&&exp[i]!='+'&&exp[i]!='-')
      {
          res+=exp[i];
      }

     else
            if(exp[i]=='(')
               {
                   push(exp[i]);
               }

            else
                if(exp[i]==')')
               {
                   char popp=pop();

                   while(popp!='(')
                     {
                         res+=popp;
                         popp=pop();
                    }


               }

                 else
                      {
                          if(top==-1)
                          {
                              push(exp[i]);
                          }

                          else
                          {
                          char e=exp[i];

                          char t=ftop();

                          p=setprec(t);
                          q=setprec(e);


                      while(p>=q)
                       {
                          res+=pop();

                          t=ftop();
                          p=setprec(t);

                       }

                       if(p<q)
                       {
                           push(exp[i]);

                       }
                          }

                     }
                        }


 while(top!=-1)
 {
     res+=pop();
 }

   cout<<"\n the expression after postfix conversion is:"<<res;


 }

int setprec(char ch)
 {


                switch(ch)
                       {
                         case '(':return 0;

                         case '^':return 3;
                                 break;

                         case '*':
                        case '/':return 2;
                                 break;

                         case '+':
                         case '-':return 1;
                                 break;

                         default:cout<<"\n entered operator cannot be excecuted!";
                                  break;
                         }
 }

 void evaluate()
 {
     int a,b,c;

     for(int i=0;i<20;i++)
     {
         str[i]='\0';
     }

     top=0;

     int l=res.length();

     for(int i=0;i<l;i++)
     {
        if(res[i]!='^'&&res[i]!='*'&&res[i]!='/'&&res[i]!='+'&&res[i]!='-')
         {
            push(res[i]);
         }

         else
          {
              while(top>=1)
              {
                  b=(pop()-'0');cout<<"b"<<b<<endl;
                  a=(pop()-'0');cout<<"a"<<a<<endl;

                  c=operate(a,b,res[i]);
                  cout<<"\nc"<<c;

                  push(char(c));
              }
          }

     }

     cout<<"\n the expression after evaluation is:"<<(str[top]-'0');


 }

 int operate(int a,int b,char r)
 {
     switch(r)
     {
         case'+': return(a+b);
                  break;

         case'-': return(a-b);
                  break;

         case'*': return(a*b);
                  break;

         case'/': return(a/b);
                  break;

         case'^': return pow(a,b);
                  break;

         default:cout<<"\n unknown operator!!!";
                 break;
     }
  }

  int pow(int a,int b)
  {
       int p=a;

      for(int i=0;i<b;i++)
      {
         p*=a;
      }

      return p;
  }

};

main()
{
   stack st;

   st.insert();
   st.postconv();
   st.evaluate();

   return 0;
}




