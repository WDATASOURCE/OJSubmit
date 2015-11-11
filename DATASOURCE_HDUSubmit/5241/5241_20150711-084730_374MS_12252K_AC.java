/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-11 08:13
# Filename:         Main.java
# Description: 
=============================================================================*/

import java.util.*;
import java.math.BigInteger;
 
public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int dx = 1; dx <= t; dx++){
            int n = in.nextInt();
            BigInteger ans = new BigInteger("32");
            ans = ans.pow(n);
            System.out.println("Case #" + dx + ": "+ ans);
        }
    }
}