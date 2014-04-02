import java.util.*;

public class Solution
	{
		public static void main(String[] args)
		{
			//store the first 4 ugly numbers 
			// 1, 2, 3, 5
			int arr[] = new int[1500];
			arr[0] = 1;
			int pos2 = 0;
			int pos3 = 0;
			int pos5 = 0;
			int ug2, ug3, ug5, i, prev;

			for(i = 1; i < 1500; i++)
			{
				prev = arr[i-1];
				//keeps track of the locations of the previous numbers
				//multiplied by 2, 3, or 5 respectively
				while(arr[pos2] * 2 <= prev)
					pos2++;
				while(arr[pos3] * 3 <= prev)
					pos3++;
				while(arr[pos5] * 5 <= prev)
					pos5++;
				//keeps track of the potential ugly numbers
				ug2 = arr[pos2] * 2;
				ug3 = arr[pos3] * 3;
				ug5 = arr[pos5] * 5;
				arr[i] = Math.min(Math.min(ug2, ug3), ug5);
			}

			System.out.println("The 1500'th ugly number is " + arr[1499] + ".");
		}
	}