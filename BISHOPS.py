import sys
for line in sys.stdin:
    if int(line) == 1:
        print("1")
    else:
        print(2*(int(line)-1)) 
