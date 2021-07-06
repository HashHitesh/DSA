import java.util.*;

public class lab4a

{
public static void main(String[] args) {
 
int size=10;    

int[] array  = new int[size] ;

for (int i = 0 ; i < size ; i++)
{
    array[i]=0;
}

array[2]=-4;
array[3]=-6;
array[4]=20;
array[5]=-10;
array[6]=12;
array[7]=-14;
array[8]=16;
array[9]=18;

func(size,array);

array[1]=1;

for(int i = 0 ; i < size ; i++)
{
  if(array[i]>0)
  {System.out.println(array[i]);}
  else
  continue;
}



}


public static void func(int size , int [] values)
{
    values[0]=-1;
    values[0]=1;

    Random rand = new Random();
    int upperlimit = 50;

    for(int i = size-1 ; i>1 ; i--)
    {
        if(values[i]>0)
        {
            values[i/2]= rand.nextInt(upperlimit);
        }
        else 
        {
            values[i/2]=-1;
        }

    }


}

}

