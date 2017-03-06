def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)
 
N=int(input())
 
for i in range(0, N):
    nums=input()
    nums=nums.split(' ')
    if(int(nums[0]) == 0 or int(nums[1]) == 0):
        print(max(int(nums[0]), int(nums[1])))
    else:
        print(gcd(int(nums[1]), int(nums[0])))
        
        
 
