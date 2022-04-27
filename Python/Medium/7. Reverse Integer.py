class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x >= 2 ** 31 - 1 or x <= -2 ** 31:
            return 0
        else:
            y = str(abs(x))
            if len(y) != 0:
                rev = y[::-1]
                if x < 0:
                    rev = '-' + rev
                res = int(rev)
                if res >= 2 ** 31 - 1 or res <= -2 ** 31:
                    return 0
                else:
                    return res
            else:
                return 0
