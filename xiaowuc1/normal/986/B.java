import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			BIT bit = new BIT(n);
			long ret = 0;
			for(int i = 0; i < n; i++) {
				int c = readInt();
				ret += i - bit.query(c);
				bit.update(c, 1);
			}
			pw.println(ret%2 == n%2 ? "Petr" : "Um_nik");
		}
		pw.close();
	}

	static class BIT {
		public int[] leaf;
		public BIT(int k) {
			leaf = new int[k+5];
		}
		public void update(int idx, int val) {
			idx += 2;
			while(idx < leaf.length) {
				leaf[idx] += val;
				idx += idx & -idx;
			}
		}
		public int query(int idx) {
			idx += 2;
			int ret = 0;
			while(idx > 0) {
				ret += leaf[idx];
				idx -= idx & -idx;
			}
			return ret;
		}
	}
	
	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}