/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*/

public class q3 
{
    public static void main(String[] args) 
    {
        int number = -123;

        int rev=0;
        int temp=number;
        int rem;

        if(temp<0)
        { 

        temp=temp*(-1);

        while(temp>0)
        {
           rem=temp%10;
           rev=(rev*10)+rem;
           temp=temp/10; 
        }

        System.out.println(rev*-1);
        
        }

        else
        {
            while(temp>0)
            {
               rem=temp%10;
               rev=(rev*10)+rem;
               temp=temp/10; 
            }
    
            System.out.println(rev);
            
        }

        

    



    }


}
