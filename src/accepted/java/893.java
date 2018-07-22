
// Problem #    : 893
// Created on   : 2018-07-21 23:27:41

import java.io.*;
import java.util.*;
import java.util.stream.*;
import java.math.*;
import java.text.SimpleDateFormat;

class Main {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int n, d, m, y;
        while (true) {
            n = sc.nextInt();
            d = sc.nextInt();
            m = sc.nextInt();
            y = sc.nextInt();

            if (n == 0 && d == 0 && m == 0 && y == 0) {
                return;
            }

            // Note: pay attn to how we need to add to the date, then read back the fields
            // directly; don't use the date formatter
            GregorianCalendar gc = new GregorianCalendar(y, m - 1, d);
            gc.add(Calendar.DATE, n);
            System.out.println(gc.get(Calendar.DATE) + " " + Integer.valueOf(gc.get(Calendar.MONTH) + 1) + " "
                    + gc.get(Calendar.YEAR));
        }

    }
}