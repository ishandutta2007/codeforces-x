import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

/*
  br = new BufferedReader(new FileReader("input.txt"));
  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
  br = new BufferedReader(new InputStreamReader(System.in));
  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */


public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int m = readInt();
			int k = readInt();
			int[] l = new int[m];
			int[] r = new int[m];
			int[] d = new int[m];
			long[] orig = new long[n];
			for(int i = 0; i < n; i++) {
				orig[i] = readLong();
			}
			for(int i = 0; i < m; i++) {
				l[i] = readInt()-1;
				r[i] = readInt();
				d[i] = readInt();
			}
			int[] opDiff = new int[m];
			for(int i = 0; i < k; i++) {
				int a = readInt()-1;
				int b = readInt();
				opDiff[a]++;
				if(b < opDiff.length) {
					opDiff[b]--;
				}
			}
			long[] inc = new long[n];
			long times = 0;
			for(int i = 0; i < m; i++) {
				times += opDiff[i];
				inc[l[i]] += times * d[i];
				if(r[i] < inc.length) {
					inc[r[i]] -= times * d[i];
				}
			}
			long curr = 0;
			for(int i = 0; i < n; i++) {
				curr += inc[i];
				pw.print(orig[i] + curr);
				pw.print(" ");
			}
			pw.println();
		}
		exitImmediately();
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}