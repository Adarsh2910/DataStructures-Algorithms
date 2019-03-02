/*
 * Find pair of number in array
 * url: https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
 */

import java.util.*;

class SockMerchant {

	static int sockPairCount(int n, int[] arr) {
		HashSet<Integer> h = new HashSet<Integer>();
		int l = 0;
		for(int i=0; i<n; i++) {
			if(h.contains(arr[i])) {
				l++;
				h.remove(arr[i]);
			} else {
				h.add(arr[i]);
			}
		}

		return l;
	}
	
	static Scanner sc = new Scanner(System.in);
	public static void main(String args[]) {
		int n = sc.nextInt();
		int[] arr = new int[n];

		for(int i=0; i<n; i++) {
			arr[i] = sc.nextInt();
		}
		
		int result = sockPairCount(n, arr);
		System.out.println(result);
		sc.close();
	}
}
