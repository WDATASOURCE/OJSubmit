/*=============================================================================
# Author:			He Shuwei
# Last modified: 	2014-09-28 19:30
# Filename: 		a.java
# Description: 
=============================================================================*/
 
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        BigInteger a = BigInteger.ZERO;
        while(true){
            BigInteger b = in.nextBigInteger();
            a = a.add(b);
            if(b.compareTo(BigInteger.ZERO) == 0)
                break;
        }
        System.out.println(a);
    }
}
