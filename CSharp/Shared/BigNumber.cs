using System;
using System.Collections.Generic;
using System.Text;

namespace Shared
{
    public class BigNumber
    {
        private int[] digits; 

        public BigNumber()
        {
            digits = new[] {0};
        }

        public BigNumber(string str)
        {
            if (String.IsNullOrWhiteSpace(str))
            {
                digits = new[] { 0 };
            }
            else
            {
                digits = new int[str.Length];
                var idx = str.Length - 1;
                foreach (var ch in str)
                {
                    digits[idx] = (int) ch - 48;
                    idx--;
                }
            }
        }

        public BigNumber(int n)
        {
            if (n == 0)
            {
                digits = new[] {0};
                return;
            }

            var result = new List<int>();
            while (n > 0)
            {
                result.Add(n % 10);
                n /= 10;
            }
            digits = result.ToArray();
        }

        public BigNumber(IEnumerable<int> numbers)
        {
            var result = new List<int>();
            result.AddRange(numbers);
            digits = result.ToArray();
        }

        public override string ToString()
        {
            var result = new StringBuilder(digits.Length);
            for (var i = digits.Length - 1;  i >=0; i--)
            {
                result.Append((char)(digits[i] + 48));
            }
            return result.ToString();
        }

        public static BigNumber operator +(BigNumber a, BigNumber b)
        {
            var result = new List<int>();

            var idx = 0;
            var carry = 0;

            var a_len = a.digits.Length;
            var b_len = b.digits.Length;

            do
            {
                var a_val = idx < a_len ? a.digits[idx] : 0;
                var b_val = idx < b_len ? b.digits[idx] : 0;
                var res = a_val + b_val + carry;
                if (res > 9)
                {
                    res -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }

                result.Add(res);
                idx++;
            } while (idx < a_len || idx < b_len || carry > 0);
            return new BigNumber(result);
        }
    }
}
