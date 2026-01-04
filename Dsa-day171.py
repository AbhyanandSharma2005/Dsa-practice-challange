class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        total_sum = 0
        
        for num in nums:
            count = 0
            divisor_sum = 0
            
            i = 1
            while i * i <= num:
                if num % i == 0:
                    count += 1
                    divisor_sum += i
                    
                    if i != num // i:
                        count += 1
                        divisor_sum += num // i
                    
                    if count > 4:
                        break
                
                i += 1
            
            if count == 4:
                total_sum += divisor_sum
        
        return total_sum