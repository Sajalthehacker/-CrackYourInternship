#User function Template for python3

class Solution:
    ##Complete this function
    #Function to check if array is sorted and rotated.
    def checkRotatedAndSorted(self,arr,n):
        #code here 
        cup,cdn = 0,0
        for i in range(1,n):
            if arr[i] > arr[i-1]:
                cup += 1
            if arr[i] < arr[i-1]:
                cdn += 1
        if ((cup == n-2) & (cdn == 1) & (arr[0] > arr[n-1])) | ((cdn == n-2) & (cup==1) & (arr[0] < arr[n-1])):
            return True
        else:
            return False

#{ 
#  Driver Code Starts
import atexit

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        a = list(map(int,input().strip().split()))
        ob=Solution()
        if ob.checkRotatedAndSorted(a,n) or ob.checkRotatedAndSorted(a[::-1],n):
            print("Yes")
        else:
            print("No")

# } Driver Code Ends