class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        n = len(s)
        d1 = [0] * n
        l, r = 0, -1
        left, right, ans = 0, -1, 0
        for i in range(n):
            k = 1 if i > r else min(d1[l + r - i], r - i + 1)
            while 0 <= i - k and i + k < n and s[i - k] == s[i + k]: k += 1
            d1[i] = k
            k -= 1
            if r < i + k:
                r = i + k
                l = i - k
            if ans < 2 * d1[i] - 1:
                ans = 2 * d1[i] - 1
                left = i - k
                right = i + k
        d2 = [0] * n
        l, r = 0, -1
        for i in range(n):
            k = 0 if i > r else min(d2[l + r - i + 1], r - i + 1)
            while 1 <= i - k and i + k < n and s[i - k - 1] == s[i + k]: k += 1
            d2[i] = k
            k -= 1
            if r < i + k:
                r = i + k
                l = i - k - 1
            if ans < 2 * d2[i]:
                ans = 2 * d2[i]
                left = i - k - 1
                right = i + k
        return s[left:right + 1]


main = Solution()
print(main.longestPalindrome("ababad"))
