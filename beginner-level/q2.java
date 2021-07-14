/*Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not. */

public class q2 {


    public static void main(String[] args) 
    {
        int rem , temp ;
        int pn=0;
        int num = 121;
        temp=num;
        
        while(num>0)
        {
           rem = num%10;
           pn = (pn*10)+rem;
           num=num/10;
        }

        if(temp==pn)
        {System.out.println("Palindrome");}
        else
        {System.out.println("Not Palindrome");}
    }
    
}
