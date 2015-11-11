/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-11 08:13
# Filename:         Main.java
# Description: 
=============================================================================*/

import java.util.*;
 
public class Main{
    public static void main(String[] args){
        byte[] a;
        Scanner in = new Scanner(System.in);
        String str;
        int t = in.nextInt();
        int n;
        for(int dx = 1; dx <= t; dx++){
            n = in.nextInt();
            str = in.next();
            a = str.getBytes();
            for(int i = 1; i <= n; i++)
                a = Base64.getEncoder().encode(a);
            System.out.println("Case #" + dx + ": "+ new String(a));
        }
    }
}
