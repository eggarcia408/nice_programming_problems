#!/usr/bin/python3

#F[0] = 0 and F[1] = 1 in my starting fib sequence
#if F[0] = 1 and F[1] = 1 in jy fib sequence, then the fib function would be
#   if N<=1:
#       return 1
#   else fib (n-1) + fib(n-2)


def fib(N):
    if N ==0:
        return 0
    elif N == 1:
        return 1
    else:
        return fib(N-1) + fib(N-2)




print("Please indicate the first fib terms you will be printing")
n = input()

print("\nThe following are the fib terms")

#up to but not including n since its first n fib numbers
#in fib sequence (0 up to n-1)
for i in range(0,int(n)):
    print(fib(i))

#If you just want to return nth number, than you just
#call the fib function one time to make it return on integer

