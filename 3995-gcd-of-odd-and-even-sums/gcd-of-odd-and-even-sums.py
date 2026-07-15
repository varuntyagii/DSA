class Solution:
    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

    def gcdOfOddEvenSums(self, n):
        sumOdd = 0
        sumEven = 0

        for i in range(1, 2 * n + 1):
            if i % 2 == 0:
                sumEven += i
            else:
                sumOdd += i

        return self.gcd(sumOdd, sumEven)