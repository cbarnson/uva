
// Problem #    : 11356
// Created on   : 2018-07-22 00:27:05

import java.io.*;
import java.util.*;
import java.math.*;
import java.time.Month;

class Main {

    // note: 0-based index returned
    public static int MonthNameToInteger(String month) {
        return Month.valueOf(month.toUpperCase()).ordinal();
    }

    public static String GetStringFromIntegerPadLeftWithZeros(int n) {
        return String.format("%02d", n);
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int n = Integer.valueOf(sc.nextLine());
        for (int i = 1; i <= n; i++) {
            String[] line = sc.nextLine().split("-");
            GregorianCalendar gc = new GregorianCalendar(Integer.valueOf(line[0]), MonthNameToInteger(line[1]),
                    Integer.valueOf(line[2]));
            gc.add(Calendar.DATE, Integer.valueOf(sc.nextLine()));
            String m = Month.of(gc.get(Calendar.MONTH) + 1).name().toLowerCase();
            System.out.println("Case " + i + ": " + gc.get(Calendar.YEAR) + "-" + Character.toUpperCase(m.charAt(0))
                    + m.substring(1) + "-" + GetStringFromIntegerPadLeftWithZeros(gc.get(Calendar.DATE)));
        }
        sc.close();
    }
}