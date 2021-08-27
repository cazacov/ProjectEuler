using System;
using Shared;

namespace Problem013
{
    class Program
    {
        static void Main(string[] args)
        {
            var acc = new BigNumber(0);
            var lines = System.IO.File.ReadAllLines("input.txt");

            foreach (var line  in lines)
            {
                var num = new BigNumber(line);
                acc = acc + num;
            }

            var result = acc.ToString();

            Console.WriteLine(result.Substring(0, 10));
        }
    }
}
