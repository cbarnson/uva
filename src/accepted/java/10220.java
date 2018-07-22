
import java.io.*;
import java.util.*;
import java.math.*;

class Main {

    static BigInteger[] f = new BigInteger[1005];

    static BigInteger fac(int n) {
        if (n < 2) {
            return (f[n] = BigInteger.ONE);
        }

        if (f[n].compareTo(BigInteger.ZERO) == 1) {
            return f[n];
        }

        f[n] = fac(n - 1).multiply(BigInteger.valueOf(n));

        return f[n];
    }

    public static void main(String args[]) // entry point from OS
    {
        Arrays.fill(f, BigInteger.ZERO);
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            BigInteger bi = fac(input.nextInt());
            String str = bi.toString();
            long s = 0;
            for (int i = 0; i < str.length(); i++) {
                s = s + Character.digit(str.charAt(i), 10);
            }
            System.out.println(s);
        }
    }
}