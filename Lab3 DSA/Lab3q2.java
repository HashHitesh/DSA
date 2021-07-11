import java.util.*;

public class Lab3q2 
{
 public static void main(String[] args) 
 {
    StackandQueue sq = new StackandQueue();
    Scanner scan = new Scanner(System.in);

    int n=1;
    int y,o;
    while(n!=3)
    {
    System.out.println("enter 1 for enqueue 2 for dequeue 3 for exit");
    n = scan.nextInt();

    switch(n)
    {
      case 1:
      System.out.println("enter the value to be enqueued \n");
      o = scan.nextInt();
      sq.enqueue(o);
      break;
    case 2:
      y=sq.deQueue();
      break;
    case 3:
      System.exit(1);     

    }

    }


 }   

}

class StackandQueue
{
    private int max_size=8;
    private int top1=-1;
    private int top2=-1;
    private int front=0 , rear=0;
    private int stack1[] = new int[8];
    private int stack2[] = new int[8];
    private int x,y;

    public Boolean isStack1Full() {
        return top1 == max_size;
      }
    
    public Boolean isStack1Empty() {
        return top1 == -1;
      }
    
    public void push1(int x) {
        if (isStack1Full()) {
          System.out.println("OverFlow\nProgram Terminated\n");
          System.exit(1);
        }
    
        System.out.println("Inserting " + x);
        stack1[++top1] = x;
      }

    public int pop1() {
        if (isStack1Empty()) {
          System.out.println("STACK EMPTY");
          System.exit(1);
        }
        return stack1[top1--];
      }

      public Boolean isStack2Full() {
        return top2 == max_size;
      }
    
    public Boolean isStack2Empty() {
        return top2 == -1;
      }
    
    public void push2(int x) {
        if (isStack2Full()) {
          System.out.println("OverFlow\nProgram Terminated\n");
          System.exit(1);
        }
    
        System.out.println("Inserting " + x);
        stack1[++top2] = x;
      }

    public int pop2() {
        if (isStack2Empty()) {
          System.out.println("STACK EMPTY");
          System.exit(1);
        }
        return stack2[top2--];
      }

    boolean isEmpty()
    {
      if(front == -1)
      {return true;}
      else
      return false;

    }

    boolean isFull()
    {
        if (front == 0 && rear == max_size - 1) {
            return true;
          }
        return false;
    }

    int enqueue(int x)
    {
        if(isFull())
        {
         return -1;
        }
        
        push2(x);
        return 1;

    }

    int deQueue()//returns -1 if Queue is empty and the value otherwise
    {
       int y;
      if(isEmpty())
       {return -1;}
       
    while (isStack2Empty() == false) //stack2 is not empty
    {
      x=pop2();
      push1(x);
    }
    y=pop1();
    return y;
    
    while (isStack1Empty() == false)  //stack2 is not empty
    {
      
    x=pop1();
    push2(x);
    
    }
    return y;
    }

}