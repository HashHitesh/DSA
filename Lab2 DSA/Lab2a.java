public class Lab2a {

public static void main(String[] args) 
{
    int array[] = new int[10];

    Stack st = new Stack(10);

    array[0]=1;
    array[1]=2;
    array[2]=3;
    array[3]=4;
    array[4]=5;
    array[5]=6;
    array[6]=7;
    array[7]=8;
    array[8]=9;
    array[9]=10;

    for(int i = 0 ; i < 10 ; i++)
    {
      if(st.isFull())
      {System.out.println("Stack Full");}
      else
      st.push(array[i]);

    }

    int a = 0;
    while (!st.isEmpty())
    {
        array[a]=st.pop();
        a++;
    }

    System.out.println("Reversed using stack");
    for(int i = 0 ; i<10;i++)
    { System.out.print(" "+array[i]);}

}

}

class Stack 
{
    private int arr[] = new int[10];
    private int top = -1;
    private int capacity = 10;
  
    // Creating a stack
    Stack(int size) {
      arr = new int[size];
      capacity = size;
      top = -1;
    }
  
    // Add elements into stack
    public void push(int x) {
      if (isFull()) {
        System.out.println("OverFlow\nProgram Terminated\n");
        System.exit(1);
      }
  
      System.out.println("Inserting " + x);
      arr[++top] = x;
    }
  
    // Remove element from stack
    public int pop() {
      if (isEmpty()) {
        System.out.println("STACK EMPTY");
        System.exit(1);
      }
      return arr[top--];
    }
  
    // Utility function to return the size of the stack
    public int size() {
      return top + 1;
    }
  
    // Check if the stack is empty
    public Boolean isEmpty() {
      return top == -1;
    }
  
    // Check if the stack is full
    public Boolean isFull() {
      return top == capacity;
    }
  
}


