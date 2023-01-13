class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        # store the (element, index) pair in the stack
        nsr_stack = []
        nsl_stack = []
        
        left = []
        right = []
        width = []
        area = []
        
        ip_size = len(heights)
        
        pseudo_index_right = ip_size
        pseudo_index_left = -1
        
        # find the nearest smaller element to right index array
        # reversed_heights = reversed(heights)
        for i in range(ip_size-1, -1 , -1):        
            while(len(nsr_stack)!=0 and nsr_stack[-1][0] >= heights[i]):
                nsr_stack.pop()
            if len(nsr_stack) == 0:
                right.append(pseudo_index_right)
            elif len(nsr_stack)!= 0 and nsr_stack[-1][0] < heights[i]:
                # store the index of the top element
                right.append(nsr_stack[-1][1])
            
            nsr_stack.append((heights[i], i))
        
        # Reverse the right array
        right.reverse()

        # find the nearest smaller element to left index array
        for i in range(0, ip_size):
            while(len(nsl_stack)!= 0 and nsl_stack[-1][0]>= heights[i]):
                nsl_stack.pop()
            if len(nsl_stack) == 0:
                left.append(pseudo_index_left)
            elif len(nsl_stack)!= 0 and nsl_stack[-1][0] < heights[i]:
                # store the index of the top element
                left.append(nsl_stack[-1][1])
            
            nsl_stack.append((heights[i], i))
        
        
        # find the width array
        width = [a-b-1 for a,b in zip(right, left)]
        
        # find the area array 
        area =  [a*b for a,b in zip(heights, width)]        
        
        # return the max of the area array
        return max(area)