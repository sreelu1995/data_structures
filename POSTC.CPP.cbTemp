#include<iostream>

using namespace std;

int setprec(char ch);

class stack{

  public:

  char str[20];
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


};

main()
{
   stack st;
   char s;
   int p,q,j;

   string exp,res;



   cout<<"enter the infix expression:";

   cin>>exp;
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
                   st.push(exp[i]);
               }

            else
                if(exp[i]==')')
               {
                   char popp=st.pop();

                   while(popp!='(')
                     {
                         res+=popp;
                         popp=st.pop();
                    }
                     char a=st.ftop();
                     cout<<"top:"<<a<<"\n";

               }

                 else
                      {
                          if(st.top==-1)
                          {
                              st.push(exp[i]);
                          }

                          else
                          {
                          char e=exp[i];

                          char t=st.ftop();

        cout<<"exp"<<e<<"top:"<<t<<"\n";

                          p=setprec(t);
                          q=setprec(e);


                      while((p>q)||(p==q))
                       {
                          res+=st.pop();
                          t=st.ftop();
                          p=setprec(t);

                       }

                       if(p<q)
                       {
                           st.push(exp[i]);



                       }
                          }



                      }
                      cout<<res<<"\t"<<i<<"\n";
  }

s=st.ftop();
cout<<"\n stack:"<<s;

 while(st.top>=0)
   {
       res+=st.pop();
        st.top--;
        s=st.ftop();
   }

   cout<<"\n the expression after postfix conversion is:"<<res;

   return 0;
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
