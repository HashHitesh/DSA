/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */

public class q1 
{

public static void main(String[] args) 
{
  int [] arr = new int [10];

  arr[0]=1;
  arr[1]=2;
  arr[2]=7;
  arr[3]=4;
  arr[4]=6;
  arr[5]=9;
  arr[6]=5;
  arr[7]=3;
  arr[8]=8;
  arr[9]=0;

  int target = 9;

  fun(arr,target);

}

public static void fun(int [] array , int target)
{
 /*
  for(int i=0;i<9;i++)
  {
    if(array[i] + array[i+1] == target)
    {System.out.println(i+" "+(i+1));}
    else
    continue;
  }
  */

  for(int i=0;i<9;i++)
  {
    
    for(int j=i+1;j<9;j++)
    {
      if(array[i]+array[j]==target)
      {
        System.out.println(i+" "+j);
      }
      else
      { continue; }

  }

}


}

}