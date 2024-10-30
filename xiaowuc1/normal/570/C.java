import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int qqq = readInt();
			char[] list = new char[n+2];
			String s = nextToken();
			for(int i = 1; i <= s.length(); i++) {
				list[i] = s.charAt(i-1);
			}
			int ret = 0;
			for(int i = 1; i < list.length; i++) {
				if(list[i] == '.' && list[i-1] == '.') {
					ret++;
				}
			}
			while(qqq-- > 0) {
				int index = readInt();
				char ch = nextToken().charAt(0);
				if(list[index-1] == '.' && list[index] == '.') ret--;
				if(list[index+1] == '.' && list[index] == '.') ret--;
				list[index] = ch;
				if(list[index-1] == '.' && list[index] == '.') ret++;
				if(list[index+1] == '.' && list[index] == '.') ret++;
				pw.println(ret);
			}
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