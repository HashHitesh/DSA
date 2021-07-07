public class Lab2b {
   
    
    public static void main(String[] args)
    {
        char [] arr = {'{','[','(',')',']','}'} ; 

        int len = arr.length;

        Stack2 st = new Stack2(10);
        st.Balance(arr, len);

    }


}

class Stack2
{
   int size = 10 ;
   int top = -1;
   char [] stack = new char[size];

   Stack2(int size) {
    stack = new char[size];
    this.size = size;
    top = -1;
  }

  int Size()
  {
    if(top!=-1){return top;}
    else 
    return 0;
  }

  boolean empty()
{
    if(top<0){return true;}
    else 
    return false;
}

boolean full()
{
    if(top== size-1){return true;}
    else
    return false;
    
}

char top_s()
{
    if(!empty())
    {return stack[top];}
    else 
    return 0;
}

void push(char x)
{
    if(!full())
    {
        top++;
        stack[top]=x;
    }
    else 
    {
        System.out.println("Stack full");
    }
}

char pop()
{
    if(!empty())
    {
        char temp = stack[top];
        top--;
        return temp;
    }
    else
    return 0;
}

void Balance(char arr[], int n)
{
  char ck;
  for(int i =0;i<n;i++)
  {
      if (arr[i]=='['||arr[i]=='{'||arr[i]=='(')
     {
         push(arr[i]);
     }
  
  else if(arr[i]==']')
  {
   ck = pop();
   if(ck!='[')
    {System.out.println("Unbalanced");}
  }
  
   else if(arr[i]=='}')
  {
   ck = pop();
   if(ck!='{')
    {System.out.println("Unbalanced");}
  }
  
   else if(arr[i]==')')
  {
   ck = pop();
   if(ck!='(')
    {System.out.println("Unbalanced");}
  }
    
}

if(!empty())
{System.out.println("Unbalanced");}
else
{System.out.println("Balanced");}
}




}
